//
// Created by pchmelo on 27-04-2024.
//

#include "grafos.h"
#include "fstream"
#include "sstream"
#include "vector"

using namespace std;

double grafos::convertToRadians(double degree) {
    return degree * (M_PI / 180);
}

double grafos::calculateDistanceHaverside(double lat1, double long1, double lat2, double long2){
    double lat1_rad = convertToRadians(lat1);
    double long1_rad = convertToRadians(long1);
    double lat2_rad = convertToRadians(lat2);
    double long2_rad = convertToRadians(long2);

    double delta_lat = lat2_rad - lat1_rad;
    double delta_long = long2_rad - long1_rad;

    double aux = pow(sin(delta_lat / 2), 2) + cos(lat1_rad) * cos(lat2_rad) * pow(sin(delta_long / 2), 2);
    double c = 2 * atan2(sqrt(aux), sqrt(1 - aux));
    double earth_radius = 6371000;

    return earth_radius * c;
}

void grafos::resetStatus() {
    for(auto v : this->graph.getVertexSet()){
        v->setVisited(false);
    }
}

bool grafos::checkEdge(int src, int dest, Graph<int> g) {
    Vertex<int>* v_src = g.findVertex(src);
    for(auto e : v_src->getAdj()){
        if(e->getDest()->getInfo() == dest){
            return true;
        }
    }
    return false;
}

Graph<int> grafos::copyGraph(Graph<int> g) {
    Graph<int> res;

    for(auto v : g.getVertexSet()){
        res.addVertex(v->getInfo());
    }

    for(auto v : g.getVertexSet()){
        for(auto e : v->getAdj()){
            res.addEdge(v->getInfo(), e->getDest()->getInfo(), e->getWeight());
        }
    }

    return res;
}

void grafos::addAllEdge(int choice, string type) {
    int max = this->readCoordinates(choice, type);

    if(type == "small"){
        if(choice == 1){
            max = 14;
        }
        else if(choice == 2){
            max = 11;
        }
        else if(choice == 3){
            max = 5;
        }
        for(int i = 0; i < max; i++){
            this->graph.addVertex(i);
        }
    }
}

double grafos::readCoordinates(int choice, string type) {
    double res = 0;
    int limit = 0;
    string input = "";
    if (type == "small"){
        return res;
    }
    else if(type == "extra"){
        input = "../src/Data/Extra_Fully_Connected_Graphs/nodes.csv";
        if(choice == 1){
            limit = 25;
        }
        else if(choice == 2){
            limit = 50;
        }
        else if(choice == 3){
            limit = 75;
        }
        else if(choice == 4){
            limit = 100;
        }
        else if(choice == 5){
            limit = 200;
        }
        else if(choice == 6){
            limit = 300;
        }
        else if(choice == 7){
            limit = 400;
        }
        else if(choice == 8){
            limit = 500;
        }
        else if(choice == 9){
            limit = 600;
        }
        else if(choice == 10){
            limit = 700;
        }
        else if(choice == 11){
            limit = 800;
        }
        else if(choice == 12){
            limit = 900;
        }
    }
    else if(type == "real"){
        if(choice == 1){
            input = "../src/Data/Real-world Graphs/graph1/nodes.csv";
        }
        else if(choice == 2){
            input = "../src/Data/Real-world Graphs/graph2/nodes.csv";
        }
        else if (choice == 3){
            input = "../src/Data/Real-world Graphs/graph3/nodes.csv";
        }
    }

    ifstream file(input);
    string line;
    getline(file, line);

    while(getline(file, line)){
        if(res == limit && type == "extra"){
            break;
        }
        vector<string> values;
        stringstream ss(line);

        while(ss.good()){
            string substr;
            getline(ss, substr, ',');
            values.push_back(substr);
        }
        this->graph.addVertex(res);
        this->vertex_map_coordinates[stoi(values[0])] = make_pair(stod(values[1]), stod(values[2]));
        res++;
    }

    return res;
}

void grafos::readGraph(int choice, string type) {
    this->addAllEdge(choice, type);

    string input = "";

    if(type == "small"){
        if(choice == 1){
            input = "../src/Data/Toy-Graphs/shipping.csv";
        }
        else if(choice == 2){
            input = "../src/Data/Toy-Graphs/stadiums.csv";
        }
        else if(choice == 3){
            input = "../src/Data/Toy-Graphs/tourism.csv";
        }
    }
    else if(type == "extra"){
        if(choice == 1){
            input = "../src/Data/Extra_Fully_Connected_Graphs/edges_25.csv";
        }
        else if(choice == 2){
            input = "../src/Data/Extra_Fully_Connected_Graphs/edges_50.csv";
        }
        else if(choice == 3){
            input = "../src/Data/Extra_Fully_Connected_Graphs/edges_75.csv";
        }
        else if(choice == 4){
            input = "../src/Data/Extra_Fully_Connected_Graphs/edges_100.csv";
        }
        else if(choice == 5){
            input = "../src/Data/Extra_Fully_Connected_Graphs/edges_200.csv";
        }
        else if(choice == 6){
            input = "../src/Data/Extra_Fully_Connected_Graphs/edges_300.csv";
        }
        else if(choice == 7){
            input = "../src/Data/Extra_Fully_Connected_Graphs/edges_400.csv";
        }
        else if(choice == 8){
            input = "../src/Data/Extra_Fully_Connected_Graphs/edges_500.csv";
        }
        else if(choice == 9){
            input = "../src/Data/Extra_Fully_Connected_Graphs/edges_600.csv";
        }
        else if(choice == 10){
            input = "../src/Data/Extra_Fully_Connected_Graphs/edges_700.csv";
        }
        else if(choice == 11){
            input = "../src/Data/Extra_Fully_Connected_Graphs/edges_800.csv";
        }
        else if(choice == 12){
            input = "../src/Data/Extra_Fully_Connected_Graphs/edges_900.csv";
        }
    }
    else if(type == "real"){
        if(choice == 1){
            input = "../src/Data/Real-world Graphs/graph1/edges.csv";
        }
        else if(choice == 2){
            input = "../src/Data/Real-world Graphs/graph2/edges.csv";
        }
        else if (choice == 3){
            input = "../src/Data/Real-world Graphs/graph3/edges.csv";
        }
    }

    ifstream file(input);
    string line;
    getline(file, line);

    while(getline(file, line)){
        vector<string> values;
        stringstream ss(line);

        while(ss.good()){
            string substr;
            getline(ss, substr, ',');
            values.push_back(substr);
        }
        this->graph.addEdge(stoi(values[0]), stoi(values[1]), stod(values[2]));
        this->graph.addEdge(stoi(values[1]), stoi(values[0]), stod(values[2]));
    }
}

void grafos::checkGraph(string type) {
    int size = this->graph.getVertexSet().size() - 1;

    for(auto v : this->graph.getVertexSet()){
        if(v->getAdj().size() != size){
            if(type == "small"){
                normalizeGraph(v);
            }
            else{
                this->normalizationRealCoordinates(v);
            }
        }
    }
}

void grafos::normalizeGraph(Vertex<int>* source) {
    queue<Vertex<int>*> q;
    vector<Vertex<int>*> vertexSet = this->getVertexSetOfVertex(source);

    for(auto v : this->graph.getVertexSet()){
        for(auto e : v->getAdj()){
            q.push(e->getDest());
        }
    }

    while(!q.empty()){
        Vertex<int>* v = q.front();
        q.pop();

        for(auto e : v->getAdj()){
            auto it = find(vertexSet.begin(), vertexSet.end(), e->getDest());
            if(it == vertexSet.end()){
                vertexSet.push_back(e->getDest());
                q.push(e->getDest());
                triangular_proximation(source, v, e->getDest());
            }
        }
    }

}

void grafos::triangular_proximation(Vertex<int>* v1, Vertex<int>* v2, Vertex<int>* v3) {
    Edge<int>* edge1;
    Edge<int>* edge2;

    for(auto e : v1->getAdj()){
        if(e->getDest() == v2){
            edge1 = e;
        }
    }

    for(auto e : v2->getAdj()){
        if(e->getDest() == v3){
            edge2 = e;
        }
    }

    double rel_dist = pow(edge1->getWeight(), 2) + pow(edge2->getWeight(), 2);
    rel_dist = sqrt(rel_dist);
    rel_dist = round(rel_dist * 100) / 100;

    this->graph.addEdge(v1->getInfo(), v3->getInfo(), rel_dist);
    this->graph.addEdge(v3->getInfo(), v1->getInfo(), rel_dist);

}

void grafos::normalizationRealCoordinates(Vertex<int>* source) {
    vector<Vertex<int>*> vertexSet = this->getVertexSetOfVertex(source);

    for(auto v : this->graph.getVertexSet()){
        auto it = find(vertexSet.begin(), vertexSet.end(), v);
        if(it == vertexSet.end()){
            double lat_1 = this->vertex_map_coordinates[source->getInfo()].second;
            double long_1 = this->vertex_map_coordinates[source->getInfo()].first;
            double lat_2 = this->vertex_map_coordinates[v->getInfo()].second;
            double long_2 = this->vertex_map_coordinates[v->getInfo()].first;

            double dist = this->calculateDistanceHaverside(lat_1, long_1, lat_2, long_2);
            this->graph.addEdge(source->getInfo(), v->getInfo(), dist);
            this->graph.addEdge(v->getInfo(), source->getInfo(), dist);

            vertexSet.push_back(v);
        }
    }
}

vector<Vertex<int>*> grafos::getVertexSetOfVertex(Vertex<int>* source) {
    vector<Vertex<int>*> res;

    for(auto e : source->getAdj()){
        res.push_back(e->getDest());
    }

    res.push_back(source);

    return res;
}

double grafos::backtrackingAlgorithm(int source, vector<int> &path, chrono::duration<double> &time) {
    auto start = chrono::high_resolution_clock::now();
    this->resetStatus();

    Vertex<int>* v = this->graph.findVertex(source);
    v->setVisited(true);

    vector<int> current_path (this->graph.getVertexSet().size());
    current_path[0] = v->getInfo();

    double res = numeric_limits<double>::max();
    auxBacktrackingAlgorithm(v, v, current_path, res, 0, 1, path);

    path.push_back(path[0]);
    auto finish = chrono::high_resolution_clock::now();
    time = finish - start;

    return res;
}

void grafos::auxBacktrackingAlgorithm(Vertex<int>* v_src, Vertex<int>* vertex, vector<int> &current_path, double &res, double cost_now, int count, vector<int> &path) {
    Edge<int>* edge;
    bool check = this->checkEdge(vertex, v_src, edge);
    if(count == this->graph.getVertexSet().size() && check){
       double cost = cost_now + edge->getWeight();
       if(cost < res){
           res = cost;
           path = current_path;
       }

       return;
    }

    for(auto v : this->graph.getVertexSet()){
        check = this->checkEdge(vertex, v, edge);
        if(!v->isVisited() && check){
            v->setVisited(true);
            cost_now += edge->getWeight();
            current_path[count] = v->getInfo();

            if(cost_now < res){
                auxBacktrackingAlgorithm(v_src, v, current_path, res, cost_now, count + 1, path);
            }

            cost_now -= edge->getWeight();
            v->setVisited(false);
        }
    }

}

bool grafos::checkEdge(Vertex<int>* vertex, Vertex<int>* dest, Edge<int>* &edge) {
    for(auto e : vertex->getAdj()){
        if(e->getDest() == dest){
            edge = e;
            return true;
        }
    }
    return false;
}

//2.2 - Triangular Approximation Heuristic

double grafos::triangularApproximationHeuristic(int src, vector<int> &path, chrono::duration<double> &time){
    auto start = chrono::high_resolution_clock::now();
    this->resetStatus();

    Vertex<int>* source = this->graph.findVertex(src);
    double res = 0;

    Vertex<int>* v_current = source;
    v_current->setVisited(true);

    path.push_back(v_current->getInfo());

    while(path.size() < this->graph.getVertexSet().size()){
        double min_cost = numeric_limits<double>::max();
        Vertex<int>* v_next = nullptr;

        for(auto e : v_current->getAdj()){
            if((e->getWeight() < min_cost) && !e->getDest()->isVisited()){
                min_cost = e->getWeight();
                v_next = e->getDest();
            }
        }

        if(v_next != nullptr) {
            v_next->setVisited(true);
            path.push_back(v_next->getInfo());
            res += min_cost;
            v_current = v_next;
        }
    }

    Edge<int>* edge;
    if(this->checkEdge(v_current, source, edge)){
        res += edge->getWeight();
    }

    path.push_back(source->getInfo());

    auto finish = chrono::high_resolution_clock::now();
    time = finish - start;

    return res;
}

void grafos::commanderTriangularApprox(){
    for(auto v : this->graph.getVertexSet()){
        triangularApprox(v);
    }
}

void grafos::triangularApprox(Vertex<int>* source) {
    for(auto e : source->getAdj()){
        double min = findMinLongTrianhularPath(source, e->getDest());
        if(min < e->getWeight()){
            e->setWeight(min);
        }
    }
}

double grafos::findMinLongTrianhularPath(Vertex<int>* source, Vertex<int>* dest){
    double res = numeric_limits<double>::max();
    for(auto v : this->graph.getVertexSet()){
        if(v->getInfo() != source->getInfo() && v->getInfo() != dest->getInfo()){
            double aux = findLongTrianhularPath(source, v, dest);
            if(aux < res){
                res = aux;
            }
        }
    }
    return res;
}

double grafos::findLongTrianhularPath(Vertex<int>* source, Vertex<int>* longVertex, Vertex<int>* dest) {
    double res = 0;
    for(auto e : source->getAdj()){
        if(e->getDest()->getInfo() == longVertex->getInfo()){
            res += e->getWeight();
            break;
        }
    }
    for(auto e : longVertex->getAdj()){
        if(e->getDest()->getInfo() == dest->getInfo()){
            res += e->getWeight();
            break;
        }
    }
    return res;
}

double grafos::lowerBoundCommander(bool flag, chrono::duration<double> &time){
    if(!flag){
        auto start = chrono::high_resolution_clock::now();
        vector<Vertex<int>*> mst = this->prim();
        double primCost = this->primTotalCost(mst);

        auto finish = chrono::high_resolution_clock::now();
        time = finish - start;
        return primCost;
    }

    auto start = chrono::high_resolution_clock::now();
    double res = 0;
    vector<int> all_vertex;

    for(auto v : this->graph.getVertexSet()){
        all_vertex.push_back(v->getInfo());
    }

    for(auto v : all_vertex){
        Vertex<int>* vertex = this->graph.findVertex(v);

        save_vertex sv;
        sv.save(vertex);
        this->graph.removeVertex(v);

        vector<Vertex<int>*> mst = this->prim();
        double primCost = this->primTotalCost(mst);

        sv.restore(this->graph);

        double t = this->maxWeightOneTree(sv.v, primCost);
        if(t > res){
            res = t;
        }
    }

    auto finish = chrono::high_resolution_clock::now();
    time = finish - start;

    return res;
}

double grafos::maxWeightOneTree(int src, double primCost){
    Vertex<int>* vertex = this->graph.findVertex(src);

    double min_edge_1 = numeric_limits<double>::infinity();
    double min_edge_2 = numeric_limits<double>::infinity();

    for (auto& edge : vertex->getAdj()) {
        if (edge->getWeight() < min_edge_1){
            min_edge_2 = min_edge_1;
            min_edge_1 = edge->getWeight();
        } else if (edge->getWeight() < min_edge_2) {
            min_edge_2 = edge->getWeight();
        }
    }
    double res = primCost + min_edge_1 + min_edge_2;

    return res;
}

double grafos::primTotalCost(vector<Vertex<int> *> &path){
    double res = 0;
    for(auto *vertex: path){
        if(vertex->getPath() == nullptr) continue;
        auto w = vertex->getPath()->getOrig();

        for(auto edge: w->getAdj()){
            if(edge->getDest()->getInfo() == vertex->getInfo()){
                res += edge->getWeight();
                break;
            }
        }
    }
    return res;
}

vector<Vertex<int> *> grafos::prim() {
    vector<Vertex<int>* > res;
    MutablePriorityQueue<Vertex<int>> q;

    for(auto v : this->graph.getVertexSet()){
        v->setVisited(false);
        v->setPath(nullptr);
        v->setDist(numeric_limits<double>::infinity());
        q.insert(v);
    }


    Vertex<int> * v = q.extractMin();
    v->setDist(0);
    res.push_back(v);

    while(!q.empty()){
        v->setVisited(true);

        for(auto e : v->getAdj()){
            auto w = e->getDest();

            if(!w->isVisited() && e->getWeight() < w->getDist()){
                w->setDist(e->getWeight());
                w->setPath(e);
                q.decreaseKey(w);
            }
        }

        v = q.extractMin();
        if(v == nullptr){
            break;
        }

        res.push_back(v);
    }

    return res;
}

Graph<int> grafos::convertPrimToGraph(vector<Vertex<int> *> mst) {
    Graph<int> res;
    for(auto v : mst){
        res.addVertex(v->getInfo());
    }

    for(auto v : mst){
        if(v->getPath() != nullptr){
            res.addEdge(v->getPath()->getOrig()->getInfo(), v->getInfo(), v->getPath()->getWeight());
            res.addEdge(v->getInfo(), v->getPath()->getOrig()->getInfo(), v->getPath()->getWeight());
        }
    }

    return res;
}



double grafos::christofidesAlgorithm(std::vector<int> &path, std::chrono::duration<double> &time){
    double res = 0;
    auto start = chrono::high_resolution_clock::now();

    //Step 1: calculate the minimum spanning tree using Prim's algorithm
    vector<Vertex<int>*> mst = this->prim();
    Graph<int> g_mst = this->convertPrimToGraph(mst);

    //Step 2: create a vector with the odd degree vertex of the mst
    vector<Vertex<int>*> odd_degree_vertex = this->oddDegreeVertices(mst, g_mst);

    //Step 3: create a subgraph with the odd degree vertex
    vector<Edge<int>*> minimum_weight_matching = this->minimumWeightMatching(odd_degree_vertex);

    //Step 4: combine the subgraph with the mst (multigraph)
    Graph<int> multigraph = this->createMultiGraph(minimum_weight_matching, g_mst);

    //Step 5: form an eulerian circuit of the multigraph
    Graph<int> multigraph_copy = this->copyGraph(multigraph);
    vector<int> eulerian_circuit = this->eulerianCircuit(multigraph_copy);

    //Step 6: form a hamiltonian circuit from the eulerian circuit
    path = this->hamiltonianCircuit(eulerian_circuit, multigraph);

    this->twoOptImprovement(path);
    //this->threeOptImprovement(path);

    res = this->calculatePathCost(path);

    auto finish = chrono::high_resolution_clock::now();
    time = finish - start;
    return res;
}

vector<Vertex<int>*> grafos::oddDegreeVertices(vector<Vertex<int>*> mst, Graph<int> g){
    vector<Vertex<int>*> res;
    for(auto v : mst){
        Vertex<int>* vertex = g.findVertex(v->getInfo());
        int out_degree = vertex->getAdj().size();
        if(out_degree % 2 != 0){
            res.push_back(v);
        }
    }
    return res;
}

vector<Edge<int>*> grafos::minimumWeightMatching(vector<Vertex<int>*> oddDegreeVertices){
    vector<Edge<int>*> res;

    while(!oddDegreeVertices.empty()){
        Vertex<int>* v = oddDegreeVertices.back();
        oddDegreeVertices.pop_back();

        double min_w = numeric_limits<double>::infinity();
        Edge<int>* edge_min;
        Vertex<int>* vertex_min;

        for(auto w : oddDegreeVertices){
            Edge<int>* v_w_edge;
            bool check = checkEdge(v, w, v_w_edge);

            if(check && v_w_edge->getWeight() < min_w){
                min_w = v_w_edge->getWeight();
                edge_min = v_w_edge;
                vertex_min = w;
            }
        }

        if(edge_min != nullptr){
            res.push_back(edge_min);
            oddDegreeVertices.erase(find(oddDegreeVertices.begin(), oddDegreeVertices.end(), vertex_min));
        }
    }
    return res;
}

Graph<int> grafos::createMultiGraph(vector<Edge<int>*> edges, Graph<int> g){
    for(auto e : edges){
        if(!this->checkEdge(e->getOrig()->getInfo(), e->getDest()->getInfo(), g)){
            g.addEdge(e->getOrig()->getInfo(), e->getDest()->getInfo(), e->getWeight());
            g.addEdge(e->getDest()->getInfo(), e->getOrig()->getInfo(), e->getWeight());
        }
    }

    return g;
}

vector<int> grafos::eulerianCircuit(Graph<int> &multigraph){
    vector<int> res;

    stack<Vertex<int>*> circuit_current;
    Vertex<int>* v_current = multigraph.findVertex(0);

    circuit_current.push(v_current);

    while(!circuit_current.empty()){
        if(!v_current->getAdj().empty()){
            circuit_current.push(v_current);
            Vertex<int>* v_next = v_current->getAdj().back()->getDest();

            multigraph.removeEdge(v_current->getInfo(), v_next->getInfo());
            multigraph.removeEdge(v_next->getInfo(), v_current->getInfo());

            v_current = v_next;
        }
        else{
            res.push_back(v_current->getInfo());

            v_current = circuit_current.top();
            circuit_current.pop();
        }
    }

    reverse(res.begin(), res.end());

    return res;
}

vector<int> grafos::hamiltonianCircuit(vector<int> &eulerianCircuit, Graph<int> &multigraph){
    vector<int> res;

    for(auto v : eulerianCircuit){
        Vertex<int>* vertex = multigraph.findVertex(v);
        if(!vertex->isVisited()){
            res.push_back(v);
            vertex->setVisited(true);
        }
    }

    res.push_back(res[0]);

    return res;
}

double grafos::calculatePathCost(vector<int> &path){
    double res = 0;
    for(int i = 0; i < path.size() - 1; i++){
        Vertex<int>* v = this->graph.findVertex(path[i]);
        for(auto e : v->getAdj()){
            if(e->getDest()->getInfo() == path[i + 1]){
                res += e->getWeight();
                break;
            }
        }
    }
    return res;
}

//2-opt improvement
void grafos::twoOptImprovement(vector<int> &path){
    bool flag = true;

    while(flag){
        flag = false;
        for(int i = 0; i < path.size() - 2; ++i){
            for(int j = i + 2; j < path.size(); ++j){

                double possivel_edge_cost = edgeCost(path[i], path[j]) + edgeCost(path[i + 1], path[j + 1]);
                double actual_edge_cost = edgeCost(path[i], path[i + 1]) + edgeCost(path[j], path[j + 1]);

                if(possivel_edge_cost < actual_edge_cost){
                    flag = true;
                    reverse(path.begin() + i + 1, path.begin() + j + 1);
                }
            }
        }
    }
}

void grafos::threeOptImprovement(vector<int> &path){
    bool flag = true;

    while(flag){
        flag= false;

        for(int i = 0; i < path.size() - 3; ++i){
            for(int j = i + 2; j < path.size() - 1; ++j){
                for(int k = j + 2; k < path.size(); ++k){

                    double possivel_edge_cost = edgeCost(path[i], path[j]) + edgeCost(path[i + 1], path[k]) + edgeCost(path[j + 1], path[k + 1]);
                    double actual_edge_cost = edgeCost(path[i], path[i + 1]) + edgeCost(path[j], path[j + 1]) + edgeCost(path[k], path[k + 1]);

                    if(possivel_edge_cost < actual_edge_cost){
                        flag = true;
                        reverse(path.begin() + i + 1, path.begin() + j + 1);
                        reverse(path.begin() + j + 1, path.begin() + k + 1);
                    }
                }
            }
        }
    }
}

double grafos::edgeCost(int src, int dest){
    Vertex<int>* v = this->graph.findVertex(src);
    for(auto e : v->getAdj()){
        if(e->getDest()->getInfo() == dest){
            return e->getWeight();
        }
    }
    return numeric_limits<double>::infinity();
}

//2.4 - Is Connected

bool grafos::isConnected(){
    auto vec = this->graph.dfs();

    for(auto v : this->graph.getVertexSet()){
        if(!v->isVisited()){
            return false;
        }
    }
    return true;
}

double grafos::realTriangularApproximationHeuristic(int src, std::vector<int> &path,
                                                    std::chrono::duration<double> &time) {
    bool canBeDone = this->isConnected();
    if(canBeDone){
        return this->triangularApproximationHeuristic(src, path, time);
    }

    return -1;
}


