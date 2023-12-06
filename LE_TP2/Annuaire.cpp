/**
 * \file Annuaire.cpp
 * \brief Implantation de la classe Annuaire
 * \author Steeve
 * \version 1.0 mise aux normes
 */

#include "Annuaire.h"
#include "Validation.h"
#include "PersonneException.h"
#include <string>
#include <vector>
#include <sstream>
using namespace std;

namespace hockey
{
  /**
 * \brief Constructeur de la classe Annuaire
 * \param[str] p_nomClub est un string qui représente le nom du club
 * \pre p_nomClub doit être valide
 * \post l'objet construit a été initialisé à partir des string passé en paramètre
 */

Annuaire::Annuaire (const std::string& p_nomClub) : m_nomClub(p_nomClub)
{
  PRECONDITION (!(m_nomClub.empty()));
  PRECONDITION (util::validerFormatNom (m_nomClub));
  
  POSTCONDITION (m_nomClub == p_nomClub);
  
  INVARIANTS ();
}


Annuaire::Annuaire (const Annuaire& orig) : m_nomClub (orig.m_nomClub)
{
  for (const auto & element : orig.m_membres)
  {
    m_membres.push_back(element->clone());
    //m_membres.push_back (unique_ptr<Personne> (new Personne (*element)));
    //m_membres.push_back (make_unique <Personne> (*element));
  }
}


Annuaire& Annuaire::operator = (const Annuaire& orig)
{
  if (!(this == & orig))
  {
    m_nomClub = orig.m_nomClub;
    m_membres.clear ();
    for (const auto & element : orig.m_membres)
    {
      m_membres.push_back(element->clone());
      //m_membres.push_back (unique_ptr<Personne> (new Personne (*element)));
      //m_membres.push_back ( make_unique <Personne> (*element));
    }
  }
return *this;
}


void Annuaire::ajouterPersonne (const Personne& p_personne)
{
  try
    {
      if (PersonneEstDejaPresente (p_personne))
        {
          throw PersonneDejaPresenteException("Impossible d’ajouter cette personne, elle est deja presente dans la liste");
        }
      m_membres.push_back(p_personne.clone());
    }
  
  catch (PersonneDejaPresenteException& e)
    {
      ostringstream os;
      os<< "Message : " << e.what ();
      os.str ();
    }
}


/**
   * \brief retourne le nom du club
   * \return un string qui représente le nom du club
   */
string Annuaire::reqNomClub () const
{
  return m_nomClub;
}


/**
   * \brief retourne de manière formatée le nom, le prénom, la date de naissance, le numéro de téléphone de la personne et le numéro de RAMQ de l'entraineur
   * \return un string formaté qui représente le nom, le prénom, la date de naissance, le numéro de téléphone et le numéro de RAMQ de l'entraineur
   */
string Annuaire::reqAnnuaireFormate () const
{
  ostringstream os;
  os << "Club  : " << m_nomClub << endl;
  os << "---------------------" << endl;
  
  for (const auto& ptr : m_membres)
    {
      os << ptr->reqPersonneFormate ();
    }
  
  return os.str ();
}


/**
   * \brief retourne le nombre de membres du club
   * \return un size_t qui représente le nombre de membres du club
   */
size_t Annuaire::reqNbMembres () const
{
  return m_membres.size();
}


bool Annuaire::PersonneEstDejaPresente(const Personne& p_personne) const
{
  bool personnePresente = false;
  
  //vector<Personne *>::const_iterator it;
  vector<unique_ptr<Personne>>::const_iterator it;
	
  for(it = m_membres.begin (); it != m_membres.end (); it++)
    {
      if ((*it)->reqPersonneFormate () == p_personne.reqPersonneFormate ())
        {
          personnePresente = true;
        }
    }
  return personnePresente;
}


void Annuaire::supprimerPersonne (const std::string& p_nom, const std::string& p_prenom, const
                          util::Date& p_dateDeNaissance)
{
  PRECONDITION (util::validerFormatNom (p_nom));
  PRECONDITION (util::validerFormatNom (p_prenom));
  //vector<Personne *>::const_iterator it;
  vector<unique_ptr<Personne>>::const_iterator it;
	
  for(it = m_membres.begin (); it != m_membres.end (); it++)
    {
      if ((*it)->reqNom () == p_nom && (*it)->reqPrenom () == p_prenom && (*it)->reqDateNaissance () == p_dateDeNaissance)
        {
          m_membres.erase(it);
        }
    }
  
  INVARIANTS ();
}


/**
   * \brief Teste l'invariant de la classe Annuaire. L'invariant de cette classe s'assure que les informations de l'annuaire sont valides
   */
void Annuaire::verifieInvariant () const
{
  INVARIANT (!(m_nomClub.empty()));
  INVARIANT (util::validerFormatNom (m_nomClub));
}


} // namespace hockey



