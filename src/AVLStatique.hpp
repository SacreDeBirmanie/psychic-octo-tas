#include <vector>

template<typename Valeur>
class AVL  {
	private : 
		Valeur _etiquette;
		bool _marque;
		
		AVL<Valeur> _pere;
		AVL<Valeur> _filsG;
		AVL<Valeur> _filsD;

		int _nbNoeud;
		
		int _balance;
	
		void rotationG();
	
		void rotationD();
	
		void dRotationG();
	
		void dRotationD();
		

	public:

		AVL(Valeur e);

		Valeur getEtiquette();

		AVL<Valeur> getPere();

		AVL<Valeur> getfilsG();

		AVL<Valeur> getfilsD();

		bool getMarque();

		int getNbNoeud();

		
		int ajouter(AVL<Valeur> * arbre);

		int ajouter(Valeur e);
	
		void equilibrage();

		std::vector<Valeur> prefix();
	
		AVL<Valeur> racine();
	
		bool appartient(int e);

};
#include "AVLStatique.tpp"