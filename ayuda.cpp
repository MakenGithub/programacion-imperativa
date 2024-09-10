#include <iostream>
#include <string>

using namespace std;

int main(){

    string c;
    cout<<"Ingrese algo: ";
    getline(cin, c);
    string p;
    int inicio = 0;
    int fin = c.find(' ');
    while (fin != -1)
    {
        p = c.substr(inicio, fin - inicio);
        char pl = p [0];
        cout<<"Se imprime algo en pantalla: "<<p<<" es "<<pl<<endl;
        inicio = fin + 1;
        fin = c.find(' ', inicio);
    }

    p = c.substr(inicio);
    char pl = p[0];
    cout<<"Se imprime algo en pantalla: "<<p<<" es "<<pl<<endl;
    

    return 0;
}