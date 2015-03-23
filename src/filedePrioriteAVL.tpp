/**
* @file filedePrioriteAVL.tpp
* @author Gonnord Kévin, Vallée Sébastien
* @since 11/02/2015
* @brief Implémentation de la classe filedePrioriteAVL
*
* @b Note s'agissant d'un patron de classe, ce fichier est inclus dans filedePrioriteAVL.hpp
**/
#include <typeinfo>
#include <iostream>
//---------------------------------------
//Constructeur
template<typename K>
	filedePrioriteAVL<K>::filedePrioriteAVL() : _nb_elements(0),_minimum(NULL){
		
	}

template<typename K>
	bool filedePrioriteAVL<K>::estVide(){
		return _nb_elements ==0;
	}

template<typename K>
	K filedePrioriteAVL<K>::premier(){
		return _minimum;
	}

template<typename K>
	void filedePrioriteAVL<K>::enfiler(K element){

		if(_nb_elements ==0){
			_racine = new AVL<K>(element);
			_nb_elements++;
			_minimum = _racine;
		}
		else{
			_nb_elements++;
			AVL<K> * tmp = new AVL<K>(element);
			_racine.ajouter(tmp);

			if(_minimum->getEtiquette() >tmp->getEtiquette()){
				_minimum = tmp;
			}
		}
		_racine = _racine->racine();
	}

template<typename K>
void filedePrioriteAVL<K>::defiler(){
	if(_minimum->getfilsD !=NULL){
		_minimum->setMarque(true);
		_minimum = _minimum->getfilsG();
		
		while(_minimum->getfilsG() !=NULL)
			_minimum = _minimum->getfilsG();
	}
	else{
		AVL<K> * tmp = _minimum;
		_minimum = _minimum->getPere();
		
		while(_minimum->getMarque()){
			tmp = _minimum;
			_minimum = _minimum->getPere();
			delete(tmp);
		}
	}
}