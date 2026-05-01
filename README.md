# cppModules-Malaga42Proyects

Colección de ejercicios y pequeños proyectos en C++ realizados durante la formación de la escuela 42 (piscine / módulos de C++). Cada carpeta `cppNN` contiene varios ejercicios (`ex00`, `ex01`, ...) con su propio `Makefile`, código fuente y pruebas cuando aplican.

**Resumen por carpetas**

- **Navegación por carpetas**: accede a los README específicos para cada módulo:

- [cpp00](cpp00/README.md)
- [cpp01](cpp01/README.md)
- [cpp02](cpp02/README.md)
- [cpp03](cpp03/README.md)
- [cpp04](cpp04/README.md)
- [cpp05](cpp05/README.md)
- [cpp06](cpp06/README.md)
- [cpp07](cpp07/README.md)
- [cpp08](cpp08/README.md)
- [cpp09](cpp09/README.md)

Revisa cada subcarpeta `cppNN/exYY` para ver el enunciado, el código fuente y tests o ficheros de datos incluidos.

Prerequisitos

- Un compilador `g++` moderno instalado (soporte para los estándares usados en cada ejercicio; muchos ejercicios usan `-std=c++98` o compatible). 
- `make` para usar los `Makefile` incluidos.

Cómo descargar

1. Clona el repositorio (sustituye `<repo-url>` por la URL real):

```bash
git clone <repo-url>
cd cppModules-Malaga42Proyects
```

Cómo compilar y ejecutar

- La mayoría de los ejercicios tienen su propio `Makefile`. Compila y ejecuta desde la carpeta del ejercicio:

```bash
cd cpp07/ex02
make
# Ejecuta el binario generado (revisa el Makefile para el nombre exacto)
./ex02
```

- Si prefieres compilar un solo fichero manualmente:

```bash
g++ -Wall -Wextra -Werror -std=c++98 -o programa fichero.cpp
./programa
```

Notas sobre ejecución

- Algunos ejercicios incluyen ficheros de datos o tests (por ejemplo `cpp09/ex00` tiene `data.csv` y ficheros de prueba). Lee el `README` o los comentarios dentro de cada `exYY` para instrucciones específicas sobre entradas y formatos.
- Si el `Makefile` genera un binario con nombre distinto, usa `ls` para localizarlo o abre el `Makefile` para ver la variable `NAME` o la regla `all`.

Estructura recomendada de trabajo

- Trabaja por carpetas: abre `cppNN/exYY`, lee el enunciado (si está) y usa `make`.
- Para depurar, compila con menos optimizaciones o añade prints temporales.

Créditos

- Proyectos y ejercicios basados en los ejercicios de la escuela 42. Código y estructura usados como material de práctica.

