#include <fstream>
#include <iostream>
#include <sstream>
#include "Client.h"
#include "Comanda.h"
#include "Produs.h"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Eroare: trebuie sa transmiti doua fisiere ca argumente!"
              << std::endl;
    return 1;
  }

  ifstream produse_input(argv[1]);
  ifstream clienti_input(argv[2]);
  ofstream comenzi_output("output_comenzi.txt");
  ofstream stoc_output("output_stoc_ramas.txt");

   

  int numarProduse=0, numarClienti;
  produse_input >> numarProduse;
  produse_input.ignore();

  Produs* produse = new Produs[numarProduse];

  for (int i = 0; i < numarProduse; i++)
    produse_input >> produse[i];

  clienti_input >> numarClienti;
  clienti_input.ignore();

  Client* clienti = new Client[numarClienti];

  for (int i = 0; i < numarClienti; i++) {
    clienti_input >> clienti[i];
    for (int j = 0; j < clienti[i].getComanda().getNrProduse(); j++) {
      for (int k = 0; k < numarProduse; k++) {
        if (strcmp(clienti[i].getComanda().getProduse()[j].getDenumire(),
                   produse[k].getDenumire()) == 0) {
          clienti[i].getComanda().getProduse()[j].setPret(produse[k].getPret());
          break;
        }
      }
    }
  }


  if (numarClienti != 0)
    for (int i = 0; i < numarClienti; i++) {
      comenzi_output << clienti[i];
      if (i != numarClienti - 1)
        comenzi_output << endl << endl;
    }
  else
    comenzi_output << "Nu exista clienti in magazin." ;

  // clienti[] este de fapt vectorul de comenzi
  // produse[] este de fapt vectorul de stoc

 //Modificare

  for (int i = 0; i < numarClienti; i++) {
    Comanda comanda = clienti[i].getComanda();
    int numarProduseComanda = comanda.getNrProduse();

    Produs* produse_comanda = comanda.getProduse();
    for (int j = 0; j < numarProduseComanda; j++) {
      int idProdus = -1;

      for (int k = 0; k < numarProduse; k++) {
        if (strcmp(produse_comanda[j].getDenumire(),
                   produse[k].getDenumire()) == 0) {
          idProdus = k;
          break;
        }
      }

      int cantitate = produse_comanda[j].getCantitate();
      if (produse[idProdus].getCantitate() < cantitate) {
        cout << "Stoc insuficient pentru produsul "
             << produse[idProdus].getDenumire() << "cu cantitatea "
             << produse[idProdus].getCantitate() << endl;
        continue;
      }

      //   cout << "Cantitatea produsului " << produse[idProdus].getDenumire()
      //        << " este: " << produse[idProdus].getCantitate() << endl;
      produse[idProdus].scadeCantitate(cantitate);
    }
  }

  stoc_output << "Stoc ramas" << endl;
  
  for (int i = 0; i < numarProduse; i++) {
    
    stoc_output << produse[i].getId() << ". " << produse[i].getDenumire()
                << ": " << produse[i].getCantitate()
                << ", Pret: " << produse[i].getPret();

    if (i != numarProduse - 1)
      stoc_output << endl;
  }

  comenzi_output.close();
  stoc_output.close();

  return 0;
}