#include "Forme.hpp"

int Forme::nbFormes_ = 0;

Forme::Forme() : id_(prochainId()), p_(), couleur_(COULEURS::BLEU), w_(0), h_(0)
{
	nbFormes_++;
}

Forme::Forme(Point p, COULEURS couleur)
	: id_(prochainId()), p_(p), couleur_(couleur), w_(0), h_(0)
{
	nbFormes_++;
}

Forme::~Forme()
{
}

int Forme::prochainId() { return nbFormes_; }

int Forme::getId() { return id_; }

Point &Forme::getPoint() { return p_; }

COULEURS Forme::getCouleur() { return couleur_; }

void Forme::setCouleur(COULEURS couleur) { couleur_ = couleur; }

void Forme::setX(int x) { p_.setX(x); }

void Forme::setY(int y) { p_.setY(y); }

void Forme::setLargeur(int w)
{
	w_ = w;
}
void Forme::setHauteur(int h)
{
	h_ = h;
}

int Forme::getLargeur() const { return w_; }

int Forme::getHauteur() const { return h_; }

int Forme::getX() const
{
	return p_.getX();
}

int Forme::getY() const
{
	return p_.getY();
}

std::string Forme::toString() const
{
	std::ostringstream oss;
	oss << "FORME " << p_.getX() << " " << p_.getY() << " " << w_ << " " << h_;
	return oss.str();
}
