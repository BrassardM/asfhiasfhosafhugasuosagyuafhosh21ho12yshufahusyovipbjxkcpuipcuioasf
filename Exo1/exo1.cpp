#include <iostream>
#include <cmath>
using namespace std;

/**
* Programme qui détermine si un nombre premier. Sinon, le plus petit diviseur de
* ce nombre est retourné.
*
* \file   exo1.cpp
* \author Jiaqi Zhao et Matthew Brassard
* \date   16 janvier 2025
* Créé le 16 janvier 2025
*/


/**
*  Fonction qui check si un nombre est premier.
*
*  \param       nombreAVerifier		Unsigned qui représente le nombre à verifier.
*  \param [out] plusPetitDiviseur	Unsigned qui représente le plusPetitDiviseur.
*  \return		double bool représentant si le nombre est premier, vrai si oui, false sinon.
*/
bool checkPrime(const unsigned& nombreAVerifier, unsigned& plusPetitDiviseur) {
	unsigned racineCarre;
	racineCarre = unsigned(sqrt(double(nombreAVerifier)));
	if (nombreAVerifier % 2 == 0 && nombreAVerifier != 2) {
		plusPetitDiviseur = 2;
		return false;
	}
	for (unsigned i = 3; i <= racineCarre; i += 2) {
		if (nombreAVerifier % i == 0)
		{
			cout << i;
			plusPetitDiviseur = i;
			return false;
		}
	}
	return true;
}

int main() {
	unsigned nombreAVerifier, plusPetitDiviseur;
	bool nombreEstPrime = false;
	while (nombreEstPrime == false) {
		cout << "Entrer un nombre entier : ";
		cin >> nombreAVerifier;
		nombreEstPrime = checkPrime(nombreAVerifier, plusPetitDiviseur);
		if (nombreEstPrime == false) {
			cout << "Ce nombre n'est pas premier car il est divisible par : " << plusPetitDiviseur << "." << endl;
		}
	}
	cout << "Ce nombre est premier." << endl;
	return 0;
}