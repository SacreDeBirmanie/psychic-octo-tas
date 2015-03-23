//#include "AVLStatique.hpp"
#include "AVL.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	AVL<int> * monarbre = new AVL<int>(0);

	cout<<"debut de l'ajout"<<endl;
	cout<<"*******1**********"<<endl;
	monarbre->ajouter(1);
	monarbre = monarbre->racine();
	cout<<"********2*********"<<endl;
	monarbre->ajouter(2);
monarbre = monarbre->racine();
cout<<"**********3*******"<<endl;
	monarbre->ajouter(3);
monarbre = monarbre->racine();
cout<<"********4*********"<<endl;
	monarbre->ajouter(4);
monarbre = monarbre->racine();
	monarbre->ajouter(5);
monarbre = monarbre->racine();
	monarbre->ajouter(6);
monarbre = monarbre->racine();
	monarbre->ajouter(7);
	monarbre = monarbre->racine();
	monarbre->ajouter(8);
monarbre = monarbre->racine();
	cout<<"fin de l'ajout"<<endl;
	cout<<monarbre->getEtiquette()<<endl;
	cout<<"*****************"<<endl;
	vector<int> pref = monarbre->prefix();
	cout<<"**************"<<endl;

	vector<int>::iterator it = pref.begin();

	for(it;it != pref.end();++it)
		cout<<*it<<",";
}
