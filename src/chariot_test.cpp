#include <iostream>
#include <ctime>

#include "produit.hpp"
#include "magasin.hpp"
#include "chariot.hpp"

#include "filedePriorite.hpp"
#include "filedePrioriteAVL.hpp"

//------------------------------------------------------------------------------
// Fonctionnalités de chronométrage
/**
 * @var chrono
 * @brief chronomètre du programme
**/
clock_t chrono;

/**
 * @def START
 * @brief démarre le chronomètre
**/
#define START chrono=clock()

/**
 * @def STOP
 * @brief arrête le chronomètre
**/
#define STOP chrono=clock()-chrono

/**
 * @def TEMPS
 * @brief donne le temps du chronomètre (après arrêt)
**/
#define TEMPS double(chrono)/CLOCKS_PER_SEC

using namespace std;

int main()
{
	Magasin m("entrepot_11.txt");

	cout << "CONSTRUCTION" << endl;
	cout << "------------" << endl;
	START;
	Chariot<FileDePriorite> caddie(10.0);
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	cout << "CAPACITE RESTANTE" << endl;
	cout << "------------" << endl;
	START;
	cout << "Capacité : " << caddie.capacite() << endl;
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	cout << "AJOUT DES ARTICLES" << endl;
	cout << "------------" << endl;
	START;
	for (auto p : m.catalogue())
	{
		caddie.ajouter(p);
	}
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	cout << "CAPACITE RESTANTE" << endl;
	cout << "------------" << endl;
	START;
	caddie.capacite();
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	cout << "AFFICHAGE" << endl;
	cout << "------------" << endl;
	START;
	for (auto p : m.catalogue())
	{
		p.afficher();
		cout << " :  prix=";
		cout.width(4);
		cout.fill('0');
		cout << m.tarif(p) << "€";
		cout << "  qté=" << m.stock(p) << endl;
	}
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	cout << "RETIRER" << endl;
	cout << "------------" << endl;
	START;
	caddie.retirer();
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	cout << "CAPACITE RESTANTE" << endl;
	cout << "------------" << endl;
	START;
	caddie.capacite();
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	cout << "PASSAGE EN CAISSE" << endl;
	cout << "------------" << endl;
	START;
	caddie.passageEnCaisse(m);
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	cout << "CAPACITE" << endl;
	cout << "------------" << endl;
	START;
	caddie.capacite();
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	return 0;
}
=======
#include <iostream>
#include <ctime>

#include "produit.hpp"
#include "magasin.hpp"
#include "chariot.hpp"

#include "filedePriorite.hpp"
#include "filedePrioriteAVL.hpp"

//------------------------------------------------------------------------------
// Fonctionnalités de chronométrage
/**
 * @var chrono
 * @brief chronomètre du programme
**/
clock_t chrono;

/**
 * @def START
 * @brief démarre le chronomètre
**/
#define START chrono=clock()

/**
 * @def STOP
 * @brief arrête le chronomètre
**/
#define STOP chrono=clock()-chrono

/**
 * @def TEMPS
 * @brief donne le temps du chronomètre (après arrêt)
**/
#define TEMPS double(chrono)/CLOCKS_PER_SEC

using namespace std;

int main()
{
	Magasin m("entrepot_11.txt");

	cout << "CONSTRUCTION" << endl;
	cout << "------------" << endl;
	START;
	Chariot<FileDePriorite> caddie(10.0);
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	
	cout << "CAPACITE" << endl;
	cout << "------------" << endl;
	START;
	caddie.capacite();
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	cout << "RETIRER" << endl;
	cout << "------------" << endl;
	START;
	caddie.retirer();
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	cout << "CAPACITE" << endl;
	cout << "------------" << endl;
	START;
	caddie.capacite();
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	cout << "PASSAGE EN CAISSE" << endl;
	cout << "------------" << endl;
	START;
	caddie.passageEnCaisse(m);
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	cout << "CAPACITE" << endl;
	cout << "------------" << endl;
	START;
	caddie.capacite();
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	return 0;
}
>>>>>>> origin/master
