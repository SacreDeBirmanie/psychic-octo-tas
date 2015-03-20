template<typename Valeur>
class AVL  {
	private : 
		Valeur _etiquette;
		//Valeur _valeur;
		AVL<Valeur> _pere;
		AVL<Valeur> _filsG;
		AVL<Valeur> _filsD;
		
		AVL<Valeur> * _minimum;
		int _nbNoeud;
		
		int _balance;
	
		void rotationG();
	
		void rotationD();
	
		void dRotationG();
	
		void dRotationD();
	
	public:
		AVL(int e, Valeur v);
	
		Valeur getValeur();
		
		int ajouter(AVL<K> * arbre);

		int ajouter(Valeur e);
	
		void equilibrage();

		ArrayList<Valeur> prefix();
	
		AVL<Valeur> racine();
	
		bool appartient(int e);

		AVL<K> * supprimer();
}
