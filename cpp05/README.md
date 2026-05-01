# cpp05

Prácticas avanzadas de gestión de memoria y seguridad del programa.

Proyectos destacados

- Ejercicios que obligan a pensar en ownership y límites de vida de objetos, evitando UB y fugas.

Objetivos de aprendizaje

- Aplicar técnicas para prevenir fugas y condiciones de carrera (donde aplique).
- Escribir código robusto y defensivo.

Cómo compilar y ejecutar

```bash
cd cpp05/ex00
make
./ex00
```

Notas

- Comprueba las flags del `Makefile` (warnings activos: `-Wall -Wextra -Werror`).

Makefile (objetivos comunes)

- Objetivos frecuentes: `all`, `clean`, `fclean` y `re`.



`make debug` (nota)

- `make debug` (disponible en los `Makefile` de estos ejercicios) compila con `DEBUG=1` y recompila desde cero (`re`). Sirve para activar mensajes o comprobaciones adicionales incluidas en el código.

Ejemplos de uso

- `ex00` (bureaucrat):
  ```bash
  cd cpp05/ex00
  make
  ./bureaucrat
  ```
- `ex01` (bureaucratForm):
  ```bash
  cd cpp05/ex01
  make
  ./bureaucratForm
  ```
- `ex02` (VariousForms):
  ```bash
  cd cpp05/ex02
  make
  ./VariousForms
  ```
- `ex03` (interExploit):
  ```bash
  cd cpp05/ex03
  make
  ./interExploit
  ```