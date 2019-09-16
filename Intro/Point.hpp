// Fichier Point.hpp

#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED

class Point
{
   // par défaut, tout est privé dans une "class"
private:
 	int x;
 	int y;

 	static int compteur;

public:
	Point();
	Point(int init_x, int init_y);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	static int getCompteur();
	void deplacerDe(int dx, int dy);
	void deplacerVers(int x, int y);

};

#endif // POINT_HPP_INCLUDED