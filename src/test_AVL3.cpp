#include "AVL.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	AVL<int> * monarbre = new AVL<int>(10);
	std::cout<<"ajout12"<<std::endl;
	monarbre->ajouter(12);
	std::cout<<"Fin 12"<<std::endl;
	monarbre = monarbre->racine();
	std::cout<<"ajout11"<<std::endl;
	monarbre->ajouter(11);
	std::cout<<"Fin 11"<<std::endl;
	monarbre = monarbre->racine();

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