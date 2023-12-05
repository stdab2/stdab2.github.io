/**
 * \file Entraineur.h
 * \brief Déclaration de la classe Entraineur qui hérite de la classe Personne
 * \author Steeve
 * \version 1.0 mise aux normes
 * Created on 19 novembre 2023, 05 h 41
 */

#ifndef ENTRAINEUR_H
#define ENTRAINEUR_H
#include "Personne.h"
#include <string>
#include <memory>

namespace hockey
{
  /**
 * \class Entraineur
 * \brief Cette classe permet de gérer des Entraineurs. Elle hérite de Personne
 */

class Entraineur : public Personne
{
public:
  Entraineur (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, 
              const std::string& p_numeroTelephone, const std::string& p_numRAMQ, const char& p_sexe);
  
  std::string reqNumRAMQ () const;
  char reqSexe () const;
  std::string reqPersonneFormate () const override;

  virtual std::unique_ptr<Personne> clone () const override;
  
  
private:
  std::string m_numRAMQ;
  char m_sexe;
  void verifieInvariant () const override;
};
} // namespace hockey

#endif /* ENTRAINEUR_H */

