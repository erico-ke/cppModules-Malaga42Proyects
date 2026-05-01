# cpp08

Contenedores y algoritmos: prácticas sobre estructuras y algoritmos personalizados y su uso con STL.

Proyectos destacados

- `easyfind.hpp`: función plantilla para buscar un valor en contenedores compatibles con iteradores.
- `Span` y `MutantStack`: implementación de estructuras personalizadas y adaptación sobre contenedores STL.

Objetivos de aprendizaje

- Usar iteradores y algoritmos disponibles en STL junto con implementaciones propias.
- Diseñar estructuras que interactúen bien con las utilidades estándar.

Cómo compilar

```bash
cd cpp08/ex00
make
./ex00
```

Notas

- Revisa los tests o `main.cpp` incluidos para ver casos de uso y ejemplos concretos.

Makefile (objetivos comunes)

- Objetivos comunes: `all` (compila), `clean`, `fclean` y `re`.



`make debug` (nota)

- `make debug` activa `DEBUG=1` y recompila, mostrando verificaciones o logs extras implementados en el código.

Ejemplos de uso

- `ex00` (easyfind):
  ```bash
  cd cpp08/ex00
  make
  ./easyfind
  ```
- `ex01` (Span):
  ```bash
  cd cpp08/ex01
  make
  ./Span
  ```
- `ex02` (MutantStack):
  ```bash
  cd cpp08/ex02
  make
  ./MutantStack
  ```