#include <iostream>
#include <cmath>
using namespace std;

/**
* Programme qui d�termine si un nombre premier. Sinon, le plus petit diviseur de
* ce nombre est retourn�.
*
* \file   exo2.cpp
* \author Jiaqi Zhao et Matthew Brassard
* \date   21 janvier 2025
* Cr�� le 21 janvier 2025
*/

/**
*  Valide les inputs pour que la somme soit plus grand que 0, le montant rembours�
*  positif et le taux soit entre 0 et 100. Sauvegarde dans errorMsg une erreur appropri�e 
*  � l'utilisateur.
*
*  \param       somme				Double qui doit �tre positif.
*  \param		montantRembourse	Double qui doit �tre positif.
*  \param		taux				Double qui doit �tre entre 0.0 et 100.0.
*  \param [out] errorMsg			String repr�sentant l'erreur de l'utilisateur.
*  \return		bool \p true si les inputs sont valides false sinon.
*/

bool validateInput(const double& somme, const double& montantRembourse, const double& taux, string& errorMsg) 
{
	errorMsg = "";
	if (somme <= 0.0) {
		errorMsg += "la somme doit etre positive (strictement plus grand que 0), ";
	}
	if (montantRembourse <= 0.0) {
		errorMsg += "le montant remoburse doit etre positive (strictement plus grand que 0), ";
	}
	if (taux < 0.0 || taux > 100.0) {
		errorMsg += "le taux doit etre entre 0 et 100, ";
	}
	if (errorMsg == "") {
		return true;
	}
	else {
		errorMsg[0] = 'L';
		errorMsg[errorMsg.length() - 2] = '.';
		errorMsg[errorMsg.length() - 1] = '\n';
		return false;
	}
}

/**
*  Fonction qui retourne la somme des inter�ts total apr�s n mois de paiement constant.
*
*  \param       somme				Double positif representant la somme totale.
*  \param		montantRembourse	Double repr�sentant le paiement constant.
*  \param		taux				Double repr�sentant le taux annuel d'interet en pourcentage.
*  \param [out] nMois				Int repr�sentant le nombre de mois que payer la dette va prendre retorune int(INFINITY) si �a ne vas pas �tre pay�.
*  \return		double repr�sentant la somme de tout les interets seulement (sans la somme) \p sommeInteret - somme.
*/

double sumInteret(const double& somme, const double& montantRembourse, const double& taux, int& nMois) {
	const double tauxMensuel = taux / 1200;
	double sommeInteret = somme;
	double interet;
	double montant = somme;

	while (montant > 0.0) {
		interet = sommeInteret * tauxMensuel;
		sommeInteret += interet;

		if (interet >= montantRembourse) {
			nMois = INFINITY;
			return(INFINITY);
		}

		montant = montant + interet - montantRembourse;
		nMois += 1;
	}
	return(sommeInteret - somme);
}

int main() {
	double somme, montantRembourse, taux;
	int nMois = 0;
	string errorMsg;
	bool validInput = false;
	
	while (validInput == false) {
		cout << errorMsg;
		cout << "Veuillez entrez la somme d'argent qui a ete pretee : ";
		cin >> somme;
		cout << "Veuillez entrez le montant rembourse � chaque mois : ";
		cin >> montantRembourse;
		cout << "Veuillez entrez le taux d'interet annuel : ";
		cin >> taux;
		validInput = validateInput(somme, montantRembourse, taux, errorMsg);
	}
	
	double interetTotal = sumInteret(somme, montantRembourse, taux, nMois);
	
	if (nMois == int(INFINITY)) {
		cout << "Vous n'allez jamais remourser votre somme." << endl;
	}
	else {
		cout << "Vous allez prendre " << nbMois << " mois pour remourser votre somme." << endl;
	}
	cout << "L'interet accumule est de " << interetTotal << "$." << endl;

	return 0;
}