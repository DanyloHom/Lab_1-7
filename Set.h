#pragma once
#include "BitString.h"

class Set
{
private:
	BitString a;
public:
	BitString getA()const { return a; }
	void setA(unsigned long l, unsigned long r);

	void Read();
	void Display();
	void Init(unsigned long l, unsigned long r);
	string toString();

	void Exclude(int pos);
	void Include(int pos);
	int Count();
	friend Set Union(Set l, Set r); //obyednannya
	friend Set Intersection(Set l, Set r); //peretyn
	friend Set Substraction(Set l, Set r); //riznycya

};

