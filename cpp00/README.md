# cpp00

Ejercicios de introducción a C++: conceptos básicos de entrada/salida, manipulación de cadenas y programación procedural.

Proyectos destacados

- `ex00` (`megaphone`): programa simple que transforma argumentos de línea de comandos (uso de `argv`, manejo básico de strings y salida por consola).
- `ex01` (`Phonebook`/`Contact`): implementación de una agenda sencilla con estructura `Contact`; práctica de arrays, clases simples y validación de entrada.
- `ex02` (`Account`): ejercicio sobre estado interno de un objeto y funciones estáticas para seguimiento global (balance, operaciones).

Objetivos de aprendizaje

- Entender manejo básico de I/O y argumentos de programa.
- Practicar estructuras simples y clases triviales.
- Familiarizarse con `Makefile` y flujo de compilación.

Cómo compilar y ejecutar

```bash
cd cpp00/ex00
make
./ex00
```

Notas

- Los ejercicios suelen compilar con `-std=c++98` o similar; revisa el `Makefile` de cada `exYY`.
- Lee los comentarios en los ficheros fuente para entender los requisitos de entrada y salida.

Makefile (objetivos comunes)

- Los `Makefile` de estos ejercicios suelen incluir objetivos: `all` (compila el binario), `clean` (borra objetos), `fclean` (borra binario y objetos) y `re` (fclean + all).
Ejemplos de uso

- `ex00` (megaphone):
	```bash
	cd cpp00/ex00
	make
	./megaphone
	```
- `ex01` (phonebook):
	```bash
	cd cpp00/ex01
	make
	./phonebook
	```
- `ex02` (accounts):
	```bash
	cd cpp00/ex02
	make
	./accounts
	```
