//
// Created by pchmelo on 27-04-2024.
//

#ifndef PROJETO_2_GRAFOS_H
#define PROJETO_2_GRAFOS_H

#include "Graph.h"
#include "math.h"
#include "chrono"


class grafos {
public:
    Graph<int> graph;
    void resetStatus();

    //Type - Small
    //1 - shipping.csv, 2 - stadiums.csv, 3 - tourism.csv
    //Type - Extra
    //1 - 25, 2 - 50, 3 - 75, 4 - 100, 5 - 200, 6 - 300, 7 - 400, 8 - 500, 9 - 600, 10 - 700, 11 - 800, 12 - 900
    void addAllEdge(int choice, std::string type);
    void readGraph(int choice, std::string type);

    //functions to normalize the graph
    void checkGraph();
    void normalizeGraph(Vertex<int>* source);
    void triangular_proximation(Vertex<int>* v1, Vertex<int>* v2, Vertex<int>* v3);
    static std::vector<Vertex<int>*> getVertexSetOfVertex(Vertex<int>* source);

    //stats
    std::vector<Vertex<int>*> prim();
    double primTotalCost(std::vector<Vertex<int> *> &path);
    double weightPrim();

    //2.1 - Backtracking algorithm
    double backtrackingAlgorithm(int source, std::vector<Vertex<int>*> &path, std::chrono::duration<double> &time);
    void auxBacktrackingAlgorithm(Vertex<int>* v_src, Vertex<int>* vertex, std::vector<Vertex<int>*> &current_path, double &res, double cost_now, int count, std::vector<Vertex<int>*> &path);
    bool checkEdge(Vertex<int>* vertex, Vertex<int>* dest, Edge<int>* &edge);

    //2.2 - Triangular Approximation Heuristic
    double triangularApproximationHeuristic(int src, std::vector<Vertex<int>*> &path, std::chrono::duration<double> &time);

    void commanderTriangularApprox();
    void triangularApprox(Vertex<int>* source);
    double findMinLongTrianhularPath(Vertex<int>* source, Vertex<int>* dest);
    double findLongTrianhularPath(Vertex<int>* source, Vertex<int>* longVertex, Vertex<int>* dest);
};


#endif //PROJETO_2_GRAFOS_H
