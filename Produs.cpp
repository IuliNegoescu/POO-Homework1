#include "Produs.h"

int Produs::nextId = 0;

Produs::Produs() : id(nextId++) {
  denumire[0] = '\0';
  pret = 0.0f;
  cantitate = 0;
}

Produs::Produs(const int id,
               const char denumire[50],
               const float pret,
               const int cantitate)
    : id(id){
  strncpy(this->denumire, denumire, 49);
  this->denumire[49] = '\0';
  this->pret = pret;
  this->cantitate = cantitate;
}

Produs::Produs(const char denumire[50], const int cantitate) : id(-1) {
  strncpy(this->denumire, denumire, 49);
  this->denumire[49] = '\0';
  this->pret = 0.0f;
  this->cantitate = cantitate;
}

Produs::Produs(const Produs& other) : id(other.id) {
  strncpy(this->denumire, other.denumire, 49);
  this->denumire[49] = '\0';
  this->pret = other.pret;
  this->cantitate = other.cantitate;
}
Produs& Produs::operator=(const Produs& other) {
  if (this != &other) {
    strncpy(this->denumire, other.denumire, 49);
    this->denumire[49] = '\0';
    this->pret = other.pret;
    this->cantitate = other.cantitate;
  }
  return *this;
}

// Implementarea funcției scadeCantitate în Produs.cpp
void Produs::scadeCantitate(int cantitateScazuta) {
  if (cantitateScazuta < 0) {
    std::cerr << "Cantitatea scazuta nu poate fi negativa pentru produsul "
              << denumire << std::endl;
    return;
  }
  if (cantitate - cantitateScazuta >= 0) {
    cantitate -= cantitateScazuta;  // Reducem cantitatea disponibilă în stoc
  } else {
    std::cerr << "Cantitate insuficienta pentru produsul " << denumire
              << std::endl;
  }
}

void Produs::setPret(float pret) {
  this->pret = pret;
}

std::istream& operator>>(std::istream& is, Produs& produs) {
  is.ignore(50, '\n');
  is.get(produs.denumire, 50, ' ');
  is >> produs.pret >> produs.cantitate;
  return is;
}

std::ostream& operator<<(std::ostream& os, const Produs& produs) {
  os << "ID: " << produs.id << ", Denumire: " << produs.denumire
     << ", Preț: " << produs.pret << ", Cantitate: " << produs.cantitate
     << std::endl;
  return os;
}
int Produs::getId() const {
  return id;  // Returnează ID-ul produsului
}

const char* Produs::getDenumire() const {
  return denumire;
}
float Produs::getPret() const {
  return pret;
}
int Produs::getCantitate() const {
  return cantitate;
}