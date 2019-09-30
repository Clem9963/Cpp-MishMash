#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

const int TAILLE = 16;
Forme::nb_formes_ = 0;

class Point
{
protected:
	int x_;
	int y_;

public:
	Point(int x, int y)
		:x_(x), y_(y)
	{}

	virtual std::string toString() = 0;
};

class Forme
{
protected:
	Point pt_;
	int w_;
	int h_;
	int ordre_;
	static int nb_formes_;

public:
	Forme(int x, int y, int w, int h, int ordre)
		:pt_(x, y), w_(w), h_(h), ordre_(ordre)
	{
		nb_formes_++;
	}

	virtual std::string toString() = 0;

	void setOrdre(int ordre)
	{
		ordre_ = ordre;
	}

	static int getNbFormes()
	{
		return nb_formes_;
	}
};

class Rectangle : public Forme
{
public:
	Rectangle(int x, int y, int w, int h, int ordre)
		:Forme(x, y, w, h, ordre)
	{}

	std::string toString() override
	{
		std::ostringstream oss;
		oss << "RECTANGLE " << x_ << " " << y_ << " " << w_ << " " << h_;
		return oss.str();
	}
};

class Cercle : public Forme
{
public:
	Cercle(int x, int y, int w, int h, int ordre)
		:Forme(x, y, w, h, ordre)
	{}

	std::string toString() override
	{
		std::ostringstream oss;
		oss << "CERCLE " << x_ << " " << y_ << " " << w_ << " " << h_;
		return oss.str();
	}
};

class Liste
{
private:
	static int compteur;

public:
	Cercle cercles[TAILLE];
	Rectangle rectangles[TAILLE];

	Liste()
	{
		for (int i = 0; i < TAILLE; ++i)
		{
			cercles[i].setOrdre(i);
			rectangles[i].setOrdre(i);
		}
	}

	int getCompteur()
	{
		return compteur;
	}

	std::string toString()
	{
		
	}
};

int Liste::compteur = 0;


int main(int, char **)
{
	Liste l;

	return EXIT_SUCCESS;
}
