//
// Created by pchmelo on 27-04-2024.
//

#ifndef PROJETO_2_GRAFOS_H
#define PROJETO_2_GRAFOS_H

#include "Graph.h"
#include "math.h"
#include "chrono"
#include "map"

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
    double maxWeightOneTree(int src, double primCost);
    std::vector<Vertex<int>*> prim();
    double primTotalCost(std::vector<Vertex<int> *> &path);
    double lowerBoundCommander(bool flag, std::chrono::duration<double> &time);

    //2.1 - Backtracking algorithm
    double backtrackingAlgorithm(int source, std::vector<int> &path, std::chrono::duration<double> &time);
    void auxBacktrackingAlgorithm(Vertex<int>* v_src, Vertex<int>* vertex, std::vector<int> &current_path, double &res, double cost_now, int count, std::vector<int> &path);
    bool checkEdge(Vertex<int>* vertex, Vertex<int>* dest, Edge<int>* &edge);

    //2.2 - Triangular Approximation Heuristic
    double triangularApproximationHeuristic(int src, std::vector<int> &path, std::chrono::duration<double> &time);

    void commanderTriangularApprox();
    void triangularApprox(Vertex<int>* source);
    double findMinLongTrianhularPath(Vertex<int>* source, Vertex<int>* dest);
    double findLongTrianhularPath(Vertex<int>* source, Vertex<int>* longVertex, Vertex<int>* dest);
};


struct save_vertex{
    int v;
    std::map<std::pair<int, int>,double> edges;

    void save(Vertex<int>* v){
        this->v = v->getInfo();
        std::pair<int, int> p;
        for(Edge<int>* e: v->getAdj()){
            p.first = e->getOrig()->getInfo();
            p.second = e->getDest()->getInfo();

            this->edges[p] = e->getWeight();
        }
        for(Edge<int>* e: v->getIncoming()){
            p.first = e->getOrig()->getInfo();
            p.second = e->getDest()->getInfo();

            this->edges[p] = e->getWeight();
        }
    }

    void restore(Graph<int> &g){
        g.addVertex(v);
        for(auto e: this->edges){
            g.addEdge(e.first.first, e.first.second, e.second);
        }
        this->edges.clear();
    }
};


#endif //PROJETO_2_GRAFOS_H
