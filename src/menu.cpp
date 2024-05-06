//
// Created by pchmelo on 05-05-2024.
//

#include "menu.h"


using namespace std;
grafos Menu::selectedGraph;
double Menu::lowerBound;
vector<int> path;
std::chrono::duration<double> elapsed_time;
double res;

void Menu::Terminal() {
    Functions::printLogo();

    cout << "\033[1;34mPlease choose your desired graph:\033[0m\n";
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
                ToyMenu();
                break;
            case 2:
                ExtraMenu();
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

void Menu::ToyMenu() {
    Functions::printLogo();

    cout << "\033[1;34mPlease choose your desired file:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " shipping.csv" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " stadiums.csv" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " tourism.csv" << endl;
    cout << "\033[1;36m[ 4 ]\033[0m" << " Ambiente Teste" << endl;
    cout << "\033[1;36m[ 5 ]\033[0m" << " Change Your Graph" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Exit" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;

    if((decision_1 < "0") || (decision_1 > "5")){
        cout << "INVALID OPTION! \n";
        ToyMenu();
    }

    decision = stoi(decision_1);

    selectedGraph.readGraph(decision, "small");
    selectedGraph.checkGraph("small");
    lowerBound = selectedGraph.lowerBoundCommander(true, elapsed_time);
    SubMenu();
}

void Menu::ExtraMenu() {
    Functions::printLogo();

    cout << "\033[1;34mPlease choose your desired number of nodes:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " 25 nodes" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " 50 nodes" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " 75 nodes" << endl;
    cout << "\033[1;36m[ 4 ]\033[0m" << " 100 nodes" << endl;
    cout << "\033[1;36m[ 5 ]\033[0m" << " 200 nodes" << endl;
    cout << "\033[1;36m[ 6 ]\033[0m" << " 300 nodes" << endl;
    cout << "\033[1;36m[ 7 ]\033[0m" << " 400 nodes" << endl;
    cout << "\033[1;36m[ 8 ]\033[0m" << " 500 nodes" << endl;
    cout << "\033[1;36m[ 9 ]\033[0m" << " 600 nodes" << endl;
    cout << "\033[1;36m[ 10 ]\033[0m" << " 700 nodes" << endl;
    cout << "\033[1;36m[ 11 ]\033[0m" << " 800 nodes" << endl;
    cout << "\033[1;36m[ 12 ]\033[0m" << " 900 nodes" << endl;
    cout << "\033[1;36m[ 13 ]\033[0m" << " Ambiente de Teste" << endl;
    cout << "\033[1;36m[ 14 ]\033[0m" << " Change Your Graph" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Exit" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;

    /*ESTE IF ESTÁ A DAR ERRO PARA NÚMEROS >= 2
    if((decision_1 < "0") || (decision_1 > "14")){
        cout << "INVALID OPTION! \n";
        ExtraMenu();
    }
    */

    decision = stoi(decision_1);

    selectedGraph.readGraph(decision, "extra");
    selectedGraph.checkGraph("extra");
    lowerBound = selectedGraph.lowerBoundCommander(true, elapsed_time);
    SubMenu();
}

void Menu::SubMenu() {
    Functions::printLogo();

    cout << "\033[1;34mPlease choose your desired option:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " Backtracking Algorithm" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Triangular Approximation Heuristic" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " Other Heuristics" << endl;
    cout << "\033[1;36m[ 4 ]\033[0m" << " Ambiente Teste" << endl;
    cout << "\033[1;36m[ 5 ]\033[0m" << " Change Your Graph" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Exit" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;

    if((decision_1 < "0") || (decision_1 > "5")){
        cout << "INVALID OPTION! \n";
        Terminal();
    }

    decision = stoi(decision_1);

    while (true) {
        switch (decision) {
            case 1:
            {
                path.clear();
                res = selectedGraph.backtrackingAlgorithm(0, path, elapsed_time);
                Functions::printResultsOptimal(path, res, elapsed_time);
                SubMenu();
                break;
            }
            case 2:
                selectedGraph.commanderTriangularApprox();

                path.clear();
                Functions::printLowerBound(lowerBound, elapsed_time);
                cout << endl;
                res = selectedGraph.triangularApproximationHeuristic(0, path, elapsed_time);
                Functions::printResultsHeuristic(path, res, elapsed_time, lowerBound);
                SubMenu();
                break;
            case 3:
                break;
            case 4:
                AmbienteTeste();
                break;
            case 5:
                Terminal();
                break;
            default:
                break;
        }

        return;
    }
}

void Menu::AmbienteTeste() {
    cout << "Welcome to the Test Environment!" << endl;
    int choice = 2;
    string type = "small";

    grafos g;
    g.readGraph(choice, type);
    g.checkGraph(type);

    auto vec = g.prim();
    auto n_g = g.convertPrimToGraph(vec);
    int i = 10;
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
    double lowerBound = g.lowerBoundCommander(true, time);
    Functions::printLowerBound(lowerBound, time);
    cout << endl;

    double res = g.backtrackingAlgorithm(0, path, time);
    //int i = 10;
    Functions::printResultsOptimal(path, res, time);

    //double res = g.backtrackingAlgorithm(0, path, time);
    //Functions::printResultsOptimal((path, res, time);


    //g.checkGraph();

    //2.2
    g.commanderTriangularApprox();
    //Functions::printGraph(g);

    /*
    cout << endl;
    path.clear();
    v = g.graph.findVertex(0);


    double lowerBound = g.lowerBoundCommander(true, time); !
    Functions::printLowerBound(lowerBound, time);
    cout << endl;

    double res = g.triangularApproximationHeuristic(0, path, time);
    Functions::printResultsHeuristic(path, res, time, lowerBound);
    */

    //double res = g.christofidesAlgorithm(path, time);
    //Functions::printResultsHeuristic(path, res, time, lowerBound);

    exit(0);
}