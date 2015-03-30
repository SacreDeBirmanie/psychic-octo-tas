 
 //#include "AVLStatique.hpp"
#include "AVL.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	AVL<int> * monarbre = new AVL<int>(2);

	monarbre->ajouter(3);
	cout<<monarbre->getEtiquette()<<endl;
	monarbre = monarbre->racine();
	monarbre->ajouter(8);
	cout<<monarbre->getEtiquette()<<endl;
	monarbre = monarbre->racine();
	monarbre->ajouter(9);
	cout<<monarbre->getEtiquette()<<endl;
	monarbre = monarbre->racine();
	monarbre->ajouter(10);
	cout<<monarbre->getEtiquette()<<endl;
	monarbre = monarbre->racine();
	monarbre->ajouter(1);
	cout<<monarbre->getEtiquette()<<endl;

	cout<<"*****************"<<endl;
	vector<int> pref = monarbre->prefix();
	cout<<"**************"<<endl;

	vector<int>::iterator it = pref.begin();

	for(it;it != pref.end();++it)
		cout<<*it<<",";

	cout<<"*****************"<<endl;
	vector<int> in = monarbre->infix();
	cout<<"**************"<<endl;

	it = in.begin();

	for(it;it != in.end();++it)
		cout<<*it<<",";

	cout<<"*****************"<<endl;
	vector<int> su = monarbre->suffix();
	cout<<"**************"<<endl;

	it = su.begin();

	for(it;it != su.end();++it)
		cout<<*it<<",";
}
