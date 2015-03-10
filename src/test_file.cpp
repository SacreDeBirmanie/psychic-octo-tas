#include "filedePriorite.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	filedePriorite<int> mafile;
	mafile.enfiler(3);
	mafile.enfiler(5);
	mafile.enfiler(7);
	mafile.enfiler(4);
	mafile.enfiler(3);
	mafile.enfiler(8);

	cout<<"RESULTAT ATTENDU (PREMIER) [8] :";
	cout<<mafile.premier()<<endl;
	mafile.defiler();
	cout<<"RESULTAT ATTENDU (PREMIER) [7] :";
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

	cout<<"RESULTAT ATTENDU (PREMIER,ESTVIDE) [9,0(faux)] :";
	cout<<mafile.premier()<<endl;
	mafile.defiler();
	cout<<"RESULTAT ATTENDU (PREMIER,ESTVIDE) [8,0(faux)] :";
	cout<<mafile.premier()<<endl;
	mafile.defiler();
	cout<<"RESULTAT ATTENDU (PREMIER,ESTVIDE) [4,0(faux)] :";
	cout<<mafile.premier()<<endl;
	mafile.defiler();
	cout<<"RESULTAT ATTENDU (PREMIER,ESTVIDE) [3,0(faux)] :";
	cout<<mafile.premier()<<endl;
	mafile.defiler();
	cout<<"RESULTAT ATTENDU (PREMIER,ESTVIDE) [3,0(faux)] :";
	cout<<mafile.premier()<<endl;
	mafile.defiler();
	cout<<"RESULTAT ATTENDU (PREMIER,ESTVIDE) [3,0(faux)] :";
	cout<<mafile.premier()<<endl;
	mafile.defiler();

	cout<<"RESULTAT ATTENDU (ESTVIDE) [1(vrai)] :";
	cout<<mafile.estVide()<<endl;


	return 0;
}