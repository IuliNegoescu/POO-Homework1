#include "Client.h"

Client::Client() {
  strcpy(nume, "");
}
Client::Client(const char* numeClient, const Comanda& comandaClient) {
  strncpy(nume, numeClient, 60);
  nume[59] = '\0';
  comanda = comandaClient;
}
Client::Client(const Client& other) {
  strncpy(nume, other.nume, 60);
  nume[59] = '\0';
  comanda = other.comanda;
}
Client& Client::operator=(const Client& other) {
  if (this != &other) {
    strncpy(nume, other.nume, 60);
    nume[59] = '\0';
    comanda = other.comanda;
  }
  return *this;
}
const char* Client::getNume() const {
  return nume;
}

const Comanda& Client::getComanda() const {
  return comanda;
}

std::ostream& operator<<(std::ostream& os, const Client& client) {
  os << "Nume: " << client.nume << "\n" << client.comanda;
  return os;
}

std::istream& operator>>(std::istream& is, Client& client) {
  is.ignore(60, '\n');
  is.getline(client.nume, 100);
  is >> client.comanda;
  return is;
}
