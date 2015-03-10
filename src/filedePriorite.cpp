/**
 * @file filedePriorite.tpp
 * @author Gonnord Kévin, Vallée Sébastien
 * @since 11/02/2015
 * @brief Implémentation de la classe filedePriorite
 * 
 * @b Note s'agissant d'un patron de classe, ce fichier est inclus dans filedePriorite.hpp
**/
#include <typeinfo>
//---------------------------------------

//Constructeur
template<typename K>
filedePriorite<K>::filedePriorite(){
	nb_elements = 0;
	indiceCourant = 0;
}

template<typename K>
bool filedePriorite<K>::estVide(){
	return nb_elements == 0;
}

template<typename K>
K filedePriorite<K>::premier(){
	return tableauDesValeurs[0];
}

template<typename K>
void filedePriorite<K>::enfiler(K element){
	tableauDesValeurs[indiceCourant] = element;
	nb_elements = nb_elements + 1;
	int courant = 0;
	k tmp;
	
	while(courant != 0 && tableauDesValeurs[courant]> tableauDesValeurs[int(courant/2)]){
		tmp = tableauDesValeurs[int(courant/2)];
		tableauDesValeurs[int(courant/2)] = tableauDesValeurs[courant];
		tableauDesValeurs[courant] = tmp;
		courant = int(courant/2);
	}
}

template<typename K>
K filedePriorite<K>::defiler(){
	int courant = 0;
	bool trouve = false;
	K tmp;
	
	tableauDesValeurs[0] = tableauDesValeurs[nb_elements];
	nb_elements = nb_elements - 1;
	while ( courant <= nb_elements && !trouve ) {
		if ( 2*1 <= nb_elements ) {
			if tableauDesValeurs[courant] >= std::max(tableauDesValeurs[2*courant], tableauDesValeurs[2*i+1]
	
	
	
	
}
