#ifndef __CPP4__CERCLE_HPP__
#define __CPP4__CERCLE_HPP__

#include "Forme.hpp"
#include <string>

class Cercle : public Forme
{
  protected:
	int ordre_;

  public:
	using Forme::Forme;
	Cercle(Point p, COULEURS couleur, int ordre);

	void setRayon(int rayon);
	int getRayon() const;
	std::string toString() const;
};

#endif
