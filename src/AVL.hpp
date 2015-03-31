/**
* @file .hpp
* @author Gonnord Kévin, Vallée Sébastien
* @since 11/02/2015
* @brief Définition du type AVL générique par type des valeurs
**/
#ifndef AVL_HPP
#define AVL_HPP
#include <vector>
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <assert.h>

template<typename Valeur>
class AVL  {
	private : 
		Valeur _etiquette;//etiquette du noeud
		bool _marque;//marque initialiser à faux par defaut

		bool _garde;
		
		AVL<Valeur> * _pere;//pere du noeud, NULL si racine
		AVL<Valeur> * _filsG;//fils gauche du noeud
		AVL<Valeur> * _filsD;//fils droit du noeud

		int _hauteur;//hauteur max de ses fils
		
		int _balance;//balance du noeud

		/**
			* cette fonction permet de renvoyer la hauteur d'un noeud (-1 si le fils est nul, 0 s'il n'a aucun fils, 1 et plus s'il en a au moins un)
			*/
		
		int hauteur(AVL<Valeur> * arbre);

		/**
			* cette procedure permet d'effectuer une rotation gauche sur le noeud, opération propre aux AVL
			*/
		void rotationG();
		
		/**
			* cette procedure permet d'effectuer une rotation droite sur le noeud, opération propre aux AVL
			*/
		void rotationD();
	
		/**
			* cette procedure permet d'effectuer une double rotation gauche sur le noeud, opération propre aux AVL
			*/
		void dRotationG();
	
		/**
			* cette procedure permet d'effectuer une  double rotation droite sur le noeud, operation propre aux AVL
			*/	
		void dRotationD();
	
	public:
		/**
			* constructeur de l'AVL
			* @param e, un objet générique qui sera l'etiquette du noeud
			*/
		AVL(Valeur e);

		/**
			* destructeur de l'AVL
			*/
		~AVL();

		/**
			* cette fonction permet de savoir si le noeud est une feuille ou non
			*/
		bool estFeuille();

		/**
			* cette fonction retourne l'etiquette du noeud courant
			*/
		Valeur getEtiquette();

		/**
			* cette fonction retourne un pointeur vers le pere du noeud courant
			*/
		AVL<Valeur> * getPere();

		/**
			* cette fonction retourne un pointeur vers le fils gauche du noeud courant
			*/
		AVL<Valeur> * getFilsG();

		/**
			* cette fonction retourne un pointeur vers le fils droit du noeud courant
			*/
		AVL<Valeur> * getFilsD();

		/**
			* cette fonction retourne la marque associe au noeud courant
			*/
		bool getMarque();

		/**
			* cette fonction retourne le nombre de sous AVL du noeud courant
			*/
		void setMarque(bool marque);

		/**
			* cette procedure permet de suprimer en priorite le fils gauche, ou le fils droit si le fils gauche est NULL
			*/
		void supprimerFilsGD();

		/**
			* cette procedure permet de suprimer en priorite le fils droit, ou le fils gauche si le fils droit est NULL
			*/
		void supprimerFilsDG();

		/**
			* cette fonction permet d'ajouter au noeud courant un sous arbre, en fonction de l'etiquette de celui ci
			* @param AVL, le nouveau sous arbre à insérer 
			*/
		void ajouter(AVL<Valeur> * arbre);

		/**
			* cette fonction permet d'ajouter au noeud courant un fils avec une nouvelle etiquette
			* @param e, la nouvel etiquette a inserer
			*/
		void ajouter(Valeur e);
		
		/**
			* cette procedure permet de vérifier l'equilibrage du noeud courant, et d'effectuer certaine rotation si necessaire
			*/
		void equilibrage();

		/**
			* cette fonction permet de créer un vector contenant tous les noeuds, rangé selon l'ordre pre-fixé : racine,sous arbre gauche,sous arbre droit
			* @return vector, le vector des etiquette pre-fixé
			*/
		std::vector<Valeur> prefix();
		
		/**
			* cette fonction permet de créer un vector contenant tous les noeuds, rangé selon l'ordre post-fixé : sous arbre gauche,sous arbre droit, racine
			* @return vector, le vector des etiquette post-fixé
			*/
		std::vector<Valeur> suffix();
		
		/**
			* cette fonction permet de créer un vector contenant tous les noeuds, rangé selon l'ordre in-fixé : sous arbre gauche,racine,sous arbre droit
			* @return vector, le vector des etiquette pre-fixé
			*/
		std::vector<Valeur> infix();
		
		/**
			* cette fonction permet de retourner un pointeur vers la racine de l'AVL dont le noeud courant fait partie
			* @return AVL, la racine de l'arbre
			*/
		AVL<Valeur> * racine();
		
		/**
			* cette fonction permet de savoir l'appartenance ou non d'une etiquette dans l'arbre
			* @param e, l'etiquette à rechercher
			* @return boolen, VRAI si letiquette appartient à l'arbre, FAUX sinon
			*/
		bool appartient(Valeur e);

};

#include "AVL.tpp"
#endif
