//
// Created by pchmelo on 05-05-2024.
//

#include "menu.h"


using namespace std;

void Menu::Terminal() {
    Functions::printLogo();

    cout << "\033[1;34mPlease choose your desired grapth:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " Toy Graphs" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Extra Fully Connected Graphs" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " Real Graphs" << endl;
    cout << "\033[1;36m[ 4 ]\033[0m" << " Ambiente Teste" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Exit" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;

    if((decision_1 < "0") || (decision_1 > "4")){
        cout << "INVALID OPTION! \n";
        Terminal();
    }

    decision = stoi(decision_1);

    while (true) {
        switch (decision) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                AmbienteTeste();
                break;
            default:
                break;
        }

        return;
    }
}

void Menu::AmbienteTeste() {
    cout << "Welcome to the Test Environment!" << endl;
    int choice = 3;
    string type = "extra";

    grafos g;
    g.readGraph(choice, type);
    g.checkGraph(type);

    //g.checkGraphSmall();
    //Functions::printGraph(g);
    //cout << "--------------------------------------" << endl;

    //2.1

    //auto vec = g.prim();
    //double primCost = g.primTotalCost(vec);

    //cout << "Prim Cost is " << primCost << endl;
    //cout << "Lower Bound one tree is "  << g.lowerBoundCommander() << endl;

    vector<int> path;
    auto v = g.graph.findVertex(0);
    std::chrono::duration<double> time;

    //double res = g.backtrackingAlgorithm(0, path, time);
    //int i = 10;
    //Functions::printResultsOptimal((path, res, time);

    //g.checkGraph();

    //2.2
    //g.commanderTriangularApprox();
    //Functions::printGraph(g);


    /*
    cout << endl;
    path.clear();
    v = g.graph.findVertex(0);

    double lowerBound = g.lowerBoundCommander(true, time);
    Functions::printLowerBound(lowerBound, time);
    cout << endl;

    double res = g.triangularApproximationHeuristic(0, path, time);
    Functions::printResultsHeuristic(path, res, time, lowerBound);
    */

    exit(0);
}