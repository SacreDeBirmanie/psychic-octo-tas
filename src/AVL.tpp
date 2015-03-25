template<typename Valeur>
		void AVL<Valeur>::rotationG() {
			std::cout<<"rotationG"<<std::endl;
			AVL<Valeur>  * b = _filsD;
			int ba = _balance;
			int bb = b->_balance;
			std::cout<<"["<<ba<<"]"<<std::endl;
			std::cout<<"["<<bb<<"]"<<std::endl;
		
			_filsD = b->_filsG;
			b->_filsG = this;

			if(_filsD !=NULL){
				_filsD->_pere = this;
			}
			b->_pere =_pere;
			_pere = b;
			_balance = ba - std::max(bb, 0) - 1;
			b->_balance = std::min(ba-2, std::min(ba+bb, bb-1));
	}

template<typename Valeur>	
		void AVL<Valeur>::rotationD() {
			std::cout<<"rotationD"<<std::endl;
			AVL<Valeur>  * b = _filsG;
			int ba = _balance;
			int bb = b->_balance;
			std::cout<<"["<<ba<<"]"<<std::endl;
			std::cout<<"["<<bb<<"]"<<std::endl;
		
			_filsG = b->_filsD;
			b->_filsD = this;
			if(_filsG !=NULL){
				_filsG->_pere = this;
			}
			b->_pere =_pere;
			_pere = b;
			_balance = ba - std::max(bb, 0) - 1;
			b->_balance = std::min(ba-2, std::min(ba+bb, bb-1));
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
			_balance = 0;
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
	int AVL<Valeur>::getNbNoeud() {
			return _nbNoeud;
	}
		
template<typename Valeur>
	void AVL<Valeur>::setMarque(bool marque) {
			_marque = marque;
	}

template<typename Valeur>
	void AVL<Valeur>::supprimerFilsGD() {
			if(_filsG != NULL){
				delete(_filsG);
				_filsG = NULL;
			}
			else if(_filsD !=NULL){
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
		int AVL<Valeur>::ajouter(AVL<Valeur> * arbre) {
			int h;
			if(_etiquette >= arbre->_etiquette) {
				if(_filsG != NULL) 
					h = _filsG->ajouter(arbre);
				else 
					_filsG = arbre;
				h = -h;
			}
			else if(_etiquette < arbre->_etiquette){
				if(_filsD != NULL) 
					h = _filsD->ajouter(arbre);
				else 
					_filsD = arbre;
			}
			else{
				return h=0;
			}

			if(h = 0)
				return 0;
			else{
				_balance = _balance + h;
				equilibrage();
			}

			if(_balance = 0)
				return 0;
			else
				return 1;
		}
		
/*template<typename Valeur>	
		int AVL<Valeur>::ajouter(Valeur e) {
			int h = 1;
			if(_etiquette < e) {
				std::cout<<"ajout de "<<e<<std::endl;
				if(_filsD != NULL) h = _filsD->ajouter(e);
				else _filsD = new AVL<Valeur>(e);
				_filsD->_pere = this;
			}
			else if(_etiquette > e) {
				std::cout<<"ajout de "<<e<<std::endl;
				if(_filsG != NULL) h = _filsG->ajouter(e);
				else _filsG = new AVL<Valeur>(e);
				h = -h;
				_filsG->_pere = this;
			}
			else h = 0;

			std::cout<<e<<" ajoute !"<<std::endl;
			_balance += h;
			std::cout<<"equilibrageBEGIN"<<std::endl;
			equilibrage();
			std::cout<<"equilibrageEND"<<std::endl;
			if(_balance == 0) return 0;
			else return 1;
		}*/

template<typename Valeur>	
		int AVL<Valeur>::ajouter(Valeur e) {
			int h;
			if(_etiquette >= e) {
				if(_filsG != NULL) 
					h = _filsG->ajouter(e);
				else 
					_filsG = new AVL<Valeur>(e);
				h = -h;
			}
			else if(_etiquette < e){
				if(_filsD != NULL) 
					h = _filsD->ajouter(e);
				else 
					_filsD = new AVL<Valeur>(e);
			}
			else{
				return h=0;
			}

			if(h = 0)
				return 0;
			else{
				_balance = _balance + h;
				equilibrage();
			}

			if(_balance = 0)
				return 0;
			else
				return 1;

		}

template<typename Valeur>	
		void AVL<Valeur>::equilibrage() {
			if(_balance == 2) {
				if(_filsD->_balance >= 0) rotationG();
				else dRotationG();
			}
			else if(_balance == -2) {
				if(_filsG->_balance >= 0) rotationD();
				else dRotationD();
			}
		}

template<typename Valeur>
		std::vector<Valeur> AVL<Valeur>::prefix() {
			std::vector<Valeur> liste;
			if(_filsG != NULL){
				std::cout<<_filsG->_etiquette<<std::endl;
				std::vector<Valeur> tmpG = _filsG->prefix();
				typename std::vector<Valeur>::iterator itG = tmpG.begin();
				for(itG;itG != tmpG.end();++itG)
					liste.push_back(*itG);
			}
			liste.push_back(_etiquette);
			if(_filsD != NULL){
				std::cout<<_filsD->_etiquette<<std::endl;
				std::vector<Valeur> tmpD = _filsD->prefix();
				typename std::vector<Valeur>::iterator itD = tmpD.begin();
				for(itD;itD != tmpD.end();++itD)
					liste.push_back(*itD);
			}
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