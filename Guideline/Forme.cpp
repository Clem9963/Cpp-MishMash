#include "Forme.hpp"

int Forme::nbFormes_ = 0;

Forme::Forme()
	:p_(), id_(prochainId()), couleur_(COULEURS::BLEU)
{
	nbFormes_++;
}

Forme::Forme(Point p, COULEURS couleur)
	:p_(p), id_(prochainId()), couleur_(couleur)
{
	nbFormes_++;
}


int Forme::prochainId()
{
	return nbFormes_;
}

int Forme::getId()
{
	return id_;
}

Point& Forme::getPoint()
{
	return p_;
}

COULEURS Forme::getCouleur()
{
	return couleur_;
}

void Forme::setCouleur(COULEURS couleur)
{
	couleur_ = couleur;
}

void Forme::setX(int x)
{
	p_.setX(x);
}

void Forme::setY(int y)
{
	p_.setY(y);
}