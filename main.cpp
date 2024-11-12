#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct Persona {
    string nombre;
    string apellido;
    string direccion;
    string adn;
    string ciudad;
    string telefono;
};

void leerPersonas(const string filename, vector<Persona> &personas) {
    ifstream file(filename);
    if(!file.is_open()) {
        cout<<"El archivo "<<filename<<" no se encontro."<<'\n';
        return;
    }

    string linea;
    while(getline(file, linea)) {
        stringstream ss(linea);
        Persona persona;
        getline(ss, persona.nombre, ',');
        getline(ss, persona.apellido, ',');
        getline(ss, persona.direccion, ',');
        getline(ss, persona.adn, ',');
        getline(ss, persona.ciudad, ',');
        getline(ss, persona.telefono, ',');

        personas.push_back(persona);
    }

    file.close();
}

void crearMatriz(const vector<Persona> &persona) {
    size_t n = persona.size();
    vector<vector<int>> matriz(n, vector<int>(n, 0));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i != j && persona[i].nombre[0] == persona[j].nombre[0]) {
                matriz[i][j] = 1;
            }
        }
    }

    cout<<"Matriz Adyacente:"<<'\n';
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        cout<<'\n';
    }
}



int main() {

    vector<Persona> people;
    leerPersonas("people.txt", people);

    crearMatriz(people);

    return 0;
}