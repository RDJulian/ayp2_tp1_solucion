#include "Menu.hpp"
#include <random>
#include <iostream>

// Ignorar. Genero un Item al azar para no perder tiempo codeando interaccion con el usuario.
std::random_device rd;
std::mt19937 gen(rd());

int Menu::random(int low, int high) {
    std::uniform_int_distribution<> dist(low, high);
    return (dist(gen));
}

Item* Menu::generarItemAleatorio() {
    Item* item;
    int r1 = random(0, 2);
    int r2 = random(1, 99);
    switch (r1) {
        case 0: {
            item = new Item("ItemTest" + std::to_string(r2), TIPO_PUZZLE);
            break;
        }
        case 1: {
            item = new Item("ItemTest" + std::to_string(r2), TIPO_MUNICION);
            break;
        }
        default: {
            item = new Item("ItemTest" + std::to_string(r2), TIPO_CURATIVO);
            break;
        }
    }
    return item;
}

// Solución a partir de aca.
void Menu::imprimirOpciones() {
    std::cout << "1: Listar contenido." << std::endl;
    std::cout << "2: Usar un Item." << std::endl;
    std::cout << "3: Agregar un Item al Inventario." << std::endl;
    std::cout << "4: Salir." << std::endl;
}

void Menu::ejecutarMenu(Inventario& inventario) {
    std::string opcion, nombre;
    while (opcion != "4") {
        imprimirOpciones();
        std::cout << "Ingrese una opcion: ";
        getline(std::cin >> std::ws, opcion);
        std::cout << std::endl;
        if (opcion == "1") {
            inventario.listarContenido();
        } else if (opcion == "2") {
            std::cout << "Ingrese el nombre del Item a eliminar: ";
            getline(std::cin >> std::ws, nombre);
            inventario.eliminarItemGastado(nombre);
        } else if (opcion == "3") {
            // Tomar entrada del Usuario.
            Item* item = generarItemAleatorio();
            inventario.agregarItemRecogido(item);
        } else if (opcion != "4") {
            std::cout << "Opcion incorrecta. Ingrese nuevamente." << std::endl;
        }
        std::cout << std::endl;
    }
}