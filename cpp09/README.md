# cpp09

Proyectos más completos y prácticos que implican parsing, validación y algoritmos eficientes.

Proyectos destacados

- `ex00` (`BitcoinExchange`): implementa un parser/validador para datos CSV de precios; incluye `data.csv` y ficheros de prueba para validar casos límite y errores de entrada.
- `ex01` (`RPN`): calculadora en notación polaca inversa; práctica de parsing de tokens y manejo de errores en cálculos.
- `ex02` (`PmergeMe`): ejercicio sobre técnicas eficientes de ordenación/mezcla, pensando en complejidad y optimización.

Cómo compilar y ejecutar

```bash
cd cpp09/ex00
make
./ex00 data.csv input.csv
```

Notas

- Revisa los ficheros `test_*.txt` para ver casos de prueba incluidos.
- Estos proyectos suelen requerir un manejo robusto de errores y validaciones fuertes de entrada.

Makefile (objetivos comunes)

- En estos ejercicios verás objetivos `all`, `clean`, `fclean` y `re` en los `Makefile`.



`make debug` (nota)

- `make debug` compila con `DEBUG=1` y recompila desde cero; útil para activar mensajes de depuración y validaciones extra.

Ejemplos de uso

- `ex00` (btc):
  ```bash
  cd cpp09/ex00
  make
  ./btc data.csv input.csv
  ```
- `ex01` (RPN):
  ```bash
  cd cpp09/ex01
  make
  ./RPN "3 4 +"
  ```
- `ex02` (PmergeMe):
  ```bash
  cd cpp09/ex02
  make
  ./PmergeMe 3 5 9 1 4 2
  ```