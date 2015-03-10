/**
 * @file filedePriorite.hpp
 * @author Gonnord Kévin, Vallée Sébastien
 * @since 11/02/2015
 * @brief Définition du type filedePriorite générique par type des valeurs
**/
#ifndef FILEDEPRIORITE_HPP
#define FILEDEPRIORITE_HPP


/**
 * @class filedePriorite<K,V> htable.hpp
 * 
 * @brief Patron de classe implémentant des tables de hashages K-->V
 * 
 */
template <typename K, class Comparateur=less<K>>
class filedePriorite{
	private:
		K tableauDesValeurs[500];
		int nb_elements;
		int indiceCourant;
		

	public :
		bool estVide();
		K premier();
		void enfiler(K element);
		K defiler();

};



//---------------------------------------
#include "filedePriorite.tpp"
#endif

