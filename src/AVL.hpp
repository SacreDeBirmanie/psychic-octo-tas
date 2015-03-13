template<typename Valeur>
class AVL  {
	private : 
		int etiquette;
		Valeur valeur;
		AVL<Valeur> pere;
		AVL<Valeur> filsG;
		AVL<Valeur> filsD;
		int balance;
	
		void rotationG();
	
		void rotationD();
	
		void dRotationG();
	
		void dRotationD();
	
	public:
		AVL(int e, Valeur v);
	
		Valeur getValeur();
	
		int ajouter(int e, Valeur v);
	
		void equilibrage();

		ArrayList<Valeur> prefix();
	
		AVL<Valeur> racine();
	
		bool appartient(int e);
}
