 
 //#include "AVLStatique.hpp"
#include "AVL.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	AVL<int> * monarbre = new AVL<int>(2);
	std::cout<<"ajout4"<<std::endl;
	monarbre->ajouter(4);
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
	std::cout<<"ajout12"<<std::endl;
	monarbre->ajouter(12);
	monarbre = monarbre->racine();
	cout<<"*****************"<<endl;
	pref = monarbre->prefix();
	cout<<"**************"<<endl;

	it = pref.begin();

	for(it;it != pref.end();++it)
		cout<<*it<<",";

	cout<<"*****************"<<endl;
	in = monarbre->infix();
	cout<<"**************"<<endl;

	it = in.begin();

	for(it;it != in.end();++it)
		cout<<*it<<",";

	cout<<"*****************"<<endl;
	su = monarbre->suffix();
	cout<<"**************"<<endl;

	it = su.begin();

	for(it;it != su.end();++it)
		cout<<*it<<",";
	monarbre->ajouter(23);
	monarbre = monarbre->racine();
	cout<<"*****************"<<endl;
	pref = monarbre->prefix();
	cout<<"**************"<<endl;

	it = pref.begin();

	for(it;it != pref.end();++it)
		cout<<*it<<",";

	cout<<"*****************"<<endl;
	in = monarbre->infix();
	cout<<"**************"<<endl;

	it = in.begin();

	for(it;it != in.end();++it)
		cout<<*it<<",";

	cout<<"*****************"<<endl;
	su = monarbre->suffix();
	cout<<"**************"<<endl;

	it = su.begin();

	for(it;it != su.end();++it)
		cout<<*it<<",";
	monarbre->ajouter(5);
	monarbre = monarbre->racine();
	cout<<"*****************"<<endl;
	pref = monarbre->prefix();
	cout<<"**************"<<endl;

	it = pref.begin();

	for(it;it != pref.end();++it)
		cout<<*it<<",";

	cout<<"*****************"<<endl;
	in = monarbre->infix();
	cout<<"**************"<<endl;

	it = in.begin();

	for(it;it != in.end();++it)
		cout<<*it<<",";

	cout<<"*****************"<<endl;
	su = monarbre->suffix();
	cout<<"**************"<<endl;

	it = su.begin();

	for(it;it != su.end();++it)
		cout<<*it<<",";
	monarbre->ajouter(8);
	monarbre = monarbre->racine();
	cout<<"*****************"<<endl;
	pref = monarbre->prefix();
	cout<<"**************"<<endl;

	it = pref.begin();

	for(it;it != pref.end();++it)
		cout<<*it<<",";

	cout<<"*****************"<<endl;
	in = monarbre->infix();
	cout<<"**************"<<endl;

	it = in.begin();

	for(it;it != in.end();++it)
		cout<<*it<<",";

	cout<<"*****************"<<endl;
	su = monarbre->suffix();
	cout<<"**************"<<endl;

	it = su.begin();

	for(it;it != su.end();++it)
		cout<<*it<<",";
	monarbre->ajouter(9);
	monarbre = monarbre->racine();
	cout<<"*****************"<<endl;
	pref = monarbre->prefix();
	cout<<"**************"<<endl;

	it = pref.begin();

	for(it;it != pref.end();++it)
		cout<<*it<<",";

	cout<<"*****************"<<endl;
	in = monarbre->infix();
	cout<<"**************"<<endl;

	it = in.begin();

	for(it;it != in.end();++it)
		cout<<*it<<",";

	cout<<"*****************"<<endl;
	su = monarbre->suffix();
	cout<<"**************"<<endl;

	it = su.begin();

	for(it;it != su.end();++it)
		cout<<*it<<",";
	monarbre->ajouter(10);
	monarbre = monarbre->racine();
	cout<<"*****************"<<endl;
	pref = monarbre->prefix();
	cout<<"**************"<<endl;

	it = pref.begin();

	for(it;it != pref.end();++it)
		cout<<*it<<",";

	cout<<"*****************"<<endl;
	in = monarbre->infix();
	cout<<"**************"<<endl;

	it = in.begin();

	for(it;it != in.end();++it)
		cout<<*it<<",";

	cout<<"*****************"<<endl;
	su = monarbre->suffix();
	cout<<"**************"<<endl;

	it = su.begin();

	for(it;it != su.end();++it)
		cout<<*it<<",";
	monarbre->ajouter(1);
	monarbre = monarbre->racine();


	cout<<endl<<"#################AJOUTS FINIS##############"<<endl;
	cout<<"*****************"<<endl;
	pref = monarbre->prefix();
	cout<<"**************"<<endl;

	it = pref.begin();

	for(it;it != pref.end();++it)
		cout<<*it<<",";

	cout<<"*****************"<<endl;
	in = monarbre->infix();
	cout<<"**************"<<endl;

	it = in.begin();

	for(it;it != in.end();++it)
		cout<<*it<<",";

	cout<<"*****************"<<endl;
	su = monarbre->suffix();
	cout<<"**************"<<endl;

	it = su.begin();

	for(it;it != su.end();++it)
		cout<<*it<<",";
}
