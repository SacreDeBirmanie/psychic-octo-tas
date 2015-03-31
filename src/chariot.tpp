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
	// Recopie des produits dans le chariot
   	FileDePriorite<Produit> achats_bis = achats_;
	// Capacité initialisée à zero
	double capacite = 0;

	// Tant que le chariot n'est pas vide
	while ( !achats_bis.estVide() ) {
		// On incrémente la capacite avec le poids du produits en haut du chariot
		capacite = capacite + achats_bis.premier().poids();
		// On retire le produit
		achats_bis.defiler();		
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
	// Assertion qui vérifie si le chariot n'est pas vide
   	assert( !achats_.estVide() );
	
	// Si la capacité résiduelle et le poids du produit ajouté est inférieur ou égale a la capacité du chariot on ajoute le produit
	if ( (capacite() + p.poids()) <= capacite_ ) {
		achats_.enfiler(p);
	}
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
Produit Chariot<FileDePriorite>::retirer()
{
      	assert( !achats_.estVide() );
	
	achats_.defiler();
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
double Chariot<FileDePriorite>::passageEnCaisse(const Magasin & mag)
{	
   	double cout = 0;
	
	while ( !achats_.estVide() ) {
		if( !mag.enCatalogue(achats_.premier()) ){
			throw std::string("/\\*****ERREUR :: LE PRODUIT N'EST PAS PRESENT DANS LE CATALOGUE /_\\*****\n");
		}
		cout = cout + mag.tarif(achats_.premier());
		achats_.defiler();		
	}
	return cout;
	
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
bool Chariot<FileDePriorite>::estAchetable(const Magasin & mag)
{
   	bool achetable = true;
	FileDePriorite<Produit> achats_bis = achats_;

	while ( !achats_bis.estVide() ) {
		if( mag.enCatalogue(achats_bis.premier()) && mag.stock(achats_bis.premier() = 0) ){
			achetable = false;
		}
	}
	return achetable;
}
