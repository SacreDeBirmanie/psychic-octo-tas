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

		ArbreBinaire<Valeur> ajouter(Valeur e);

		AVL<K> * supprimer();
}
