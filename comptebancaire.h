#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H

#include <string>
#include <vector>
#include "transaction.h"

class comptebancaire {
private:
    double solde;
    std::string numcompte;
    std::string iban;
    std::vector<transaction> transactions;

public:
    comptebancaire();

    static std::string generernumcompte();
    static std::string genererIban();

    double getSolde() const;
    std::string getNumcompte() const;
    std::string getIban() const;

    void addTransaction(double montant, const std::string &type, const std::string &date, const std::string &destname, const std::string &destiban = "N/A");
    void affichercompte() const;

    void savefile(const std::string& filename) const;
    void loadfile(const std::string& filename);
    const std::vector<transaction>& getTransactions() const {
        return transactions;
    }
};

#endif // COMPTEBANCAIRE_H
