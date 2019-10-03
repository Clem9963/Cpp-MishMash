#ifndef __CPP4__POINT_HPP__
#define __CPP4__POINT_HPP__

class Point
{
protected:
	int x_;
	int y_;

public:
	Point(int x = 0, int y = 0);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
};

// declaration d'un point ORIGINE
// il ne faudra pas oublier de l'instancier quelque part
extern Point ORIGINE;

#endif