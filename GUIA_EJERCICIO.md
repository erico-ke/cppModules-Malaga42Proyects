# Guía para completar el Ejercicio 01: I don't want to set the world on fire

## 📋 Resumen del Ejercicio

Este ejercicio extiende el anterior añadiendo el concepto de **composición** y **gestión de memoria dinámica**. Los animales (Dog y Cat) ahora tendrán un "cerebro" (Brain) que debe ser gestionado correctamente para evitar memory leaks y shallow copies.

---

## 🎯 Objetivos Principales

1. ✅ Crear una clase `Brain` con 100 ideas
2. ✅ Añadir un atributo `Brain*` a Dog y Cat
3. ✅ Gestionar la memoria dinámica correctamente
4. ✅ Implementar deep copy (copia profunda)
5. ✅ Probar que no hay memory leaks
6. ✅ Crear un array de Animals (mitad Dogs, mitad Cats)

---

## 📝 Pasos Detallados

### **PASO 1: Implementar la clase Brain**

**Archivo:** `includes/Brain.hpp` y `src/Brain.cpp`

#### En Brain.hpp:
- [ ] Declarar un array privado: `std::string ideas[100];`
- [ ] Declarar constructor por defecto
- [ ] Declarar copy constructor: `Brain(const Brain& other);`
- [ ] Declarar copy assignment operator: `Brain& operator=(const Brain& other);`
- [ ] Declarar destructor
- [ ] (Opcional) Añadir getters/setters para acceder a ideas

#### En Brain.cpp:
- [ ] **Constructor:** Imprimir mensaje como "Brain constructor called"
- [ ] **Copy constructor:** 
  - Imprimir mensaje
  - Copiar TODAS las ideas del array (deep copy)
  - Usar un loop: `for (int i = 0; i < 100; i++) this->ideas[i] = other.ideas[i];`
- [ ] **Copy assignment operator:**
  - Imprimir mensaje
  - Verificar self-assignment: `if (this != &other)`
  - Copiar todas las ideas
  - Retornar `*this`
- [ ] **Destructor:** Imprimir mensaje como "Brain destructor called"

---

### **PASO 2: Modificar la clase Dog**

**Archivos:** `includes/Dog.hpp` y `src/Dog.cpp`

#### En Dog.hpp:
- [ ] Añadir atributo privado: `Brain* brain;`

#### En Dog.cpp:
- [ ] **Constructor:**
  - Llamar al constructor base (Animal)
  - Crear el Brain: `this->brain = new Brain();`
  - Imprimir mensaje de construcción del Dog
  
- [ ] **Copy constructor:**
  - Llamar al copy constructor base
  - Crear un NUEVO Brain: `this->brain = new Brain(*other.brain);`
  - Esto asegura deep copy
  
- [ ] **Copy assignment operator:**
  - Verificar self-assignment
  - Llamar al assignment del padre
  - Eliminar el Brain actual si existe
  - Crear un nuevo Brain copiando el del other
  - Retornar `*this`
  
- [ ] **Destructor:**
  - Imprimir mensaje de destrucción del Dog
  - IMPORTANTE: `delete this->brain;` (liberar memoria)

---

### **PASO 3: Modificar la clase Cat**

**Archivos:** `includes/Cat.hpp` y `src/Cat.cpp`

- [ ] Hacer exactamente lo mismo que en Dog (pasos idénticos)
- [ ] Añadir `Brain* brain;` como atributo privado
- [ ] Implementar constructor, copy constructor, copy assignment, destructor
- [ ] Crear/destruir el Brain con new/delete
- [ ] Asegurar deep copy en el copy constructor

---

### **PASO 4: Verificar que Animal tiene destructor virtual**

**Archivo:** `includes/Animal.hpp`

- [ ] Verificar que el destructor está declarado como `virtual ~Animal();`
- [ ] Esto es CRÍTICO para que se llamen los destructores correctos cuando se elimine un Animal*

---

### **PASO 5: Actualizar el Makefile**

**Archivo:** `Makefile`

- [ ] Añadir `./src/Brain.cpp` a la lista de archivos SRC
- [ ] Verificar que el nombre del ejecutable sea apropiado
- [ ] El Makefile debería verse así:
```makefile
SRC = main.cpp ./src/Animal.cpp ./src/Cat.cpp ./src/Dog.cpp \
      ./src/WrongAnimal.cpp ./src/WrongCat.cpp ./src/Brain.cpp
```

---

### **PASO 6: Implementar main.cpp con tests completos**

**Archivo:** `main.cpp`

Debes implementar varios tests:

#### Test 1: Basic test del subject
```cpp
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j; // should not create a leak
delete i;
```

#### Test 2: Array de Animals (requisito del ejercicio)
```cpp
// Crear array de 10 Animals (5 Dogs, 5 Cats)
Animal* animals[10];
for (int i = 0; i < 5; i++)
    animals[i] = new Dog();
for (int i = 5; i < 10; i++)
    animals[i] = new Cat();

// Eliminar todos como Animals
for (int i = 0; i < 10; i++)
    delete animals[i];
```

#### Test 3: Deep copy test (muy importante)
```cpp
// Test con Dog
Dog* original = new Dog();
// Modificar algunas ideas del Brain original
Dog* copy = new Dog(*original); // Copy constructor
// Verificar que son diferentes objetos
// Modificar ideas de la copia
// Verificar que el original no cambió (deep copy)
delete original;
delete copy;

// Repetir con Cat
```

#### Test 4: Assignment operator test
```cpp
Dog dog1;
Dog dog2;
dog2 = dog1; // Debe hacer deep copy
```

---

## 🔍 Puntos Críticos a Verificar

### Memory Management
- [ ] Cada `new` tiene su correspondiente `delete`
- [ ] El destructor de Animal debe ser `virtual`
- [ ] Dog y Cat eliminan su Brain en el destructor
- [ ] No hay double-delete ni dangling pointers

### Deep Copy
- [ ] El copy constructor de Brain copia todo el array
- [ ] El copy constructor de Dog/Cat crea un NUEVO Brain
- [ ] Después de copiar, modificar uno no afecta al otro
- [ ] El copy assignment operator también hace deep copy

### Orden de Construcción/Destrucción
```
Constructor order:
1. Animal constructor
2. Dog/Cat constructor
3. Brain constructor

Destructor order (inverso):
1. Dog/Cat destructor
2. Brain destructor (delete brain)
3. Animal destructor
```

---

## 🧪 Testing y Validación

### Compilar
```bash
make
```

### Ejecutar
```bash
./Polymorphism
```

### Verificar memory leaks con Valgrind
```bash
valgrind --leak-check=full ./Polymorphism
```

Debes ver:
- **"All heap blocks were freed -- no leaks are possible"**
- Todos los constructores y destructores llamados en orden correcto

---

## 📊 Checklist Final

- [ ] Brain.hpp y Brain.cpp implementados con array de 100 strings
- [ ] Dog tiene Brain* y lo gestiona correctamente
- [ ] Cat tiene Brain* y lo gestiona correctamente
- [ ] Destructores virtuales en Animal
- [ ] Deep copy implementado (copy constructor y assignment)
- [ ] main.cpp con múltiples tests (incluido array de Animals)
- [ ] Makefile actualizado con Brain.cpp
- [ ] Compila sin warnings con -Wall -Wextra -Werror
- [ ] Valgrind confirma 0 memory leaks
- [ ] Los mensajes de constructores/destructores se muestran correctamente

---

## 💡 Tips Importantes

1. **Self-assignment**: En el copy assignment operator, siempre verificar `if (this != &other)`

2. **Deep copy en Brain**: El loop debe copiar las 100 strings:
   ```cpp
   for (int i = 0; i < 100; i++)
       this->ideas[i] = other.ideas[i];
   ```

3. **Deep copy en Dog/Cat**: Crear un NUEVO Brain:
   ```cpp
   this->brain = new Brain(*other.brain);
   // NO hacer: this->brain = other.brain; (shallow copy!)
   ```

4. **Destructor virtual**: Sin él, solo se llamaría el destructor de Animal y habría leaks

5. **Test de deep copy**: Modifica las ideas después de copiar y verifica que el original no cambia

---

## ❓ Preguntas para Autoevaluación

1. ¿Por qué necesitamos un copy constructor personalizado para Dog y Cat?
2. ¿Qué pasaría si no tuviéramos el destructor virtual en Animal?
3. ¿Cuál es la diferencia entre shallow copy y deep copy?
4. ¿Por qué usamos `Brain*` en lugar de `Brain` como atributo?
5. ¿Qué pasa si olvidamos `delete brain` en el destructor?

---

## 🎓 Conceptos Clave

- **Composición**: Dog/Cat "tiene un" Brain
- **Gestión de memoria dinámica**: new/delete
- **Deep copy vs Shallow copy**: Copiar el contenido vs copiar el puntero
- **Virtual destructor**: Polimorfismo en destructores
- **Rule of Three**: Si necesitas uno de (destructor, copy constructor, copy assignment), probablemente necesitas los tres

---

¡Buena suerte! 🚀
