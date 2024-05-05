//
// Created by pchmelo on 05-05-2024.
//

#ifndef PROJETO_2_FUNCTIONS_H
#define PROJETO_2_FUNCTIONS_H

#include "Graph.h"
#include "iostream"
#include "chrono"
#include "grafos.h"


class Functions {
public:
    static void printLogo();

    static void printGraph(grafos g);

    //2.1 printar resultados do backtracking
    static void printResults(std::vector<Vertex<int>*> path, double cost, std::chrono::duration<double> time);


};


#endif //PROJETO_2_FUNCTIONS_H
