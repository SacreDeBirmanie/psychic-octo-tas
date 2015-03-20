/**
* @file filedePrioriteBinaire.tpp
* @author Gonnord Kévin, Vallée Sébastien
* @since 11/02/2015
* @brief Implémentation de la classe filedePrioriteBinaire
*
* @b Note s'agissant d'un patron de classe, ce fichier est inclus dans filedePrioriteBinaire.hpp
**/
#include <typeinfo>
#include <iostream>
//---------------------------------------
//Constructeur
template<typename K>
	filedePrioriteBinaire<K>::filedePrioriteBinaire() : _nb_elements(0),_minimum(NULL){
		
	}

template<typename K>
	bool filedePrioriteBinaire<K>::estVide(){
		return _nb_elements ==0;
	}

template<typename K>
	K filedePrioriteBinaire<K>::premier(){
		
	}

template<typename K>
	void filedePrioriteBinaire<K>::enfiler(K element){

		if(_nb_elements ==0){
			_racine = new AVL<K>(k element);
			_nb_elements++;
			_minimum = &_racine
		}
		else{
			_nb_elements++;
			AVL<K> * tmp = new AVL<K>(element);
			_racine.ajouter(tmp);

			if(_minimum->getEtiquette() >tmp->getEtiquette()){
				_minimum = tmp;
			}
		}
	}

template<typename K>
void filedePrioriteBinaire<K>::defiler(){
	
}