#include <iostream>
#include "Inventario.hpp"
#include "Lector.hpp"

Inventario::Inventario() = default;

void Inventario::cargarInventario(std::string ruta) {
    Lector::procesarArchivo(this, ruta);
}

void Inventario::guardarInventario(std::string ruta) {
    // Polémico, pero no rompe encapsulamiento. La clase cede voluntariamente un atributo.
    Lector::guardarItems(items, ruta);
}

void Inventario::listarContenido() {
    for (size_t i = 0; i < items.tamanio(); i++) {
        items[i]->listarInformacion();
        std::cout << std::endl;
    }
}

void Inventario::eliminarItemGastado(std::string item) {
    size_t i = 0;
    bool eliminado = false;
    while (i < items.tamanio() && !eliminado) {
        if (*items[i] == item) {
            eliminado = true;
            Item* itemEliminado = items.baja(i);
            delete itemEliminado;
        }
        i++;
    }
}

void Inventario::agregarItemRecogido(Item* item) {
    if (items.tamanio() < TAMANIO_MAXIMO) {
        items.alta(item);
    } else {
        std::cout << "El inventario esta lleno." << std::endl;
        delete item;
    }
}

Inventario::~Inventario() {
    for (size_t i = 0; i < items.tamanio(); i++) {
        delete items[i];
    }
}