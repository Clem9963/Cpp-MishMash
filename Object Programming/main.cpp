#include <iostream>

class Bavarde {
private:
	int m_arg;

public:
	Bavarde(int arg = 0)
		:m_arg(arg)
	{
		std::cout << "Construction de Bavarde, argument : " << arg << std::endl;
	}

	int getArg()
	{
		return m_arg;
	}

	void afficher()
	{
		std::cout << "Affichage de " << m_arg << std::endl;
	}

	~Bavarde()
	{
		std::cout << "Tais-toi " << m_arg << std::endl;
	}
};// bizarre(1);	// Création d'un objet bizarre

class Couple
{
private:
	Bavarde m_bvrd1;
	Bavarde m_bvrd2;
public:
	Couple(int arg1, int arg2)
		:m_bvrd1(arg1), m_bvrd2(arg2)
	{
		std::cout << "Construction d'un couple" << std::endl;
	}
};

class Famille
{
public:
	Bavarde *tab;
	int taille;
public:
	Famille(int nb)
		:tab(new Bavarde[nb]), taille(nb)
	{}

	~Famille()
	{
		delete[] tab;
	}
	
};

//Bavarde globale(2);

void fonction(Bavarde& b) {
	std::cout << "L'argument passé au constructeur est : " << b.getArg() << std::endl;
}

int main(int, char **) {
	Famille f(12);

	return 0;
}