#include "Groupe.hpp"

/**
 * @todo A optimiser
 * @body Le comportement de cette fonction pourrait être optimisé
 */
void Groupe::ajouterForme(Forme *f)
{
	tab_.push_back(f);

	if (f->getX() + f->getLargeur() > this->getX() + this->getLargeur())
		this->setLargeur(this->getLargeur() + f->getX() + f->getLargeur() - this->getX() + this->getLargeur());

	if (f->getX() - f->getLargeur() < this->getX() - this->getLargeur())
		this->setLargeur(this->getLargeur() + this->getX() + this->getLargeur() - f->getX() + f->getLargeur());

	if (f->getY() + f->getHauteur() > this->getY() + this->getHauteur())
		this->setHauteur(this->getHauteur() + f->getY() + f->getHauteur() - this->getY() + this->getHauteur());

	if (f->getY() - f->getHauteur() < this->getY() - this->getHauteur())
		this->setHauteur(this->getHauteur() + this->getY() + this->getHauteur() - f->getY() + f->getHauteur());
}

/**
 * @todo Gerer le redimensionnement
 */
void Groupe::supprimerForme(int ordre)
{
	tab_.erase(tab_.begin() + ordre);
}

std::string Groupe::toString() const
{
	std::ostringstream oss;
	oss << "GROUPE " << p_.getX() << " " << p_.getY() << " " << w_ << " " << h_ << std::endl;

	for (const Forme *f : tab_)
		oss << f->toString() << std::endl;

	return oss.str();
}
