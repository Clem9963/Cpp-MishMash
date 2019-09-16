// Fichier Point.cpp

#include <iostream>  // Inclusion d'un fichier standard
#include "Point.hpp" // Inclusion d'un fichier du répertoire courant

int Point::compteur = 0;

Point::Point()
	:x(0), y(0)
{
	std::cout << "Constructeur sans argument" << std::endl;
	compteur++;
}

Point::Point(int init_x, int init_y)
	:x(init_x), y(init_y)
{
	std::cout << "Constructeur avec arguments" << std::endl;
	compteur++;
}

void Point::setX(int x)
{
	this->x = x;
}

void Point::setY(int y)
{
	this->y = y;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

int Point::getCompteur()
{
	return compteur;
}

void Point::deplacerDe(int dx, int dy)
{
	setX(x + dx);
	setY(y + dy);
}

void Point::deplacerVers(int x, int y)
{
	setX(x);
	setY(y);
}
