/**
 * \file EntraineurTesteur.cpp
 * \brief Testeur de la classe Entraineur
 *  A tester:
 *         Entraineur (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, 
           const std::string& p_numeroTelephone, const std::string& p_numRAMQ, const char& p_sexe);
 *         std::string reqNumRAMQ () const;
 *         char reqSexe () const;
 *         std::string reqPersonneFormate () const override;
 *         virtual std::unique_ptr<Personne> clone () const override;
 */
#include <gtest/gtest.h>
#include "Entraineur.h"
#include "ContratException.h"
#include <sstream>

using namespace hockey;

/**
 * \brief Test fixture pour les méthodes de la classe Entraineur.
 */
class EntraineurValide: public ::testing::Test
{
public:
  EntraineurValide (): f_pVal ("Duval", "Jean", util::Date(15, 05, 2004), "581-857-2438", "DUVJ 0405 1512", 'M'){}
  Entraineur f_pVal;
};

/**
 * \brief Test du constructeur avec paramètre  Entraineur (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, 
              const std::string& p_numeroTelephone, const std::string& p_numRAMQ, const char& p_sexe).
 *     Cas valide:  Le nom n'est pas vide.
 *     Cas invalide: Le nom est vide.
 */
TEST_F (EntraineurValide, ConstructeurParamètreValide)
{
  util::Date uneDate(15, 05, 2004);
  ASSERT_EQ("Duval", f_pVal.reqNom());
  ASSERT_EQ("Jean", f_pVal.reqPrenom());
  ASSERT_EQ(uneDate, f_pVal.reqDateNaissance ());
  ASSERT_EQ("581-857-2438", f_pVal.reqNumeroTelephone());
  ASSERT_EQ("DUVJ 0405 1512", f_pVal.reqNumRAMQ());
  ASSERT_EQ('M', f_pVal.reqSexe());
}

TEST_F (EntraineurValide, ConstructeurParamètreInvalide)
{
  util::Date uneDate(15, 05, 2004);
  ASSERT_THROW(Entraineur unePersonne("", "Jean", uneDate, "581-857-2438", "DUVJ 0405 1512", 'M'), ContratException)<<"Le nom ne doit pas être vide";
}

/**
 * \brief Test de la méthode string reqNumRAMQ().
 *     Cas valide: vérifier le retour du numéro de RAMQ.
 *     Cas invalide: aucun.
 */
TEST_F (EntraineurValide, reqNumRAMQ)
{
  ASSERT_EQ("DUVJ 0405 1512", f_pVal.reqNumRAMQ ());
}

/**
 * \brief Test de la méthode string reqSexe().
 *     Cas valide: vérifier le retour du sexe.
 *     Cas invalide: aucun.
 */
TEST_F (EntraineurValide, reqSexe)
{
  ASSERT_EQ('M', f_pVal.reqSexe ());
}

/**
 * \brief Test de la méthode d'affichage std::string reqPersonneFormate () const override.
 *     Cas valide: vérifier la chaine retournée.
 *     Cas invalide: aucun.
 */
TEST_F (EntraineurValide, reqPersonneFormate)
{
  std::ostringstream os;
  
  os << "Nom" << "                     : " << "Duval" << std::endl;
  os << "Prenom" << "                  : " << "Jean" << std::endl;
  os << "Date de naissance" << "       : " << util::Date(15, 05, 2004).reqDateFormatee () << std::endl;
  os << "Telephone" << "               : " << "581-857-2438" << std::endl;
  os << "Numero de RAMQ" << "          : " << "DUVJ 0405 1512" << std::endl;
  os << "---------------------" << std::endl;
  
  ASSERT_EQ(os.str(), f_pVal.reqPersonneFormate ());
}

/**
 * \brief Test de la méthode virtual std::unique_ptr<Personne> clone () const override.
 *     Cas valide: la copie n'est pas nulle.
 *     Cas invalide: aucun.
 */
TEST_F (EntraineurValide, Clone) 
{
  std::unique_ptr<Personne> copie = f_pVal.clone();
  
  ASSERT_TRUE(copie != nullptr);
}
