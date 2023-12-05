/**
 * \file Personne.cpp
 * \brief Implantation de la classe Personne
 *        révision : normes 12-2013
 *        balises Doxygen
 *        révision des commentaires de spécification d'en-tête des méthodes
 * \author Steeve Dabire
 * \date 06 novembre 2023
 * \version 1.1
 */

#include "Personne.h"
#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include "Validation.h"
using namespace std;

namespace hockey
{
  /**
   * \brief constructeur avec paramètres
   * 		  On construit un objet Personne à partir de valeurs passées en paramètres.
   * 		  Les attributs sont assignés seulement si la personne est considérée comme valide.
   * 		  Autrement, une erreur d'assertion est générée.
   * \param[str] p_nom est un string qui représente le nom de la personne
   * \param[str] p_prenom est un string qui représente le prénom de la personne
   * \param[date] p_dateNaisance est un objet Date qui représente la date de naissance de la personne
   * \param[str] p_numeroTelephone est un string qui représente le numéro de téléphone de la personne
   * \pre p_nom, p_prenom, p_dateNaissance et p_NumeroTelephone doivent être valides
   * \post l'objet construit a été initialisé à partir des strings et entiers passés en paramètres
   */
Personne::Personne (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, const std::string& p_numeroTelephone) :
m_nom(p_nom), m_prenom(p_prenom), m_dateNaissance(p_dateNaissance), m_numeroTelephone(p_numeroTelephone)
{
  PRECONDITION (util::validerFormatNom (m_nom));
  PRECONDITION (util::validerFormatNom (m_prenom));
  PRECONDITION (util::validerFormatTelephone (m_numeroTelephone));
  
  POSTCONDITION (m_nom == p_nom);
  POSTCONDITION (m_prenom == p_prenom);
  POSTCONDITION (m_numeroTelephone == p_numeroTelephone);
  POSTCONDITION (m_dateNaissance == p_dateNaissance);
  
  INVARIANTS ();
}


/**
   * \brief retourne le nom de la personne
   * \return un string qui représente le nom de la personne
   */
string Personne::reqNom() const
{
  return m_nom;
}


/**
   * \brief retourne le prénom de la personne
   * \return un string qui représente le prénom de la personne
   */
string Personne::reqPrenom() const
{
  return m_prenom;
}


/**
   * \brief retourne la date de naissance de la personne
   * \return un objet date qui représente la date de naissance de la personne
   */
util::Date Personne::reqDateNaissance() const
{
  return m_dateNaissance;
}


/**
   * \brief retourne le numéro de téléphone de la personne
   * \return un string qui représente le numéro de téléphone de la personne
   */
string Personne::reqNumeroTelephone() const
{
  return m_numeroTelephone;
}


/**
   * \brief Assigne un numéro de téléphone à l'objet courant
   * \param[str] n_numeroTelephone est un string qui représente le numéro de téléphone de la personne
   * \pre n_numeroTelephone doit être un numéro valide
   * \post l'objet a été assigné à partir du string passé en paramètres
   */
void Personne::asgNumeroTelephone(const std::string& n_numeroTelephone)
{
  PRECONDITION (util::validerFormatTelephone (n_numeroTelephone));
          
  m_numeroTelephone = n_numeroTelephone;
  
  POSTCONDITION (m_numeroTelephone == n_numeroTelephone);
  
  INVARIANTS();
}


/**
   * \brief retourne de manière formatée le nom, le prénom, la date de naissance et le numéro de téléphone de la personne
   * \return un string formaté qui représente le nom, le prénom, la date de naissance et le numéro de téléphone de la personne
   */
string Personne::reqPersonneFormate () const
{
  ostringstream os;
  
  os << "Nom" << "               : " << m_nom << endl;
  os << "Prenom" << "            : " << m_prenom << endl;
  os << "Date de naissance" << " : " << m_dateNaissance.reqDateFormatee () << endl;
  os << "Telephone" << "         : " << m_numeroTelephone << endl;
  
  return os.str ();
}


/**
   * \brief surcharge de l'opérateur ==
   * \param[personne] autrePersonne < comparer avec la persone courante
   * \return un booléen indiquant si les deux personnes sont égales ou non
   */
bool Personne::operator==(const Personne& autrePersonne)
{
  bool validation = true;
  
  if (m_nom != autrePersonne.m_nom)
    {
      validation = false;
    }
  
  else if (m_prenom != autrePersonne.m_prenom)
    {
      validation = false;
    }
  
  else if (m_dateNaissance.reqAnnee () != autrePersonne.m_dateNaissance.reqAnnee ())
    {
      validation = false;
    }
  
  else if (m_dateNaissance.reqMois () != autrePersonne.m_dateNaissance.reqMois ())
    {
      validation = false;
    }
  
  else if (m_dateNaissance.reqJour () != autrePersonne.m_dateNaissance.reqJour ())
    {
      validation = false;
    }
  
  else if (m_numeroTelephone != autrePersonne.m_numeroTelephone)
    {
      validation = false;
    }
  
  return validation;
}


/**
   * \brief Teste l'invariant de la classe Personne. L'invariant de cette classe s'assure que les informations de la personne sont valides
   */
void Personne::verifieInvariant () const
{
  INVARIANT (util::validerFormatNom (m_nom));
  INVARIANT (util::validerFormatNom (m_prenom));
  INVARIANT (util::validerFormatTelephone (m_numeroTelephone));
}


} // namespace hockey

