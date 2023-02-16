//Método de Newton_Raphson para el cálculo de raíces
include <iostream> 
include <iomanip>
include <math.h>

#define PRECISION 10
#define MAX_ITER 100
#define INTERVALOS 6

using namespace std;

void tabula(double a, double b, int intervalos); // Muestra un número tabulado de intervalos
double f(double x); // Función a la que se le calcula la raíz
double df(double x); // Derivada de la función
void newton_raphson(double x0, double tolerancia, int iter); // Calcula la raí aproximada de la función

int main()
{
    double a, b, x0, tolerancia;
    int intervalos, iter;

    cout << "Método de Newton-Raphson" << endl;
    cout << "Introduzca el intervalo [a,b] en el que se encuentra la raíz" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "Introduzca el número de intervalos: ";
    cin >> intervalos;
    tabula(a, b, intervalos);
    cout << "Introduzca el valor inicial de x0: ";
    cin >> x0;
    cout << "Introduzca la tolerancia: ";
    cin >> tolerancia;
    cout << "Introduzca el número máximo de iteraciones: ";
    cin >> iter;
    newton_raphson(x0, tolerancia, iter);
    return 0;
}