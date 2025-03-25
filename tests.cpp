#include <gtest/gtest.h>
#include "../include/comptebancaire.h"

// Test per la classe destinatario
TEST(DestinatarioTest, CreazioneConIBAN) {
 const  destinatario d("Mario Rossi", "IT123456789");
  EXPECT_EQ(d.getName(), "Mario Rossi");
  EXPECT_EQ(d.getIban(), "IT123456789");
}

TEST(DestinatarioTest, CreazioneSenzaIBAN) {
  destinatario d("Supermercato");
  EXPECT_EQ(d.getName(), "Supermercato");
  EXPECT_EQ(d.getIban(), "N/A");
}

// Test per la classe transaction
TEST(TransactionTest, CreazioneTransaction) {
  destinatario d("Mario Rossi", "IT123456789");
  transaction t(100.0, "uscita", "2025-03-17", d);
  EXPECT_EQ(t.getMontant(), 100.0);
  EXPECT_EQ(t.getType(), "uscita");
  EXPECT_EQ(t.getDate(), "2025-03-17");
  EXPECT_EQ(t.getDestinatario().getName(), "Mario Rossi");
}

// Test per la classe comptebancaire
TEST(CompteBancaireTest, AggiuntaTransazione) {
  comptebancaire c;
  const double saldoIniziale = c.getSolde();
  c.addTransaction(100, "entrata", "2025-03-17", "Stipendio");
  EXPECT_EQ(c.getSolde(), saldoIniziale + 100);
}


 
