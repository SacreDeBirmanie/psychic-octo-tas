/**
 * @file chariot.tpp
 * @author C. Jermann
 * @since 09/03/2015
 * @brief Implémentation de la classe Chariot<FP>
 * 
 * @b Note s'agissant d'un patron de classe, ce fichier est inclus dans chariot.hpp
**/
#include <cassert>

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
Chariot<FileDePriorite>::Chariot(double contenance/*=50.0*/)
{
	// Initialisation de la capacité du chariot
	capacite_ = contenance;
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
Chariot<FileDePriorite>::~Chariot()
{
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
double Chariot<FileDePriorite>::capacite() const
{
	// Copie des produits dans le chariot
   	FileDePriorite<Produit> achats_tmp = achats_;
	// Capacité initialisée à zero
	double capacite = capacite_;

	// Tant que le chariot copié n'est pas vide
	while ( !achats_tmp.estVide() ) {
		// On décrémente la capacite avec le poids du produits en haut du chariot
		capacite = capacite - achats_tmp.premier().poids();
		// On retire le produit
		achats_tmp.defiler();		
	}
	return capacite;
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
bool Chariot<FileDePriorite>::estVide() const
{
   	return achats_.estVide();
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
void Chariot<FileDePriorite>::ajouter(const Produit & p,unsigned int nb/*=1*/)
{	
	// Si la capacité résiduelle additionnée au poids du produit à ajouter est inférieur ou égale a la capacité du chariot on ajoute le produit
	if ( ( capacite() - p.poids() ) >= 0 ) {
		achats_.enfiler(p);
	}
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
Produit Chariot<FileDePriorite>::retirer()
{
	// Assertion qui vérifie si le chariot n'est pas vide
      	assert( !achats_.estVide() );

	achats_.defiler();
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
double Chariot<FileDePriorite>::passageEnCaisse(const Magasin & mag)
{	
	// Initialisation du coût total du chariot
   	double cout = 0;
	
	// Tant que le chariot n'est pas vide
	while ( !achats_.estVide() ) {
		// Si le produit le plus léger n'est pas dans le catalogue du magasin, on affiche un message d'erreur
		if( !mag.enCatalogue(achats_.premier()) ){
			throw std::string("/\\*****ERREUR :: LE PRODUIT N'EST PAS PRESENT DANS LE CATALOGUE /_\\*****\n");
		}
		// Incrémentation du coût total avec le tarif du produit
		cout = cout + mag.tarif(achats_.premier());
		// On retire le produit le plus léger
		achats_.defiler();		
	}
	return cout;
	
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
bool Chariot<FileDePriorite>::estAchetable(const Magasin & mag) const
{
	// Booléen qui confirme ou non que le chariot peut est achetable, initialisé à vrai
   	bool achetable = true;
	// Copie des produits dans le chariot
   	FileDePriorite<Produit> achats_tmp = achats_;

	// Tant que le chariot copié n'est pas vide
	while ( !achats_tmp.estVide() ) {
		// Si le produit le plus léger n'est pas dans le catalogue ou s'il n'est pas en stock, le booléen passe à faux
		if( !mag.enCatalogue(achats_tmp.premier()) || mag.stock(achats_tmp.premier()) == 0 ){
			achetable = false;
		}
		achats_tmp.defiler();
	}
	return achetable;
}
