//#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>
#include <cmath>
#include "Algoritmos Ordenamiento.cpp"
using namespace std;

typedef void (*FuncionPuntero)(vector<int>,int);

int n_num = 100000;

void generarNumerosAletorios(){
    ofstream file;
    file.open("numerosAleatorios.txt");
    for(int i=0; i<n_num; i++){
        random_device hola;
        mt19937 gen(hola());
        uniform_int_distribution<int> dis(1, n_num);
        file<<dis(gen)<<endl;
    }
    file.close();
}

vector<int> leerNumerosAleatorios(vector<int>& nums){
    ifstream file;
    file.open("numerosAleatorios.txt");
    string num;
    while (getline(file, num)){
        nums.push_back(stoi(num));
    }
    return nums;
}

void leerArreglo(vector<int>&nums){
    for(int i:nums){
        cout<<i<<endl;
    }
}

void graficarComplejidadComputacional(){
    system("python complejidad.py");
}

//double ejecutarFuncion(FuncionPuntero funct,vector<int> vect ,int valor) {
//    auto start_time = std::chrono::high_resolution_clock::now();
//    funct(vect,valor);
//    auto end_time = std::chrono::high_resolution_clock::now();
//    auto duration = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end_time - start_time);
//    double rounded_duration = std::round(duration.count() * 10.0) / 10.0;
//    cout << std::fixed << std::setprecision(1);
//    cout << "Tiempo de ejecucion: " << rounded_duration << " milisegundos" << std::endl;
//    return rounded_duration;
//}
double ejecutarFuncion(FuncionPuntero funct, std::vector<int> vect, int valor) {
    auto start_time = std::chrono::high_resolution_clock::now();
    funct(vect, valor);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end_time - start_time);
    return duration.count();
}

void menu(){
    cout<<"1.- Generar archivo con nuevos numeros aleatorios.\n";
    cout<<"2.- Mostrar grafica comparando la complejidad computacional\n";
}

void escribirDatos(string nombreArchivo,vector<int> cantidadNums,vector<int>nums){
    ofstream file;
    file.open(nombreArchivo);
    
    //BubbleSort
    cout<<"Llego";
    for(int i : cantidadNums){
       double aux = ejecutarFuncion(BubbleSort,nums,i); 
       file<<aux<<" ";
    }
    file<<endl;
    // Heap Sort
    for(int i : cantidadNums){
       double aux = ejecutarFuncion(HeapSort,nums,i); 
       file<<aux<<" ";
    }
    file<<endl;

    // Insertion Sort
    for(int i : cantidadNums){
       double aux = ejecutarFuncion(InsertionSort,nums,i); 
       file<<aux<<" ";
    }
    file<<endl;

    //Selection Sort
    for(int i : cantidadNums){
       double aux = ejecutarFuncion(SelectionSort,nums,i); 
       file<<aux<<" ";
    }
    file<<endl;
    // Shell Sort
    for(int i : cantidadNums){
       double aux = ejecutarFuncion(ShellSort,nums,i); 
       file<<aux<<" ";
    }
    file<<endl;
    
    //Merge Sort
    for(int i : cantidadNums){
       double aux = ejecutarFuncion(MergeSort,nums,i); 
       file<<aux<<" ";
    }
    file<<endl;
    
    // Quick Sort
    for(int i : cantidadNums){
       double aux = ejecutarFuncion(QuickSort,nums,i); 
       file<<aux<<" ";
    }
    file<<endl;
    cout<<endl;
    file.close();

}

int main()
{
    vector<int>nums;
    //generarNumerosAletorios();    
    leerNumerosAleatorios(nums);
    //int cantidadNums[7] = {100,1000,5000,10000,100000,500000,1000000};
    //int cantidadNums[7] = {100,1000,5000,10000,100000,1000000};
    vector<int>cantidadNums = {10,100,500,1000,2500,5000};
    vector<int>cantidadNums2 = {5000,10000,20000,50000,100000};

    leerArreglo(nums);

    escribirDatos("tiempos.txt", cantidadNums, nums);
    escribirDatos("tiempos2.txt", cantidadNums2, nums);
    //graficarComplejidadComputacional();

        cout<<"Termino"<<endl;

    //leerArreglo(nums);

    return 0;
}

