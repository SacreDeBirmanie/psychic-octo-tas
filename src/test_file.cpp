#include "filedePriorite.hpp"
#include "filedePrioriteN.hpp"

#include "filedePrioriteAVL.hpp"
#include "Comparateur.cpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	filedePrioriteAVL<int> mafile;
	cout<<"RESULTAT ATTENDU (PREMIER) [levé d'exeption] :";
	//vérification de la levé de l'exeption pour premier
	try{
	mafile.premier();
	}
	catch(const std::string & Msg){
		std::cerr << Msg;
	}

    //bloc de test pour la file
	try{
	mafile.enfiler(3);
	mafile.enfiler(5);
	mafile.enfiler(7);
	mafile.enfiler(4);
	mafile.enfiler(3);
	mafile.enfiler(8);
	
	mafile.afficher();
	
	cout<<"RESULTAT ATTENDU (PREMIER) [3] :";
	cout<<mafile.premier()<<endl;
	mafile.defiler();
	cout<<"RESULTAT ATTENDU (PREMIER) [3] :";
	cout<<mafile.premier()<<endl;
	mafile.defiler();

	mafile.defiler();
	mafile.defiler();
	mafile.defiler();
	mafile.defiler();

	cout<<"RESULTAT ATTENDU (ESTVIDE) [1(vrai)] :";
	cout<<mafile.estVide()<<endl;
	mafile.enfiler(8);
	cout<<"RESULTAT ATTENDU (PREMIER) [8] :";
	cout<<mafile.premier()<<endl;
	mafile.enfiler(3);
	mafile.enfiler(4);
	mafile.enfiler(3);
	mafile.enfiler(9);
	mafile.enfiler(3);
	
	mafile.afficher();
	cout<<"RESULTAT ATTENDU (PREMIER,ESTVIDE) [3,0(faux)] :";
	cout<<mafile.premier()<<","<<mafile.estVide()<<endl;
	mafile.defiler();
	cout<<"RESULTAT ATTENDU (PREMIER,ESTVIDE) [3,0(faux)] :";
	cout<<mafile.premier()<<","<<mafile.estVide()<<endl;
	mafile.defiler();
	cout<<"RESULTAT ATTENDU (PREMIER,ESTVIDE) [3,0(faux)] :";
	cout<<mafile.premier()<<","<<mafile.estVide()<<endl;
	mafile.defiler();
	cout<<"RESULTAT ATTENDU (PREMIER,ESTVIDE) [4,0(faux)] :";
	cout<<mafile.premier()<<","<<mafile.estVide()<<endl;
	mafile.defiler();
	cout<<"RESULTAT ATTENDU (PREMIER,ESTVIDE) [8,0(faux)] :";
	cout<<mafile.premier()<<","<<mafile.estVide()<<endl;
	mafile.defiler();
	cout<<"RESULTAT ATTENDU (PREMIER,ESTVIDE) [9,0(faux)] :";
	cout<<mafile.premier()<<","<<mafile.estVide()<<endl;
	mafile.defiler();

	cout<<"RESULTAT ATTENDU (ESTVIDE) [1(vrai)] :";
	cout<<mafile.estVide()<<endl;
	}
	catch(const std::string & Msg){
		std::cerr << Msg;
	}

    cout<<"RESULTAT ATTENDU (DEFILER) [levé d'exeption] :";
	//vérification de la levé de l'exeption pour defiler
	try{
	mafile.defiler();
	}
	catch(const std::string & Msg){
		std::cerr << Msg;
	}


	return 0;
}
