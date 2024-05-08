//
// Created by pchmelo on 05-05-2024.
//

#ifndef PROJETO_2_MENU_H
#define PROJETO_2_MENU_H

#include <iostream>
#include "functions.h"
#include "structs/data_type/grafos.h"

class Menu {
    private:
    // Declare selectedGraph member variable
    static grafos selectedGraph;
    static double lowerBound;

    public:
        static void Terminal();
        static void ToyMenu();
        static void ExtraMenu();
        static void RealMenu();
        static void SubMenu();
        static void SubMenuReal();
        static void AmbienteTeste();

};


#endif //PROJETO_2_MENU_H
