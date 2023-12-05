/**
 * \file Validation.cpp
 * \brief Implantation des fonction de validation
 * \author Steeve
 * \version 1.0 mise aux normes
 */

#include "Validation.h"
#include <string>
#include <array>
#include <sstream>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;



namespace util
{
  /**
   * \brief retourne si oui ou non le format du nom est correct.
   * \param[str] nom est un string qui représente un nom quelqu'il soit.
   * \return un booléen indiquant si le format du nom est correct.
   */
  bool validerFormatNom(const string& nom)
  {
    bool validation = true;
  
  if (nom.empty())
    {
      validation = false;
    }
  
  for (char element : nom) 
    {
      if (!isalpha(element)) 
        {
          validation = false;
        }       
    }
  
  return validation;
  }
  
  
  /**
   * \brief retourne si oui ou non le format du numéro de téléphone est correct.
   * \param[str] numeroTelephone est un string qui représente un numéro de téléphone.
   * \return un booléen indiquant si le format du numéro de téléphone est correct.
   */
  bool validerFormatTelephone(const string& numeroTelephone)
  {
    array<int, 34> code {403, 780, 604, 236, 250, 778, 902, 204, 431, 506, 905, 519, 289, 705, 613, 807, 416, 647, 438, 514, 450, 579, \
                       418, 581, 819, 873, 306, 709, 867, 800, 866, 877, 888, 855};
    bool validationCodeRégEtSansFrais = false;
    string chiffreServicesPayants = "9";
    bool valide = true;
    char tiret = '-';
  
    if (numeroTelephone.size() != 12)
      {
        valide = false;
      }
  
    istringstream is_chaine {numeroTelephone};

    int premier;
    is_chaine >> premier;

    for (auto element: code)
      {
        if (premier == element)
          {
            validationCodeRégEtSansFrais = true;
            break;
          }
      }
  
    char premiertr;
    is_chaine >> premiertr;

    int second;
    is_chaine >> second;

    char secondtr;
    is_chaine >> secondtr;

    int troisieme;
    is_chaine >> troisieme;

    if ((to_string(premier)).size() != 3)
      {
        valide = false;
      }

    else if (premiertr != tiret)
      {
        valide = false;
      }
  
    else if ((to_string(second)).size() != 3)
      {
        valide = false;
      }

    else if (secondtr != tiret)
      {
        valide = false;
      }

    else if ((to_string(troisieme)).size() != 4)
      {
        valide = false;
      }

    else if (validationCodeRégEtSansFrais == false & to_string(premier).substr(0, 1) != chiffreServicesPayants)
      {
        valide = false;
      }

    return valide;
  }
  
  
  /**
   * \brief retourne si oui ou non le format du numéro de RAMQ est correct.
   * \param[str] p_numero est un string qui représente un numéro de RAMQ.
   * \param[str] p_nom est un string qui représente un nom.
   * \param[str] p_prenom est un string qui représente un prénom.
   * \param[int] p_jourNaissance est un entier qui représente le jour de naissance.
   * \param[int] p_moisNaissance est un entier qui représente le mois de naissance.
   * \param[int] p_anneeNaissance est un entier qui représente l'année de naissance.
   * \param[char] p_sex est un caractère qui représente le sexe.
   * \return un booléen indiquant si le format du numéro de RAMQ est correct.
   */
  bool validerFormatNumRAMQ (const std::string& p_numero, const std::string& p_nom, const std::string& p_prenom, 
                             int p_jourNaissance, int p_moisNaissance, int p_anneeNaissance, char p_sex)
  {
   string verif_nom = (p_nom.size() > 2) ? p_nom.substr(0, 3) : p_nom + "X";
  string verif_prenom = p_prenom.substr(0, 1);
  string moisNaissanceHomme = (to_string(p_moisNaissance).size() < 2) ? "0" + to_string(p_moisNaissance) : to_string(p_moisNaissance);
  string jourNaissance = (to_string(p_jourNaissance).size() < 2) ? "0" + to_string(p_jourNaissance) : to_string(p_jourNaissance);
  
  transform(verif_nom.begin(), verif_nom.end(), verif_nom.begin(), ::toupper);
  
  bool valide = true;
  
  if (p_numero.size() != 14)
    {
      valide = false;
    }
  
  string lettres = "";
  string chiffres = "";

  for (char c : p_numero) 
    {
      if (isalpha(c)) 
        {
          lettres += c;
        } 
      else if (isdigit(c)) 
        {
          chiffres += c;
        }
    }
  
  if (lettres.size() != 4 || lettres != (verif_nom + verif_prenom) || chiffres.size() != 8)
    {
      valide = false;
    }
  
  if (p_sex == 'M')
    {
      if ((to_string(p_anneeNaissance)).substr(2, 2) != chiffres.substr (0, 2))
        {
          valide = false;
        }
      else if (moisNaissanceHomme != chiffres.substr (2, 2))
        {
          valide = false;
        }
      else if (jourNaissance != chiffres.substr (4, 2))
        {
          valide = false;
        }
      else if (p_numero.substr(4, 1) != " " || p_numero.substr(9, 1) != " ")
        {
          valide = false;
        }
    }
  
  else if (p_sex == 'F')
    {
      if ((to_string(p_anneeNaissance)).substr(2, 2) != chiffres.substr (0, 2))
        {
          valide = false;
        }
      else if ((to_string(p_moisNaissance + 50)) != chiffres.substr (2, 2))
        {
          valide = false;
        }
      else if (jourNaissance != chiffres.substr (4, 2))
        {
          valide = false;
        }
      else if (p_numero.substr(4, 1) != " " || p_numero.substr(9, 1) != " ")
        {
          valide = false;
        }
    }
  
  cout << p_numero << endl;
  
  return valide;
  }
  
  
}

