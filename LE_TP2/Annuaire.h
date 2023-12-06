/**
 * \file Annuaire.h
 * \brief Déclaration de la classe Annuaire
 * \author Steeve
 * \version 1.0 mise aux normes
 */

#ifndef ANNUAIRE_H
#define ANNUAIRE_H
#include "Personne.h"
#include "ContratException.h"
#include <string>
#include <vector>
#include <memory>

namespace hockey
{
  /**
 * \class Annuaire
 * \brief Cette classe permet de gérer un annuaire de personnes
 */

class Annuaire
{
public:
  Annuaire (const std::string& p_nomClub);
  Annuaire (const Annuaire& orig);
  Annuaire& operator= (const Annuaire& orig);
  
  std::string reqNomClub() const;
  void ajouterPersonne (const hockey::Personne& p_personne);
  std::string reqAnnuaireFormate() const;
  size_t reqNbMembres () const;
  bool PersonneEstDejaPresente(const Personne& p_personne) const;
  void supprimerPersonne (const std::string& p_nom, const std::string& p_prenom, const
                          util::Date& p_dateDeNaissance);

  
  
private:
  std::string m_nomClub;
  std::vector<std::unique_ptr<hockey::Personne>> m_membres;
  void verifieInvariant () const;

};
} // namespace hockey

#endif /* ANNUAIRE_H */


