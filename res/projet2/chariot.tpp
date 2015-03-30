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
   /* À COMPLÉTER */
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
   /* À COMPLÉTER */
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
bool Chariot<FileDePriorite>::estVide() const
{
   /* À COMPLÉTER */
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
void Chariot<FileDePriorite>::ajouter(const Produit & p,unsigned int nb/*=1*/)
{
   /* À COMPLÉTER */
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
Produit Chariot<FileDePriorite>::retirer()
{
   /* À COMPLÉTER */
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
double Chariot<FileDePriorite>::passageEnCaisse(const Magasin & mag)
{
   /* À COMPLÉTER */
}

//----------------------------------------------------------------------------------------
template < template <typename T> class FileDePriorite >
bool Chariot<FileDePriorite>::estAchetable(const Magasin & mag)
{
   /* À COMPLÉTER */
}
