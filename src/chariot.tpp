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
   capacite_ = contenance;
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
Chariot<FileDePriorite>::~Chariot()
{
   /* À COMPLÉTER */
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
double Chariot<FileDePriorite>::capacite() const
{
   	FileDePriorite<Produit> achat_bis = achats_;
	double capacite = 0;

	while ( !achat_bis.estVide() ) {
			capacite = capacite + achat_bis.premier().poids();
			achat_bis.defiler();		
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
   	assert( !achats_.estVide() );
	
	if ( (capacite() + p.poids) <= capacite_ ) {
		achats_.enfiler(p);
	}
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
Produit Chariot<FileDePriorite>::retirer()
{
      	assert( !achats_.estVide() );
	
	achats_.defiler(p);
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
double Chariot<FileDePriorite>::passageEnCaisse(const Magasin & mag)
{	
   	double cout = 0;
	
	while ( !achat_.estVide() ) {
		if( !mag.enCatalogue(p) ){
			throw std::string("/\\*****ERREUR :: LE PRODUIT N'EST PAS PRESENT DANS LE CATALOGUE /_\\*****\n");
		}
		cout = cout + mag.tarif(achat.premier());
		achat_.defiler();		
	}
	return cout;
	
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
bool Chariot<FileDePriorite>::estAchetable(const Magasin & mag)
{
   	bool achetable = true;
	FileDePriorite<Produit> achat_bis = achats_;

	while ( !achat_bis.estVide() ) {
		if( mag.enCatalogue(achat_bis.premier()) && mag.stock(achat_bis.premier() = 0 ){
			achetable = false;
		}
	}
	return achetable;
}
