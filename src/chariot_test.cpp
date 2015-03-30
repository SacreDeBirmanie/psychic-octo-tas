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
