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
#include "Personne.h"
#include "Joueur.h"
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

/**
 * \brief Test de la méthode bool PersonneEstDejaPresente(const Personne& p_personne) const;
 *     Cas valide: Lorsqu'une personne est ajoutée dans l'annuaire, la méthode nous retourne true, signe que la personne est bien dans l'annuaire
 *     Cas invalide: aucun.
 */
TEST_F (AnnuaireValide, PersonneEstDejaPresente)
{
  Entraineur unEntraineur("Duval", "Jean", util::Date(15, 05, 2004), "581-857-2438", "DUVJ 0405 1512", 'M');
  f_pVal.ajouterPersonne (unEntraineur);
  ASSERT_TRUE(f_pVal.PersonneEstDejaPresente (unEntraineur));
}

/**
 * \brief Test de la méthode void supprimerPersonne (const std::string& p_nom, const std::string& p_prenom, const
                          util::Date& p_dateDeNaissance);
 *     Cas valide: Lorsqu'une personne ajoutée dans l'annuaire est ensuite retirée de la liste, la méthode PersonneEstDejaPresente nous retourne false, 
 *                 signe que la personne n'est plus dans l'annuaire
 *     Cas invalide: aucun.
 */
TEST_F (AnnuaireValide, supprimerPersonne)
{
  Entraineur unEntraineur("Duval", "Jean", util::Date(15, 05, 2004), "581-857-2438", "DUVJ 0405 1512", 'M');
  f_pVal.ajouterPersonne (unEntraineur);
  f_pVal.supprimerPersonne ("Duval", "Jean", util::Date(15, 05, 2004));
  ASSERT_FALSE(f_pVal.PersonneEstDejaPresente (unEntraineur));
}

/**
 * \brief Test de la méthode Personne& reqPersonne(int index) const;
 *     Cas valide: Lorsqu'on essaie d'accéder a une personne dans l'annuaire grâce a sa position (index), la méthode nous retourne la bonne personne
 *     Cas invalide: aucun.
 */
TEST_F (AnnuaireValide, reqPersonne)
{
  Entraineur unEntraineur("Duval", "Jean", util::Date(15, 05, 2004), "581-857-2438", "DUVJ 0405 1512", 'M');
  Joueur unJoueur("Boly", "Georges", util::Date(12, 12, 2008), "581-456-2345", "centre");
  Entraineur deuxEntraineurs("Zinedine", "Zidane", util::Date(14, 06, 2001), "581-645-5432", "ZINZ 0106 1412", 'M');
  f_pVal.ajouterPersonne (unEntraineur);
  f_pVal.ajouterPersonne (unJoueur);
  f_pVal.ajouterPersonne (deuxEntraineurs);
  ASSERT_EQ(deuxEntraineurs.reqPersonneFormate (), f_pVal.reqPersonne (2).reqPersonneFormate ());
}