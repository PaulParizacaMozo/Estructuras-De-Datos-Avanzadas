import matplotlib.pyplot as plt
import numpy as np

# Definir el rango de valores para n
n = np.arange(1, 100, 1)

# Definir las funciones
funcion1 = n**2
funcion2 = n**2
funcion3 = n**2
funcion4 = n * np.log2(n)
funcion5 = n * np.log(n)
funcion6 = n * np.log(n)
funcion7 = n * np.log(n)

# Crear gráficos individuales
plt.figure(figsize=(12, 8))

# Graficar la función n^2
plt.subplot(4, 2, 1)
plt.plot(n, funcion1, label='n^2')
plt.title('n^2')
plt.xlabel('n')
plt.ylabel('Valor de la función')
plt.legend()

# Graficar la función n^2
plt.subplot(4, 2, 2)
plt.plot(n, funcion2, label='n^2')
plt.title('n^2')
plt.xlabel('n')
plt.ylabel('Valor de la función')
plt.legend()

# Graficar la función n^2
plt.subplot(4, 2, 3)
plt.plot(n, funcion3, label='n^2')
plt.title('n^2')
plt.xlabel('n')
plt.ylabel('Valor de la función')
plt.legend()

# Graficar la función n log^2 n
plt.subplot(4, 2, 4)
plt.plot(n, funcion4, label='n log^2 n')
plt.title('n log^2 n')
plt.xlabel('n')
plt.ylabel('Valor de la función')
plt.legend()

# Graficar la función n log n
plt.subplot(4, 2, 5)
plt.plot(n, funcion5, label='n log n')
plt.title('n log n')
plt.xlabel('n')
plt.ylabel('Valor de la función')
plt.legend()

# Graficar la función n log n
plt.subplot(4, 2, 6)
plt.plot(n, funcion6, label='n log n')
plt.title('n log n')
plt.xlabel('n')
plt.ylabel('Valor de la función')
plt.legend()

# Graficar la función n log n
plt.subplot(4, 2, 7)
plt.plot(n, funcion7, label='n log n')
plt.title('n log n')
plt.xlabel('n')
plt.ylabel('Valor de la función')
plt.legend()

# Ajustar diseño y mostrar gráficos
plt.tight_layout()
plt.show()

