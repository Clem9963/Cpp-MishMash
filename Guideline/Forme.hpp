#ifndef __CPP4__FORME_HPP__
#define __CPP4__FORME_HPP__

#include "Point.hpp"

// enum COULEURS { BLANC, NOIR};
enum class COULEURS { BLANC, NOIR, BLEU, ROUGE, VERT, JAUNE };

class Forme
{
protected:
	static int nbFormes_;

	Point p_;
	int id_;
	COULEURS couleur_;

public:
	static int prochainId();

	Forme();
	Forme(Point p, COULEURS couleur);
	int getId();
	Point& getPoint();
	COULEURS getCouleur();
	void setCouleur(COULEURS couleur);
	void setX(int x);
	void setY(int y);
};

#endif
