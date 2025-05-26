#include "Comanda.h"

int Comanda::nextId = 0;

Comanda::Comanda() : id(nextId++) {
  zi = 0;
  luna = 0;
  an = 0;
  nrProduse = 0;
  produse = nullptr;
}

Comanda::Comanda(const int id,
                 const int zi,
                 const int luna,
                 const int an,
                 const int nrProduse,
                 const Produs* produse)
    : id(id),
      zi(zi),
      luna(luna),
      an(an),
      nrProduse(nrProduse),
      produse(nullptr) {
  if (nrProduse > 0 && produse != nullptr) {
    this->nrProduse = nrProduse;
    this->produse = new Produs[nrProduse];
    for (int i = 0; i < nrProduse; ++i) {
      this->produse[i] = produse[i];
    }
  }
}

Comanda::Comanda(const Comanda& other)
    : id(other.id),
      zi(other.zi),
      luna(other.luna),
      an(other.an),
      nrProduse(other.nrProduse),
      produse(nullptr) {
  if (nrProduse > 0 && other.produse != nullptr) {
    this->nrProduse = other.nrProduse;
    this->produse = new Produs[nrProduse + 1];
    for (int i = 0; i < nrProduse; ++i) {
      this->produse[i] = other.produse[i];
    }
  }
}

Comanda& Comanda::operator=(const Comanda& other) {
  if (this != &other) {
    delete[] produse;

    // id = other.id; // id should not be assigned in the assignment operator
    zi = other.zi;
    luna = other.luna;
    an = other.an;
    nrProduse = other.nrProduse;

    produse = new Produs[nrProduse];
    for (int i = 0; i < nrProduse; ++i) {
      produse[i] = other.produse[i];
    }
  }
  return *this;
}

Comanda::~Comanda() {
  if (produse != nullptr)
    delete[] produse;
}
int Comanda::getId() const {
  return id;
}

int Comanda::getZi() const {
  return zi;
}

int Comanda::getLuna() const {
  return luna;
}

int Comanda::getAn() const {
  return an;
}

int Comanda::getNrProduse() const {
  return nrProduse;
}

Produs* Comanda::getProduse() const {
  return produse;
}

std::istream& operator>>(std::istream& is, Comanda& comanda) {
  is >> comanda.zi >> comanda.luna >> comanda.an >> comanda.nrProduse;

  comanda.produse = new Produs[comanda.nrProduse + 1];

  for (int j = 0; j < comanda.nrProduse; j++) {
    char numeProdus[100];
    int cantitate;
    is.ignore(60, '\n');

    is.get(numeProdus, 100, ' ');
    is >> cantitate;

    comanda.produse[j] = Produs(numeProdus, cantitate);
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, const Comanda& comanda) {
  os << "Comanda ID: " << comanda.id << "\nData comenzii: " << comanda.zi << "/"
     << comanda.luna << "/" << comanda.an << "\nProduse comandate:\n";

  double total = 0.0;
  for (int i = 0; i < comanda.nrProduse; ++i) {
    os << comanda.produse[i].getCantitate() << " X "
       << comanda.produse[i].getDenumire() << " ("
       << comanda.produse[i].getPret() << ")\n";
    total += comanda.produse[i].getPret() * comanda.produse[i].getCantitate();
  }

  os << "Total comanda: " << total << " RON";

  return os;
}