/**
 * @file magasin.cpp
 * @author C. Jermann
 * @since 09/03/2015
 * @brief Implémentation des fonctions de la classe Magasin
**/

#include <cassert>
#include <fstream>
#include <string>
#include <sstream>
#include "magasin.hpp"

//--------------------------------------------------------------------
Magasin::Magasin(std::string entrepot)
{
   // ouverture du fichier entrepot
   std::ifstream fic(entrepot);
   // erreur en cas de lecture impossible
   assert(fic.is_open());
   // lecture de l'entrepot
   std::string ligne;
   getline(fic,ligne);
   while(!fic.eof())
   {  // traitement d'une ligne du fichier
      std::stringstream ss(ligne);
      std::string nom;
      double poids,prix;
      int codebarre;
      unsigned int quantite;
      // récupération des données de la ligne : le fichier est supposé bien formé
      ss >> codebarre >> nom >> poids >> prix >> quantite;
      // ajout du produit au catalogue
      catalogue_.push_back(Produit(nom,poids,codebarre));
      // association du prix
      prix_.associer(codebarre,prix);
      // association du stock
      if (quantite>0)
      {
         stock_.associer(codebarre,quantite);
      }
      // lecture de la prochaine ligne (si elle existe)
      getline(fic,ligne);
   }
}

//--------------------------------------------------------------------
const std::vector<Produit> & Magasin::catalogue() const
{
   return catalogue_;
}

//--------------------------------------------------------------------
bool Magasin::enCatalogue(const Produit & p) const
{
   return prix_.estClef(p.codebarre());
}

//--------------------------------------------------------------------
double Magasin::tarif(const Produit & p) const
{
   return prix_.valeurAssociee(p.codebarre()); // accès par étiquette
}

//--------------------------------------------------------------------
unsigned int Magasin::stock(const Produit & p) const
{
	unsigned int qt = 0;
	if (stock_.estClef(p.codebarre()))
	{ // produit en stock => quantité positive
	   qt = stock_.valeurAssociee(p.codebarre()); // accès par étiquette
	}
	return qt;
}
