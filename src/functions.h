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

    //stats
    static void printLowerBound(double lowerBound, std::chrono::duration<double> time);

    //2.1 printar resultados de uma optimal solution
    static void printResultsOptimal(std::vector<int> path, double optimal, std::chrono::duration<double> time);

    //2.2 printar resultados de uma heuristic solution
    static void printResultsHeuristic(std::vector<int> path, double heuristic, std::chrono::duration<double> time, double lower_bound);

};


#endif //PROJETO_2_FUNCTIONS_H
