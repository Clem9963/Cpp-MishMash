#ifndef __CPP4__FORME_HPP__
#define __CPP4__FORME_HPP__

#include "Point.hpp"
#include <sstream>
#include <string>

// enum COULEURS { BLANC, NOIR};
enum class COULEURS
{
	BLANC,
	NOIR,
	BLEU,
	ROUGE,
	VERT,
	JAUNE
};

class Forme
{
  protected:
	static int nbFormes_;

	int id_;
	Point p_;
	COULEURS couleur_;
	int w_;
	int h_;

  public:
	// Méthodes statiques
	static int prochainId();

	// Constructeurs
	Forme();
	Forme(Point p, COULEURS couleur);

	// Destructeurs
	virtual ~Forme();

	// Getters
	int getId();
	Point &getPoint();
	COULEURS getCouleur();
	int getLargeur() const;
	int getHauteur() const;
	int getX() const;
	int getY() const;

	//Setters
	void setCouleur(COULEURS couleur);
	void setX(int x);
	void setY(int y);
	void setLargeur(int w_);
	void setHauteur(int h_);

	// Autres
	virtual std::string toString() const;
};

#endif
