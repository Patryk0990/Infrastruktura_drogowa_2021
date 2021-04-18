#pragma once

/** Zwraca treœæ dla danego kodu b³êdu w wybranych funkcjach.
*
* @param[in] fnName Nazwa funkcji wywo³uj¹cej zarz¹dzanie b³êdami
* @param[in] code Numer kodu b³êdu
*/
void ErrorHandler(const char* fnName, const int code);

/** Sprawdza wprowadzone argumentu programu.
* W przypadku znalezienia prawid³owych argumentów przypisuje ich wartoœæ do zmiennych programu input, output.
*
* @param[in] argc Iloœæ argumentów
* @param[in] argv[] Tablica z argumentami
* @param[in,out] input Przechowuje œcie¿kê do pliku z danymi
* @param[in,out] output Przechowuje œcie¿kê do pliku wyjœciowego
* @return Zwraca kod b³êdu
*/
int ManageFlags(const int argc, char* argv[], string& input, string& output);

/** Sprawdza czy napis nie zawiera liczb.
*
* @param[in] s Napis do sprwadzenia
* @return Zwraca wartoœæ boolean w zale¿noœci od wyniku sprawdzania
*/
bool IsAlphabetic(const string& s);

/** Dodaje miasta do wektora, których jeszcze w nim nie ma.
*
* @param[in,out] cities Wektor pe³ni¹cy role s³ownika dla miast
* @param[in] city Nazwa miasta
* @return Zwraca pozycjê miasta podanego w argumentach funkcji
*/
int AddCities(vector <string>& cities, const string city);

/** Zwraca cenê budowy danej drogi na podstawie pozycji miast w "s³owniku".
*
* @param[in] a Pozycja w grafie
* @param[in] b Pozycja w grafie
* @return Zwraca najwiêksza pozycjê
*/
int GetHighestValue(const int& a, const int& b);

/** Wype³nia graf wartoœciami (0 domyœlnie, dla pozycji [x][y] oraz [x][y] cenê danej drogi)
* @param[in] x Pozycja w grafie
* @param[in] x Pozycja w grafie
* @param[in] price Cena danej drogi w pozycji [x][y]
* @param[in,out] routesGraph Graf w postaci macierzy s¹siedztwa przedstawiaj¹cy strukturê dróg
*/
void FillGraph(const int& x, const int& y, const double& price, vector <vector <double>>& routesGraph);

/** Pobiera dane z pliku i na ich podstawie tworzy graf.
*
* @param[in] fName Nazwa pliku do odczytu
* @param[in,out] routes Wektor struktur dróg
* @param[in,out] routesGraph Graf w postaci macierzy s¹siedztwa przedstawiaj¹cy strukturê dróg
* @param[in,out] cities Wektor "s³ownik" nazw miast
* @return Zwraca kod b³êdu
*/
int ReadData(const string& fName, vector <vector <double>>& routesGraph, vector <string>& cities);

/** Tworzy wektor struktur na podstawie grafu.
*
* @param[in,out] routes Wektor struktur Routes, w których przechowywane s¹ wybrane drogi
* @param[in,out] routesGraph Graf w postaci macierzy s¹siedztwa przedstawiaj¹cy strukturê dróg
* @param[in] cities Wektor "s³ownik" nazw miast
*/
void ChooseRoutes(vector <Route>& routes, vector <vector <double>>& routesGraph, const vector <string>& cities);

/** Zapisuje wektor struktur do pliku.
*
* @param[in] fName Nazwa pliku do zapisu
* @param[in,out] routes Wektor struktur dróg
* @return Zwraca kod b³êdu
*/
int SaveResults(const string& fName, vector <Route> routes);