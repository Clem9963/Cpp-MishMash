#ifndef PRIORITY_QUEUE_ZZ_H_
#define PRIORITY_QUEUE_ZZ_H_

#include <ostream>
#include <string>

class ZZ
{
  private:
	std::string _nom, _prenom;
	double _note;

  public:
	ZZ(const std::string &nom, const std::string &prenom, double note);

	bool operator<(const ZZ &o) const;
	friend std::ostream &operator<<(std::ostream &stream, const ZZ &zz);
};

#endif