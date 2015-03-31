/**
 * @file mappe.hpp
 * @author C. Jermann
 * @since 09/03/2015
 * @brief Définition d'un patron de classe Charriot<FP> où FP est une File de 
 * Priorité
**/

#ifndef __CHARIOT_HPP__
#define __CHARIOT_HPP__

#include "FileDePrioriteTAS.hpp"
#include "produit.hpp"
#include <assert.h>

/**
 * @class Chariot<K,V> chariot.hpp
 * 
 * @brief Patron de classe implémentant un chariot dans lequel les produits les 
 * plus lourds vont dans le fond
 * 
 * Le paramètre générique FP doit être conforme à la spécification de File de 
 * Priorité. Il sert à stocker les produits dans le chariot par ordre de poids.
 * 
 * Le chariot a une contenance maximal en poids : l'ensemble des produits 
 * contenus ne doit jamais excéder cette capacité définie à la création du chariot
 */
template < template <typename T> class FileDePriorite >
class Chariot
{
	private:
		// Capacité maximal du chariot
		double capacite_;
		// L'ensemble des produits dans le chariot rangés du plus petit au plus grand
		FileDePriorite<Produit> achats_;

	public:
		/**
		* @brief Constructeur
		* @param contenance, la capacité d'accueil maximale du chariot, 50 par défaut
		* 
		* @b Complexité Θ(1)
		*/
		Chariot(double contenance=50.0);

		/**
		* @brief Destructeur
		* 
		* @b Complexité Θ(1)
		*/
		~Chariot();

		/**
		* @brief Accès à la capacité restante
		* @return Capacité résiduelle = capacité initiale -- poids de tous les 
		* produits dans le chariot
		* 
		* @b Complexité avec FileDePriorite Ω(nbp) et O(nbp*log(nbp)), où nbp est le nombre de produit dans le chariot
		* @b Complexité avec AVL Ω(nbp) et O(nbp*log(nbp)), où nbp est le nombre de produit dans le chariot
		*/
		double capacite() const;

		/**
		* @brief Test de présence de produits dans le chariot
		* @return Vrai ssi le chariot ne contient aucun produit
		* 
		* @b Complexité Θ(1)
		*/
		bool estVide() const;

		/**
		* @brief Ajout de produits dans le chariot
		* @param p Le produit considéré
		* @param qte Le nombre d'exemplaires à ajouter
		* @pre La capacité résiduelle doit être suffisante
		* 
		* @b Complexité Ω(1) et O(log(nbp)), ou npb est le nombre de produits
		*/
		void ajouter(const Produit & p,unsigned int qte=1);

		/**
		* @brief Retrait d'un exemplaire du produit le plus léger présent dans 
		* le chariot
		* @return Le produit retiré
		* @pre Le chariot n'est pas vide
		* 
		* @b Complexité Ω(1) et O(log(nbp)), ou npb est le nombre de produits
		*/
		Produit retirer();

		/**
		* @brief Encaissement du chariot dans un magasin
		* @param mag Le magasin dans lequel le chariot est encaissé
		* @return le coût total des produits dans le chariot
		* @pre Les produits dans le chariot sont bien dans le catalogue de mag
		* @post Le chariot est vide
		* 
		* @b Complexité Ω(nbp) et O(nbp*log(nbp)), ou npb est le nombre de produits
		*/
		double passageEnCaisse(const Magasin & mag);

		/**
		* @brief Test de la possibilité d'acheter le chariot dans un magasin donné
		* @param mag Le magasin considéré
		* @return Vrai ssi tous les produits dans le chariot sont au catalogue du magasin ET sont en stock en quantité suffisante
		* @post Le chariot est inchangé
		* 
		* @b Complexité Ω(nbp) et O(nbp*log(nbp)), ou npb est le nombre de produits
		*/
		bool estAchetable(const Magasin & mag) const;

};

#include "chariot.tpp"

#endif // __CHARIOT_HPP__
