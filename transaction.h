#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "destinatario.h"

class transaction {
private:
    double montant;
    std::string type;
    std::string date;
    destinatario dest;

public:
    transaction(double m, std::string t, std::string d, destinatario desti);

    double getMontant() const;
    std::string getType() const;
    std::string getDate() const;
    destinatario getDestinatario() const;

    std::string toString() const;
    static transaction fromString(const std::string& line);
};

#endif // TRANSACTION_H
