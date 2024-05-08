//
// Created by pchmelo on 27-04-2024.
//

#ifndef PROJETO_2_GRAFOS_H
#define PROJETO_2_GRAFOS_H

#include "Graph.h"
#include "math.h"
#include "chrono"
#include "map"
#include "stack"

class grafos {
public:
    Graph<int> graph;
    std::map<int, std::pair<double, double>> vertex_map_coordinates;

    void resetStatus();
    bool checkEdge(int src, int dest, Graph<int> g);
    Graph<int> copyGraph(Graph<int> g);

    //Type - Small
    //1 - shipping.csv, 2 - stadiums.csv, 3 - tourism.csv
    //Type - Extra
    //1 - 25, 2 - 50, 3 - 75, 4 - 100, 5 - 200, 6 - 300, 7 - 400, 8 - 500, 9 - 600, 10 - 700, 11 - 800, 12 - 900
    void addAllEdge(int choice, std::string type);
    double readCoordinates(int choice, std::string type);
    void readGraph(int choice, std::string type);

    //functions to normalize the graph
    void checkGraph(std::string type);
    void normalizationRealCoordinates(Vertex<int>* source);
    void normalizeGraph(Vertex<int>* source);
    void triangular_proximation(Vertex<int>* v1, Vertex<int>* v2, Vertex<int>* v3);
    static std::vector<Vertex<int>*> getVertexSetOfVertex(Vertex<int>* source);

    //extra
    double convertToRadians(double degree);
    double calculateDistanceHaverside(double lat1, double long1, double lat2, double long2);

    //stats
    double maxWeightOneTree(int src, double primCost);
    std::vector<Vertex<int>*> prim();
    Graph<int> convertPrimToGraph(std::vector<Vertex<int>*> mst);
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

    //2.3 - Christofides Algorithm
    double christofidesAlgorithm(std::vector<int> &path, std::chrono::duration<double> &time);
    std::vector<Vertex<int>*> oddDegreeVertices(const std::vector<Vertex<int>*>& mst, const Graph<int>& g);
    std::vector<Edge<int>*> minimumWeightMatching(const std::vector<Vertex<int>*>& oddDegreeVertices);
    Graph<int> createMultiGraph(std::vector<Edge<int>*> edges, Graph<int> g);
    std::vector<int> eulerianCircuit(Graph<int> &multigraph);
    std::vector<int> hamiltonianCircuit(const std::vector<int>& eulerianCircuit, const Graph<int>& multigraph);
    double calculatePathCost(std::vector<int> &path);

    //2-opt improvement
    void twoOptImprovement(std::vector<int> &path);
    void threeOptImprovement(std::vector<int> &path);
    double edgeCost(int src, int dest);

    //2.4 - Is Connected
    bool isConnected();
    double realTriangularApproximationHeuristic(int src, std::vector<int> &path, std::chrono::duration<double> &time);

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
