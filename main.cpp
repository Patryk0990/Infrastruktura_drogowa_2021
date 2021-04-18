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
    setlocale(LC_ALL, "pl_PL"); //Deklaracja polskich znaków
    string input, output; //Zmienne przechowuj¹ce œcie¿kê dostêpu do plików

    if (ManageFlags(argc, argv, input, output) == 2) {

        vector < vector <double>> routesGraph; //Graf w postaci macierzy s¹siedztwa przedstawiaj¹cy strukturê dróg
        vector <string> cities; // Wektor "s³ownik" nazw miast

        if (ReadData(input, routesGraph, cities) == 2) {

            vector <Route> routes; //Wektor struktur przechowuj¹cy pozycjê drogi w grafie, która zosta³a wybrana

            ChooseRoutes(routes, routesGraph, cities);
            SaveResults(output, routes);
        }
    }

}
