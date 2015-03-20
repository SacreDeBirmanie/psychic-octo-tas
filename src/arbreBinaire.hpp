template<typename Valeur>
class ArbreBinaire  {
	private : 
		Valeur _etiquette;
		//Valeur _valeur;
		AVL<Valeur> _pere;
		AVL<Valeur> _filsG;
		AVL<Valeur> _filsD;
		
	public:
		ArbreBinaire(int e, Valeur v);
	
		Valeur getValeur();
		
		int ajouter(AVL<K> * arbre);

		int ajouter(Valeur e);
	
		void equilibrage();

		ArrayList<Valeur> prefix();
	
		AVL<Valeur> racine();
	
		bool appartient(int e);

		AVL<K> * supprimer();
}
