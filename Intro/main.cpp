
#include <iostream>
#include "Point.hpp" // Inclusion d'un fichier du répertoire courant

int main(int, char**)
{
	std::cout << Point::getCompteur() << std::endl;

	Point *p1 = new Point(0, 2);
	Point *p2 = new Point(8, 1);

	std::cout << Point::getCompteur() << std::endl;

	p1->setX(4);

	std::cout << p1->getX() << std::endl;
	std::cout << p2->getY() << std::endl;

	delete p1;
	delete p2;

	return 0;
}

#if 0
/* on peut utiliser le mot clé const pour définir la taille d'un tableau statique en C++ */
const int TAILLE = 10;

int main(int, char**) {

	int tab[TAILLE];

	for (int i=0; i < TAILLE; ++i) {
		tab[i] = i %2;
		cout << tab[i] << " ";
	}

	cout << endl;

	return TAILLE;
}

#endif

#if 0

void fonction1(int a) {
	std::cout << &a << std::endl;
}

void fonction1(int& a) {
	std::cout << &a << std::endl;
}

int main(int, char **) {
	int age = 41;

	std::cout << &age << std::endl;
	fonction1(age);
	fonction1(age);

	return 0;
}

#endif

#if 0
void echangeRefs(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void echangePtrs(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int main(int, char **)
{
	int  a = 3;
	int  b = 4;

	echangePtrs(&a, &b);
	std::cout << "a : " << a << " b : " << b << std::endl;
	echangeRefs(a,b);
	std::cout << "a : " << a << " b : " << b << std::endl;
}
#endif

#if 0
int main(int, char**) {
	int * p = new int;

	*p = 3;
	std::cout << *p << std::endl;

	delete p;

	return 0;
}
#endif

#if 0
int main(int, char**) {
	const int taille = 500;

	int * p = new int[taille];

	for(auto i = 0; i< taille; ++i ) p[i] = i;
	for(auto i = 0; i< taille; ++i ) std::cout << p[i] << std::endl;

	delete[] p;

	return 0;
}
#endif