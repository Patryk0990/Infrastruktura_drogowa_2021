using namespace std;

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <limits>

#include "structures.h"
#include "functions.h"

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "pl_PL"); //Deklaracja polskich znak�w
    string input, output; //Zmienne przechowuj�ce �cie�k� dost�pu do plik�w

    if (ManageFlags(argc, argv, input, output) == 2) {

        vector < vector <double>> routesGraph; //Graf w postaci macierzy s�siedztwa przedstawiaj�cy struktur� dr�g
        vector <string> cities; // Wektor "s�ownik" nazw miast

        if (ReadData(input, routesGraph, cities) == 2) {

            vector <Route> routes; //Wektor struktur przechowuj�cy pozycj� drogi w grafie, kt�ra zosta�a wybrana

            ChooseRoutes(routes, routesGraph, cities);
            SaveResults(output, routes);
        }
    }

}
