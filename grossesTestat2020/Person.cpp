/* Person.cpp
TestGross: Klassen
Loose, 18.12.2019
*/

#include <iostream>
#include <string>
#include "Person.h"
using namespace std; 

Person::Person(string name, int alter)
{
	setName(name);
	setAlter(alter);
}
Person::Person(PKW p, Haus h)
{
	Person();
	setPKW(p);
	setHaus(h);

}
Person::Person(const Person& st)
{
	if (this != &st) *this = st;
}

const Person& Person::operator = (const Person& f)
{
	Name = f.Name;
	Alter = f.Alter;
	return *this;
}

ostream& operator << (ostream& s, const Person& z)
{
	if (typeid(s) == typeid(cout))
	{
		s << "Person = {" << z.getName() << ", " << z.getAlter() << "}" << endl;
	}
	else
	{
		s << z.getName() << ";" << z.getAlter() << ";";
		s << endl;
	}
	return s;
}

istream& operator >> (istream& s, Person& z)
{
	//string pname, name;
	//int alter, ez;
	if (typeid(s) == typeid(cin))
	{
		cout << "Geben Sie Namen und Alter der Person ein:" << endl;
		s >> z.Name >> z.Alter;
	}
	else
	{
#define N 1 
		char tmpc[100];
		int w[N];
		s.getline(tmpc, 100);
		string tmp(tmpc), tmp1;
		//cout << tmp << endl;
		int id = tmp.find(";");
		int idb = 0;
		z.Name = tmp.substr(0, id);
		for (int k = 0; k < N; k++)
		{
			tmp = string(&tmpc[idb + id + 1]);
			idb = idb + id + 1;
			//cout << tmp << endl;
			id = tmp.find(";");
			w[k] = atoi((tmp.substr(0, id)).c_str());
		}
		z.Alter = w[0];
		tmp = string(&tmpc[idb + id + 1]);
		idb = idb + id + 1;
		//cout << tmp << endl;
		id = tmp.find(";");
	}
	//z = Person(pname, alter, name, ez, str, plz);
	return s;
}
