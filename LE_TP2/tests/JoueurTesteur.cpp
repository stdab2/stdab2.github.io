/**
 * \file JoueurTesteur.cpp
 * \brief Testeur de la classe Joueur
 *  A tester:
 *         Joueur (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, 
           const std::string& p_numeroTelephone, const std::string& p_position);
 *         std::string reqPosition() const;
 *         void asgPosition(const std::string& nouvellePostion);
 *         std::string reqPersonneFormate() const override;
 *         virtual std::unique_ptr<Personne> clone () const override;
 */
#include <gtest/gtest.h>
#include "Joueur.h"
#include "ContratException.h"
#include <sstream>

using namespace hockey;

/**
 * \brief Test fixture pour les méthodes de la classe Joueur.
 */
class JoueurValide: public ::testing::Test
{
public:
  JoueurValide (): f_pVal ("Duval", "Jean", util::Date(15, 05, 2007), "581-857-2438", "centre"){}
  Joueur f_pVal;
};

/**
 * \brief Test du constructeur avec paramètre  Joueur (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, 
           const std::string& p_numeroTelephone, const std::string& p_position).
 *     Cas valide:  Le nom n'est pas vide.
 *     Cas invalide: Le nom est vide.
 */
TEST_F (JoueurValide, ConstructeurParamètreValide)
{
  util::Date uneDate(15, 05, 2007);
  ASSERT_EQ("Duval", f_pVal.reqNom());
  ASSERT_EQ("Jean", f_pVal.reqPrenom());
  ASSERT_EQ(uneDate, f_pVal.reqDateNaissance ());
  ASSERT_EQ("581-857-2438", f_pVal.reqNumeroTelephone());
  ASSERT_EQ("centre", f_pVal.reqPosition ());
}

TEST_F (JoueurValide, ConstructeurParamètreInvalide)
{
  util::Date uneDate(15, 05, 2007);
  ASSERT_THROW(Joueur unePersonne("", "Jean", uneDate, "581-857-2438", "centre"), ContratException)<<"Le nom ne doit pas être vide";
}

/**
 * \brief Test de la méthode std::string reqPosition() const.
 *     Cas valide: vérifier le retour de la position.
 *     Cas invalide: aucun.
 */
TEST_F (JoueurValide, reqPosition)
{
  ASSERT_EQ("centre", f_pVal.reqPosition ());
}

/**
 * \brief Test de la méthode d'affichage std::string reqPersonneFormate() const override.
 *     Cas valide: vérifier la chaine retournée.
 *     Cas invalide: aucun.
 */
TEST_F (JoueurValide, reqPersonneFormate)
{
  std::ostringstream os;
  os << "Nom" << "                     : " << "Duval" << std::endl;
  os << "Prenom" << "                  : " << "Jean" << std::endl;
  os << "Date de naissance" << "       : " << util::Date(15, 05, 2007).reqDateFormatee () << std::endl;
  os << "Telephone" << "               : " << "581-857-2438" << std::endl;
  os << "Position" << "                : " << "centre" << std::endl;
  os << "---------------------";
  
  ASSERT_EQ(os.str(), f_pVal.reqPersonneFormate ());
}

/**
 * \brief Test de la méthode void asgPosition(const std::string& nouvellePostion).
 *     Cas valide: nouvellePosition == centre ou défenseur ou gardien ou ailier.
 *     Cas invalide: nouvellePosition != centre ou défenseur ou gardien ou ailier.
 */
TEST_F (JoueurValide, asgPositionValide)
{
  f_pVal.asgPosition ("gardien");
  ASSERT_EQ("gardien", f_pVal.reqPosition());
}

TEST_F (JoueurValide, asgPostionInvalide)
{
  ASSERT_THROW(f_pVal.asgNumeroTelephone ("buteur"), ContratException)<<"Les postions possibles sont gardien, défenseur, centre, ailier";
}

/**
 * \brief Test de la méthode virtual std::unique_ptr<Personne> clone () const override.
 *     Cas valide: la copie n'est pas nulle.
 *     Cas invalide: aucun.
 */
TEST_F (JoueurValide, Clone) 
{
  std::unique_ptr<Personne> copie = f_pVal.clone();
  
  ASSERT_TRUE(copie != nullptr);
}
