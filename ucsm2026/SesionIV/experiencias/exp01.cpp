#include <iostream>
#include <string>

using namespace std;

class Hijo {
private:
    string nombre;

public:
    Hijo() {
        this->nombre = "Sin nombre";
    }
    
    Hijo(string n) {
        this->nombre = n;
    }
    
    string getNombre() {
        return nombre;
    }
    
    void setNombre(string n) {
        this->nombre = n;
    }
};

class Padre {
private:
    string nombre;
    static const int MAX_HIJOS = 10;
    Hijo hijos[MAX_HIJOS];
    int numHijos;

public:
    Padre(string n) {
        this->nombre = n;
        this->numHijos = 0; 
    }
    
    string getNombre() {
        return nombre;
    }
    
    void setNombre(string n) {
        this->nombre = n;
    }
    
    void agregarHijo(Hijo h) {
        if (numHijos < MAX_HIJOS) {
            hijos[numHijos] = h; 
            numHijos++;          
        } else {
            cout << "Limite de hijos alcanzado." << endl;
        }
    }
    
    void imprimirInfo() {
        cout << "Nombre del Padre: " << nombre << endl;
        cout << "Cantidad de objetos 'Hijo' relacionados: " << numHijos << endl;
        
        if (numHijos > 0) {
            cout << "Nombres de los hijos:" << endl;
            for (int i = 0; i < numHijos; i++) {
                cout << " - " << hijos[i].getNombre() << endl;
            }
        }
    }
};

int main() {
    Padre padre1("Roberto");
    
    Hijo h1("Miguel");
    Hijo h2("Sofia");
    Hijo h3("Lucas");
    
    padre1.agregarHijo(h1);
    padre1.agregarHijo(h2);
    padre1.agregarHijo(h3);
    
    cout << "--- Verificando la relacion unidireccional ---" << endl;
    padre1.imprimirInfo();

    return 0;
}