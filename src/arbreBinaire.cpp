template<typename Valeur>
	ArbreBinaire(Valeur e){
		_etiquette = e;
		_pere = null;
		_filsG = null;
		_filsD = null;
	}

template<typename Valeur>	
	ArbreBinaire<Valeur> * ajouter(Valeur e){
		if(_etiquette > e){
			if(_filsG != null)
				return _filsG.ajouter(e);
			else{
				_filsG = new ArbreBinaire<K>(e);
				return &_filsG;
			}
		}
		else
			if(_filsD !=null)
				return _filsD.ajouter(e)
			else{
				_filsD = new ArbreBinaire<K>(e);
				return &_filsD;
			}
	}
template<typename Valeur>
	ArbreBinaire<K> * supprimer(){
		if(_filsD == null){
			if(_filsG !=null){
				_pere._filsG = _filsG;
			}
		}
	}