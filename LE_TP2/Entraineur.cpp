/**
 * \file Entraineur.cpp
 * \brief Implantation de la classe Carre
 * \author Steeve
 * \version 1.0 mise aux normes
 */

#include "Entraineur.h"
#include "Validation.h"
#include <string>
#include <sstream>
using namespace std;

namespace hockey
{
  /**
   * \brief constructeur avec paramètres
   * 		  On construit un objet Entraineur à partir de valeurs passées en paramètres.
   * 		  Les attributs sont assignés seulement si l'entraineur est considérée comme valide.
   * 		  Autrement, une erreur d'assertion est générée.
   * \param[str] p_nom est un string qui représente le nom de l'entraineur
   * \param[str] p_prenom est un string qui représente le prénom de l'entraineur
   * \param[date] p_dateNaisance est un objet Date qui représente la date de naissance de l'entraineur
   * \param[str] p_numeroTelephone est un string qui représente le numéro de téléphone de l'entraineur
   * \param[str] p_numRAMQ est un string qui représente le numéro de de RAMQ de l'entraineur
   * \param[char] p_sexe est un caractère qui représente le sexe de l'entraineur
   * \pre p_nom, p_prenom, p_dateNaissance, p_NumeroTelephone, p_numRAMQ et p_sexe doivent être valides
   * \post l'objet construit a été initialisé à partir des strings, caractères et dates passés en paramètres
   */
Entraineur::Entraineur (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, 
                        const std::string& p_numeroTelephone, const std::string& p_numRAMQ, const char& p_sexe) : 
                        Personne (p_nom, p_prenom, p_dateNaissance, p_numeroTelephone), m_numRAMQ(p_numRAMQ), m_sexe(p_sexe)
{
  PRECONDITION (util::validerFormatNumRAMQ (m_numRAMQ, reqNom (), reqPrenom (), reqDateNaissance ().reqJour (), 
                                         reqDateNaissance ().reqMois (), reqDateNaissance ().reqAnnee (), m_sexe));
  
  PRECONDITION (m_sexe == 'M' || m_sexe == 'F');
  
  util::Date dateActuelle;
  
  PRECONDITION ((dateActuelle.reqAnnee () - reqDateNaissance ().reqAnnee ()) >= 18);
  
  POSTCONDITION (m_numRAMQ == p_numRAMQ);
  POSTCONDITION (m_sexe == p_sexe);
  
  INVARIANTS ();
}


/**
   * \brief retourne le numéro de RAMQ de l'entraineur
   * \return un string qui représente le numéro de RAMQ de l'entraineur
   */
string Entraineur::reqNumRAMQ () const
{
  return m_numRAMQ;
}


/**
   * \brief retourne le sexe de l'entraineur
   * \return un caractère qui représente le sexe de l'entraineur
   */
char Entraineur::reqSexe () const
{
  return m_sexe;
}


/**
   * \brief retourne de manière formatée le nom du club ainsi que le nom, le prénom, la date de naissance, le numéro de téléphone et le numéro de RAMQ ou la position de chaque membre du club
   * \return un string formaté qui représente le nom du club ainsi que le nom, le prénom, la date de naissance, le numéro de téléphone et le numéro de RAMQ ou la position de chaque membre du club
   */
string Entraineur::reqPersonneFormate () const
{
  ostringstream os;
  
  os << "Nom" << "                     : " << Personne::reqNom () << endl;
  os << "Prenom" << "                  : " << Personne::reqPrenom () << endl;
  os << "Date de naissance" << "       : " << Personne::reqDateNaissance ().reqDateFormatee () << endl;
  os << "Telephone" << "               : " << Personne::reqNumeroTelephone () << endl;
  os << "Numero de RAMQ" << "          : " << m_numRAMQ << endl;
  os << "---------------------" << endl;
  
  return os.str ();
}


/**
   * \brief retourne une copie de l'entraineur courant 
   * \return une copie de l'entraineur courant
   */
unique_ptr<Personne> Entraineur::clone () const
{
  return make_unique<Entraineur>(*this);
}


/**
   * \brief Teste l'invariant de la classe Entraineur. L'invariant de cette classe s'assure que les informations de l'entraineur sont valides
   */
void Entraineur::verifieInvariant () const
{
  INVARIANT (util::validerFormatNumRAMQ (m_numRAMQ, reqNom (), reqPrenom (), reqDateNaissance ().reqJour (), 
                                         reqDateNaissance ().reqMois (), reqDateNaissance ().reqAnnee (), m_sexe));
  
  INVARIANT (m_sexe == 'M' || m_sexe == 'F');
}


} // namespace hockey

