# 📚 CPP09 - STL Completo: Guía de Solución


## 🏗️ Arquitectura de Excepciones - Transversal a Todo el Proyecto

### Principio de Diseño

**Cada ejercicio implementa una jerarquía de excepciones personalizada** siguiendo el mismo patrón arquitectónico. Esto demuestra:

1. **Consistencia**: Mismo enfoque en los 3 ejercicios
2. **Profesionalismo**: Manejo robusto de errores
3. **Reutilización de conceptos**: Patrón standardizado
4. **Extensibilidad**: Fácil agregar nuevas excepciones

### Patrón Base (Aplicable a Todos)

```cpp
/* ===== HEADER ===== */
#ifndef EXERCISE_EXCEPTION_HPP
#define EXERCISE_EXCEPTION_HPP

#include <exception>
#include <string>

// BASE: Hereda de std::exception
class ExerciseException : public std::exception
{
	protected:
		std::string _message;

	public:
		ExerciseException(const std::string& message);
		ExerciseException(const ExerciseException& other);
		ExerciseException& operator=(const ExerciseException& other);
		virtual ~ExerciseException(void) throw();
		
		virtual const char* what(void) const throw();
};

// DERIVADAS: Específicas del problema
class SpecificException : public ExerciseException { ... };

#endif
```

```cpp
/* ===== IMPLEMENTACIÓN ===== */
ExerciseException::ExerciseException(const std::string& message)
	: _message(message) {}

ExerciseException::ExerciseException(const ExerciseException& other)
	: _message(other._message) {}

ExerciseException& ExerciseException::operator=(const ExerciseException& other)
{
	if (this != &other)
		_message = other._message;
	return *this;
}

ExerciseException::~ExerciseException(void) throw() {}

const char* ExerciseException::what(void) const throw()
{
	return _message.c_str();
}
```

### Jerarquía por Ejercicio

**EX00: Bitcoin Exchange**
```
std::exception
    ↓
BitcoinExchangeException
    ├── FileException
    ├── DateException
    ├── ValueException
    └── InvalidFormatException
```

**EX01: RPN**
```
std::exception
    ↓
RPN_Exception
    ├── TokenException
    ├── StackUnderflowException
    ├── DivisionByZeroException
    └── SyntaxException
```

**EX02: PmergeMe**
```
std::exception
    ↓
PmergeMe_Exception
    ├── InputException
    ├── NegativeNumberException
    └── InvalidSequenceException
```

### Uso Consistente en main()

```cpp
// Mismo patrón en los 3 ejercicios
try
{
    Exercise exercise;
    exercise.process(arguments);
}
catch (const ExerciseException& e)
{
    std::cerr << ERROR_COLOR << e.what() << RESET << std::endl;
    return 1;
}
catch (const std::exception& e)
{
    std::cerr << ERROR_COLOR << "Unexpected error: " << e.what() << RESET << std::endl;
    return 1;
}
```

### Beneficios de Esta Arquitectura

| Aspecto | Beneficio |
|--------|----------|
| **Captura selectiva** | Podemos diferenciar entre tipos de error |
| **Información clara** | Cada excepción explica qué salió mal |
| **Debugging** | Con macros DEBUG_ERROR, fácil ver dónde falló |
| **Mantenimiento** | Agregar nuevos errores es simple |
| **Testing** | Podemos probar casos de error específicos |
| **C++98 compatible** | `std::exception` es estándar desde 1998 |

---

## 📋 Tabla de Contenidos General

### [Arquitectura Transversal de Excepciones](#-arquitectura-de-excepciones---transversal-a-todo-el-proyecto)
- [Principio Base](#principio-de-diseño)
- [Patrón Estándar](#patrón-base-aplicable-a-todos)
- [Jerarquía por Ejercicio](#jerarquía-por-ejercicio)
- [Uso en main()](#uso-consistente-en-main)
- [Beneficios](#beneficios-de-esta-arquitectura)

### [Exercise 00: Bitcoin Exchange](#exercise-00-bitcoin-exchange)
- [Descripción](#ex00-descripción-del-problema)
- [Análisis de Diseño](#ex00-análisis-y-decisiones-de-diseño)
- [Estructura](#ex00-estructura-del-proyecto)
- [Implementación](#ex00-guía-de-implementación)
- [Validaciones](#ex00-validaciones-requeridas)

### [Exercise 01: RPN](#exercise-01-rpn)
- [Descripción](#ex01-descripción-del-problema)
- [Excepciones](#ex01-excepciones-específicas)
- [Análisis de Diseño](#ex01-análisis-y-decisiones-de-diseño)
- [Arquitectura](#ex01-arquitectura)
- [Implementación](#ex01-guía-de-implementación)

### [Exercise 02: PmergeMe](#exercise-02-pmergeme)
- [Descripción](#ex02-descripción-del-problema)
- [Excepciones](#ex02-excepciones-específicas)
- [Ford-Johnson Algorithm](#ex02-ford-johnson-algorithm)
- [Números de Jacobsthal](#ex02-números-de-jacobsthal)
- [Implementación](#ex02-guía-de-implementación)

---

# Exercise 00: Bitcoin Exchange

## EX00: Descripción del Problema

### Objetivo
Crear un programa `btc` que:
1. Lee un archivo CSV histórico con precios de Bitcoin a través del tiempo
2. Lee un archivo de entrada del usuario con fechas y cantidades
3. Para cada línea, calcula: `cantidad × precio_histórico = valor_en_usd`
4. Imprime el resultado o mensaje de error

### Formato de Entrada

**Archivo CSV histórico (`data.csv`):**
```
date,exchange_rate
2009-01-02,0
2009-01-05,0
2011-01-03,0.3
2011-01-09,0.32
...
```

**Archivo de entrada del usuario:**
```
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-09 | 1
2012-01-11 | -1        ← Negativo (error)
2001-42-42             ← Fecha inválida (error)
2012-01-11 | 2147483648 ← Muy grande (error)
```

### Salida Esperada
```
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
Error: too large a number.
```

---

## EX00: Análisis y Decisiones de Diseño

### 1. Contenedor: `std::map<std::string, float>`

#### ¿Por qué NO vector o list?
- **Vector**: Necesitaría búsqueda lineal O(n) cada vez. Con miles de fechas, ineficiente
- **List**: No permite acceso indexado. No podemos usar binary search

#### ¿Por qué SÍ map?

| Característica | Beneficio |
|---|---|
| **Orden automático** | Las claves `std::string` (fechas YYYY-MM-DD) se ordenan lexicográficamente = **orden cronológico** |
| **Búsqueda O(log n)** | Mucho más rápida que búsqueda lineal |
| **`lower_bound()`** | Encuentra automáticamente la entrada más cercana **menor o igual** a la fecha buscada |
| **Sin duplicados** | Cada fecha aparece una sola vez |

#### Ejemplo práctico de `lower_bound()`:
```
Map contiene: 2011-01-03, 2011-01-09, 2012-01-11

Buscamos: 2011-01-05
lower_bound(2011-01-05) → devuelve iterator a 2011-01-09
Necesitamos el anterior → --iterator → 2011-01-03 ✓

Buscamos: 2011-01-03 (existe exacta)
lower_bound(2011-01-03) → devuelve iterator a 2011-01-03 ✓

Buscamos: 2010-12-25 (anterior a todas)
lower_bound(2010-12-25) → devuelve begin()
--iterator → undefined behavior X
Necesitamos chequear que no sea begin()
```

### 2. Estructura de Clases

**Separación de responsabilidades:**
- **BitcoinExchange**: Gestiona la base de datos (map) y búsquedas
- **BitcoinExchangeException**: Jerarquía de excepciones personalizada
- **main.cpp**: Orquesta carga de datos y procesamiento de entrada

### 3. Encapsulación

```cpp
std::map<std::string, float> _database;  // PRIVADO

// No exponemos el map directamente porque:
// 1. Evitamos modificaciones accidentales
// 2. Controlamos cómo se accede
// 3. Podemos cambiar implementación sin afectar código externo
```

### 4. Precisión de Números

```cpp
float  // Suficiente para precios históricos (hasta 2 decimales en general)
       // NO usamos double porque es C++98 y queremos eficiencia

// Si necesitáramos exactitud decimal (moneda):
// Usaríamos long double o multiplicar por 100 y usar long (centavos)
```

---

## EX00: Excepciones Específicas

### Jerarquía

Ver [Arquitectura Transversal de Excepciones](#-arquitectura-de-excepciones---transversal-a-todo-el-proyecto)

**Clases específicas de EX00:**
- `FileException` → "Error: could not open file."
- `DateException` → "Error: bad input => {date}"
- `ValueException` → "Error: not a positive number." o "Error: too large a number."
- `InvalidFormatException` → "Error: bad input => {línea}"

### Flujo de Lanzamiento en el Código

```cpp
// En loadDatabase()
if (!file.is_open())
    throw FileException("data.csv");

// En _isValidDate()
if (!isValidFormat || monthOutOfRange || dayOutOfRange)
    throw DateException(date);

// En _isValidValue()
if (value < 0)
    throw ValueException(value_str, "negative");
if (value > 1000)
    throw ValueException(value_str, "too_large");

// En processInput()
if (line.find(" | ") == std::string::npos)
    throw InvalidFormatException(line);
```

---

## EX00: Estructura del Proyecto

```
ex00/
├── BitcoinExchange.hpp
├── BitcoinExchange.cpp
├── BitcoinExchangeException.hpp
├── BitcoinExchangeException.cpp
├── main.cpp
├── data.csv                 ← CSV histórico (DEBE EXISTIR EXTERNAMENTE)
├── input.txt               ← Archivo entrada (ejemplo)
└── Makefile
```

### Archivos a Crear/Modificar

| Archivo | Responsabilidad |
|---------|-----------------|
| `BitcoinExchange.hpp` | Interfaz pública + macros debug |
| `BitcoinExchange.cpp` | Lógica de carga de datos y búsqueda |
| `BitcoinExchangeException.hpp` | Definición de excepciones |
| `BitcoinExchangeException.cpp` | Implementación de excepciones |
| `main.cpp` | Entry point, manejo de argumentos |
| `Makefile` | Compilación con flags y debug |

---

## EX00: Guía de Implementación

### Paso 1: Excepciones (`BitcoinExchangeException.hpp`)

```cpp
#ifndef BITCOINEXCHANGEEXCEPTION_HPP
#define BITCOINEXCHANGEEXCEPTION_HPP

#include <exception>
#include <string>

/* ===== BASE EXCEPTION ===== */
class BitcoinExchangeException : public std::exception
{
	protected:
		std::string_message;

	public:
		BitcoinExchangeException(const std::string& message);
		BitcoinExchangeException(const BitcoinExchangeException& other);
		BitcoinExchangeException&operator=(const BitcoinExchangeException& other);
		virtual ~BitcoinExchangeException(void) throw();

		virtual const char*what(void) const throw();
};

/* ===== DERIVED EXCEPTIONS ===== */

/// Lanzada cuando data.csv no puede abrirse
class FileException : public BitcoinExchangeException
{
	public:
		FileException(const std::string& filename);
		~FileException(void) throw();
};

/// Lanzada cuando la fecha tiene formato inválido
class DateException : public BitcoinExchangeException
{
	public:
		DateException(const std::string& date);
		~DateException(void) throw();
};

/// Lanzada cuando el valor es negativo o demasiado grande
class ValueException : public BitcoinExchangeException
{
	public:
		ValueException(const std::string& value, const std::string& reason);
		~ValueException(void) throw();
};

/// Lanzada cuando el formato de línea no es "date | value"
class InvalidFormatException : public BitcoinExchangeException
{
	public:
		InvalidFormatException(const std::string& line);
		~InvalidFormatException(void) throw();
};

#endif
```

**Explicaciones de cada excepción:**

1. **BitcoinExchangeException**
   - Base virtual para toda la jerarquía
   - `_message` protegido: subclases lo modifican antes de throw
   - `what()` virtual: polimorfismo para capturar por tipo
   - `throw()` vacío: promesa C++98 de no lanzar excepciones en dtor/what

2. **FileException**
   - Constructor recibe filename
   - Construye mensaje: "Error: could not open file."

3. **DateException**
   - Constructor recibe fecha inválida
   - Construye mensaje: "Error: bad input => {date}"

4. **ValueException**
   - Constructor recibe valor y razón (ej: "too negative", "too large")
   - Construye mensaje apropiado

5. **InvalidFormatException**
   - Para líneas que no cumplen formato "date | value"
   - Construye mensaje: "Error: bad input => {line}"

### Paso 2: Header Principal (`BitcoinExchange.hpp`)

```cpp
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

/* ===== DEBUG MODE ===== */
#ifndef DEBUG
# define DEBUG 0
#endif

#if DEBUG == 1
# define DEBUG_LOG(msg) do { std::cout << msg << std::endl; } while (0)
#else
# define DEBUG_LOG(msg) do {} while (0)
#endif

/* ===== ANSI COLOR CODES ===== */
#define RESET "\033[0m"
#define CONSTRUCTOR_COLOR "\033[36m"      /* Cyan */
#define DESTRUCTOR_COLOR "\033[35m"       /* Magenta */
#define ERROR_COLOR "\033[91m"            /* Bright Red */

#if DEBUG == 1
# define DEBUG_ERROR(msg) do { \
	std::cerr << ERROR_COLOR << msg << RESET << std::endl; } while (0)
#else
# define DEBUG_ERROR(msg) do {} while (0)
#endif

/* ===== MAIN CLASS ===== */
class BitcoinExchange
{
	private:
		std::map<std::string, float>_database;

		// Validation helpers
		col_isValidDate(const std::string& date) const;
		col_isValidValue(const std::string& value) const;
		float _parseFloat(const std::string& str) const;
		col_isNumber(const std::string& str) const;
		inte_parseInt(const std::string& str) const;

	public:
		// Orthodox Canonical Form
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&operator=(const BitcoinExchange& other);
		~BitcoinExchange(void);

		// Main API
		foldloadDatabase(const std::string& filename);
		foldprocessInput(const std::string& inputFile);

	private:
		float _getExchangeRate(const std::string& date) const;
};

#endif
```

**Explicación de métodos privados:**

| Método | Responsabilidad |
|--------|-----------------|
| `_isValidDate()` | Verifica formato YYYY-MM-DD y coherencia (mes 1-12, día 1-31) |
| `_isValidValue()` | Verifica que sea número, positivo y ≤ 1000 |
| `_parseFloat()` | Conversión segura string → float |
| `_isNumber()` | Detecta si string es número válido (entero o decimal) |
| `_parseInt()` | Extrae números para validar fecha |
| `_getExchangeRate()` | Búsqueda con lower_bound() |
| `processInput()` | Lee archivo entrada y procesa cada línea |
| `loadDatabase()` | Carga CSV en el map |

### Paso 3: Macros Debug

**Compilación Normal:**
```bash
make
# DEBUG=0, las macros NO generan código
```

**Compilación Debug:**
```bash
make debug
# DEBUG=1, mensajes con colores en stdout/stderr
```

**Uso en código:**

```cpp
// En constructor
DEBUG_LOG(CONSTRUCTOR_COLOR << "BitcoinExchange created" << RESET);

// En método de error
DEBUG_ERROR("Date validation failed for: " << date);

// Durante carga de datos
DEBUG_LOG("Loaded " << _database.size() << " entries");
```

---

## EX00: Validaciones Requeridas

### 1. Validación de Fecha

**Formato:** `YYYY-MM-DD`

```
✓ 2011-01-03
✓ 2012-12-31
✗ 2011-1-3         (faltan ceros)
✗ 2011/01/03       (separador incorrecto)
✗ 2001-42-42       (mes/día fuera de rango)
✗ 2011-13-01       (mes 13 inválido)
✗ 2011-02-30       (feb no tiene 30)
```

**Implementación:**
```cpp
bool BitcoinExchange::_isValidDate(const std::string& date) const
{
    // 1. Verificar longitud = 10
    // 2. Verificar formato YYYY-MM-DD
    //    - Posiciones 4 y 7 deben ser '-'
    //    - Resto deben ser dígitos
    // 3. Parsear año, mes, día
    // 4. Validar rangos:
    //    - Mes: 1-12
    //    - Día: según el mes (validar febrero)
    // 5. Retornar true/false
}
```

### 2. Validación de Valor

**Rango:** 0 ≤ valor ≤ 1000

```
✓ 0
✓ 0.5
✓ 1.2
✓ 1000
✗ -1             (negativo)
✗ 1000.1         (mayor que 1000)
✗ 2147483648     (entero gigante)
✗ "abc"          (no es número)
```

**Implementación:**
```cpp
bool BitcoinExchange::_isValidValue(const std::string& value) const
{
    // 1. Verificar que sea número (int o float)
    //    - Máximo un '.' 
    //    - Todos dígitos excepto el punto
    // 2. Parsear a float
    // 3. Verificar rango 0-1000
    // 4. Retornar true/false
    
    // IMPORTANTE: Detectar overflow en parseInt
    //    "2147483648" → INT_MAX = 2147483647
}
```

### 3. Formato de Línea

**Formato requerido:** `date | value`

```
✓ 2011-01-03 | 3
✓ 2011-01-03 | 0.5
✗ 2011-01-03 |3       (sin espacio después |)
✗ 2011-01-03|3        (sin espacios)
✗ 2011-01-03 3        (sin |)
✗ 2011-01-03 | 3 | 5  (extra pipe)
```

**Implementación:**
```cpp
// Parsear línea:
// 1. Buscar ' | ' (con espacios)
// 2. Si no existe → InvalidFormatException
// 3. Extraer parte izquierda = fecha
// 4. Extraer parte derecha = valor
// 5. Trim whitespace
// 6. Validar cada parte
```

### 4. Casos de Error

| Error | Mensaje Esperado | Condición |
|-------|-----------------|-----------|
| Valor negativo | `Error: not a positive number.` | value < 0 |
| Valor muy grande | `Error: too large a number.` | value > 1000 |
| Fecha inválida | `Error: bad input => {date}` | formato o rango incorrecto |
| Formato incorrecto | `Error: bad input => {línea}` | no es "date \| value" |
| CSV no existe | `Error: could not open file.` | data.csv no se puede abrir |

---

## EX00: Flujo de Ejecución

```
1. main(argc, argv)
   └─ Verificar argc == 2
   
2. try {
     BitcoinExchange btc;
     btc.loadDatabase("data.csv");  ← Carga CSV a map
     btc.processInput(argv[1]);     ← Procesa archivo entrada
   }

3. loadDatabase()
   └─ Abre data.csv
   └─ Para cada línea:
      ├─ Parsea "date,rate"
      ├─ Valida fecha
      ├─ Parsea float
      └─ _database[date] = rate

4. processInput(filename)
   └─ Abre archivo entrada
   └─ Lee línea 1: "date | value"  (encabezado, ignora)
   └─ Para cada línea:
      ├─ Parsea "date | value"
      ├─ Valida fecha → throw DateException
      ├─ Valida valor → throw ValueException
      ├─ Busca tasa con _getExchangeRate(date)
      ├─ Calcula resultado
      └─ Imprime stdout

5. catch (BitcoinExchangeException& e)
   └─ Imprime e.what() a stderr
   └─ Continúa siguiente línea
```

---

## EX00: Conceptos Demostrados

Este ejercicio cubre:

- ✅ **STL Containers**: `std::map` y sus operaciones
- ✅ **Algorithms**: `lower_bound()` para búsqueda eficiente
- ✅ **Excepciones Custom**: Jerarquía de herencia
- ✅ **File I/O**: Lectura de archivos CSV
- ✅ **String Parsing**: Tokenización y validación
- ✅ **Orthodox Canonical Form**: Correcto manejo de objetos
- ✅ **Encapsulation**: Métodos públicos vs privados
- ✅ **Debug Macros**: Condicionales de compilación
- ✅ **ANSI Colors**: Output mejorado en terminal

---

---

# Exercise 01: RPN

## EX01: Descripción del Problema

### Objetivo
Crear un programa `RPN` que:
1. Recibe una expresión en notación polaca inversa como argumento
2. Evalúa la expresión usando operadores: `+`, `-`, `*`, `/`
3. Imprime el resultado o mensaje de error

### Notación Polaca Inversa (RPN)

**Concepto**: Los operandos van antes que el operador

```
Notación Normal: 8 + 9 = 17
Notación RPN:   8 9 +  = 17

Notación Normal: (8 * 9) - 9 = 63
Notación RPN:   8 9 * 9 -  = 63

Notación Normal: ((8 * 9) - 9) - 9 - 9 - 4 + 1 = 42
Notación RPN:   8 9 * 9 - 9 - 9 - 4 - 1 + = 42
```

### Ejemplos de Uso

```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42

./RPN "7 7 * 7 -"
42

./RPN "1 2 * 2 / 2 * 2 4 - +"
0

./RPN "(1 + 1)"
Error

./RPN "1 2 +"
3
```

---

---

## EX01: Excepciones Específicas

### Jerarquía

Ver [Arquitectura Transversal de Excepciones](#-arquitectura-de-excepciones---transversal-a-todo-el-proyecto)

**Clases específicas de EX01:**
- `TokenException` → "Invalid token"
- `StackUnderflowException` → "Not enough operands for operation" 
- `DivisionByZeroException` → "Division by zero"
- `SyntaxException` → "Invalid expression syntax"
- `TooManyNumbersException` → "Error: too many numbers in the expression" (máximo 10 números válidos)

### Implementación

Mantener el mismo patrón de constructor, copia, asignación, destructor virtual y `what()`. Todas heredan de `RPN_Exception` que hereda de `std::exception`.

**Nota**: Cada excepción lanza un mensaje **personalizado y descriptivo** específico del problema. El usuario ve exactamente qué salió mal, no un "Error" genérico. El main() usa `e.what()` para mostrar el mensaje de la excepción.

---

### 1. Contenedor: `std::stack<int>`

#### ¿Por qué stack?

| Aspecto | Explicación |
|--------|-------------|
| **Naturaleza LIFO** | RPN es Last-In-First-Out por definición |
| **Operaciones O(1)** | Push y pop son instantáneos |
| **Interfaz simple** | Solo push, pop, top, empty - exacto lo que necesitamos |
| **No necesita búsqueda** | No requerimos acceso a elementos intermedios |

#### ¿Por qué NO usamos vector?

Aunque vector podría funcionar (push_back/pop_back simulan stack), **está prohibido en EX01**:
- EX00 ya usó `std::map`
- EX01 DEBE usar `std::stack`
- EX02 usará `std::deque` + otro contenedor

**Stack es la elección correcta:**
```cpp
std::stack<int> s;
s.push(5);        // O(1), push a la pila
int val = s.top(); // O(1), ve el tope
s.pop();          // O(1), elimina el tope
// Interfaz LIFO natural, semántica clara
```

### 2. Algoritmo RPN

**Pseudocódigo:**
```
stack = nueva pila vacía
contar_numeros = 0

para cada token en la expresión:
    si token es número:
        contar_numeros++
        si contar_numeros > 10:
            lanzar TooManyNumbersException
        stack.push(número)
    sino si token es operador:
        b = stack.pop()      # Segundo operando (tope)
        a = stack.pop()      # Primer operando (debajo)
        resultado = a OP b   # ORDEN CRÍTICO
        stack.push(resultado)
    sino:
        lanzar TokenException

si stack.size() != 1:
    lanzar SyntaxException
sino:
    retornar stack.top()
```

**Visualización paso a paso (ejemplo: "5 3 - 2 /"):**
```
Expresión: 5 3 - 2 /  (queremos: (5 - 3) / 2 = 1)

Token=5:    Stack: [5]
            Números: 1
Token=3:    Stack: [5, 3]
            Números: 2
Token=-:    Pop b=3, pop a=5
            Calcula: 5 - 3 = 2
            Stack: [2]
Token=2:    Stack: [2, 2]
            Números: 3
Token=/:    Pop b=2, pop a=2
            Calcula: 2 / 2 = 1
            Stack: [1]

Resultado: 1 ✓

**ORDEN CRÍTICO del pop:**
- Primero pop: segundo operando (tope actual)
- Segundo pop: primer operando (debajo)
- Operación: primer OP segundo

Si invertimos el orden obtenemos: 3 - 5 = -2 ✗
```

### 3. Restricciones del Módulo

**Contenedores permitidos:**
- ✅ `std::stack` (DEBE usarse en EX01)
- ❌ `std::map` (ya usada en EX00)
- ❌ `std::vector` (reservada para EX02)

**Números:**
- ✅ Números positivos sin límite de dígitos (pueden ser > 9)
- ❌ Máximo 10 números en la expresión
- ✅ Divisiones son enteras (5 / 2 = 2)

**Esta es la regla de oro del módulo:**
> "Una vez un contenedor es usado, no puede usarse para el resto del módulo"

---

## EX01: Arquitectura

### Excepciones Personalizadas

Similar a ex00, usaremos excepciones propias:

```cpp
class RPN_Exception : public std::exception { ... }

class TokenException : public RPN_Exception { ... }
class StackUnderflowException : public RPN_Exception { ... }
class DivisionByZeroException : public RPN_Exception { ... }
class SyntaxException : public RPN_Exception { ... }
```

### Estructura de Clases

```cpp
class RPN
{
    private:
        std::stack<int> _stack;
        
        // Struct para claridad en pop order
        struct Operands
        {
            int first;   // Primer operando (debajo en stack)
            int second;  // Segundo operando (tope)
        };
        
        // Helpers privados
        bool        _isOperator(const std::string& token) const;
        bool        _isNumber(const std::string& token) const;
        int         _parseNumber(const std::string& token) const;
        int         _calculate(int first, int second, char op) const;
        Operands    _popOperands(void);  // Devuelve operandos en orden correcto
        
    public:
        RPN(void);
        RPN(const RPN& other);
        RPN&        operator=(const RPN& other);
        ~RPN(void);
        
        // API principal
        void        validateExpression(const std::string& expression);
        int         processExpression(const std::string& expression);
};
```

### Validaciones Requeridas

| Validación | Ejemplo | Acción |
|-----------|---------|--------|
| Máximo 10 números | "1 2 3 4 5 6 7 8 9 10 +" | ✓ OK (10 números) |
| | "1 2 3 4 5 6 7 8 9 10 11 +" | ✗ "Error: too many numbers in the expression" |
| Números positivos | "5 3 -" | ✓ OK |
| | "-5 3 +" | ✗ "Invalid token" |
| Operadores válidos | "5 3 *" | ✓ OK |
| | "5 3 &" | ✗ "Invalid token" |
| Suficientes operandos | "5 3 +" | ✓ OK |
| | "5 +" | ✗ "Not enough operands for operation" |
| Stack final = 1 | "5 3 +" | ✓ OK (resultado 8) |
| | "5 3 + 2" | ✗ "Invalid expression syntax" |
| División por cero | "5 0 /" | ✗ "Division by zero" |
| Sin paréntesis | "(5+3)" | ✗ "Invalid token" |
| Sin decimales | "5.5 3 +" | ✗ "Invalid token" (el . es inválido) |

---

## EX01: Guía de Implementación

### Paso 1: Struct Operands para Claridad

```cpp
// En RPN.hpp - definición privada
private:
    struct Operands
    {
        int first;   // Primer operando (fue puesto en stack primero)
        int second;  // Segundo operando (fue puesto en stack segundo, está en tope)
    };
    
    Operands _popOperands(void)
    {
        if (_stack.size() < 2)
            throw StackUnderflowException("Not enough operands");
        
        Operands ops;
        ops.second = _stack.top(); _stack.pop();  // Tope = segundo operando
        ops.first = _stack.top();  _stack.pop();   // Debajo = primer operando
        
        DEBUG_LOG("Popped: " << ops.first << " and " << ops.second);
        
        return ops;
    }
```

### Paso 2: Validación de Expresión

```cpp
void RPN::validateExpression(const std::string &expression)
{
    if (expression.empty())
        throw SyntaxException("Empty expression.");
    
    std::stringstreamss(expression);
    std::stringtoken;

    while (ss >> token)
    {
        if (_isNumber(token))
        {
            int num = std::atoi(token.c_str());
            if (num < 0 || num > 9)
                throw InvalidRangeOfNumberException("Error: numbers must be between 0 and 9.");
        }
        else if (!_isOperator(token))
        {
            throw TokenException(token);
        }
    }
}
    
    DEBUG_LOG("Expression validated. " << numberCount << " numbers found");
}
```

### Paso 3: Procesamiento de Expresión

```cpp
int RPN::processExpression(const std::string& expression)
{
    validateExpression(expression);  // Primero validar
    
    // Limpiar stack previo
    while (!_stack.empty())
        _stack.pop();
    
    std::stringstream ss(expression);
    std::string token;
    
    // Procesar tokens en tiempo real
    while (ss >> token)
    {
        if (_isNumber(token))
        {
            _stack.push(_parseNumber(token));
            DEBUG_LOG("Pushed: " << token);
        }
        else if (_isOperator(token))
        {
            Operands ops = _popOperands();
            int result = _calculate(ops.first, ops.second, token[0]);
            _stack.push(result);
            DEBUG_LOG("Calculated: " << ops.first << " " << token << " " 
                  << ops.second << " = " << result);
        }
    }
    
    if (_stack.size() != 1)
        throw SyntaxException("Invalid expression");
    
    return _stack.top();
}
```

### Paso 4: Operación Aritmética

```cpp
int RPN::_calculate(int first, int second, char op) const
{
    switch (op)
    {
        case '+':
            return first + second;
        case '-':
            return first - second;  // first - second (no second - first)
        case '*':
            return first * second;
        case '/':
            if (second == 0)
                throw DivisionByZeroException("Division by zero");
            return first / second;   // División entera
        default:
            throw TokenException("Unknown operator");
    }
}
```

### Paso 5: Helpers para Validación

```cpp
bool RPN::_isNumber(const std::string& token) const
{
    if (token.empty())
        return false;
    
    // Verificar que todos los caracteres sean dígitos
    for (size_t i = 0; i < token.length(); ++i)
    {
        if (!std::isdigit(token[i]))
            return false;
    }
    return true;
}

bool RPN::_isOperator(const std::string& token) const
{
    return token.length() == 1 && 
           (token[0] == '+' || token[0] == '-' || 
            token[0] == '*' || token[0] == '/');
}

int RPN::_parseNumber(const std::string& token) const
{
    if (!_isNumber(token))
        throw TokenException("Invalid number");
    
    // Convertir string a int
    char* endptr;
    long value = std::strtol(token.c_str(), &endptr, 10);
    
    // Detectar overflow o negativos
    if (*endptr != '\0' || value < 0 || value > INT_MAX)
        throw TokenException("Invalid number");
    
    return static_cast<int>(value);
}
```

### Paso 6: main() Limpio con Manejo de Errores

```cpp
#include "RPN.hpp"
#include "RPN_Exception.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    try
    {
        // Validar argumentos
        if (argc != 2)
        {
            std::cerr << ERROR_COLOR << "Error: usage: [expression]" << RESET << std::endl;
            return 1;
        }
        
        // Procesar expresión RPN
        RPN calculator;
        int result = calculator.processExpression(argv[1]);
        
        // Salida a stdout
        std::cout << result << std::endl;
    }
    catch (const std::exception& e)
    {
        // Mostrar el mensaje personalizado de la excepción
        std::cerr << ERROR_COLOR << e.what() << RESET << std::endl;
        return 1;
    }
    
    return 0;
}
```

**¿Por qué un solo catch?**
- Todas nuestras excepciones heredan de `RPN_Exception` → `std::exception`
- El catch `const std::exception& e` atrapa toda la jerarquía
- Usuario ve "Error" simple
- Con `DEBUG=1`, vemos detalles con macro `DEBUG_ERROR()`

---

## EX01: Conceptos Demostrados

- ✅ **STL Stack**: estructura LIFO nativa, interfaz específica
- ✅ **Tokenización**: streaming directo sin vector
- ✅ **Operandos ordenados**: struct para claridad en pop order
- ✅ **Operaciones aritméticas**: cálculos respetando orden
- ✅ **Excepciones personalizadas**: múltiples tipos específicos
- ✅ **Validación previa**: separada del procesamiento
- ✅ **Algoritmos clásicos**: RPN fundamental en compiladores e intérpretes

---

---

# Exercise 02: PmergeMe

## EX02: Excepciones Específicas

### Jerarquía

Ver [Arquitectura Transversal de Excepciones](#-arquitectura-de-excepciones---transversal-a-todo-el-proyecto)

**Clases específicas de EX02:**
- `InputException` → "Error: Invalid input arguments"
- `NegativeNumberException` → "Error: Negative numbers not allowed"
- `InvalidSequenceException` → "Error: Empty or invalid sequence"

### Implementación

Mantener el mismo patrón base. En EX02, las excepciones se lanzan durante validación de argumentos en main().

---

## EX02: Descripción del Problema

### Objetivo
Crear un programa `PmergeMe` que:
1. Recibe una secuencia de números positivos como argumentos (mínimo 3000)
2. Ordena la secuencia usando el **Ford-Johnson Algorithm** (Merge-Insertion Sort en su forma COMPLETA)
3. Implementa el algoritmo con **DOS contenedores diferentes** (deque y vector)
4. Mide y compara el tiempo de ejecución con máxima precisión

### Limitaciones
- **Contenedores permitidos**: `std::deque` y `std::vector` (y sus helpers)
- **Debe implementar**: Ford-Johnson COMPLETO con números Jacobsthal
- **Debe soportar**: mínimo 3000 números
- **Timing**: máxima precisión posible en C++98

### Ejemplos de Uso

```bash
./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::deque: 0.00031 us
Time to process a range of 5 elements with std::vector: 0.00028 us

./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::deque: 62.14389 us
Time to process a range of 3000 elements with std::vector: 58.27212 us

./PmergeMe "-1" "2"
Error: Negative numbers not allowed
```

---

## EX02: Ford-Johnson Algorithm - Análisis Detallado

### Historia y Propósito Matemático

**Inventado**: L.R. Ford Jr. y Selmer M. Johnson (1959)

**Problema**: ¿Cuál es el número **mínimo teórico** de comparaciones para ordenar n elementos?

**Solución**: Ford-Johnson alcanza:
$$\text{Comparaciones} = n \lceil \log_2(3n/4) \rceil \approx n \log_2 n - 1.415n$$

**Resultado práctico**:
- Para n ≤ 22: **ÓPTIMO** (no hay algoritmo mejor)
- Para n > 22: Muy competitivo con quicksort/mergesort
- El factor ~1.415 es la clave (vs ~2.0 para algoritmos genéricos)

### Las Tres Fases

#### **Fase 1: Pairing - Agrupación en Pares**

**Objetivo**: Reducir el conjunto de búsqueda a la mitad.

```
Input: [8, 3, 7, 2, 5, 1, 9]

Paso 1: Agrupar en pares
(8,3), (7,2), (5,1), [9-impar]

Paso 2: Comparar cada par (guardando el más grande)
Comparación 1: 8 vs 3 → Mayor=8, Menor=3
Comparación 2: 7 vs 2 → Mayor=7, Menor=2
Comparación 3: 5 vs 1 → Mayor=5, Menor=1
Impar: 9 → Se trata separado

Resultado:
- Mayores (para ordenar recursivamente): [8, 7, 5, 9]
- Menores (para insertar luego): [3, 2, 1]
```

**Por qué funciona**: Cada comparación elimina un elemento de la recursión siguiente.

#### **Fase 2: Recursive Sorting - Ordenamiento Recursivo**

**Objetivo**: Ordenar recursivamente solo los elementos "mayores" usando Ford-Johnson nuevamente.

```
Entrada: [8, 7, 5, 9]

Aplicar Ford-Johnson recursivamente:
- Pairing: (8,7), (5,9)
- Comparar: Mayor=8, Mayor=9
- Recursión en [8, 9]: Ya están ordenados → [8, 9]
- Menores: [7, 5]
- Insertion: insertar 5 en [8, 9] → [5, 8, 9]
- Insertion: insertar 7 en [5, 8, 9] → [5, 7, 8, 9]

Resultado: [5, 7, 8, 9]
```

**Profundidad**: O(log n) llamadas recursivas.

#### **Fase 3: Insertion - Inserción Óptima (LA MAGIA)**

**Objetivo**: Insertar los elementos "menores" de forma que cada búsqueda binaria sea óptima.

**La clave**: Usar números de **Jacobsthal** para determinar el orden de inserción.

```
Entrada:
- Sorted: [5, 7, 8, 9]  (4 elementos ordenados)
- ToInsert: [3, 2, 1]   (3 elementos para insertar)

Naive (MAL): Insertar en orden [3, 2, 1]
- Insertar 3: search en [5,7,8,9] → posición 0 → [3,5,7,8,9]
- Insertar 2: search en [3,5,7,8,9] → posición 0 → [2,3,5,7,8,9]
- Insertar 1: search en [2,3,5,7,8,9] → posición 0 → [1,2,3,5,7,8,9]
Total: 3 binary searches, pero no óptimos

ÓPTIMO (CON JACOBSTHAL): Insertar en orden específico
- Génerar Jacobsthal: [0, 1, 1, 3, 5, 11, ...]
- Calcular gaps: [2, 2, 6, 10, 22, ...]
- Esto determina el orden de inserción para maximizar eficiencia
```

---

## EX02: Números de Jacobsthal - La Secuencia Mágica

### Definición Matemática

La **sucesión de Jacobsthal** se define recursivamente:

$$J(n) = \begin{cases} 
0 & \text{if } n = 0 \\
1 & \text{if } n = 1 \\
J(n-1) + 2 \cdot J(n-2) & \text{if } n \geq 2
\end{cases}$$

### Primeros 12 Términos

```
n:    0   1   1   3   5   11   21   43   85   171  341  683
J(n): 0   1   1   3   5   11   21   43   85   171  341  683
      ↑   ↑   ↑   ↑   ↑   ↑    ↑    ↑    ↑    ↑    ↑    ↑
      base1 base2
```

**Cálculo paso a paso**:
```
J(0) = 0
J(1) = 1
J(2) = J(1) + 2·J(0) = 1 + 2·0 = 1
J(3) = J(2) + 2·J(1) = 1 + 2·1 = 3
J(4) = J(3) + 2·J(2) = 3 + 2·1 = 5
J(5) = J(4) + 2·J(3) = 5 + 2·3 = 11
J(6) = J(5) + 2·J(4) = 11 + 2·5 = 21
J(7) = J(6) + 2·J(5) = 21 + 2·11 = 43
```

### ¿Por Qué en Ford-Johnson?

**El orden óptimo de inserción se basa en los GAPS (brechas) entre números Jacobsthal:**

$$\text{Gap}[i] = J(i+2) - J(i+1)$$

```
Gap[0] = J(2) - J(1) = 1 - 1 = 0    (no usar)
Gap[1] = J(3) - J(2) = 3 - 1 = 2
Gap[2] = J(4) - J(3) = 5 - 3 = 2
Gap[3] = J(5) - J(4) = 11 - 5 = 6
Gap[4] = J(6) - J(5) = 21 - 11 = 10
Gap[5] = J(7) - J(6) = 43 - 21 = 22
Gap[6] = J(8) - J(7) = 85 - 43 = 42
Skip gap=0, luego: 2, 2, 6, 10, 22, 42, ...
```

### Estrategia de Inserción con Gaps

```cpp
// Pseudocódigo de inserción óptima
std::vector<int> jacobsthal = generateJacobsthal(maxNeeded);
std::vector<int> gaps;
for (size_t i = 2; i < jacobsthal.size(); ++i)
    gaps.push_back(jacobsthal[i] - jacobsthal[i-1]);

// Insertar en orden de gaps
for (int gap : gaps) {
    // Insertar elementos en posiciones basadas en gap
    // Esto asegura que cada binary search sea O(log k) óptimo
}
```

**Propiedad crucial**: Los gaps garantizan que cada búsqueda binaria sea contra un rango de tamaño **2^m - 1** (uno menos que potencia de 2), maximizando comparaciones útiles.

---

## EX02: Elemento Impar - Análisis de Opciones

### Escenario
Si tenemos n=7 elementos: [8, 3, 7, 2, 5, 1, 9]

Pairing produce:
- Pares: (8,3), (7,2), (5,1)
- Impar: [9]

### Opción Elegida: Insertar al Final

**Decisión**: El elemento impar se trata como "pequeño sin pareja" y se inserta al final de la secuencia ordenada **sin binary search** (simple `push_back`).

```cpp
// Pairing
std::vector<int> mayores, menores;
for (size_t i = 0; i + 1 < input.size(); i += 2) {
    if (input[i] > input[i+1]) {
        mayores.push_back(input[i]);
        menores.push_back(input[i+1]);
    } else {
        mayores.push_back(input[i+1]);
        menores.push_back(input[i]);
    }
}

// Si hay impar
int impar = -1;
if (input.size() % 2 == 1) {
    impar = input.back();  // Guardar para después
}

// Después de ordenar mayores...
// Insertar menores con Jacobsthal...

// Al final: insertar impar
if (impar != -1)
    sorted.push_back(impar);
```

**Ventajas de esta opción**:
- ✅ Implementación simple
- ✅ Mantiene garantía de correctitud (el impar irá al final)
- ✅ No interfiere con calidad de comparaciones de Jacobsthal para otros elementos

**Desventaja**:
- ❌ Si el impar es muy grande, no está en posición óptima
- **Solución**: Es aceptable porque la ganancia de Ford-Johnson en los mayores compensa

---

## EX02: Timing - Máxima Precisión en C++98

### Estrategia

En C++98, **no hay `std::chrono`**. Las opciones son:

1. **`std::clock()`** - Portátil pero baja resolución
2. **`gettimeofday()`** - Mejor precisión pero no estándar
3. **`clock_t` manual** - Mejor balance

**Elegimos**: `clock()` con conversión cuidadosa a microsegundos.

### Implementación Óptima

```cpp
#include <ctime>
#include <iostream>
#include <iomanip>

int main() {
    // ...
    
    std::clock_t start = std::clock();
    
    pmergeMeDeque.sort(dataDeque);
    
    std::clock_t end = std::clock();
    
    // Convertir a microsegundos
    // CLOCKS_PER_SEC es ticks por segundo
    // Queremos microsegundos (10^-6 segundos)
    double elapsed_microseconds = double(end - start) / CLOCKS_PER_SEC * 1000000.0;
    
    std::cout << "Time to process a range of " << dataDeque.size() 
              << " elements with std::deque: " 
              << std::fixed << std::setprecision(5) 
              << elapsed_microseconds << " us" << std::endl;
    
    return 0;
}
```

### Consideraciones

**CLOCKS_PER_SEC** varía por SO:
- Linux: Generalmente 10^6 (muy preciso)
- Windows: Puede ser 10^3 (menos preciso)
- macOS: Puede ser 10^6

**Fórmula universal**:
```cpp
// Microsegundos
double us = double(end - start) / CLOCKS_PER_SEC * 1000000.0;

// Milisegundos (alternativa menos precisa)
double ms = double(end - start) / CLOCKS_PER_SEC * 1000.0;
```

**Best Practice**:
- Ejecutar múltiples veces y promediar para datasets pequeños
- Para datasets grandes (>1000 elementos), una ejecución es suficiente
- Usar `std::setprecision(5)` para mostrar 5 decimales de precisión

---

## EX02: Contenedores - Análisis Comparativo

### `std::deque` vs `std::vector`

| Aspecto | Deque | Vector |
|--------|-------|--------|
| **Acceso indexado** | O(1) | O(1) |
| **Inserción inicio** | O(1) amortizado | O(n) |
| **Inserción centro** | O(n) | O(n) |
| **Inserción final** | O(1) amortizado | O(1) amortizado |
| **Eliminación inicio** | O(1) amortizado | O(n) |
| **Memoria** | Bloques + punteros | Contiguo |
| **Cache locality** | Peor | Mejor |

### En Ford-Johnson

**Deque gana porque**:
- Las inserciones de Jacobsthal son en posiciones aleatorias → O(n) en ambos
- Pero deque no requiere realocación global
- Mejor para datasets grandes (>10k elementos)

**Vector potencialmente mejor porque**:
- Cache locality superior
- Menos overhead de memoria
- Para datasets pequeños (<1000) frecuentemente más rápido

**Conclusión**: Ambos son válidos. Deque teóricamente mejor, pero resultado depende de la máquina.

---

## EX02: Guía de Implementación Completa

### Paso 1: Template de Clase

```cpp
// PmergeMe.hpp
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>

template<typename Container>
class PmergeMe
{
    private:
        // Jacobsthal sequence generator
        std::vector<int> _generateJacobsthal(int max_value);
        
        // Ford-Johnson phases
        void _pairingPhase(Container& input, 
                          Container& larger, 
                          Container& smaller, 
                          int& oddElement);
        
        void _recursiveSort(Container& larger);
        
        void _insertionPhaseOptimal(Container& sorted, 
                                   const Container& smaller, 
                                   int oddElement);
        
        // Helpers
        void _mergeInsert(Container& container);
        int _binarySearch(const Container& sorted, int element);
        
    public:
        PmergeMe(void);
        ~PmergeMe(void);
        
        // Main API
        void sort(Container& data);
};

#endif
```

### Paso 2: Generar Números de Jacobsthal

```cpp
template<typename Container>
std::vector<int> PmergeMe<Container>::_generateJacobsthal(int max_value)
{
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    // Generar hasta que excedamos max_value
    while (jacobsthal.back() < max_value)
    {
        int size = jacobsthal.size();
        int next = jacobsthal[size - 1] + 2 * jacobsthal[size - 2];
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}
```

### Paso 3: Pairing Phase (Fase 1)

```cpp
template<typename Container>
void PmergeMe<Container>::_pairingPhase(Container& input, 
                                        Container& larger, 
                                        Container& smaller, 
                                        int& oddElement)
{
    oddElement = -1;
    
    // Iterar en pares
    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        // Comparar par
        if (input[i] > input[i + 1])
        {
            larger.push_back(input[i]);
            smaller.push_back(input[i + 1]);
        }
        else
        {
            larger.push_back(input[i + 1]);
            smaller.push_back(input[i]);
        }
    }
    
    // Guardar elemento impar si existe
    if (input.size() % 2 == 1)
        oddElement = input.back();
}
```

### Paso 4: Recursive Sort (Fase 2)

```cpp
template<typename Container>
void PmergeMe<Container>::_recursiveSort(Container& larger)
{
    // Base case
    if (larger.size() <= 1)
        return;
    
    if (larger.size() == 2)
    {
        if (larger[0] > larger[1])
            std::swap(larger[0], larger[1]);
        return;
    }
    
    // Aplicar Ford-Johnson recursivamente
    Container newLarger, newSmaller;
    int oddElem = -1;
    
    _pairingPhase(larger, newLarger, newSmaller, oddElem);
    _recursiveSort(newLarger);
    _insertionPhaseOptimal(newLarger, newSmaller, oddElem);
    
    // Copiar resultado ordenado de vuelta
    larger.clear();
    for (size_t i = 0; i < newLarger.size(); ++i)
        larger.push_back(newLarger[i]);
}
```

### Paso 5: Insertion Phase con Jacobsthal (Fase 3) - LA MAGIA

```cpp
template<typename Container>
void PmergeMe<Container>::_insertionPhaseOptimal(Container& sorted, 
                                                 const Container& smaller, 
                                                 int oddElement)
{
    // Generar Jacobsthal para número de elementos a insertar
    std::vector<int> jacobsthal = _generateJacobsthal(smaller.size());
    
    // Calcular gaps
    std::vector<int> gaps;
    for (size_t i = 2; i < jacobsthal.size(); ++i)
    {
        int gap = jacobsthal[i] - jacobsthal[i - 1];
        if (gap > 0 && gap <= (int)smaller.size())
            gaps.push_back(gap);
    }
    
    // Insertar menores usando gaps de Jacobsthal
    std::vector<bool> inserted(smaller.size(), false);
    
    for (size_t g = 0; g < gaps.size(); ++g)
    {
        int gap = gaps[g];
        
        for (int j = gap; j > 0 && j <= (int)smaller.size(); --j)
        {
            if (!inserted[j - 1])
            {
                // Binary search en sorted[0..j]
                typename Container::iterator it = 
                    std::lower_bound(sorted.begin(), 
                                   sorted.begin() + std::min((int)sorted.size(), j + 1),
                                   smaller[j - 1]);
                sorted.insert(it, smaller[j - 1]);
                inserted[j - 1] = true;
            }
        }
    }
    
    // Elementos no insertados (fallback simple)
    for (size_t i = 0; i < smaller.size(); ++i)
    {
        if (!inserted[i])
        {
            typename Container::iterator it = 
                std::lower_bound(sorted.begin(), sorted.end(), smaller[i]);
            sorted.insert(it, smaller[i]);
        }
    }
    
    // Insertar elemento impar al final (simple)
    if (oddElement != -1)
        sorted.push_back(oddElement);
}
```

### Paso 6: API Principal

```cpp
template<typename Container>
void PmergeMe<Container>::sort(Container& data)
{
    if (data.size() <= 1)
        return;
    
    Container larger, smaller;
    int oddElement = -1;
    
    // Fase 1: Pairing
    _pairingPhase(data, larger, smaller, oddElement);
    
    // Fase 2: Recursive sort
    _recursiveSort(larger);
    
    // Fase 3: Insertion with Jacobsthal
    _insertionPhaseOptimal(larger, smaller, oddElement);
    
    // Copiar resultado ordenado de vuelta a data
    data.clear();
    for (size_t i = 0; i < larger.size(); ++i)
        data.push_back(larger[i]);
}
```

### Paso 7: Main con Timing Preciso

```cpp
#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>

int main(int argc, char **argv)
{
    try
    {
        // Validar argumentos
        if (argc < 2)
        {
            std::cerr << "Error: Invalid input arguments" << std::endl;
            return 1;
        }
        
        // Leer datos
        std::deque<int> dataDeque;
        std::vector<int> dataVector;
        
        for (int i = 1; i < argc; ++i)
        {
            long value = std::strtol(argv[i], NULL, 10);
            
            if (value < 0)
            {
                std::cerr << "Error: Negative numbers not allowed" << std::endl;
                return 1;
            }
            
            dataDeque.push_back(static_cast<int>(value));
            dataVector.push_back(static_cast<int>(value));
        }
        
        // Mostrar entrada
        std::cout << "Before: ";
        for (size_t i = 0; i < dataDeque.size(); ++i)
            std::cout << dataDeque[i] << " ";
        std::cout << std::endl;
        
        // Ordenar con deque
        std::clock_t start_deque = std::clock();
        PmergeMe<std::deque<int> > pmergeDeque;
        pmergeDeque.sort(dataDeque);
        std::clock_t end_deque = std::clock();
        
        // Ordenar con vector
        std::clock_t start_vector = std::clock();
        PmergeMe<std::vector<int> > pmergeVector;
        pmergeVector.sort(dataVector);
        std::clock_t end_vector = std::clock();
        
        // Mostrar salida
        std::cout << "After: ";
        for (size_t i = 0; i < dataDeque.size(); ++i)
            std::cout << dataDeque[i] << " ";
        std::cout << std::endl;
        
        // Mostrar timing (máxima precisión)
        double time_deque = double(end_deque - start_deque) / CLOCKS_PER_SEC * 1000000.0;
        double time_vector = double(end_vector - start_vector) / CLOCKS_PER_SEC * 1000000.0;
        
        std::cout << "Time to process a range of " << dataDeque.size()
                  << " elements with std::deque: "
                  << std::fixed << std::setprecision(5) << time_deque << " us" << std::endl;
        
        std::cout << "Time to process a range of " << dataVector.size()
                  << " elements with std::vector: "
                  << std::fixed << std::setprecision(5) << time_vector << " us" << std::endl;
        
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
```

---

## EX02: Conceptos Demostrados

- ✅ **Ford-Johnson Algorithm Completo**: Las 3 fases (pairing, recursive sort, insertion)
- ✅ **Números de Jacobsthal**: Secuencia matemática para optimizar inserción binaria
- ✅ **Templates en C++98**: Genéricos con múltiples contenedores
- ✅ **Timing preciso**: Conversión de clock() a microsegundos
- ✅ **Binary search optimizado**: Con rangos de tamaño 2^n - 1
- ✅ **Análisis de complejidad**: Explicación matemática de por qué funciona
- ✅ **Múltiples contenedores**: Comparación deque vs vector en práctica real

---

## 🎓 Notas Generales

### C++98 Compatibility
```cpp
// ✓ Usar
std::map, std::vector, std::deque, std::list, std::stack, std::set
std::sort, std::lower_bound, std::upper_bound
std::string, std::stringstream

// ✗ NO usar
auto, lambdas, nullptr, std::stoi, std::stof
RangeFor, std::to_string
```

### Memory Management
Todos los contenedores STL manejan memoria automáticamente.
No hay necesidad de new/delete.
Los destructores se llaman automáticamente.

### Performance Tips

1. **Reserve space when possible**:
   ```cpp
   vector.reserve(1000);  // Evita realocaciones
   ```

2. **Use references in loops**:
   ```cpp
   for (const std::string& s : container)  // No copia
   ```

3. **Choose right container**:
   - Vector: índice frecuente
   - List: inserción/eliminación frecuente
   - Deque: inserción en extremos
   - Map: búsqueda por clave

---

## 📝 Resumen de Restricciones

```
MÓDULO CPP09 - REGLA DE ORO
╔════════════════════════════════════════════════════════════╗
║ Cada contenedor STL se PUEDE usar UNA SOLA VEZ             ║
║                                                            ║
║ EX00: std::map  ✓                                          ║
║ EX01: std::stack ✓                                         ║
║ EX02: std::deque + std::list (ó vector/set) ✓              ║
║                                                            ║
║ Después de EX00: map PROHIBIDO en EX01 y EX02              ║
║ Después de EX01: stack PROHIBIDO en EX02                   ║
║ Después de EX02: vector/deque (fin módulo)    ex00     ║
╚════════════════════════════════════════════════════════════╝
```

---

**Fin de la Guía CPP09 Completa**

Última actualización: Abril 10, 2026
