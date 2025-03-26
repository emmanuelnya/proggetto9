#include "../include/comptebancaire.h"
#include "../include/transaction.h"
#include "../include/destinatario.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

comptebancaire::comptebancaire() : solde(0.0) {
    numcompte = generernumcompte();
    iban = genererIban();
}

std::string comptebancaire::generernumcompte() {
    return "ACC-" + std::to_string(rand() % 1000000);
}

std::string comptebancaire::genererIban() {
    return "IT73J0589653695500000012321-" + std::to_string(rand() % 10000);
}
double comptebancaire::getSolde() const {
    return solde;
}

std::string comptebancaire::getNumcompte() const {
    return numcompte;
}

std::string comptebancaire::getIban() const {
    return iban;
}

void comptebancaire::addTransaction(double montant, const std::string &type, const std::string &date, const std::string &destname, const std::string &destiban) {
    if (type == "uscita" && montant > solde) {
        std::cout << "Credito insufficiente!" << std::endl;
        return;
    }

    destinatario dest(destname, destiban);
    transaction t(montant, type, date, dest);
    transactions.push_back(t);

    if (type == "entrata") {
        solde += montant;
    } else {
        solde -= montant;
    }
}

void comptebancaire::affichercompte() const {
    std::cout << "Numéro di conto: " << numcompte << std::endl;
    std::cout << "IBAN: " << iban << std::endl;
    std::cout << "Solde actuel: " << solde << " EUR" << std::endl;
    std::cout << "Historico di transazione:" << std::endl;

    for (const auto& t : transactions) {
        std::string segno=(t.getType()=="entrata")?"+":"-";
        std::cout << t.getDate() << " - " << t.getType() << " : " << segno<<t.getMontant() << " EUR - "
                  << (t.getType() == "entrata" ? "Provenance" : "Destinatario") << " : "
                  << t.getDestinatario().getName();

        if (t.getDestinatario().getIban() != "N/A") {
            std::cout << " (IBAN: " << t.getDestinatario().getIban() << ")";
        }

        std::cout << " - Transaction ID: " << t.getDestinatario().getNumtransaction() << std::endl;
    }
}

void comptebancaire::savefile(const std::string& filename) const {

    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error di apertura di un file!" << filename<<std::endl;
        return;
    }
    for (const auto& transaction : transactions) {
        file<<transaction.toString()<<std::endl;
    }
    file << numcompte << "," << iban << "," << solde << std::endl;
    for (const auto& t : transactions) {
        file << t.toString() << std::endl;
    }
    file.close();
}

void comptebancaire::loadfile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error: nessun file trovato, inizializzazione." << std::endl;
        return;
    }

    transactions.clear();
    std::string ligne;
    getline(file, ligne);
    std::stringstream ss(ligne);
    std::string soldeStr;
    getline(ss, numcompte, ',');
    getline(ss, iban, ',');
    getline(ss, soldeStr, ',');
    solde = stod(soldeStr);

    while (getline(file, ligne)) {
        transaction t = transaction::fromString(ligne);
        transactions.push_back(t);
    }

    file.close();
}
