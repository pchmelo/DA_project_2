#include <iostream>
#include "structs/data_type/grafos.h"

using namespace std;

int main(){
    cout << "Hello World!" << endl;
    int choice = 1;

    grafos g;
    g.readGraph(choice);
    g.checkGraph();

    int i = 0;

    for(auto v : g.graph.getVertexSet()){
        cout << "Vertex: " << i << endl;
        for(auto e : v->getAdj()){
            cout << "Orig: " << e->getOrig()->getInfo() << " Dest: " << e->getDest()->getInfo() << " Dist: " << e->getWeight() <<endl;
        }
        cout << endl;
        i++;
    }


    return 0;
}
