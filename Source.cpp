#include <iostream>
#include "BitString.h"
#include "Set.h"
#include <string>

using namespace std;


int main()
{	
	Set A, B, C, D, E;
	A.Read();
	B.Read();
	C = Union(A, B);
	cout << "A and B union = ";
	C.Display();
	cout << endl;
	D = Intersection(A, B);
	cout << "A and B intersection = ";
	D.Display();
	cout << endl;
	E = Substraction(A, B);
	cout << "A and B substraction  = ";
	E.Display();
	cout << endl;

}