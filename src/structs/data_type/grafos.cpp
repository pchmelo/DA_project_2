//
// Created by pchmelo on 27-04-2024.
//

#include "grafos.h"
#include "fstream"
#include "sstream"
#include "vector"

using namespace std;

void grafos::resetStatus() {
    for(auto v : this->graph.getVertexSet()){
        v->setVisited(false);
    }
}

void grafos::addAllEdge(int choice, string type) {
    int max = 0;

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
    }
    else if(type == "extra"){
        if(choice == 1){
            max = 25;
        }
        else if(choice == 2){
            max = 50;
        }
        else if(choice == 3){
            max = 75;
        }
        else if(choice == 4){
            max = 100;
        }
        else if(choice == 5){
            max = 200;
        }
        else if(choice == 6){
            max = 300;
        }
        else if(choice == 7){
            max = 400;
        }
        else if(choice == 8){
            max = 500;
        }
        else if(choice == 9){
            max = 600;
        }
        else if(choice == 10){
            max = 700;
        }
        else if(choice == 11){
            max = 800;
        }
        else if(choice == 12){
            max = 900;
        }
    }

    for(int i = 0; i < max; i++){
        this->graph.addVertex(i);
    }
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

void grafos::checkGraph() {
    int size = this->graph.getVertexSet().size() - 1;

    for(auto v : this->graph.getVertexSet()){
        if(v->getAdj().size() != size){
            normalizeGraph(v);
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




