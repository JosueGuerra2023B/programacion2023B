#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Estructura para representar un artículo
struct Articulo {
    int id;
    string categoria;
    string nombre;
    double precio;
    int stock;
};

// Función para cargar los artículos desde el archivo
vector<Articulo> cargarArticulos(const string& archivo) {
    vector<Articulo> articulos;
    ifstream archivoEntrada(archivo);

    if (!archivoEntrada) {
        cerr << "Error al abrir el archivo " << archivo << endl;
        return articulos;
    }

    Articulo articulo;
    while (archivoEntrada >> articulo.id >> articulo.categoria >> articulo.nombre >> articulo.precio >> articulo.stock) {
        articulos.push_back(articulo);
    }

    archivoEntrada.close();
    return articulos;
}

// Función para mostrar los artículos
void mostrarArticulos(const vector<Articulo>& articulos) {
    cout << "ID  | Categoría       | Nombre                | Precio   | Stock" << endl;
    cout << "--------------------------------------------------------------" << endl;
    for (const auto& articulo : articulos) {
        cout << setw(3) << articulo.id << " | " << setw(15) << articulo.categoria << " | " << setw(20) << articulo.nombre
             << " | $" << setw(7) << fixed << setprecision(2) << articulo.precio << " | " << setw(5) << articulo.stock << endl;
    }
}

int main() {
    const string archivoArticulos = "articulos.txt";
    vector<Articulo> articulos = cargarArticulos(archivoArticulos);

    // Aquí puedes implementar la lógica para que el usuario seleccione y compre artículos

    // Ejemplo: Mostrar todos los artículos
    mostrarArticulos(articulos);

    return 0;
}