#include "Chaine.hpp"

#include <cstdlib>
#include <cstring>

Chaine::Chaine()
	: capacite_(-1), tab_(nullptr)
{
}

Chaine::Chaine(int capacite)
	: capacite_(capacite), tab_(static_cast<char *>(malloc(sizeof(char) * capacite_)))
{
}

Chaine::Chaine(char *source)
	: capacite_(strlen(source) + 1), tab_(static_cast<char *>(malloc(sizeof(char) * capacite_)))
{
	strcpy(tab_, base.tab_);
}

Chaine::Chaine(const Chaine &base)
	: capacite_(base.capacite_), tab_(static_cast<char *>(malloc(sizeof(char) * capacite_)))
{
	strcpy(tab_, base.tab_);
}