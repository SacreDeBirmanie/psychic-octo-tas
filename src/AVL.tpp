template<typename Valeur>
		void rotationG() {
			AVL<Valeur> b = filsD;
			int ba = balance;
			int bb = b.balance;
		
			filsD = b.filsG;
			b.filsG.pere = this;
			b.filsG = this;
			b.pere = pere;
			if(pere!=null && pere.filsD == this) pere.filsD = b;
			else if(pere!=null) pere.filsG = b;
			pere = b;
		
			balance = ba - Math.max(bb, 0) - 1;
			b.balance = Math.min(ba-2, Math.min(ba+bb, bb-1));
	}

template<typename Valeur>	
		void rotationD() {
			AVL<Valeur> b = filsG;
			int ba = balance;
			int bb = b.balance;
			
			filsG = b.filsD;
			b.filsD.pere = this;
			b.filsD = this;
			b.pere = pere;
			if(pere!=null && pere.filsD == this) pere.filsD = b;
			else if(pere!=null) pere.filsG = b;
			pere = b;
			
			balance = ba - Math.max(bb, 0) - 1;
			b.balance = Math.min(ba-2, Math.min(ba+bb, bb-1));
		}

template<typename Valeur>
		void dRotationG() {
			filsD.rotationD();
			rotationG();
		}

template<typename Valeur>	
		void dRotationD() {
			filsG.rotationG();
			rotationD();
		}
	
template<typename Valeur>
		AVL(int e, Valeur v) {
			etiquette = e;
			valeur = v;
			pere = null;
			filsG = null;
			filsD = null;
			balance = 0;
		}
		
template<typename Valeur>	
		Valeur getValeur() {
			return valeur;
		}

template<typename Valeur>	
		int ajouter(AVL<K> arbre) {
			int h = 1;
			if(etiquette < arbre->_etiquette) {
				if(filsD != null) h = filsD.ajouter(arbre);
				else filsD = arbre;
			}
			else if(etiquette > arbre->_etiquette) {
				if(filsG != null) h = filsG.ajouter(arbre);
				else filsG = arbre;
				h = -h;
			}
			else h = 0;
			balance += h;
			//equilibrage();
			if(balance == 0) return 0;
			else return 1;
		}
		
template<typename Valeur>	
		int ajouter(Valeur e) {
			int h = 1;
			if(etiquette < e) {
				if(filsD != null) h = filsD.ajouter(e,v);
				else filsD = new AVL<Valeur>(e,v);
			}
			else if(etiquette > e) {
				if(filsG != null) h = filsG.ajouter(e,v);
				else filsG = new AVL<Valeur>(e,v);
				h = -h;
			}
			else h = 0;
			balance += h;
			//equilibrage();
			if(balance == 0) return 0;
			else return 1;
		}

template<typename Valeur>	
		void equilibrage() {
			if(balance == 2) {
				if(filsD.balance >= 0) rotationG();
				else dRotationG();
			}
			else if(balance == -2) {
				if(filsG.balance >= 0) rotationD();
				else dRotationD();
			}
		}

template<typename Valeur>
		ArrayList<Valeur> prefix() {
			ArrayList<Valeur> liste = new ArrayList<Valeur>();
			if(filsG != null) liste.addAll(filsG.prefix());
			liste.add(valeur);
			if(filsD != null) liste.addAll(filsD.prefix());
			return liste;
		}

template<typename Valeur>	
		AVL<Valeur> racine() {
			if(pere == null) return this;
			else return pere.racine();
		}

template<typename Valeur>	
		bool appartient(int e) {
			if(etiquette < e) {
				if(filsD != null) return filsD.appartient(e);
				else return false;
			}
			else if(etiquette > e) {
				if(filsG != null) return filsG.appartient(e);
				else return false;
			}
			else return true;
		}

template<typename Valeur>
	AVL<K> * supprimer(){

	}

