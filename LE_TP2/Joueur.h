/**
 * \file Joueur.h
 * \brief Déclaration de la classe Joueur qui hérite de la classe Personne
 * \author Steeve
 * \version 1.0 mise aux normes
 * Created on 19 novembre 2023, 05 h 41
 */

#ifndef JOUEUR_H
#define JOUEUR_H
#include "Personne.h"
#include <string>
#include <memory>

namespace hockey
{
  /**
 * \class Joueur
 * \brief Cette classe permet de gérer des Joueurs. Elle hérite de Personne
 */

class Joueur : public Personne
{
public:
  Joueur (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, 
          const std::string& p_numeroTelephone, const std::string& p_position);
  
  std::string reqPosition() const;
  void asgPosition(const std::string& nouvellePostion);
  
  std::string reqPersonneFormate() const override;
  virtual std::unique_ptr<Personne> clone () const override;
  
  
private:
  std::string m_position;
  void verifieInvariant () const override;
};
} // namespace hockey

#endif /* JOUEUR_H */

