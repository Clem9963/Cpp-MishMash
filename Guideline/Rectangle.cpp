#include "Rectangle.hpp"

Rectangle::Rectangle(Point p, COULEURS couleur, int ordre)
	: Forme(p, couleur), ordre_(ordre)
{
}

std::string Rectangle::toString() const
{
	std::ostringstream oss;
	oss << "RECTANGLE " << p_.getX() << " " << p_.getY() << " " << w_ << " " << h_;
	return oss.str();
}
