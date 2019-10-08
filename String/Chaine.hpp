#ifndef CPP5__CHAINE_HPP
#define CPP5__CHAINE_HPP

#include <fstream>
#include <iostream>

class Chaine
{
  protected:
	int capacite_;
	char *tab_;

  public:
	Chaine();
	Chaine(int capacite);
	Chaine(char *source);
	Chaine(const Chaine &base);
};

#endif
