#include "Inventario.hpp"
#include "Menu.hpp"

int main() {
    Inventario inventario;
    inventario.cargarInventario("SaveFile.csv");
    Menu::ejecutarMenu(inventario);
    inventario.guardarInventario("SaveFile.csv");
    return 0;
}
