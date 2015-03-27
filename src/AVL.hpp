#include <vector>
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <assert.h>

template<typename Valeur>
class AVL  {
	private : 
		Valeur _etiquette;
		bool _marque;
		
		AVL<Valeur> * _pere;
		AVL<Valeur> * _filsG;
		AVL<Valeur> * _filsD;

		int _nbNoeud;
		
		int _balance;
	
		void rotationG();
	
		void rotationD();
	
		void dRotationG();
	
		void dRotationD();
	
	public:
		AVL(Valeur e);

		bool estFeuille();

		Valeur getEtiquette();

		AVL<Valeur> * getPere();

		AVL<Valeur> * getFilsG();

		AVL<Valeur> * getFilsD();

		bool getMarque();

		int getNbNoeud();

		void setMarque(bool marque);

		void supprimerFilsGD();

		void supprimerFilsDG();

		
		int ajouter(AVL<Valeur> * arbre);

		int ajouter(Valeur e);
	
		void equilibrage();

		std::vector<Valeur> prefix();
		std::vector<Valeur> suffix();
		std::vector<Valeur> infix();
	
		AVL<Valeur> * racine();
	
		bool appartient(Valeur e);

};

#include "AVL.tpp"
