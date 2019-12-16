#ifndef __SMS
#define __SMS

#include <algorithm>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class Reseau;

class Message {
public:
  static int _cle;

protected:
  std::string _exp;
  std::string _dest;
  std::string _date;
  std::string _msg;
  int _id;

public:
  static int getCle();
  Message(const std::string &exp, const std::string &dest,
          const std::string &date);
  int getId() const;
  virtual std::string afficher() const = 0;
};

class SMS : public Message {
public:
  SMS(const std::string &exp, const std::string &dest, const std::string &date);
  void setTexte(const std::string &msg);
  std::string getTexte() const;
  std::string afficher() const;
};

class Telephone {
private:
  std::string _numero;
  std::vector<Message *> _tab;
  Reseau *_reseau;

public:
  Telephone();
  Telephone(const std::string &numero);
  Telephone(const std::string &numero, Reseau *reseau);

  std::string getNumero() const;
  Reseau *getReseau() const;
  void setNumero(const std::string &numero);
  int getNbMessages() const;

  void textoter(const std::string &dest, const std::string &date);

  bool operator<(const Telephone &o) const;
};

class Reseau {
private:
  std::list<Telephone> _ensemble;

public:
  Reseau();
  std::string lister() const;

  std::list<Telephone> &getEnsemble();
  void ajouter(const std::string &numero);
  void ajouter(const std::string &numero, Reseau *reseau);
  Telephone &trouveTel(const std::string &numero);
};

class MauvaisNumero : public std::invalid_argument {
public:
  MauvaisNumero();
};

#endif