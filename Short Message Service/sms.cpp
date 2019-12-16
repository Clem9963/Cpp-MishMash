#include "sms.hpp"

Telephone::Telephone() : _numero(""), _reseau(nullptr) {}

Telephone::Telephone(const std::string &numero)
    : _numero(numero), _reseau(nullptr) {}

Telephone::Telephone(const std::string &numero, Reseau *reseau)
    : _numero(numero), _reseau(reseau) {}

std::string Telephone::getNumero() const { return _numero; }
Reseau *Telephone::getReseau() const { return _reseau; }

void Telephone::setNumero(const std::string &numero) { _numero = numero; }

int Telephone::getNbMessages() const { return _tab.size(); }

bool Telephone::operator<(const Telephone &o) const {
  return _numero < o._numero;
}

void Telephone::textoter(const std::string &dest, const std::string &date) {
  auto it = std::find_if(
      getReseau()->getEnsemble().begin(), getReseau()->getEnsemble().end(),
      [&dest](const Telephone &tel) { return tel.getNumero() == dest; });

  if (it == getReseau()->getEnsemble().end()) {
    getReseau()->ajouter(dest);
  }

  _tab.push_back(new SMS(getNumero(), dest, date));
  getReseau()->trouveTel(dest)._tab.push_back(new SMS(getNumero(), dest, date));
}

Reseau::Reseau() : _ensemble({}) {}

std::list<Telephone> &Reseau::getEnsemble() { return _ensemble; }

std::string Reseau::lister() const {
  std::ostringstream oss;
  for (const Telephone &telephone : _ensemble) {
    oss << telephone.getNumero() << "\n";
  }

  return oss.str();
}

void Reseau::ajouter(const std::string &numero) {
  _ensemble.insert(std::upper_bound(_ensemble.begin(), _ensemble.end(),
                                    Telephone(numero, this)),
                   Telephone(numero, this));
}

Telephone &Reseau::trouveTel(const std::string &numero) {
  auto it = std::find_if(
      _ensemble.begin(), _ensemble.end(),
      [&numero](const Telephone &tel) { return tel.getNumero() == numero; });

  if (it == _ensemble.end()) {
    throw MauvaisNumero();
  }
  return *it;
}

MauvaisNumero::MauvaisNumero() : invalid_argument("mauvais numero") {}

int Message::_cle = 0;

int Message::getCle() { return _cle; }

Message::Message(const std::string &exp, const std::string &dest,
                 const std::string &date)
    : _exp(exp), _dest(dest), _date(date), _id(_cle++) {}

int Message::getId() const { return _id; }

SMS::SMS(const std::string &exp, const std::string &dest,
         const std::string &date)
    : Message(exp, dest, date) {}

void SMS::setTexte(const std::string &msg) { _msg = msg; }
std::string SMS::getTexte() const { return _msg; }
std::string SMS::afficher() const { return getTexte(); }