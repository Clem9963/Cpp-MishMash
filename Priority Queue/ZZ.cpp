#include "ZZ.hpp"

ZZ::ZZ(const std::string &nom, const std::string &prenom, double note)
	: _nom(nom), _prenom(prenom), _note(note)
{}

bool ZZ::operator<(const ZZ &o) const
{
	if (_note < o._note)
		return true;
	return false;
}

std::ostream &operator<<(std::ostream &stream, const ZZ &zz)
{
	stream << zz._note;
	return stream;
}