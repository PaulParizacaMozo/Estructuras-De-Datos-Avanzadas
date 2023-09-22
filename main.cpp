#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;

class Espacio{
    public:
        //Atributos
        int dimension;
        int cantidad_puntos;
        vector<vector<double>>puntos;
        vector<double>distancias;
        
        //Constructor
        Espacio(int dimension,int cantidad_puntos){
            this->dimension = dimension;
            this->cantidad_puntos = cantidad_puntos;
            vector<std::vector<double>> matriz(cantidad_puntos,vector<double>(dimension));
            this->puntos = matriz;
        }

        //Funciones
        void info(){
            cout<<"\nInformacion del espacio: "<<endl;
            cout<<"Numero de puntos generados -> "<<puntos.size()<<endl;
            cout<<"Dimension en el cual se generan los puntos -> "<<puntos[0].size()<<endl;
        }

        void printPuntos(){
            for(int i=0; i<cantidad_puntos; i++){
                for (int n = 0; n < dimension; ++n){
                    cout<<puntos[i][n]<<" ";
                }
                cout<<endl;
            }
        }
        
        void completarMatriz(){
            for(int i=0; i<cantidad_puntos; i++){
                random_device hola;  
                mt19937 gen(hola());
                uniform_real_distribution<> dis(0.0, 1.0);
                for (int n = 0; n < dimension; ++n){
                    puntos[i][n] = dis(gen);
                }
            }
        }

        double distancia_euclediana(vector<double>punto1,vector<double>punto2){
            double distancia = 0;
            for (int i=0 ;i<dimension;i++) {
                distancia += pow(punto2[i]-punto1[i],2);
            }
            distancia = sqrt(distancia);
            return distancia;
        }

        void calcular_distancias(){
            for(int i=0 ;i<cantidad_puntos;i++){
                for(int j=0;j<cantidad_puntos;j++){
                    if(i < j){
                        double aux = distancia_euclediana(puntos[i],puntos[j]);
                        distancias.push_back(aux);
                    }
                }
            }
        }
        void escribir_archivos(){
            ofstream file;
            file.open("distancias.txt");
            for(auto vec : distancias){
                file<<vec<<'\n';
            }
            file.close();
            file.open("data.txt");
            file<<dimension<<'\n';
            file<<cantidad_puntos<<'\n';
            file.close();
        }
};


int main()
{
    int dim,cant;
    cout<<"Ingrese la dimension -> ";
    cin>>dim;
    cout<<"Ingrese la cantidad de puntos -> ";
    cin>>cant;
    Espacio a(dim,cant);
    a.info();
    a.completarMatriz();
    a.calcular_distancias();
    cout<<"Numero de distancias generadas -> "<<a.distancias.size()<<endl<<endl;
    cout<<"Iniciando Grafica ..."<<endl;
    a.escribir_archivos();
    cin.get();
    system("python histograma.py");
    cout<<"Finalizado."<<endl;
    return 0;
}
