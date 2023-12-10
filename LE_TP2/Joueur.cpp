/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Joueur.cpp
 * Author: etudiant
 * 
 * Created on 19 novembre 2023, 21 h 57
 */

#include "Joueur.h"
#include <string>
#include<sstream>
using namespace std;

namespace hockey
{
  /**
   * \brief constructeur avec paramètres
   * 		  On construit un objet Joueur à partir de valeurs passées en paramètres.
   * 		  Les attributs sont assignés seulement si le joueur est considérée comme valide.
   * 		  Autrement, une erreur d'assertion est générée.
   * \param[str] p_nom est un string qui représente le nom du joueur
   * \param[str] p_prenom est un string qui représente le prénom du joueur
   * \param[date] p_dateNaisance est un objet Date qui représente la date de naissance du joueur
   * \param[str] p_numeroTelephone est un string qui représente le numéro de téléphone du joueur
   * \param[str] p_position est un string qui représente la position du joueur
   * \pre p_nom, p_prenom, p_dateNaissance, p_NumeroTelephone et p_postion doivent être valides
   * \post l'objet construit a été initialisé à partir des strings et dates passés en paramètres
   */
  Joueur::Joueur (const std::string& p_nom, const std::string& p_prenom, const util::Date& p_dateNaissance, 
          const std::string& p_numeroTelephone, const std::string& p_position) :
          Personne(p_nom, p_prenom, p_dateNaissance, p_numeroTelephone), m_position(p_position)
  {
    PRECONDITION (!(p_position.empty()));
    PRECONDITION (p_position == "ailier" || p_position == "centre" || p_position == "défenseur" || p_position == "gardien");
    util::Date dateActuelle;
    PRECONDITION (15 <= (dateActuelle.reqAnnee () - Personne::reqDateNaissance ().reqAnnee ()) <= 17);
    
    POSTCONDITION (m_position == p_position);
    
    INVARIANTS ();
  }
  
  
  /**
   * \brief retourne la position du joueur
   * \return un string qui représente la position du joueur
   */
  string Joueur::reqPosition() const
  {
    return m_position;
  }
  
  
  /**
   * \brief Assigne une position à l'objet courant
   * \param[str] n_position est un string qui représente la position du joueur
   * \pre n_position doit être uneposition valide
   * \post l'objet a été assigné à partir du string passé en paramètres
   */
  void Joueur::asgPosition(const std::string& nouvellePosition)
  {
    PRECONDITION (nouvellePosition == "ailier" || nouvellePosition == "centre" || nouvellePosition == "défenseur" || nouvellePosition == "gardien");
    
    m_position = nouvellePosition;
    
    POSTCONDITION (m_position == nouvellePosition);
    
    INVARIANTS ();
  }
  
  
  /**
   * \brief retourne de manière formatée le nom, le prénom, la date de naissance, le numéro de téléphone et la position du joueur
   * \return un string formaté qui représente le nom, le prénom, la date de naissance, le numéro de téléphone et la position du joueur
   */
  string Joueur::reqPersonneFormate() const
  {
    ostringstream os;
    os << "Nom" << "                     : " << Personne::reqNom () << endl;
    os << "Prenom" << "                  : " << Personne::reqPrenom () << endl;
    os << "Date de naissance" << "       : " << Personne::reqDateNaissance ().reqDateFormatee () << endl;
    os << "Telephone" << "               : " << Personne::reqNumeroTelephone () << endl;
    os << "Position" << "                : " << m_position << endl;
    os << "---------------------" << endl;
    
    return os.str ();
  }
  
  
  /**
   * \brief retourne une copie du joueur courant 
   * \return une copie du joueur courant
   */
  unique_ptr<Personne> Joueur::clone() const
  {
    return make_unique<Joueur>(*this);
  }
  
  
  /**
   * \brief Teste l'invariant de la classe Joueur. L'invariant de cette classe s'assure que les informations du joueur sont valides
   */
  void Joueur::verifieInvariant () const
  {
    INVARIANT (!(m_position.empty()));
    INVARIANT (m_position == "ailier" || m_position == "centre" || m_position == "défenseur" || m_position == "gardien");
  }
  
  
} // namespace hockey

