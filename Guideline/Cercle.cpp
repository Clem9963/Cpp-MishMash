#include "Cercle.hpp"

Cercle::Cercle(Point p, COULEURS couleur, int ordre)
	: Forme(p, couleur), ordre_(ordre)
{
}

void Cercle::setRayon(int rayon)
{
    w_ = rayon;
    h_ = rayon;
}

int Cercle::getRayon() const
{
	return w_;
}

std::string Cercle::toString() const
{
	std::ostringstream oss;
	oss << "CERCLE " << p_.getX() << " " << p_.getY() << " " << w_ << " " << h_;
	return oss.str();
}