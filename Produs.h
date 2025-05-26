#pragma once

#include <cstring>
#include <iostream>


class Produs {
  static int nextId;
  const int id;       // Cod unic al produsului
  char denumire[50];  // Denumirea produsului (șir de caractere)
  float pret;         // Prețul produsului
  int cantitate;      // Cantitatea pe stoc a produsului

 public:
  Produs();
  Produs(const int id,
         const char denumire[50],
         const float pret,
         const int cantitate);
  Produs(const char denumire[50], const int cantitate);
  Produs(const Produs& other);
  Produs& operator=(const Produs& other);
  int getId() const;
  const char* getDenumire() const;
  float getPret() const;
  int getCantitate() const;
  void setPret(float pret);
  // Adăugăm această metodă în Produs.h
  void scadeCantitate(int cantitateScazuta);

  friend std::ostream& operator<<(std::ostream& os, const Produs& produs);
  friend std::istream& operator>>(std::istream& is, Produs& produs);
};
