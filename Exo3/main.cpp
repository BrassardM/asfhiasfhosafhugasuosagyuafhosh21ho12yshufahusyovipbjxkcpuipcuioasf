#include <iostream>
#include <cmath>
using namespace std;

/**
* Programme qui détermine si un nombre premier. Sinon, le plus petit diviseur de
* ce nombre est retourné.
*
* \file   exo3.cpp
* \author Jiaqi Zhao et Matthew Brassard
* \date   21 janvier 2025
* Créé le 21 janvier 2025
*/

/**
*  Valide les inputs pour que la hauteur intiale soit plus grand que 0, le nombre
*  de rebonds soit entre 0 et 1 et le nombre de rebonds soit positif. Sauvegarde dans
*  errorMsg une erreur appropriée à l'utilisateur.
* 
*  \param       hauteurInitiale		Double qui doit être positif.
*  \param		cDeRebond			Double qui doit être entre 0.0 et 1.0.
*  \param		nRebondsTot			Int qui doit être positif.
*  \param [out] errorMsg			String représentant l'erreur de l'utilisateur.
*  \return		bool \p true si les inputs sont valides false sinon.
*/
bool validateInput(const double& hauteurInitiale, const double& cDeRebond, const int& nRebondsTot, string& errorMsg) {
	errorMsg = "";
	if (hauteurInitiale <= 0.0) {
		errorMsg += "la hauteur intiale doit etre positive (strictement plus grand que 0), ";
	}
	if (cDeRebond <= 0.0 || cDeRebond >= 1.0) {
		errorMsg += "le coefficient de rebond doit etre entre 0 et 1 exclus, ";
	}
	if (nRebondsTot <= 0) {
		errorMsg += "le nombre de rebonds doit etre positive (strictement plus grand que 0), ";
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
*  Fonction recursive qui retourne la hauteur après n rebonds. Repasse dans elle même si le nombre 
*  de rebonds n'est pas égale au nombre total voulu.
*
*  \param       nRebondsTot			Int représentant le nombre total de rebonds voulu.
*  \param [in/out] rebonds			Int représentant le nombre courrant de rebonds.
*  \param		cDeRebond			Double représentant le coeff de rebonds.
*  \param [in/out] vitesse			Double représentant la vitesse de l'iteration courrante.
*  \return		double la hauteur de la balle après n rebonds \p hauteur^2 / 2*g.
*/
double getHauteur(const int& nRebondsTot, int& rebonds, const double& cDeRebond, double& vitesse) {
	vitesse = cDeRebond * vitesse;
	rebonds += 1;
	if (nRebondsTot == rebonds) {
		return (pow(vitesse,2) / (2 * 9.81));
	}
	return getHauteur(nRebondsTot,rebonds,cDeRebond,vitesse);
}

int main() {
	double hauteurInitiale, cDeRebond;
	int nRebondsTot;
	string errorMsg;
	bool validInput = false;

	while (validInput == false) {
		cout << errorMsg;
		cout << "Veuillez entrez la hauteur intiale de la balle (en metres): ";
		cin >> hauteurInitiale;
		cout << "Veuillez entrez le nombre de rebonds : ";
		cin >> nRebondsTot;
		cout << "Veuillez entrez le coefficient de rebond : ";
		cin >> cDeRebond;
		validInput = validateInput(hauteurInitiale, cDeRebond, nRebondsTot, errorMsg);
	}

	int rebonds = 0;
	double vitesseInitiale = sqrt(2.0*9.81*hauteurInitiale);

	double hauteurFinale = getHauteur(nRebondsTot,rebonds,cDeRebond,vitesseInitiale);

	cout << "La hauteur atteinte par la balle est de " << hauteurFinale << "m." << endl;

	return 0;
}