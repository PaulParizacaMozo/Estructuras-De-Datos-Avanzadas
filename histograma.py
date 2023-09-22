import matplotlib.pyplot as plt
from matplotlib.ticker import MultipleLocator

dist = []
data = []

with open('distancias.txt', 'r') as archivo:
    for linea in archivo:
        valor_distancia = float(linea.strip())
        dist.append(valor_distancia)

with open('data.txt', 'r') as archivo:
    for linea in archivo:
        valor = int(linea.strip())
        data.append(valor)

plt.hist(dist, edgecolor='k', rwidth=0.9, color='skyblue')
plt.xlabel('Distancia')
plt.ylabel('Frecuencia')
plt.title('Histograma de las distancias entre puntos con dimension '+str(data[0]))

dim = 1
x_locator = MultipleLocator(dim)
plt.gca().xaxis.set_major_locator(x_locator)

plt.xlim(0)
plt.grid(True)

plt.show()
