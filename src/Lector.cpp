#include "Lector.hpp"
#include <fstream>
#include <sstream>

Item* Lector::generarItem(std::string linea) {
    Item* item = nullptr;
    std::string nombre, tipo;
    std::stringstream lineaStream(linea);

    getline(lineaStream, nombre, ',');
    getline(lineaStream, tipo);

    if (tipo == TIPO_CURATIVO || tipo == TIPO_PUZZLE || tipo == TIPO_MUNICION) {
        item = new Item(nombre, tipo);
    }
    return item;
}

void Lector::procesarArchivo(Inventario* inventario, std::string ruta) {
    Item* item;
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        // Puede hacer otra cosa.
        return;
    } else {
        std::string linea;
        while (getline(archivo, linea)) {
            item = generarItem(linea);
            if (item) {
                inventario->agregarItemRecogido(item);
            }
        }
        archivo.close();
    }
}

// Este método esta altamente acoplado al Inventario, pero funciona para este TP.
void Lector::guardarItems(Vector<Item*>& items, std::string ruta) {
    std::ofstream archivo(ruta);
    for (size_t i = 0; i < items.tamanio(); i++) {
        archivo << *items[i] << std::endl;
    }
    archivo.close();
}