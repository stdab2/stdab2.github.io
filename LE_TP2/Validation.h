/**
 * \file Validation.h
 * \brief Déclaration des fonctions de validation
 * \author Steeve
 * \version 1.0 mise aux normes
 */

#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>


namespace util
{
  bool validerFormatNom(const std::string& nom);
  
  bool validerFormatTelephone(const std::string& numeroTelephone);
  
  bool validerFormatNumRAMQ (const std::string& p_numero, const std::string& p_nom, const std::string& p_prenom, 
                             int p_jourNaissance, int p_moisNaissance, int p_anneeNaissance, char p_sex);
}



#endif /* VALIDATION_H */

