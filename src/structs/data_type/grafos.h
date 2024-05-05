//
// Created by pchmelo on 27-04-2024.
//

#ifndef PROJETO_2_GRAFOS_H
#define PROJETO_2_GRAFOS_H

#include "Graph.h"
#include "math.h"


class grafos {
public:
    Graph<int> graph;

    void addAllEdge(int choice);
    void readGraph(int choice);

    //functions to normalize the graph
    void checkGraph();
    void normalizeGraph(Vertex<int>* source);
    void triangular_proximation(Vertex<int>* v1, Vertex<int>* v2, Vertex<int>* v3);
    static std::vector<Vertex<int>*> getVertexSetOfVertex(Vertex<int>* source);


};


#endif //PROJETO_2_GRAFOS_H
