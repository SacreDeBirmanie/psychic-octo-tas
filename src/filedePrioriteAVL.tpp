/**
* @file FileDePrioriteAVL.tpp
* @author Gonnord Kévin, Vallée Sébastien
* @since 11/02/2015
* @brief Implémentation de la classe FileDePrioriteAVL
*
* @b Note s'agissant d'un patron de classe, ce fichier est inclus dans FileDePrioriteAVL.hpp
**/
#include <typeinfo>
#include <iostream>
#include <vector>
//---------------------------------------
//Constructeur
template<typename K>
	FileDePrioriteAVL<K>::FileDePrioriteAVL() : _nb_elements(0),_minimum(NULL),_racine(NULL){
		
	}

//---------------------------------------
//Constructeur
template<typename K>
	FileDePrioriteAVL<K>::~FileDePrioriteAVL(){
		delete _racine;
	}

template<typename K>
	bool FileDePrioriteAVL<K>::estVide(){
		return _nb_elements ==0;
	}

template<typename K>
	K FileDePrioriteAVL<K>::premier(){
		if(_nb_elements == 0){
			assert(_racine == NULL);
			assert(_minimum == NULL);
			throw std::string("/\\*****ERREUR :: LA FILE EST VIDE, FONCTION PREMIER SANS EFFET /_\\*****\n");
		}
		return _minimum->getEtiquette();
	}

template<typename K>
	void FileDePrioriteAVL<K>::enfiler(K element){

		AVL<K> * arbre  = new AVL<K>(element);
		if(_nb_elements>0){
			_racine->ajouter(arbre);
			_racine = _racine->racine();

			if( element <=_minimum->getEtiquette()){
				_minimum->setMarque(false);
				_minimum = arbre;
				_minimum->setMarque(true);
			}

		}
		else{
			_racine = arbre;
			_minimum = arbre;
			_minimum->setMarque(true);
		}
		
		_nb_elements++;
	}

template<typename K>
void FileDePrioriteAVL<K>::defiler(){
	if(_nb_elements == 0){
		assert(_racine == NULL);
		assert(_minimum == NULL);
		throw std::string("/\\*****ERREUR :: LA FILE EST VIDE, FONCTION DEFILER SANS EFFET /_\\*****\n");
	}
	else if(_nb_elements==1){
		delete _racine;
		_racine = NULL;
		_minimum = NULL;
	}
	else{

		assert(_minimum->getFilsG() ==NULL);

		if(_minimum->getFilsD() != NULL){

			_minimum = _minimum->getFilsD();
			while(_minimum->getFilsG() !=NULL)
				_minimum = _minimum->getFilsG();
		}
		else{
				bool trouve = false;
				while(_minimum->getMarque()==true &&_minimum->getPere() != NULL && !trouve){
					_minimum = _minimum->getPere();
					_minimum->supprimerFilsGD();
				}


					
		}
			/*if(_minimum->getPere() == NULL){
				std::cout<<"graou"<<std::endl;
				delete _minimum;
				_minimum = NULL;
				_racine = NULL;

			}*/
	}

	if(_minimum!=NULL)
		_minimum->setMarque(true);

	_nb_elements--;
	//std::cout<<"et le minimum est maintenant :"<<_minimum->getEtiquette()<<"_nb_elements : "<<_nb_elements<<std::endl;
}

template<typename K>
void FileDePrioriteAVL<K>::afficher(){
	if(_nb_elements == 0){
		assert(_racine == NULL);
		assert(_minimum == NULL);
		std::cout<<"[LA FILE EST VIDE]"<<std::endl;
	}
	else{

		std::vector<K> in,pre,su;
		
		in = _racine->infix();
		pre = _racine->prefix();
		su = _racine->suffix();
		int i;
		std::cout<<"prefix : [";
		for(i =0;i < pre.size();++i)
			std::cout<<pre.at(i)<<",";
		std::cout<<"]"<<std::endl;
		

		std::cout<<"infix : [";
		for(i =0;i < in.size();++i)
			std::cout<<in.at(i)<<",";
		std::cout<<"]"<<std::endl;
		

		std::cout<<"suffix : [";
		for(i =0;i < su.size();++i)
			std::cout<<su.at(i)<<",";
		std::cout<<"]"<<std::endl;
	}

}

template<typename K>
void FileDePrioriteAVL<K>::racine(){
	std::cout<<_racine->getEtiquette()<<std::endl;

}


