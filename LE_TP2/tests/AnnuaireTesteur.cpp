/**
 * \file AnnuaireTesteur.cpp
 * \brief Testeur de la classe Annuaire
 *  A tester:
 *         Annuaire (const std::string& p_nomClub);
 *         Annuaire (const Annuaire& orig);
 *         Annuaire& operator= (const Annuaire& orig);
 *         std::string reqNomClub() const;
 *         void ajouterPersonne (const hockey::Personne& p_personne);
 *         std::string reqAnnuaireFormate() const;
 *         size_t reqNbMembres () const;
 */
#include <gtest/gtest.h>
#include "Annuaire.h"
#include "ContratException.h"
#include "Entraineur.h"
#include <sstream>

using namespace hockey;

/**
 * \brief Test fixture pour les méthodes de la classe Annuaire.
 */
class AnnuaireValide: public ::testing::Test
{
public:
  AnnuaireValide (): f_pVal ("Victo"){}
  Annuaire f_pVal;
};

/**
 * \brief Test du constructeur avec paramètre Annuaire (const std::string& p_nomClub).
 *     Cas valide:  Le nom du club n'est pas vide.
 *     Cas invalide: Le nom du club est vide.
 */
TEST_F (AnnuaireValide, ConstructeurParamètreValide)
{
  ASSERT_EQ("Victo", f_pVal.reqNomClub ());
}

TEST_F (AnnuaireValide, ConstructeurParamètreInvalide)
{
  ASSERT_THROW(Annuaire unClub(""), ContratException)<<"Le nom du club ne doit pas être vide";
}

/**
 * \brief Test de la méthode std::string reqNomClub() const.
 *     Cas valide: vérifier le retour du nom du club.
 *     Cas invalide: aucun.
 */
TEST_F (AnnuaireValide, reqNomClub)
{
  ASSERT_EQ("Victo", f_pVal.reqNomClub ());
}

/**
 * \brief Test de la méthode size_t reqNbMembres () const.
 *     Cas valide: vérifier le retour du nnombres de membres.
 *     Cas invalide: aucun.
 */
TEST_F (AnnuaireValide, reqNbMembres)
{
  int nb = 0;
  ASSERT_EQ(nb, f_pVal.reqNbMembres ());
}

/**
 * \brief Test du constructeur copie avec paramètre Annuaire (const Annuaire& orig).
 *     Cas valide:  L'objet copie est identique a l'objet courant.
 *     Cas invalide: aucun.
 */
TEST_F(AnnuaireValide, ConstructeurCopieValide) 
{
  Annuaire copie(f_pVal);
  
  ASSERT_EQ(copie.reqNomClub (), f_pVal.reqNomClub ());
  
  ASSERT_EQ(copie.reqNbMembres (), f_pVal.reqNbMembres ());

  ASSERT_EQ(copie.reqAnnuaireFormate (), f_pVal.reqAnnuaireFormate ()); // Assurez-vous que vous avez une méthode pour obtenir le nombre de membres
 
}

/**
 * \brief Test de l'opérateur copie avec paramètre Annuaire& operator= (const Annuaire& orig).
 *     Cas valide:  L'objet copie est identique a l'objet courant.
 *     Cas invalide: aucun.
 */
TEST_F(AnnuaireValide, OpérateurCopieValide) 
{
  Annuaire copie = f_pVal;
  
  ASSERT_EQ(copie.reqNomClub (), f_pVal.reqNomClub ());
  
  ASSERT_EQ(copie.reqNbMembres (), f_pVal.reqNbMembres ());

  ASSERT_EQ(copie.reqAnnuaireFormate (), f_pVal.reqAnnuaireFormate ()); // Assurez-vous que vous avez une méthode pour obtenir le nombre de membres
 
}

/**
 * \brief Test de la méthode d'affichage std::string reqAnnuaireFormate() const.
 *     Cas valide: vérifier la chaine retournée.
 *     Cas invalide: aucun.
 */
TEST_F (AnnuaireValide, reqAnnuaireFormate)
{
  std::ostringstream os;
  os << "Club  : " << f_pVal.reqNomClub () << std::endl;
  os << "---------------------" << std::endl;
  
  ASSERT_EQ(os.str(), f_pVal.reqAnnuaireFormate ());
}

/**
 * \brief Test de la méthode void ajouterPersonne (const hockey::Personne& p_personne);
 *     Cas valide: Lorsqu'une personne est ajoutée dans l'annuaire, le nombre de personnes s'incrémente de 1
 *     Cas invalide: aucun.
 */
TEST_F (AnnuaireValide, ajouterPersonne)
{
  Entraineur unEntraineur("Duval", "Jean", util::Date(15, 05, 2004), "581-857-2438", "DUVJ 0405 1512", 'M');
  f_pVal.ajouterPersonne (unEntraineur);
  int nb = 1;
  ASSERT_EQ(nb, f_pVal.reqNbMembres ());
}