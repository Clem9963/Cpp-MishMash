#ifndef __CPP4__RECTANGLE_HPP__
#define __CPP4__RECTANGLE_HPP__

#include "Forme.hpp"
#include <string>

class Rectangle : public Forme
{
  protected:
	int ordre_;

  public:
	using Forme::Forme;
	Rectangle(Point p, COULEURS couleur, int ordre);
	std::string toString() const;
};

#endif
