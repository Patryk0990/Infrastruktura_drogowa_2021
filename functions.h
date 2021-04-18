#pragma once

/** Zwraca tre�� dla danego kodu b��du w wybranych funkcjach.
*
* @param[in] fnName Nazwa funkcji wywo�uj�cej zarz�dzanie b��dami
* @param[in] code Numer kodu b��du
*/
void ErrorHandler(const char* fnName, const int code);

/** Sprawdza wprowadzone argumentu programu.
* W przypadku znalezienia prawid�owych argument�w przypisuje ich warto�� do zmiennych programu input, output.
*
* @param[in] argc Ilo�� argument�w
* @param[in] argv[] Tablica z argumentami
* @param[in,out] input Przechowuje �cie�k� do pliku z danymi
* @param[in,out] output Przechowuje �cie�k� do pliku wyj�ciowego
* @return Zwraca kod b��du
*/
int ManageFlags(const int argc, char* argv[], string& input, string& output);

/** Sprawdza czy napis nie zawiera liczb.
*
* @param[in] s Napis do sprwadzenia
* @return Zwraca warto�� boolean w zale�no�ci od wyniku sprawdzania
*/
bool IsAlphabetic(const string& s);

/** Dodaje miasta do wektora, kt�rych jeszcze w nim nie ma.
*
* @param[in,out] cities Wektor pe�ni�cy role s�ownika dla miast
* @param[in] city Nazwa miasta
* @return Zwraca pozycj� miasta podanego w argumentach funkcji
*/
int AddCities(vector <string>& cities, const string city);

/** Zwraca cen� budowy danej drogi na podstawie pozycji miast w "s�owniku".
*
* @param[in] a Pozycja w grafie
* @param[in] b Pozycja w grafie
* @return Zwraca najwi�ksza pozycj�
*/
int GetHighestValue(const int& a, const int& b);

/** Wype�nia graf warto�ciami (0 domy�lnie, dla pozycji [x][y] oraz [x][y] cen� danej drogi)
* @param[in] x Pozycja w grafie
* @param[in] x Pozycja w grafie
* @param[in] price Cena danej drogi w pozycji [x][y]
* @param[in,out] routesGraph Graf w postaci macierzy s�siedztwa przedstawiaj�cy struktur� dr�g
*/
void FillGraph(const int& x, const int& y, const double& price, vector <vector <double>>& routesGraph);

/** Pobiera dane z pliku i na ich podstawie tworzy graf.
*
* @param[in] fName Nazwa pliku do odczytu
* @param[in,out] routes Wektor struktur dr�g
* @param[in,out] routesGraph Graf w postaci macierzy s�siedztwa przedstawiaj�cy struktur� dr�g
* @param[in,out] cities Wektor "s�ownik" nazw miast
* @return Zwraca kod b��du
*/
int ReadData(const string& fName, vector <vector <double>>& routesGraph, vector <string>& cities);

/** Tworzy wektor struktur na podstawie grafu.
*
* @param[in,out] routes Wektor struktur Routes, w kt�rych przechowywane s� wybrane drogi
* @param[in,out] routesGraph Graf w postaci macierzy s�siedztwa przedstawiaj�cy struktur� dr�g
* @param[in] cities Wektor "s�ownik" nazw miast
*/
void ChooseRoutes(vector <Route>& routes, vector <vector <double>>& routesGraph, const vector <string>& cities);

/** Zapisuje wektor struktur do pliku.
*
* @param[in] fName Nazwa pliku do zapisu
* @param[in,out] routes Wektor struktur dr�g
* @return Zwraca kod b��du
*/
int SaveResults(const string& fName, vector <Route> routes);