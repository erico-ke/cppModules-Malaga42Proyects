# cpp07

Ejercicios de templates y programación genérica en C++.

Proyectos destacados

- `iter.hpp`: plantilla para aplicar una función a cada elemento de un array (práctica de funciones plantilla y punteros a funciones).
- `Array.hpp`/`Array.tpp`: implementación de un contenedor de tamaño fijo parametrizado por tipo; manejo de excepciones y sobrecarga de `operator[]`.

Objetivos de aprendizaje

- Entender la sintaxis y semántica de templates en C++.
- Implementar contenedores genéricos y manejar errores mediante excepciones.

Cómo compilar

```bash
cd cpp07/ex02
make
./ex02
```

Notas

- Comprueba la implementación en `Array.tpp` para ver uso de plantillas y especializaciones.

Makefile (objetivos comunes)

- Los `Makefile` suelen definir `all`, `clean`, `fclean` y `re`.



`make debug` (nota)

- `make debug` compila con `DEBUG=1` (si el `Makefile` lo soporta) activando comprobaciones internas.

Ejemplos de uso

- `ex00` (whateverItTakes):
  ```bash
  cd cpp07/ex00
  make
  ./whateverItTakes
  ```
- `ex01` (iter):
  ```bash
  cd cpp07/ex01
  make
  ./iter
  ```
- `ex02` (Array):
  ```bash
  cd cpp07/ex02
  make
  ./Array
  ```