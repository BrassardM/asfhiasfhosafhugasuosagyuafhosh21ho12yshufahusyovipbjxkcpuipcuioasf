#include <iostream>
#include <random>
using namespace std;

/**
* Programme qui approxime la valeur de Pi à partir de la méthode Monte-Carlo.
*
* \file   exo4.cpp
* \author Jiaqi Zhao et Matthew Brassard
* \date   21 janvier 2025
* Créé le 21 janvier 2025
*/

/**
* Programme qui approxime la valeur de Pi à travers la méthode de Monte Carlo.
*
* \file   exo3.cpp
* \author Jiaqi Zhao et Matthew Brassard
* \date   21 janvier 2025
* Créé le 21 janvier 2025
*/
double genNombreAleatoire() {
    default_random_engine aleatoire(random_device{}());
    uniform_real_distribution<double> distribution(-1.0, 1.0);
    return distribution(aleatoire);
}

bool isInCircle(double x, double y) {
    return (pow(x, 2) + pow(y, 2)) < 1.0;
}

int main() {
    int nIterations = 0;
    int nInTheCircle = 0;
    double x = 0.0;
    double y = 0.0;
    cout << "Combien de répétitions voulez-vous?";
    cin >> nIterations;

    for (int i = 0; i < nIterations; i++) {
        x = genNombreAleatoire();
        y = genNombreAleatoire();
        nInTheCircle = nInTheCircle + int(isInCircle(x, y));
    }
    cout << 4 * double(nInTheCircle) / double(nIterations);
}