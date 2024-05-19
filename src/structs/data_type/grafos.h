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

    /**
     * @brief Function to reset the status of the graph.
     *
     * This function resets the status of the graph by setting the visited attribute of all vertices to false.
     */
    void resetStatus();

    /**
     * @brief Function to check if an edge exists between two vertices.
     *
     * @param src The source vertex.
     * @param dest  The destination vertex.
     * @param g The graph.
     *
     * @return True if the edge exists, false otherwise.
     */
    bool checkEdge(int src, int dest, Graph<int> g);

    /**
     * @brief Function to copy a graph.
     *
     * @param g The graph to be copied.
     *
     * @return The copied graph.
     */
    Graph<int> copyGraph(Graph<int> g);

    //Type - Small
    //1 - shipping.csv, 2 - stadiums.csv, 3 - tourism.csv, 4 - test44.csv
    //Type - Extra
    //1 - 25, 2 - 50, 3 - 75, 4 - 100, 5 - 200, 6 - 300, 7 - 400, 8 - 500, 9 - 600, 10 - 700, 11 - 800, 12 - 900
    //Type - Real
    //1- Graph1, 2- Graph2, 3- Graph3
    /**
     * @brief Function to add all edges to the graph.
     *
     * @param choice The file.
     * @param type Small or Extra.
     */
    void addAllEdge(int choice, std::string type);

    /**
     * @brief Function to read the coordinates of a vertex.
     *
     * @param choice The file.
     * @param type Small or Extra.
     *
     * @return The coordinates of the vertex.
     */
    double readCoordinates(int choice, std::string type);

    /**
     * @brief Function to read the graph.
     *
     * @param choice The file.
     * @param type Small or Extra.
     */
    void readGraph(int choice, std::string type);

    //functions to normalize the graph

    /**
     * @brief Function to check the graph.
     *
     * Complexity: O(V * E^4) if the graph is "small", where V is the number of vertices
     * of the graph and E is the number of edges that exist in each vertex, O(V^3) if "extra"
     * where V is the number of vertices in the graph.
     *
     * @param type The type of the graph.
     */
    void checkGraph(std::string type);

    /**
     * @brief Function to normalize the real coordinates of the graph.
     *
     * Complexity: O(n^2) where n is the number of vertices in the graph.
     *
     * @param source The source vertex.
     */
    void normalizationRealCoordinates(Vertex<int>* source);

    /**
     * @brief Function to normalize the graph.
     *
     * Complexity: O(n^4) where n is the number of edges that exist in each vertex.
     *
     * @param source The source vertex.
     */
    void normalizeGraph(Vertex<int>* source);

    /**
     * @brief Function that makes the triangular approximation of the graph.
     *
     * Complexity: O(n) where n is the number of edges that exist in each vertex.
     *
     * @param v1 First vertex.
     * @param v2 Second vertex.
     * @param v3 Third vertex.
     */
    void triangular_approximation(Vertex<int>* v1, Vertex<int>* v2, Vertex<int>* v3);

    /**
     * @brief Function to get the vertex set of a vertex.
     *
     * Complexity: O(n) where n is the number of edges that exist in each vertex.
     *
     * @param source The source vertex.
     *
     * @return The vertex set of the vertex.
     */
    static std::vector<Vertex<int>*> getVertexSetOfVertex(Vertex<int>* source);

    //extra
    /**
     * @brief Function to convert from degrees to radians.
     *
     * Complexity: O(1).
     *
     * @param degree The degree to convert.
     *
     * @return The degree in radians.
     */
    double convertToRadians(double degree);

    /**
     * @brief Function to calculate the distance between two points using the Haverside formula.
     *
     * Complexity: O(1).
     *
     * @param lat1 The latitude of point 1.
     * @param long1 The longitude of point 1.
     * @param lat2 The latitude of point 2.
     * @param long2 The longitude of point 2.
     *
     * @return The distance between the two points.
     */
    double calculateDistanceHaverside(double lat1, double long1, double lat2, double long2);

    //stats
    /**
     * @brief Function to calculate the maximum weight of a tree.
     *
     * Complexity: O(E) where E is the number of edges that exist in each vertex.
     *
     * @param src The source vertex.
     * @param primCost The cost of the prim algorithm.
     *
     * @return The maximum weight of the tree.
     */
    double maxWeightOneTree(int src, double primCost);

    /**
     * @brief Function to calculate the prim's algorithm.
     *
     * Complexity: O(E * logV), where E is the number of edges that exist in each vertex and V is the number of vertices in the graph.
     *
     * @return The minimum spanning tree.
     */
    std::vector<Vertex<int>*> prim();

    /**
     * @brief Function to convert the minimum spanning tree into a graph.
     *
     * Complexity: O(V + E), where V is the number of vertices in the minimum spanning tree (MST)
     * and E is the number of edges in the MST.
     *
     * @param mst
     *
     * @return
     */
    Graph<int> convertPrimToGraph(std::vector<Vertex<int>*> mst);

    /**
     * @brief Function to calculate the total cost of the minimum spanning tree.
     *
     * Complexity: O(V * E), where V is the number of vertices in the minimum spanning tree (MST) and E is the number of edges in each vertex.
     *
     * @param path
     *
     * @return The total cost of the minimum spanning tree.
     */
    double primTotalCost(std::vector<Vertex<int> *> &path);

    /**
     * @brief Function to calculate the value of the lower bound
     *
     * This function calls all the auxiliary functions to calculate the lower bound.
     *
     * Complexity: O(E * log V) if flag is false, where E is the number of edges that exist in each vertex and V is the number of vertices in the graph.
     * If flag is true, O(V * (E + V * log V)), where V is the number of vertices in the graph and E is the number of edges in each vertex.
     *
     * @param flag
     * @param time
     *
     * @return The value of the lower bound.
     */
    double lowerBoundCommander(bool flag, std::chrono::duration<double> &time);

    //2.1 - Backtracking algorithm
    /**
     * @brief Function that explores all possible paths from the source vertex to all other vertices in the graph.
     *
     * This function calls the auxiliary function auxBacktrackingAlgorithm.
     *
     * Complexity: O(N!) where N is the number of vertices in the graph.
     *
     * @param source
     * @param path
     * @param time
     *
     * @return The cost of the path.
     */
    double backtrackingAlgorithm(int source, std::vector<int> &path, std::chrono::duration<double> &time);

    /**
     * @brief Function that explores all possible paths from the source vertex to all other vertices in the graph.
     *
     * This function uses backtracking to avoid unnecessary computation.
     *
     * Complexity: O(N!) where N is the number of vertices in the graph.
     *
     * @param v_src
     * @param vertex
     * @param current_path
     * @param res
     * @param cost_now
     * @param count
     * @param path
     */
    void auxBacktrackingAlgorithm(Vertex<int>* v_src, Vertex<int>* vertex, std::vector<int> &current_path, double &res, double cost_now, int count, std::vector<int> &path);

    /**
     * @brief Function to check if an edge exists between two vertices.
     *
     * Complexity: O(E) where E is the number of edges that exist in each vertex.
     *
     * @param vertex
     * @param dest
     * @param edge
     *
     * @return True if the edge exists, false otherwise.
     */
    bool checkEdge(Vertex<int>* vertex, Vertex<int>* dest, Edge<int>* &edge);

    //2.2 - Triangular Approximation Heuristic

    /**
     * @brief Function to calculate the triangular approximation heuristic.
     *
     * This function calls the auxiliary function triangularApproximationHeuristic.
     *
     * Complexity: O(V^2) where V is the number of vertices in the graph.
     *
     * @param src
     * @param path
     * @param time
     *
     * @return The cost of the path.
     */
    double triangularApproximationHeuristic(int src, std::vector<int> &path, std::chrono::duration<double> &time);

    /**
     * @brief Function that applies the triangular approximation to all vertices in the graph.
     *
     * Complexity: O(V^2) where V is the number of vertices in the graph.
     */
    void commanderTriangularApprox();

    /**
     * @brief Function that finds the minimum longest triangular path between a source vertex and a destination vertex.
     *
     * Complexity: O(n^2), where n is the number of adjacent vertices to the source vertex.
     *
     * @param source
     */
    void triangularApprox(Vertex<int>* source);

    /**
     * @brief Function to find the minimum triangular path.
     *
     * Complexity: O(n^2) where n is the number of adjacent vertices of the source vertex.
     *
     * @param source
     * @param dest
     *
     * @return The cost of the minimum longest triangular path.
     */
    double findMinLongTriangularPath(Vertex<int>* source, Vertex<int>* dest);

    /**
     * @brief Function to find the longest triangular path.
     *
     * Complexity: O(n) where n is the number of adjacent vertices of the source vertex.
     *
     * @param source
     * @param longVertex
     * @param dest
     *
     * @return The cost of the longest triangular path.
     */
    double findLongTriangularPath(Vertex<int>* source, Vertex<int>* longVertex, Vertex<int>* dest);

    //2.3 - Christofides Algorithm
    /**
     * @brief Function to calculate the Christofides algorithm.
     *
     * This function calls the auxiliary functions oddDegreeVertices, minimumWeightMatching, createMultiGraph, eulerianCircuit, and hamiltonianCircuit.
     *
     * Complexity: O(V^3) where V is the number of vertices in the graph.
     *
     * @param path
     * @param time
     *
     * @return The cost of the path.
     */
    double christofidesAlgorithm(std::vector<int> &path, std::chrono::duration<double> &time);

    /**
     * @brief Function to find the vertices with odd degree.
     *
     * Complexity: O(V) where V is the number of vertices in the graph.
     *
     * @param mst
     * @param g
     *
     * @return The vertices with odd degree.
     */
    std::vector<Vertex<int>*> oddDegreeVertices(std::vector<Vertex<int>*> mst, Graph<int> g);

    /**
     * @brief Function to find the minimum weight matching.
     *
     * Complexity: O(V^3) where V is the number of vertices in the graph.
     *
     * @param oddDegreeVertices
     *
     * @return The minimum weight matching.
     */
    std::vector<Edge<int>*> minimumWeightMatching(std::vector<Vertex<int>*> oddDegreeVertices);

    /**
     * @brief Function to create a multigraph.
     *
     * Complexity: O(E^2) where E is the number of edges in the graph.
     *
     * @param edges
     * @param g
     *
     * @return The multigraph.
     */
    Graph<int> createMultiGraph(std::vector<Edge<int>*> edges, Graph<int> g);

    /**
     * @brief Function to find the Eulerian circuit.
     *
     * Complexity: O(E) where E is the number of edges in the multigraph.
     *
     * @param multigraph
     *
     * @return The Eulerian circuit.
     */
    std::vector<int> eulerianCircuit(Graph<int> &multigraph);

    /**
     * @brief Function to find the Hamiltonian circuit.
     *
     * Complexity: O(V) where V is the number of vertices in the eulerian circuit.
     *
     * @param eulerianCircuit
     * @param multigraph
     *
     * @return The Hamiltonian circuit.
     */
    std::vector<int> hamiltonianCircuit(std::vector<int> &eulerianCircuit, Graph<int> &multigraph);

    /**
     * @brief Function to calculate the cost of the path.
     *
     * Complexity: O(V^2) where V is the number of vertices in the path.
     *
     * @param path
     *
     * @return The cost of the path.
     */
    double calculatePathCost(std::vector<int> &path);

    //2-opt improvement

    /**
     * @brief Function to apply the 2-opt improvement to the path.
     *
     * Complexity: O(V^2) where V is the number of vertices in the path.
     *
     * @param path
     */
    void twoOptImprovement(std::vector<int> &path);
    void threeOptImprovement(std::vector<int> &path);

    /**
     * @brief Function to calculate the cost of the path.
     *
     * Complexity: O(V) where V is the number of vertices in the path.
     *
     * @param path
     *
     * @return The cost of the path.
     */
    double edgeCost(int src, int dest);

    //2.4 - Is Connected

    /**
     * @brief Function to check if the graph is connected.
     *
     * Complexity: O(V + E) where V is the number of vertices in the graph and E is the number of edges in the graph.
     *
     * @return True if the graph is connected, false otherwise.
     */
    bool isConnected();

    /**
     * @brief Function that calculates the shortest path using triangular approximation heuristic, if the graph is connected.
     *
     * Complexity: O(E) where E is the number of edges in the graph.
     *
     * @param src The source vertex.
     * @param path The path.
     * @param time The time.
     *
     * @return The cost of the path (-1 if the graph is not connected).
     */
    double realTriangularApproximationHeuristic(int src, std::vector<int> &path, std::chrono::duration<double> &time);

    /**
     * @brief Function to calculate the shortest path in a graph using the triangular approximation heuristic, given a source vertex.
     *
     * Complexity: O(V^2) where V is the number of vertices in the graph.
     *
     * @param src The source vertex.
     * @param path The path.
     * @param time The time.
     *
     * @return The cost of the path.
     */
    double triangularApproximationHeuristicReal(int src, std::vector<int> &path, std::chrono::duration<double> &time);

    /**
     * @brief Function to check if all vertices in the graph have been visited by the given path.
     *
     * Complexity: O(V) where V is the number of vertices in the graph.
     *
     * @param path The path.
     * @param notVisited The not visited vertices.
     *
     * @return True if all vertices have been visited, false otherwise.
     */
    bool checkerPath(std::vector<int> &path, std::vector<int> &notVisited);

    /**
     * @brief Function to check if all vertices in the graph have been visited by the given path.
     *
     * Complexity: O(V) where V is the number of vertices in the graph.
     *
     * @param path The path.
     * @param notVisited The not visited vertices.
     *
     * @return True if all vertices have been visited, false otherwise.
     */
    bool hasVisitedAllVertices();

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
