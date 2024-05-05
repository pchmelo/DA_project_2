//
// Created by pchmelo on 27-04-2024.
//

#include "grafos.h"
#include "fstream"
#include "sstream"
#include "vector"

using namespace std;

void grafos::addAllEdge(int choice) {
    int max = 0;

    if(choice == 1){
        max = 13;
    }
    else if(choice == 2){
        max = 10;
    }
    else if(choice == 3){
        max = 4;
    }

    for(int i = 0; i <= max; i++){
        this->graph.addVertex(i);
    }
}

void grafos::readGraph(int choice) {
    this->addAllEdge(choice);

    string input = "";
    if(choice == 1){
        input = "../src/Data/Toy-Graphs/shipping.csv";
    }
    else if(choice == 2){
        input = "../src/Data/Toy-Graphs/stadiums.csv";
    }
    else if(choice == 3){
        input = "../src/Data/Toy-Graphs/tourism.csv";
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
