//
// Created by pchmelo on 05-05-2024.
//

#include <set>
#include "menu.h"


using namespace std;
grafos Menu::selectedGraph;
double Menu::lowerBound;
vector<int> path;
std::chrono::duration<double> elapsed_time;
double res;
chrono::duration<double>  timeTriangular;
chrono::duration<double>  timeHeuristic;
string type;

void Menu::Terminal() {
    Functions::printLogo();

    cout << "\033[1;34mPlease choose your desired graph:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " Toy Graphs" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Extra Fully Connected Graphs" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " Real Graphs" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Exit" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;

    if((decision_1 < "0") || (decision_1 > "3")){
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
                RealMenu();
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
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;

    if((decision_1 < "0") || (decision_1 > "3")){
        cout << "INVALID OPTION! \n";
        ToyMenu();
    }

    decision = stoi(decision_1);
    type = "small";
    selectedGraph.readGraph(decision, type);
    SubMenu(type);
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
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;

    set<string> validOptions = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};

    if(validOptions.find(decision_1) == validOptions.end()){
        cout << "INVALID OPTION! \n";
        ExtraMenu();
    }

    type = "extra";
    decision = stoi(decision_1);
    selectedGraph.readGraph(decision, type);
    selectedGraph.checkGraph(type);
    lowerBound = selectedGraph.lowerBoundCommander(false, elapsed_time);
    Functions::printLowerBound(lowerBound, elapsed_time);
    SubMenu(type);
}

void Menu::RealMenu() {
    Functions::printLogo();

    cout << "\033[1;34mPlease choose your desired graph:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " graph1" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " graph2" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " graph3" << endl;
    cout << "\033[1;36m[ 4 ]\033[0m" << " Pratical example" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;

    if((decision_1 < "0") || (decision_1 > "4")){
        cout << "INVALID OPTION! \n";
        RealMenu();
    }

    decision = stoi(decision_1);
    if(decision == 4){
        type = "small";
        selectedGraph.readGraph(decision, type);
    }else {
        type = "real";
        selectedGraph.readGraph(decision, type);
    }
    Graph<int> g = selectedGraph.graph;
    SubMenuReal();
}

void Menu::SubMenu(string type) {
    Functions::printLogo();

    cout << "\033[1;34mPlease choose your desired option:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " Backtracking Algorithm" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Triangular Approximation Heuristic" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " Other Heuristics" << endl;
    cout << "\033[1;36m[ 4 ]\033[0m" << " Change Your Graph" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Exit" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;

    if((decision_1 < "0") || (decision_1 > "4")){
        cout << "INVALID OPTION! \n";
        SubMenu(type);
    }

    decision = stoi(decision_1);

    while (true) {
        switch (decision) {
            case 1:
            {
                path.clear();
                res = selectedGraph.backtrackingAlgorithm(0, path, elapsed_time);
                Functions::printResultsOptimal(path, res, elapsed_time);
                SubMenu(type);
                break;
            }
            case 2:
                if(type == "small") {
                    selectedGraph.checkGraph(type);
                    lowerBound = selectedGraph.lowerBoundCommander(false, elapsed_time);
                    Functions::printLowerBound(lowerBound, elapsed_time);
                    cout << endl;
                }
                //selectedGraph.commanderTriangularApprox(); //demora demasiado tempo a partir do choice 5

                path.clear();
                cout << endl;
                res = selectedGraph.triangularApproximationHeuristic(0, path, elapsed_time);
                Functions::printResultsHeuristic(path, res, elapsed_time, lowerBound);
                SubMenu(type);
                break;
            case 3: {
                //selectedGraph.commanderTriangularApprox();

                path.clear();

                double res_2 = selectedGraph.triangularApproximationHeuristic(0, path, elapsed_time);
                timeTriangular = elapsed_time;
                double res_3 = selectedGraph.christofidesAlgorithm(path, elapsed_time);
                timeHeuristic = elapsed_time;
                Functions::printResultsHeuristic(path, res_3, elapsed_time, lowerBound);
                cout << endl;
                cout << "Efficiency Stats: " << endl;
                cout << "Triangular Heuristic Algorithm result: " << res_2 << endl;
                cout << "Other Heuristic Algorithm result: " << res_3 << endl;
                cout << "New Algorithm is " << res_2 / res_3 << "x more efficient than the Triangular Heuristic Algorithm" << endl;
                cout << endl;
                cout << "Time Stats: " << endl;
                cout << "Triangular Heuristic Algorithm time: " << timeTriangular.count() << endl;
                cout << "Other Heuristic Algorithm time: " << timeHeuristic.count() << endl;
                if(timeHeuristic / timeTriangular > 1) {
                    cout << "Triangular Heuristic Algorithm is " << timeHeuristic / timeTriangular << "x faster than the New Algorithm" << endl;
                } else {
                    cout << "New Algorithm is " << timeTriangular / timeHeuristic << "x faster than the Triangular Heuristic Algorithm" << endl;
                }
                SubMenu(type);
                break;
            }
            case 4:
                Functions::resetGraph(selectedGraph);
                Terminal();
                break;
            default:
                break;
        }

        return;
    }
}

void Menu::SubMenuReal() {
    Functions::printLogo();

    cout << "\033[1;34mPlease choose your desired option:\033[0m\n";
    cout << "\033[1;36m[ 1 ]\033[0m" << " Triangular Approximation Heuristic" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Other Heuristics" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " TSP in the Real World" << endl;
    cout << "\033[1;36m[ 4 ]\033[0m" << " Change Your Graph" << endl;
    cout << "\033[1;31m[ 0 ]\033[0m" << " Exit" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;

    if((decision_1 < "0") || (decision_1 > "4")){
        cout << "INVALID OPTION! \n";
        SubMenuReal();
    }

    decision = stoi(decision_1);

    while (true) {
        switch (decision) {
            case 1:
                selectedGraph.checkGraph("real");
                lowerBound = selectedGraph.lowerBoundCommander(false, elapsed_time);
                Functions::printLowerBound(lowerBound, elapsed_time);
                cout << endl;
                //selectedGraph.commanderTriangularApprox(); //demora demasiado tempo a partir do choice 5

                path.clear();
                cout << endl;
                res = selectedGraph.triangularApproximationHeuristic(0, path, elapsed_time);
                Functions::printResultsHeuristic(path, res, elapsed_time, lowerBound);
                SubMenuReal();
                break;
            case 2: {
                selectedGraph.checkGraph("real");
                lowerBound = selectedGraph.lowerBoundCommander(false, elapsed_time);
                Functions::printLowerBound(lowerBound, elapsed_time);
                cout << endl;
                //selectedGraph.commanderTriangularApprox();

                path.clear();

                double res_2 = selectedGraph.triangularApproximationHeuristic(0, path, elapsed_time);
                timeTriangular = elapsed_time;
                double res_3 = selectedGraph.christofidesAlgorithm(path, elapsed_time);
                timeHeuristic = elapsed_time;
                Functions::printResultsHeuristic(path, res_3, elapsed_time, lowerBound);
                cout << endl;
                cout << "Efficiency Stats: " << endl;
                cout << "Triangular Heuristic Algorithm result: " << res_2 << endl;
                cout << "Other Heuristic Algorithm result: " << res_3 << endl;
                cout << "New Algorithm is " << res_2 / res_3 << "x more efficient than the Triangular Heuristic Algorithm" << endl;
                cout << endl;
                cout << "Time Stats: " << endl;
                cout << "Triangular Heuristic Algorithm time: " << timeTriangular.count() << endl;
                cout << "New Algorithm time: " << timeHeuristic.count() << endl;
                if(timeHeuristic / timeTriangular > 1) {
                    cout << "Triangular Heuristic Algorithm is " << timeHeuristic / timeTriangular << "x faster than the New Algorithm" << endl;
                } else {
                    cout << "New Algorithm is " << timeTriangular / timeHeuristic << "x faster than the Triangular Heuristic Algorithm" << endl;
                }
                SubMenuReal();
                break;
            }
            case 3:
                SubMenuRealTSP();
                break;
            case 4:
                Functions::resetGraph(selectedGraph);
                Terminal();
                break;
            default:
                break;
        }

        return;
    }
}

void Menu::SubMenuRealTSP() {
    Functions::printLogo();
    int tamanho = selectedGraph.graph.getVertexSet().size();
    cout << "\033[1;34mPlease choose your desired starting point:\033[0m\n";
    cout << "\033[1;34mYour choice must be an integer between 0 and " << tamanho-1 << "\033[0m\n";
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    string decision_1;
    int decision;
    cin >> decision_1;
    cout << endl;

    try {
        decision = std::stoi(decision_1);
        if(decision < 0 || decision > tamanho - 1){
            std::cout << "Invalid input. Please enter an integer between 0 and " << tamanho - 1 << ".\n";
            SubMenuRealTSP();
        }
    } catch (std::invalid_argument& e) {
        // If here, then decision_1 is not an integer.
        std::cout << "Invalid input. Please enter an integer.\n";
        SubMenuRealTSP();
    }
    path.clear();
    if(res == -1){
        cout << "Graph is not connected!" << endl;
        SubMenuReal();
    }else{
        vector<int> notVisited;
        lowerBound = selectedGraph.lowerBoundCommander(false, elapsed_time);
        res = selectedGraph.triangularApproximationHeuristicReal(decision,path, elapsed_time);
        bool flag = selectedGraph.checkerPath(path, notVisited);
        Functions::printResultsHeuristic(path, res, elapsed_time, lowerBound);
        SubMenuReal();
    }
}