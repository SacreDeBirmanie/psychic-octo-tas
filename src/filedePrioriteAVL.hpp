/**
* @file .hpp
* @author Gonnord Kévin, Vallée Sébastien
* @since 11/02/2015
* @brief Définition du type filedePriorite générique par type des valeurs
**/
#ifndef FILEDEPRIORITEBINAIRE_HPP
#define FILEDEPRIORITEBINAIRE_HPP
#include <stdexcept>
#include "AVL.hpp"
/**
* @class filedePrioriteAVL<K,V> htable.hpp
*
* @brief Patron de classe implémentant des tables de hashages K-->V
*
*/
template <typename K>
	class filedePrioriteBinaire<K>{
		private:
			ArbreBinaire<K> _racine;
			ArbreBinaire<K> * _minimum;
			int _nb_elements;
		public :
			/**
			* constructeur de la file de priorite
			*/
			filedePrioriteBinaire();
			/**
			* cette fonction permet de savoir si la file est vide ou non
			* @return un booléen à vraie si la file est vide, false si elle contient des élements
			*/
			bool estVide();
			/**
			* cette fonction permet de récupérer l'élement racine de la file (le plus grand selon le comparateur)
			* @return un type K, le plus grand élement de la file
			*/
			K premier();
			/**
			* cette procédure permet d'ajouter un élement dans la file
			* @param element l'élement à ajouter dans la file
			*/
			void enfiler(K element);
			/**
			* cette procédure permet d'enlever la racine de la file ( le plus grand élement selon le comparateur )
			*/
			void defiler();
	};
//---------------------------------------
#include "filedePrioriteBinaire.tpp"
#endif
