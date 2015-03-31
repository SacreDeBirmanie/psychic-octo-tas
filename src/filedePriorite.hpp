/**
* @file filedePriorite.hpp
* @author Gonnord Kévin, Vallée Sébastien
* @since 11/02/2015
* @brief Définition du type FileDePriorite générique par type des valeurs
**/
#ifndef FILEDEPRIORITE_HPP
#define FILEDEPRIORITE_HPP
#include <stdexcept>
/**
* @class FileDePriorite<K,V> FileDePriorite.hpp
*
* @brief Patron de classe implémentant des FP
*
* L'élément le plus petit est le premier élément
*/
template <typename K>
class FileDePriorite
{
	private:
		// Ensemble des éléments de la file
		K _tableauDesValeurs[500];
		// Nombre d'éléments
		int _nb_elements;
	public :
		/**
		* @brief Constructeur 
		* @param contenance La capacité d'accueil maximale du chariot, 50 par défaut
		*
		* @b Complexité Θ(1)
		*/
		FileDePriorite();

		/**
		* @brief Destructeur
		*
		* @b Complexité Θ(1)
		*/
		~FileDePriorite();

		/**
		* @brief Cette fonction permet de savoir si la file est vide ou non
		* @return un booléen à vraie si la file est vide, false si elle contient des élements
		*
		* @b Complexité Θ(1)
		*/
		bool estVide();

		/**
		* @brief Cette fonction permet de récupérer l'élement racine de la file (le plus grand selon le comparateur)
		* @return le petit élement de la file
		*
		* @b Complexité Θ(1)
		*/
		K premier();

		/**
		* @brief cette procédure permet d'ajouter un élement dans la file
		* @param element l'élement à ajouter dans la file
		*
		* @b Complexité Ω(1) et O(log(nbe)), ou npb est le nombre d'éléments K
		*/
		void enfiler(K element);

		/**
		* @brief cette procédure permet d'enlever la racine de la file ( le plus grand élement selon le comparateur )
		*
		* @b Complexité Ω(1) et O(log(nbe)), ou npb est le nombre d'éléments K
		*/
		void defiler();
		
		/**
		* @brief fonction de test
		*/
		void afficher();
};
//---------------------------------------
#include "filedePriorite.tpp"
#endif
