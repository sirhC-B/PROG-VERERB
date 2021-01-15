#pragma once
/* Person.h
TestGross: Klassen
- Person - konkret
Loose, 18.12.2019
*/

#include <iostream>
#include <string>
#include "Haus.h" 
#include "Fahrzeug.h"
#include "PKW.h"

using namespace std;

class Person : public Haus, public PKW
{
private:
	string Name;
	int Alter;
	
public:
	Person(string name = string("Loose"), int alter = 100);
	Person(PKW p, Haus h);
	Person(const Person& st);
	~Person() {};
	string getName() const { return Name; }
	void setName(string name) { Name = name; }
	int getAlter() const { return Alter; }
	void setAlter(int alter) { Alter = alter; }
	
	//custom
	void setPKW(PKW p);
	PKW getPKW() const;
	void setHaus(Haus h);
	Haus getHaus() const;
	

	const Person& operator = (const Person& f);
	friend ostream& operator << (ostream& s, const Person& z);
	friend istream& operator >> (istream& s, Person& z);
};

