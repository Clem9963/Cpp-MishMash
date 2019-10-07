#ifndef __CPP4__GROUPE_HPP__
#define __CPP4__GROUPE_HPP__

#include "Forme.hpp"
#include <iostream>
#include <string>
#include <vector>

class Groupe : public Forme
{
  protected:
	std::vector<Forme *> tab_;

  public:
	using Forme::Forme;

	void ajouterForme(Forme *forme);

	void supprimerForme(int ordre);
	std::string toString() const;
};

#endif
