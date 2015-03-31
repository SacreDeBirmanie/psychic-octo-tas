/**
* @file FileDePriorite.tpp
* @author Gonnord Kévin, Vallée Sébastien
* @since 11/02/2015
* @brief Implémentation de la classe FileDePriorite
*
* @b Note s'agissant d'un patron de classe, ce fichier est inclus dans FileDePriorite.hpp
**/
#include <typeinfo>
#include <iostream>
//---------------------------------------
//Constructeur
template<typename K>
	FileDePriorite<K>::FileDePriorite(){
		_nb_elements = 0;	
	}
//Destructeur
template<typename K>
	FileDePriorite<K>::~FileDePriorite(){
	}

template<typename K>
	bool FileDePriorite<K>::estVide(){
		return _nb_elements==0;
	}

template<typename K>
	K FileDePriorite<K>::premier(){
		if(_nb_elements == 0)
			throw std::string("/\\*****ERREUR :: LA FILE EST VIDE, FONCTION PREMIER SANS EFFET /_\\*****\n");
		return _tableauDesValeurs[0];
	}

template<typename K>
	void FileDePriorite<K>::enfiler(K element){
		_tableauDesValeurs[_nb_elements] = element;
		int courant = _nb_elements;
		_nb_elements = _nb_elements + 1;
		K tmp;
		while(courant != 0 && _tableauDesValeurs[courant]> _tableauDesValeurs[int(courant/2)]){
			tmp = _tableauDesValeurs[int(courant/2)];
			_tableauDesValeurs[int(courant/2)] = _tableauDesValeurs[courant];
			_tableauDesValeurs[courant] = tmp;
			courant = int(courant/2);
		}
	}

template<typename K>
void FileDePriorite<K>::defiler(){
	if(_nb_elements == 0)
		throw std::string("/\\*****ERREUR :: LA FILE EST VIDE, FONCTION DEFILER SANS EFFET /_\\***** \n");
	int courant = 0;
	bool trouve = false;
	K tmp;
	_nb_elements = _nb_elements - 1;
	_tableauDesValeurs[0] = _tableauDesValeurs[_nb_elements];
	
	while ( courant <= _nb_elements && !trouve ) {
		if (2*courant <= _nb_elements && _tableauDesValeurs[courant] < _tableauDesValeurs[2*courant]){
			tmp = _tableauDesValeurs[courant];
			_tableauDesValeurs[courant] = _tableauDesValeurs[2*courant];
			_tableauDesValeurs[2*courant] = tmp;
			courant = 2*courant;
		}
		else if(2*courant+1 <=_nb_elements && _tableauDesValeurs[courant] < _tableauDesValeurs[2*courant+1]){
			tmp = _tableauDesValeurs[courant];
			_tableauDesValeurs[courant] = _tableauDesValeurs[2*courant+1];
			_tableauDesValeurs[2*courant+1] = tmp;
			courant = 2*courant+1;
		}
		else
			trouve = true;
	}
}

template<typename K>
	void FileDePriorite<K>::afficher(){
	int courant = 0;
	std::cout<<"LISTE ::(";
	while(courant<_nb_elements){
		std::cout<<_tableauDesValeurs[courant];
		courant++;
	}
	std::cout<<")"<<std::endl;

}
