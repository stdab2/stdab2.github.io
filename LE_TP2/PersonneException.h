/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PersonneException.h
 * Author: etudiant
 *
 * Created on 5 décembre 2023, 18 h 31
 */

#ifndef PERSONNEEXCEPTION_H
#define PERSONNEEXCEPTION_H

#include <stdexcept>

class PersonneException : public std::runtime_error{
public:
	PersonneException(const std::string& p_raison): std::runtime_error(p_raison){}
};

class PersonneDejaPresenteException: public PersonneException{
public:
	PersonneDejaPresenteException(const std::string& p_raison): PersonneException(p_raison){}
};

class PersonneAbscenteException: public PersonneException{
public:
	PersonneAbscenteException(const std::string& p_raison): PersonneException(p_raison){}
};

#endif /* PERSONNEEXCEPTION_H */

