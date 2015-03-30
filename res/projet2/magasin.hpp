/**
 * @file magasin.hpp
 * @author C. Jermann
 * @since 09/03/2015
 * @brief Définition d'une classe Magasin simplifiée
**/

#ifndef __MAGASIN_HPP__
#define __MAGASIN_HPP__

#include <string>
#include <vector>
#include "produit.hpp"
#include "mappe.hpp"

/**
 * @class Magasin magasin.hpp
 * 
 * @brief Classe implémentant un magasin de Produits
 * 
 * Le magasin dispose d'un catalogue de produits ;
 * Il associe à chacun un prix unitaire et un stock ;
 */
class Magasin
{
   private:
      // Ensemble des Produits au catalogue du magasin
      std::vector<Produit> catalogue_;

      // Table associative Etiquette-->Prix de vente unitaire
      // Note : tout produit en catalogue a un prix associé
      Mappe<unsigned int,double> prix_;

      // Table associative Etiquette-->Quantité en stock
      // Note : les produits du catalogue épuisés ne sont pas en stock
      Mappe<unsigned int,unsigned int> stock_;

   public:
      /** 
       * @brief Constructeur, construit le magasin à partir d'un entrepôt
       * @param entrepot le nom du fichier entreposant les produits et leurs informations
       * @attention L'entrepôt peut contenir des produits dont le stock est nul ; 
       * en ce cas, ils sont ajoutés au catalogue et à la liste des prix, mais pas 
       * au stock @n <em>=> le trousseau du stock peut différer du catalogue</em>
       * 
       * @b Complexité Θ(nbp), nbp = nombre de produits dans le fichier entrepot
       */
      Magasin(std::string entrepot);

      /** 
       * @brief Accès (en lecture seulement) au catalogue de produits du magasin
       * @return le catalogue (référence constante => donnée partagée mais immuable)
       * 
       * @b Complexité Θ(1)
       */
      const std::vector<Produit> & catalogue() const;

      /** 
       * @brief Test de présence d'un produit au catalogue du magasin
       * @param p Le produit considéré
       * @return Vrai ssi le produit est en catalogue
       * 
       * @b Complexité Θ(log nbc), avec nbc = nombre de produits au catalogue
       */
      bool enCatalogue(const Produit & p) const;

      /** 
       * @brief Accès au prix unitaire d'un produit en catalogue
       * @param p le produit
       * @return le prix unitaire du produit p
       * @pre le produit est dans le catalogue
       * 
       * @b Complexité O(log nbc), avec nbc = nombre de produits au catalogue
       */
      double tarif(const Produit & p) const;

      /** 
       * @brief Accès au stock d'un produit
       * @param p le produit
       * @return la quantité du produit p en stock, ou 0 s'il n'est pas en stock
       * @pre le produit est dans le catalogue
       * 
       * @b Complexité O(log nbs) avec nbs = nombre de produits en stock
       */
      unsigned int stock(const Produit & p) const;		

};

#endif // __MAGASIN_HPP__
