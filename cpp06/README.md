# cpp06

Temas avanzados de OOP y utilidades auxiliares que preparan para ejercicios con templates y estructuras más complejas.

Proyectos y objetivos

- Ejercicios con helpers reutilizables y utilidades que suelen utilizarse en ejercicios posteriores.
- Refuerza principios SOLID básicos aplicados a código simple.

Cómo compilar

```bash
cd cpp06/ex00
make
./ex00
```

Notas

- Ideal para preparar ejercicios de templates y containers en `cpp07`/`cpp08`.

Makefile (objetivos comunes)

- Revisa el `Makefile` de cada ejercicio: normalmente incluye `all`, `clean`, `fclean` y `re`.


`make debug` (nota)

- `make debug` establece `DEBUG=1` y recompila; útil para activar logs/chequeos adicionales del código.

Ejemplos de uso

- `ex00` (convert):
  ```bash
  cd cpp06/ex00
  make
  ./convert 42
  ```
- `ex01` (serializer):
  ```bash
  cd cpp06/ex01
  make
  ./serializer
  ```
- `ex02` (identify):
  ```bash
  cd cpp06/ex02
  make
  ./identify
  ```