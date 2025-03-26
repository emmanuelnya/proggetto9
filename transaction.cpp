#include "../include/transaction.h"
#include "../include/destinatario.h"
#include <sstream>
#include<iomanip>

transaction::transaction(double m, std::string t, std::string d, destinatario desti) : montant(m), type(std::move(t)), date(std::move(d)), dest(std::move(desti)) {}

double transaction::getMontant() const {
    return montant;
}

std::string transaction::getType() const {
    return type;
}

std::string transaction::getDate() const {
    return date;
}

destinatario transaction::getDestinatario() const {
    return dest;
}

std::string transaction::toString() const {
    return date + "," + type + "," + std::to_string(montant) + "," + dest.toString();
}

transaction transaction::fromString(const std::string& line) {
    std::stringstream ss(line);
    std::string type, date, montantStr, destname, iban, Numtransaction;
    getline(ss, type, ',');
    getline(ss, date, ',');
    getline(ss, montantStr, ',');
    getline(ss, destname, ',');
    getline(ss, iban, ',');
    return transaction(stod(montantStr), type, date, destinatario(destname, iban));
}
