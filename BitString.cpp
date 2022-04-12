#include "BitString.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void BitString::Read()
{
	unsigned long l, r;
	cout << "first part = " << endl;
	cin >> l;
	cout << "second part = " << endl;
	cin >> r;
	Init(l, r);
}

void BitString::Display()
{
	cout << "first part = " << first << endl;
	cout << "second part = " << second << endl;
}

void BitString::Init(unsigned long l, unsigned long r)
{
	setFirst(l);
	setSecond(r);
}

string BitString::toString()
{
	stringstream sout;
	sout << first << second << endl;
	return sout.str();
}

void BitString::Not()
{
	~first;
	~second;
}

void BitString::ShiftLeft(int pos)
{
	unsigned long mask;								//stvoryuemo masku
	mask = second & ~(~0 << pos) << (32 - pos);		//inicializaciya masky( 1 - zapovnyuemo odynycyamy  2 - sunemo na pos, stvoryuemo neobhidnu kilist nuliv  3 - robymo zaperechennya, shchob nuli stalu 1 i navpaky  4 - sunemo napochatok, shchob skopiyuvaty neobhidni bity
	mask >> (32 - pos);								//sunemo vkinec, shchob mozhna bulo korectno vstavyty u first
	first << pos;									//sunemo first
	second << pos;									//sunemo second
	first | mask;									//vstavlyaemo potribni bity v pochatok first
}

void BitString::ShiftRight(int pos)
{
	unsigned long mask;
	mask = first & ~(~0 << pos);					//inicializaciya masky( 1 - zapovnyuemo odynycyamy  2 - sunemo na pos, stvoryuemo neobhidnu kilist nuliv  3 - robymo zaperechennya, shchob nuli stalu 1 i navpaky  4 - vony i tak vkinci
	mask << (32 - pos);								///sunemo napochatok, shchob mozhna bulo korectno vstavyty u second
	first >> pos;									//sunemo first
	second >> pos;									//sunemo second
	second | mask;									//vstavlyaemo potribni bity v kinec second
}

BitString And(BitString l, BitString r)
{
	BitString A;
	A.first = l.first & r.first;
	A.second = l.second & r.second;

	return A;
}

BitString Or(BitString l, BitString r)
{
	BitString A;
	A.first = l.first | r.first;
	A.second = l.second | r.second;

	return A;
}

BitString XOr(BitString l, BitString r)
{
	BitString A;
	A.first = l.first ^ r.first;
	A.second = l.second ^ r.second;

	return A;
}

