import matplotlib.pyplot as plt
import numpy as np

n = np.linspace(1, 100, 100)

# Funciones a comparar
n_cuadrado = n**2
n_log_n = n * np.log(n)
n_log_cuadrado_n = n * (np.log(n)**2)

plt.figure(figsize=(10, 6))

plt.plot(n, n_cuadrado, label='n^2 - (Bubble sort, Insertion Sort, Selection Sort,)')
plt.plot(n, n_log_n, label='n log n - (Heap Sort, Merge Sort, Quick Sort)')
plt.plot(n, n_log_cuadrado_n, label='n log^2 n - (Shell Sort)')

plt.title('Complejidad Computacional - Comparacion')
plt.xlabel('Tamaño de Entrada (n)')
plt.ylabel('Operaciones')
plt.legend()

# Mostrar la gráfica
plt.grid(True)
plt.show()
