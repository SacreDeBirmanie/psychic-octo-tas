template<typename Valeur>
	int AVL<Valeur>::hauteur(AVL<Valeur> * arbre){
		if(arbre ==NULL)
			return -1;
		else
			return arbre->_hauteur;
	}


/*template<typename Valeur>
		void AVL<Valeur>::rotationG() {
			std::cout<<"rotationG sur "<<_etiquette<<std::endl;
			AVL<Valeur>  * pereA = _pere;
			AVL<Valeur> * filsD = _filsD;
			AVL<Valeur> * petitFilsG = _filsD->_filsG;

			int balance_b = filsD->_balance;
			int balance_a = _balance;

			if(pereA !=NULL)
				if(pereA->_filsD == this)
					pereA->_filsD = filsD;
				else if(pereA->_filsG == this)
					pereA->_filsG = filsD;
			

			filsD->_pere = pereA;

			_filsD = petitFilsG;
			if(petitFilsG != NULL)
				petitFilsG->_pere = this;

			_pere = filsD;
			filsD->_filsG = this;

			_balance = balance_a - std::max(balance_b, 0) - 1;
			filsD->_balance = std::min(balance_a-2, std::min(balance_a+balance_b-2, balance_b-1));

	}*/
template<typename Valeur>
		void AVL<Valeur>::rotationG() {
			//std::cout<<"rotationG sur "<<_etiquette<<std::endl;
			assert(_filsD !=NULL);
			AVL<Valeur>  * pereA = _pere;
			AVL<Valeur> * filsD = _filsD;

			int balance_b = filsD->_balance;
			int balance_a = _balance;

			_filsD = filsD->_filsG;
			if(_filsD !=NULL)
				_filsD->_pere = this;

			filsD->_filsG = this;
			_pere = filsD;

			if(pereA !=NULL)
				if(pereA->_filsD == this)
					pereA->_filsD = filsD;
				else if(pereA->_filsG == this)
					pereA->_filsG = filsD;
			filsD->_pere = pereA;


				_hauteur = std::max(hauteur(_filsG), hauteur(_filsD)) +1;
				filsD->_hauteur = std::max(hauteur(filsD->_filsG),hauteur(filsD->_filsD)) + 1;

				_balance = hauteur (_filsD) - hauteur(_filsG);
				filsD->_balance = hauteur(filsD->_filsD) - hauteur(filsD->_filsG);

			//std::cout<<"Fin de rotationG"<<std::endl;

	}

/*template<typename Valeur>	
		void AVL<Valeur>::rotationD() {
			std::cout<<"rotationD sur "<<_etiquette<<std::endl;
			AVL<Valeur>  * pereA = _pere;
			AVL<Valeur> * filsG = _filsG;
			AVL<Valeur> * petitFilsD = _filsG->_filsD;

			int balance_b = filsG->_balance;
			int balance_a = _balance;
		
			if(pereA !=NULL)
				if(pereA->_filsD == this)
					pereA->_filsD = filsG;
				else if(pereA->_filsG == this)
					pereA->_filsG = filsG;
		
			filsG->_pere = pereA;

			_filsG = petitFilsD;
			if(petitFilsD != NULL)
				petitFilsD->_pere = this;

			_pere = filsG;
			filsG->_filsD = this;

			_balance = balance_a - std::max(balance_b, 0) - 1;
			filsG->_balance = std::min(balance_a-2, std::min(balance_a+balance_b-2, balance_b-1));
		}*/
template<typename Valeur>	
		void AVL<Valeur>::rotationD() {
			//std::cout<<"rotationD sur "<<_etiquette<<std::endl;
			AVL<Valeur>  * pereA = _pere;
			AVL<Valeur> * filsG = _filsG;

			int balance_b = filsG->_balance;
			int balance_a = _balance;

			_filsG = filsG->_filsD;
			if(_filsG !=NULL)
				_filsG->_pere = this;

			filsG->_filsD = this;
			_pere = filsG;

			if(pereA !=NULL)
				if(pereA->_filsD == this)
					pereA->_filsD = filsG;
				else if(pereA->_filsG == this)
					pereA->_filsG = filsG;
			filsG->_pere = pereA;

			_hauteur = std::max(hauteur(_filsG), hauteur(_filsD)) +1;
				filsG->_hauteur = std::max(hauteur(filsG->_filsG),hauteur(filsG->_filsD)) + 1;

				_balance = hauteur (_filsD) - hauteur(_filsG);
				filsG->_balance = hauteur(filsG->_filsD) - hauteur(filsG->_filsG);
		}


template<typename Valeur>
		void AVL<Valeur>::dRotationG() {
			_filsD->rotationD();
			rotationG();
		}

template<typename Valeur>	
		void AVL<Valeur>::dRotationD() {
			_filsG->rotationG();
			rotationD();
		}
	
template<typename Valeur>
		AVL<Valeur>::AVL(Valeur e) {
			_etiquette = e;
			_pere = NULL;
			_filsG = NULL;
			_filsD = NULL;
			_marque = false;
			_garde = false;
			_balance = 0;
			_hauteur = 0;
		}

template<typename Valeur>
		AVL<Valeur>::~AVL() {
			delete _filsG;
			delete _filsD;
		}

template<typename Valeur>
	bool AVL<Valeur>::estFeuille() {
			if(_filsG == NULL && _filsD == NULL)
				return true;
			else
				return false;
	}


template<typename Valeur>
	Valeur AVL<Valeur>::getEtiquette() {
			return _etiquette;
	}
		

template<typename Valeur>
	AVL<Valeur> * AVL<Valeur>::getPere() {
			return _pere;
	}
		

template<typename Valeur>
	AVL<Valeur> * AVL<Valeur>::getFilsG() {
			return _filsG;
	}
		
template<typename Valeur>
	AVL<Valeur> * AVL<Valeur>::getFilsD() {
			return _filsD;
	}
		
template<typename Valeur>
	bool AVL<Valeur>::getMarque() {
			return _marque;
	}
		
template<typename Valeur>
	void AVL<Valeur>::setMarque(bool marque) {
			_marque = marque;
	}

template<typename Valeur>
	void AVL<Valeur>::supprimerFilsGD() {
			if(_filsG != NULL){
				_garde = true;
				delete(_filsG);
				_filsG = NULL;
			}
			else if(_filsD !=NULL){
				_garde = true;
				delete(_filsD);
				_filsD = NULL;
			}
	}

template<typename Valeur>
	void AVL<Valeur>::supprimerFilsDG() {
			if(_filsD != NULL){
				delete(_filsD);
				_filsD = NULL;
			}
			else if(_filsG !=NULL){
				delete(_filsG);
				_filsG = NULL;
			}
	}
		
template<typename Valeur>	
		void AVL<Valeur>::ajouter(AVL<Valeur> * arbre) {
		if(arbre->_etiquette < _etiquette){
			if(_filsG != NULL){
				_filsG->ajouter(arbre);
				_hauteur = std::max(hauteur(_filsG),hauteur(_filsD))+1;

			}
			else{
				_filsG = arbre;
				_filsG->_pere = this;
				_hauteur = std::max(hauteur(_filsD),1);
			}
		}
		else if(_etiquette < arbre->_etiquette){
			if(_filsD != NULL){
				_filsD->ajouter(arbre);
				_hauteur = std::max(hauteur(_filsG),hauteur(_filsD))+1;
			}
			else{
				_filsD = arbre;
				_filsD->_pere=this;
				_hauteur = std::max(hauteur(_filsG),1);
			}
		}
		else{
			if(_filsG != NULL){
				_filsG->ajouter(arbre);
				_hauteur = std::max(hauteur(_filsG),hauteur(_filsD))+1;

			}
			else{
				_filsG = arbre;
				_filsG->_pere = this;
				_hauteur = std::max(hauteur(_filsD),1);
			}
		}

		_balance = hauteur(_filsD) - hauteur(_filsG);
		//std::cout<<std::max(hauteur(_filsD),0)<<"_"<<std::max(hauteur(_filsG),0)<<"**"<<_balance<<": "<<_etiquette<<std::endl;
		//modif ajout VAL
		if(_garde == false)
			equilibrage();

		_hauteur = std::max(hauteur(_filsG),hauteur(_filsD))+1;
		_balance = hauteur(_filsD) - hauteur(_filsG);
		//modif ajout VAL
}
		
template<typename Valeur>	
		void AVL<Valeur>::ajouter(Valeur e) {

		if(e <= _etiquette){
			if(_filsG != NULL){
				_filsG->ajouter(e);
				_hauteur = std::max(hauteur(_filsG),hauteur(_filsD))+1;

			}
			else{
				_filsG = new AVL<Valeur>(e);
				_filsG->_pere = this;
				_hauteur = std::max(hauteur(_filsD),1);
			}
		}
		else{
			if(_filsD != NULL){
				_filsD->ajouter(e);
				_hauteur = std::max(hauteur(_filsG),hauteur(_filsD))+1;
			}
			else{
				_filsD = new AVL<Valeur>(e);
				_filsD->_pere=this;
				_hauteur = std::max(hauteur(_filsG),1);
				std::cout<<_hauteur<<"||||"<<std::endl;
			}
		}

		_balance = hauteur(_filsD) - hauteur(_filsG);
		//std::cout<<std::max(hauteur(_filsD),0)<<"_"<<std::max(hauteur(_filsG),0)<<"**"<<_balance<<": "<<_etiquette<<std::endl;
		//modif ajout VAL
		if(_garde == false)
			equilibrage();
		_hauteur = std::max(hauteur(_filsG),hauteur(_filsD))+1;
		_balance = hauteur(_filsD) - hauteur(_filsG);
		//modif ajout VAL

}


template<typename Valeur>	
		void AVL<Valeur>::equilibrage() {
			if(_balance == 2) {
				if(_filsD->_balance >= 0) rotationG();
				else dRotationG();
			}
			else if(_balance == -2) {
				if(_filsG->_balance <= 0) rotationD();
				else dRotationD();
			}
		}

template<typename Valeur>
		std::vector<Valeur> AVL<Valeur>::prefix() {
			std::vector<Valeur> liste;
			liste.push_back(_etiquette);
			if(_filsG != NULL){
				std::vector<Valeur> tmpG = _filsG->prefix();
				typename std::vector<Valeur>::iterator itG = tmpG.begin();
				for(itG;itG != tmpG.end();++itG)
					liste.push_back(*itG);
			}
			
			if(_filsD != NULL){
				std::vector<Valeur> tmpD = _filsD->prefix();
				typename std::vector<Valeur>::iterator itD = tmpD.begin();
				for(itD;itD != tmpD.end();++itD)
					liste.push_back(*itD);
			}
			return liste;
		}

template<typename Valeur>
		std::vector<Valeur> AVL<Valeur>::infix() {
			std::vector<Valeur> liste;
			if(_filsG != NULL){
				std::vector<Valeur> tmpG = _filsG->infix();
				typename std::vector<Valeur>::iterator itG = tmpG.begin();
				for(itG;itG != tmpG.end();++itG){

					liste.push_back(*itG);
				}
			}
			liste.push_back(_etiquette)	;
			if(_filsD != NULL){
				std::vector<Valeur> tmpD = _filsD->infix();
				typename std::vector<Valeur>::iterator itD = tmpD.begin();
				for(itD;itD != tmpD.end();++itD){
					liste.push_back(*itD);
				}
			}
			return liste;
		}

template<typename Valeur>
		std::vector<Valeur> AVL<Valeur>::suffix() {
			std::vector<Valeur> liste;
			if(_filsG != NULL){
				std::vector<Valeur> tmpG = _filsG->suffix();
				typename std::vector<Valeur>::iterator itG = tmpG.begin();
				for(itG;itG != tmpG.end();++itG)
					liste.push_back(*itG);
			}
			
			if(_filsD != NULL){
				std::vector<Valeur> tmpD = _filsD->suffix();
				typename std::vector<Valeur>::iterator itD = tmpD.begin();
				for(itD;itD != tmpD.end();++itD)
					liste.push_back(*itD);
			}
			liste.push_back(_etiquette);
			return liste;
		}

template<typename Valeur>	
		AVL<Valeur> * AVL<Valeur>::racine() {
			if(_pere == NULL) return this;
			else return _pere->racine();
		}

template<typename Valeur>	
		bool AVL<Valeur>::appartient(Valeur e) {
			if(_etiquette < e) {
				if(_filsD != NULL) return _filsD->appartient(e);
				else return false;
			}
			else if(_etiquette > e) {
				if(_filsG != NULL) return _filsG->appartient(e);
				else return false;
			}
			else return true;
		}
