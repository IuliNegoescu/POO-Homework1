#pragma once

#include "Produs.h"

class Comanda {
  static int nextId;
  const int id;      // Id-ul unic al comenzii
  int zi, luna, an;  // Data comenzii
  int nrProduse;     // Numarul total de produse din comanda
  Produs* produse;   // Vector alocat dinamic pentru produsele din comanda

 public:
  Comanda();
  Comanda(const int id,
          const int zi,
          const int luna,
          const int an,
          const int nrProduse,
          const Produs* produse);
  Comanda(const Comanda& other);
  Comanda& operator=(const Comanda& other);
  int getId() const;
  int getZi() const;
  int getLuna() const;
  int getAn() const;
  int getNrProduse() const;
  Produs* getProduse() const;
  ~Comanda();
  friend std::istream& operator>>(std::istream& os, Comanda& comanda);
  friend std::ostream& operator<<(std::ostream& os, const Comanda& comanda);
};
