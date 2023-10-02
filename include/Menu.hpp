#ifndef AYP2_TP1_SOLUCION_MENU_HPP
#define AYP2_TP1_SOLUCION_MENU_HPP

#include "Inventario.hpp"

class Menu {
private:
    // Pre: -
    // Post: Devuelve un numero al azar entre low y high.
    static int random(int low, int high);

    // Pre: -
    // Post: Genera un Item con nombre y tipo aleatorio.
    static Item* generarItemAleatorio();

    // Pre -
    // Post: Imprime el menu principal por pantalla.
    static void imprimirOpciones();

public:
    // Pre: -
    // Post: Ejecuta el menu principal.
    static void ejecutarMenu(Inventario& inventario);
};

#endif