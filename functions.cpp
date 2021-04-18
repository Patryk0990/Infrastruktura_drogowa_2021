#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <limits>
#include "structures.h"

using namespace std;

void ErrorHandler(const char* fnName, const int code) {
    if (fnName == "ManageFlags") {
        switch (code) {
        case 0:
            cerr << "----------------------------------------------------------------" << endl;
            cerr << "Podano nieprawid³owe parametry!" << endl;
            cerr << "----------------------------------------------------------------" << endl;

            break;
        case 1:
            cerr << "----------------------------------------------------------------" << endl;
            cerr << "Do poprawdnego dzia³ania programu potrzebne s¹ 2 parametry." << endl;
            cerr << "\"-i\" plik wejœciowy" << endl;
            cerr << "\"-o\" plik_wyjœciowy" << endl;
            cerr << "Przyk³ad prawid³owego wywo³ania programu:" << endl;
            cerr << "infrastruktura_drogowa \"-i\" <plik_wejsciowy> oraz \"-o\" <plik_wyjsciowy>" << endl;
            cerr << "----------------------------------------------------------------" << endl;

            break;
        }
    }
    else if (fnName == "ReadData") {
        switch (code) {
        case 0:
            cerr << "----------------------------------------------------------------" << endl;
            cerr << "Nie znaleziono pliku z danymi." << endl;
            cerr << "----------------------------------------------------------------" << endl;

            break;
        case 1:
            cerr << "----------------------------------------------------------------" << endl;
            cerr << "Dane zosta³y wprowadzone w niepoprawnym formacie." << endl;
            cerr << "Schemat danych:" << endl;
            cerr << "Miasto_1 Miasto_2 Koszt_budowy" << endl;
            cerr << "----------------------------------------------------------------" << endl;

            break;
        }
    }
    else if (fnName == "SaveResults") {
        switch (code) {
        case 0:
            cerr << "----------------------------------------------------------------" << endl;
            cerr << "Nie uda³o siê zapisaæ danych." << endl;
            cerr << "----------------------------------------------------------------" << endl;

            break;
        case 1:
            cerr << "----------------------------------------------------------------" << endl;
            cerr << "Dane zosta³y zapisane do pliku." << endl;
            cerr << "----------------------------------------------------------------" << endl;

            break;
        }
    }
}

int ManageFlags(const int argc, char* argv[], string& input, string& output) {

    int errorCode = 0;

    if (argc == 5) {
        for (int i = 0; i < argc; i++) {
            if (string(argv[i]) == "-i") {
                input = argv[i + 1];
                i++;
            }
            else if (string(argv[i]) == "-o") {
                output = argv[i + 1];
                i++;
            }
        }

        if (!input.empty() && !output.empty()) {
            errorCode = 2;
        }

    }
    else if (((argc == 2) && (string(argv[1]) == "-h")) || (argc == 1)) {
        errorCode = 1;
    }

    ErrorHandler(__func__, errorCode);
    return errorCode;

}

bool IsAlphabetic(const string& s) {

    int i;
    stringstream(s) >> i;

    if (i || s.empty()) {
        return false;
    }
    else {
        return true;
    }

}

int AddCities(vector <string>& cities, const string city) {

    auto Iterator = find(cities.begin(), cities.end(), city);

    if (Iterator != cities.end())
    {
        return distance(cities.begin(), Iterator);
    }
    else
    {
        cities.push_back(city);
        return cities.size() - 1;
    }
}

int GetHighestValue(const int& a, const int& b) {

    if (a > b) return a;
    else return b;

}

void FillGraph(const int& x, const int& y, const double& price, vector <vector <double>>& routesGraph) {

    const int pointer = GetHighestValue(x, y);
    int lastPosition = routesGraph.size() - 1;

    if (pointer > lastPosition) {
        routesGraph.resize(pointer + 1);
        for (int i = 0; i <= pointer; i++) {
            routesGraph[i].resize(pointer + 1);
        }
    }

    routesGraph[x][y] = price;
    routesGraph[y][x] = price;

}

int ReadData(const string& fName, vector <vector <double>>& routesGraph, vector <string>& cities) {

    ifstream dataFile(fName);
    int errorCode = 0;

    if (!dataFile.fail()) {

        string dataLine;

        while (getline(dataFile, dataLine) && errorCode != 1) {

            string city_1, city_2;
            double price;
            stringstream sLine(dataLine);

            sLine >> city_1 >> city_2 >> price;

            if (IsAlphabetic(city_1) && IsAlphabetic(city_2) && (price > 0) && sLine.eof()) {
                int x = AddCities(cities, city_1);
                int y = AddCities(cities, city_2);
                FillGraph(x, y, price, routesGraph);
            }
            else {
                errorCode = 1;
                routesGraph.clear();
            }

        }

        if (errorCode != 1) errorCode = 2;

    }

    dataFile.close();
    ErrorHandler(__func__, errorCode);
    return errorCode;

}

void ChooseRoutes(vector <Route>& routes, vector <vector <double>>& routesGraph, const vector <string>& cities) {

    int citiesAmount = cities.size();

    if (!routesGraph.empty() && citiesAmount > 0) {

        vector <bool> selectedRoutes(citiesAmount, false);
        selectedRoutes[0] = true;

        int x, y;
        int edges = 0;

        while (edges < citiesAmount - 1) {

            x = 0;
            y = 0;

            double min = numeric_limits <double>::max();
            for (int i = 0; i < citiesAmount; i++) {
                if (selectedRoutes[i]) {
                    for (int j = 0; j < citiesAmount; j++) {
                        if (!selectedRoutes[j] && (routesGraph[i][j] > 0)) {
                            if (min > routesGraph[i][j]) {
                                min = routesGraph[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }

            routes.push_back({ cities[x], cities[y], routesGraph[x][y] });

            selectedRoutes[y] = true;
            edges++;
        }
    }

    routesGraph.clear();

}

int SaveResults(const string& fName, vector <Route> routes) {

    ofstream resultFile(fName);
    int errorCode = 0;

    if (!resultFile.fail()) {

        for (auto route : routes) {
            resultFile << route.City_1 << " " << route.City_2 << " " << route.Price << endl;
        }

        errorCode = 1;
    }

    routes.clear();

    resultFile.close();
    ErrorHandler(__func__, errorCode);
    return errorCode;

}