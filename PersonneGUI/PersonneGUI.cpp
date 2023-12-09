/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   PersonneGUI.cpp
 * Author: etudiant
 *
 * Created on 9 décembre 2023, 17 h 11
 */

#include "PersonneGUI.h"

PersonneGUI::PersonneGUI (hockey::Annuaire& annuaire) : monAnnuaire(annuaire)
{
  widget.setupUi (this);
}

PersonneGUI::~PersonneGUI () { }
