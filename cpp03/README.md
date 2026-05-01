# cpp03

Énfasis en gestión de recursos y prácticas RAII: copias profundas y sobrecarga de operadores.

Proyectos destacados

- Ejercicios prácticos para aplicar Rule of Three/Five: diseñar clases que gestionan memoria o recursos (archivos, buffers).

Objetivos de aprendizaje

- Implementar correctamente constructores copia, operadores de asignación y destructores.
- Evitar aliasing y fugas implementando copias profundas cuando proceda.

Cómo compilar y ejecutar

```bash
cd cpp03/ex00
make
./ex00
```

Notas

- Herramientas útiles: `valgrind`, `gdb` para depuración y comprobación de leaks.

Makefile (objetivos comunes)

- Objetivos típicos: `all`, `clean`, `fclean`, `re` y a veces `debug`.

Ejemplos de uso

- `ex00` (clapTrap):
	```bash
	cd cpp03/ex00
	make
	./clapTrap
	```
- `ex01` (ScavTrap):
	```bash
	cd cpp03/ex01
	make
	./ScavTrap
	```
- `ex02` (FragTrap):
	```bash
	cd cpp03/ex02
	make
	./FragTrap
	```
- `ex03` (DiamondTrap):
	```bash
	cd cpp03/ex03
	make
	./DiamondTrap
	```
