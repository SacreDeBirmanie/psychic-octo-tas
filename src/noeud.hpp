template<typename C, typename V>
class Noeud{

	private :
		C clef;
		int degre;
		Noeud * pere;
		Noeud * fils;

		V valeur;
		
		Noeud * frereGauche;
		Noeud * frereDroit;

		bool marque;
}