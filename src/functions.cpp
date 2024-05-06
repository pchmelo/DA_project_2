//
// Created by pchmelo on 05-05-2024.
//

#include "functions.h"
using namespace std;

void Functions::printLogo(){
    cout << endl;
    cout << "\033[1;34m  _____    _____     _______\033[0m\n";
    cout << "\033[1;34m |_   _|  / ____|   |  ___  |\033[0m\n";
    cout << "\033[1;34m   | |   | (____    |  |_|  |\033[0m\n";
    cout << "\033[1;34m   | |    \\___  \\   |  _____|\033[0m\n";
    cout << "\033[1;34m   | |     ____) |  |  |\033[0m\n";
    cout << "\033[1;34m   |_|    |_____/   |__|\033[0m\n\n";
}

void Functions::printLowerBound(double lowerBound, chrono::duration<double> time){
    std::cout << "\033[1;31mLower Bound: " << lowerBound << "\033[0m" << std::endl;
    std::cout << "\033[1;33mElapsed time: " << time.count() << " seconds\033[0m" << std::endl;
}

void Functions::printGraph(grafos g){
    int i = 0;
    for(auto v : g.graph.getVertexSet()){
        cout << "Vertex: " << i << endl;
        for(auto e : v->getAdj()){
            cout << "Orig: " << e->getOrig()->getInfo() << " Dest: " << e->getDest()->getInfo() << " Dist: " << e->getWeight() <<endl;
        }
        cout << endl;
        i++;
    }
}

void Functions::printResultsOptimal(vector<int> path, double optimal, chrono::duration<double> time){
    std::cout << "\033[1;34mPath: ";
    bool first = true;
    for(auto v : path){
        if(first){
            std::cout << v;
            first = false;
            continue;
        }
        std::cout << " -> " << v;
    }
    std::cout << "\033[0m" << std::endl;
    std::cout << "\033[1;32mOptimal Solution: " << optimal << "\033[0m" << std::endl;
    std::cout << "\033[1;33mElapsed time: " << time.count() << " seconds\033[0m" << std::endl;
}

void Functions::printResultsHeuristic(vector<int> path, double heuristic, chrono::duration<double> time, double lower_bound){
    std::cout << "\033[1;34mPath: ";
    bool first = true;
    for(auto v : path){
        if(first){
            std::cout << v;
            first = false;
            continue;
        }
        std::cout << " -> " << v;
    }
    std::cout << "\033[0m" << std::endl;
    std::cout << "\033[1;31mLower Bound: " << lower_bound << "\033[0m" << std::endl;
    std::cout << "\033[1;32mHeuristic Solution: " << heuristic << "\033[0m" << std::endl;
    std::cout << "\033[1;35mAproximation: " << heuristic/lower_bound << "\033[0m" << std::endl;
    std::cout << "\033[1;33mElapsed time: " << time.count() << " seconds\033[0m" << std::endl;
}

void Functions::resetGraph(grafos &g){
    g.graph = Graph<int>();
}


