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
		if(_nb_elements == 0)
			throw std::string("/\\*****ERREUR :: LA FILE EST VIDE, FONCTION PREMIER SANS EFFET /_\\*****\n");
		return _minimum->getEtiquette();
	}

template<typename K>
	void filedePrioriteAVL<K>::enfiler(K element){

		AVL<K> * arbre  = new AVL<K>(element);
		if(_nb_elements>0){
			_racine->ajouter(arbre);
			_racine = _racine->racine();

			if( element <=_minimum->getEtiquette()){
				_minimum = _racine->racine();
			}

		}
		else{
			_racine = arbre;
			_minimum = arbre;
		}
		
		_nb_elements++;
	}

template<typename K>
void filedePrioriteAVL<K>::defiler(){
	assert(_minimum->getFilsG() ==NULL);

	if(_minimum->getFilsD() != NULL){
		_minimum = _minimum->getFilsD();
		while(_minimum->getFilsG() !=NULL)
			_minimum = _minimum->getFilsG();
	}
	else{
		while(_minimum->getMarque()==true){
			_minimum = _minimum->getPere();
			_minimum->supprimerFilsGD();
		}
	}

	_minimum->setMarque(true);
	_nb_elements--;
}