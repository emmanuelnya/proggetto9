#include <iostream>
#include <ctime>
#include <fstream>

#include "include/comptebancaire.h"

int main() {
    
    srand(time(0)); // Générer des nombres aléatoires différents à chaque exécution

    comptebancaire compte;
    compte.addTransaction(1500, "entrata", "2025-03-25", "stipendio");
    compte.addTransaction(300, "uscita", "2025-03-30", "Andrea Fabrizio", "IT13K1523654780000001236547");
    compte.addTransaction(1000, "entrata", "2025-04-01", "DEMIAN CANT");
    compte.addTransaction(25, "uscita", "2025-04-02", "CONAD CITY-VIA DALMAZIA");

    compte.affichercompte();

    std::ofstream testfile ("test.txt");
    if (!testfile) {
        std::cerr << "Error creating test file!" << std::endl;
    }else {
        testfile <<"succes file created!"<<std::endl;
        testfile.close();
    }
    compte.savefile("transaction.txt");

    return 0;
}
