/**
* @file .hpp
* @author Gonnord Kévin, Vallée Sébastien
* @since 11/02/2015
* @brief Définition du type FileDePriorite générique par type des valeurs
**/
#ifndef filedePrioriteAVL_HPP
#define filedePrioriteAVL_HPP
#include <stdexcept>
#include "AVL.hpp"
/**
* @class FileDePrioriteAVL<K,V> htable.hpp
*
* @brief Patron de classe implémentant des tables de hashages K-->V
*
* L'élément le plus petit est le premier élément
*/
template <typename K>
class FileDePrioriteAVL
{
	private:
		AVL<K> *_racine;
		AVL<K> *_minimum;
		int _nb_elements;
	public :
		/**
		* @brief Constructeur
		* 
		* @b Complexité Θ(1)
		*/
		FileDePrioriteAVL();

		/**
		* @brief Constructeur
		* 
		* @b Complexité Θ(1)
		*/
		~FileDePrioriteAVL();

		/**
		* @biref Cette fonction permet de savoir si la file est vide ou non
		* @return un booléen à vraie si la file est vide, false si elle contient des élements
		* 
		* @b Complexité Θ(1)
		*/
		bool estVide();

		/**
		* @brief Cette fonction permet de récupérer l'élement racine de la file (le plus grand selon le comparateur)
		* @return un type K, le plus grand élement de la file
		* 
		* @b Complexité Θ(1)
		*/
		K premier();

		/**
		* @biref Cette procédure permet d'ajouter un élement dans la file
		* @param element l'élement à ajouter dans la file
		* 
		* @b Complexité Ω(1) et O(log(nbe)), ou npb est le nombre d'éléments K
		*/
		void enfiler(K element);

		/**
		* @brief Cette procédure permet d'enlever la racine de la file ( le plus grand élement selon le comparateur )
		* 
		* @b Complexité Ω(1) et O(log(nbe)), ou npb est le nombre d'éléments K
		*/
		void defiler();

		/**
		* @brief
		* 
		* @b Complexité Θ(1)
		*/
		void racine();

		/**
		* @brief fonction de test
		*/
		void afficher();		
};
//---------------------------------------
#include "filedePrioriteAVL.tpp"
#endif
