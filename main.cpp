#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
#include <chrono>
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

int hammingDistance(const string &s1, const string &s2) {
    if (s1.length() != s2.length()) {
        cout<< "Error: DNA sequences must be of the same length to calculate Hamming distance.\n";
        return -1;
    }
    int distance = 0;
    for (size_t i = 0; i < s1.length(); ++i) {
        if (s1[i] != s2[i]) {
            ++distance;
        }
    }
    return distance;
}

vector<vector<int>> crearMatriz(const vector<Persona> &persona, int max) {
    size_t n = persona.size();
    vector<vector<int>> matriz(n, vector<int>(n, 0));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            int distance = hammingDistance(persona[i].adn, persona[j].adn);

            if (distance != -1 && distance <= max) {
                matriz[i][j] = 1;
                matriz[j][i] = 1;
            }
        }
    }

    return matriz;
}

void printMatriz(vector<vector<int>> &matriz, int n) {
    std::cout << "Adjacency Matrix (based on DNA similarity using Hamming distance):\n";
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int BFS(const vector<vector<int>> &matriz, const vector<Persona> &personas, const string &adnObjetivo) {
    queue<int> cola;
    vector<bool> visitado(personas.size(), false);

    cola.push(0);
    visitado[0] = true;

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();

        if (personas[actual].adn == adnObjetivo) {
            cout << "BFS encontro la persona: " << personas[actual].nombre << " " << personas[actual].apellido << '\n';
            return actual;
        }

        for (size_t i = 0; i < matriz.size(); ++i) {
            if (matriz[actual][i] == 1 && !visitado[i]) {
                cola.push(i);
                visitado[i] = true;
            }
        }
    }

    cout << "BFS no encontro coincidencia.\n";
    return -1;
}

int DFS(const vector<vector<int>> &matriz, const vector<Persona> &personas, const string &adnObjetivo) {
    stack<int> pila;
    vector<bool> visitado(personas.size(), false);

    pila.push(0);
    visitado[0] = true;

    while (!pila.empty()) {
        int actual = pila.top();
        pila.pop();

        if (personas[actual].adn == adnObjetivo) {
            cout << "DFS encontro la persona: " << personas[actual].nombre << " " << personas[actual].apellido << '\n';
            return actual;
        }

        for (size_t i = 0; i < matriz.size(); ++i) {
            if (matriz[actual][i] == 1 && !visitado[i]) {
                pila.push(i);
                visitado[i] = true;
            }
        }
    }

    cout << "DFS no encontro coincidencia.\n";
    return -1;
}




int main() {

    vector<Persona> personas;
    leerPersonas("people.txt", personas);

    int max = 9;
    size_t n = personas.size();

    vector<vector<int>> matriz = crearMatriz(personas, max);

    string adnObjetivo;

    cout<<"Ingresa el ADN de la persona: ";
    cin>>adnObjetivo;
    cout<<"Buscando en la base de datos..."<<'\n';

    auto inicioBFS = chrono::high_resolution_clock::now();
    BFS(matriz, personas, adnObjetivo);
    auto finBFS = chrono::high_resolution_clock::now();
    chrono::duration<double> duracionBFS = finBFS - inicioBFS;
    cout << "Tiempo BFS: " << duracionBFS.count() << " segundos\n";

    auto inicioDFS = chrono::high_resolution_clock::now();
    DFS(matriz, personas, adnObjetivo);
    auto finDFS = chrono::high_resolution_clock::now();
    chrono::duration<double> duracionDFS = finDFS - inicioDFS;
    cout << "Tiempo DFS: " << duracionDFS.count() << " segundos\n";

    return 0;
}