/**
 * \file   Personne.h
 * \brief  Déclaration de la classe Personne, classe abstraite
 * \author Steeve Dabire
 * \date 06 novembre 2023
 * \version 1.1
 */

#ifndef PERSONNE_H
#define PERSONNE_H
#include "Date.h"
#include <string>
#include <memory>
#include "ContratException.h"


namespace hockey
{
  /**
 * \class Personne
 * \brief Classe abstraite qui permet de gérer des personnes
 */
class Personne
{
public:
  Personne (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, const std::string& p_numeroTelephone);
  virtual ~Personne() {}

  virtual std::unique_ptr<Personne> clone() const = 0;
  virtual std::string reqPersonneFormate() const;
  
  
  std::string reqNom() const;
  std::string reqPrenom() const;
  util::Date reqDateNaissance() const;
  std::string reqNumeroTelephone() const;
  
  void asgNumeroTelephone(const std::string& nouveauTelephone);
  bool operator==(const Personne& autrePersonne);
  
  
private:
  std:: string m_nom;
  std:: string m_prenom;
  util::Date m_dateNaissance;
  std:: string m_numeroTelephone;
  virtual void verifieInvariant () const;
};
} // namespace hockey

#endif /* PERSONNE_H */

