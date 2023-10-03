#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>
#include <cmath>

// Bubble sort
void BubbleSort(std::vector<int> A,int tam){
    int n = tam;
    bool intercambio; // swap
    for (int i = 0; i < n-1; i++) {
        intercambio = false;
        for (int j = 0; j < n-i-1; j++) {
            if (A[j] > A[j + 1]) {
                std::swap(A[j], A[j + 1]);
                intercambio = true;
            }
        }
        if (intercambio == false)
            break;
    }    
}
// Heap sort
void heapify(std::vector<int>& A, int n, int i)
{
    int mayor = i;      // Inicializamos el indice del mayor como la raiz del subarbol
    int l = 2 * i + 1;   // Calculamos el indice del hijo izquierdo: left = 2 * i + 1
    int r = 2 * i + 2;   // Calculamos el indice del hijo derecho: right = 2 * i + 2

    if (l < n && A[l] > A[mayor]) // Si el hijo izquierdo es mayor que la raiz
        mayor = l;

    if (r < n && A[r] > A[mayor]) // Si el hijo derecho es mayor que el mayor actual
        mayor = r;

    if (mayor != i) { // Si el mayor no es la raiz
        std::swap(A[i], A[mayor]); // Intercambiamos el valor de la raiz con el mayor
        heapify(A, n, mayor);      // Llamamos recursivamente para asegurarnos de que el subarbol también sea un heap
    }
}


void HeapSort(std::vector<int> A, int n){
    // Construir un heap (reorganizar el vector)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);

    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i > 0; i--) { 
        std::swap(A[0], A[i]); // Mueve el current root al final
        heapify(A, i, 0); // call max heapify on the reduced heap
    }
}
// Insertion sort
void InsertionSort(std::vector<int> A, int n){
    int i, j, current;
    for ( i=1; i<n; i++){
        current = A[i];
        j = i - 1;
        while(j>=0 && A[j]>current){
            A[j+1] = A[j];
            j -= 1;
        }
        A[j+1] = current;
    }
}
// Selection sort
void SelectionSort(std::vector<int> A, int n){
    int indiceMin; // Indice del elemento minimo

    // Iterar en la submatriz no ordenada
    for (int i = 0; i < n - 1; i++) {
        // Encontrar el elemento mínimo en la submatriz no ordenada
        indiceMin = i; // Suponemos que el elemento actual es el mínimo
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[indiceMin])
                indiceMin = j; // Actualizar el indice del minimo si encontramos un elemento menor
        }
        // Intercambiar el elemento minimo encontrado con el primer elemento no ordenado
        if (indiceMin != i)
            std::swap(A[indiceMin], A[i]);
    }
}
// Shell sort
void ShellSort(std::vector<int> A, int n){
    // Comenzar con un espacio grande, luego ir reduciendo el espacio
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Realizar una ordenación por inserción con espaciado para este tamaño de espacio.
        // Los primeros elementos gap a[0..gap-1] ya están en orden con espaciado.
        // Agregar un elemento más hasta que todo A esté ordenado con espaciado.
        for (int i = gap; i < n; i += 1)
        {
            // Agregar A[i] a los elementos que ya han sido ordenados con espaciado
            // Guardar A[i] en temp y crear un hueco en la posición i
            int temp = A[i];

            // Desplazar hacia arriba los elementos previamente ordenados con espaciado
            // hasta encontrar la ubicación correcta para A[i]
            int j;
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap)
                A[j] = A[j - gap];

            // Poner temp (el valor original de A[i]) en su ubicación correcta
            A[j] = temp;
        }
    }
}
// Merge sort
void Merge(std::vector<int>& myArray, int inicio, int medio, int fin) {
    int sizeIzq = medio - inicio + 1;
    int sizeDer = fin - medio;
    int* subArrayIzq = new int[sizeIzq];
    int* subArrayDer = new int[sizeDer];
    
    for (int i = 0; i < sizeIzq; i++)
        subArrayIzq[i] = myArray[inicio + i];
    for (int j = 0; j < sizeDer; j++)
        subArrayDer[j] = myArray[medio + 1 + j];

    int i = 0, j = 0, k = inicio;
    
    while (i < sizeIzq && j < sizeDer) {
        if (subArrayIzq[i] <= subArrayDer[j]) {
            myArray[k] = subArrayIzq[i];
            i++;
        } else {
            myArray[k] = subArrayDer[j];
            j++;
        }
        k++;
    }
    
    while (i < sizeIzq) { // Copia los elementos restantes del subArrayIzq
        myArray[k] = subArrayIzq[i];
        i++; 
        k++;
    }
    
    while (j < sizeDer) { // Copia los elementos restantes del subArrayDer
        myArray[k] = subArrayDer[j];
        j++; 
        k++;
    }
    
    delete[] subArrayIzq;
    delete[] subArrayDer;
}

void MyMergeSort(std::vector<int>& A, int inicio, int fin){
    if(inicio < fin){
        int medio = (inicio + fin) / 2; // Dividimos por la mitad
        MyMergeSort(A, inicio, medio);
        MyMergeSort(A, medio+1, fin);
        Merge(A,inicio,medio,fin); // Mezcla las partes ordenadas
    }
}

void MergeSort(std::vector<int> A, int n){
    MyMergeSort(A,0,n-1);
}
// Quick sort
int partition(std::vector<int>& A, int low, int high) {
    int pivot = A[high]; // Elegir el pivote
    // Índice del elemento más pequeño y que indica
    // la posición correcta del pivote encontrada hasta ele momento
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        // Si el elemento actual es menor que el pivote
        if (A[j] < pivot) {
            // Incrementar el índice del elemento más pequeño
            i++;
            std::swap(A[i], A[j]);
        }
    }

    std::swap(A[i + 1], A[high]);
    return (i + 1);
}
 
void MyQuickSort(std::vector<int>& A, int low, int high)
{
    if (low < high) {
        // pi es el índice de partición, A[p] está ahora en el lugar correcto
        int pi = partition(A, low, high);
        // Ordenar por separado los elementos antes y despues de la particion
        MyQuickSort(A, low, pi - 1);
        MyQuickSort(A, pi + 1, high);
    }
}
 

void QuickSort(std::vector<int> A, int n){
    MyQuickSort(A, 0, n - 1);
}
