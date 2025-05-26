#pragma once
#include "Comanda.h"

class Client {
 private:
  char nume[60];    // Numele clientului
  Comanda comanda;  // comanda clientului

 public:
  Client();
  Client(const char* numeClient, const Comanda& comandaClient);
  Client(const Client& other);
  Client& operator=(const Client& other);
  const char* getNume() const;
  const Comanda& getComanda() const;
  friend std::ostream& operator<<(std::ostream& os, const Client& client);
  friend std::istream& operator>>(std::istream& is, Client& client);
};