/**
 * \file PersonneTesteur.cpp
 * \brief Testeur de la classe Personne
 *  A tester:
 *         Personne (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, const std::string& p_numeroTelephone);
 *         virtual std::string reqPersonneFormate() const;
 *         std::string reqNom() const;
 *         std::string reqPrenom() const;
 *         util::Date reqDateNaissance() const;
 *         std::string reqNumeroTelephone() const;
 *         void asgNumeroTelephone(const std::string& nouveauTelephone);
 *         bool operator==(const Personne& autrePersonne);
 */
#include <gtest/gtest.h>
#include "Personne.h"
#include "Entraineur.h"
#include "ContratException.h"
#include <sstream>

using namespace hockey;


/**
 * \brief Test du constructeur avec paramètre Personne (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, const std::string& p_numeroTelephone);
 *     Cas valide:  Le nom n'est pas vide.
 *     Cas invalide: Le nom est vide.
 */
TEST (Personne, ConstructeurParamètreValide)
{
  util::Date uneDate(15, 05, 2004);
  Entraineur unePersonne("Duval", "Jean", uneDate, "581-857-2438", "DUVJ 0405 1512", 'M');
  ASSERT_EQ("Duval", unePersonne.reqNom());
  ASSERT_EQ("Jean", unePersonne.reqPrenom());
  ASSERT_EQ(uneDate, unePersonne.reqDateNaissance ());
  ASSERT_EQ("581-857-2438", unePersonne.reqNumeroTelephone());
}

TEST (Personne, ConstructeurParamètreInvalide)
{
  util::Date uneDate(15, 05, 2004);
  ASSERT_THROW(Entraineur unePersonne("", "Jean", uneDate, "581-857-2438", "DUVJ 0405 1512", 'M'), ContratException)<<"Le nom ne doit pas être vide";
}

/**
 * \brief Test fixture pour les méthodes de la classe Personne.
 */
class PersonneValide: public ::testing::Test
{
public:
  PersonneValide (): f_pVal ("Duval", "Jean", util::Date(15, 05, 2004), "581-857-2438", "DUVJ 0405 1512", 'M'){}
  Entraineur f_pVal;
};

/**
 * \brief Test de la méthode string reqNom().
 *     Cas valide: vérifier le retour du nom.
 *     Cas invalide: aucun.
 */
TEST_F (PersonneValide, reqNom)
{
  ASSERT_EQ("Duval", f_pVal.reqNom ());
}

/**
 * \brief Test de la méthode string reqPrenom().
 *     Cas valide: vérifier le retour du prenom.
 *     Cas invalide: aucun.
 */
TEST_F (PersonneValide, reqPrenom)
{
  ASSERT_EQ("Jean", f_pVal.reqPrenom ());
}

/**
 * \brief Test de la méthode util::Date reqDateNaissance().
 *     Cas valide: vérifier le retour de la date de naissance.
 *     Cas invalide: aucun.
 */
TEST_F (PersonneValide, reqDateNaissance)
{
  ASSERT_EQ(util::Date(15, 05, 2004), f_pVal.reqDateNaissance ());
}

/**
 * \brief Test de la méthode string reqNumeroTelephone().
 *     Cas valide: vérifier le retour du numero de telephone.
 *     Cas invalide: aucun.
 */
TEST_F (PersonneValide, reqNumeroTelephone)
{
  ASSERT_EQ("581-857-2438", f_pVal.reqNumeroTelephone ());
}

/**
 * \brief Test de la méthode void asgNumeroTelephone(const std::string& nouveauTelephone);.
 *     Cas valide: nouveauTelephone.size() == 12.
 *     Cas invalide: nouveauTelephone.size() != 12.
 */
TEST_F (PersonneValide, asgNumeroTelephoneValide)
{
  f_pVal.asgNumeroTelephone ("581-248-3489");
  ASSERT_EQ("581-248-3489", f_pVal.reqNumeroTelephone ());
}

TEST_F (PersonneValide, asgNumeroTelephoneInvalide)
{
  ASSERT_THROW(f_pVal.asgNumeroTelephone ("581-28-3489"), ContratException)<<"Le numero doit avoir 12 caractes";
}

/**
 * \brief Test de la méthode d'affichage reqPersonneFormate().
 *     Cas valide: vérifier la chaine retournée.
 *     Cas invalide: aucun.
 */
TEST_F (PersonneValide, reqPersonneFormate)
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
 * \brief Test de la méthode bool operator==(const Personne& autrePersonne);.
 *     Cas valide: Les 2 objets sont identiques.
 *     Cas invalide: aucun.
 */
TEST_F (PersonneValide, operator)
{
  Entraineur autre("Duval", "Jean", util::Date(15, 05, 2004), "581-857-2438", "DUVJ 0405 1512", 'M');
  ASSERT_EQ(true, f_pVal.operator == (autre));
}

