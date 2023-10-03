import matplotlib.pyplot as plt
import numpy as np

# Leer el archivo y crear el vector de vectores
vector = []
with open('tiempos.txt', 'r') as archivo:
    for linea in archivo:
        elementos = [float(elemento) for elemento in linea.strip().split()]
        vector.append(elementos)

for i in vector:
    print(i)

# Redondear los elementos del vector a 1 decimal
vector_de_vectores = [[round(elemento, 3) for elemento in fila] for fila in vector]

# Configurar el eje x
ubicaciones_x = list(range(1, len(vector_de_vectores[0]) + 1))

# Graficar el contenido
for i, columna in enumerate(vector_de_vectores):
    plt.plot(ubicaciones_x, columna, label=f'Linea {i + 1}')

# Configurar etiquetas y límites de los ejes
plt.xlabel('Ubicaciones en el eje X')
plt.ylabel('Valores en el eje Y')
plt.legend()

# Mostrar la gráfica
plt.show()

