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
#include "AjouterEntraineur.h"
#include <string>
#include "Entraineur.h"

PersonneGUI::PersonneGUI (hockey::Annuaire& annuaire) : monAnnuaire(annuaire)
{
  ui.setupUi (this);
}


PersonneGUI::~PersonneGUI () { }


void PersonneGUI::dialogEntraineur ()
{
  AjouterEntraineur unEntraineur;
  
  /*char sexe;
  
  if (unEntraineur.reqSexe().toStdString() == "M")
    {
      sexe = 'M';
    }
  
  if (unEntraineur.reqSexe().toStdString() == "F")
    {
      sexe = 'F';
    }*/
  
  if (unEntraineur.exec ())
    {
      hockey::Entraineur nouvellePersonne(
        unEntraineur.reqNom().toStdString(),
        unEntraineur.reqPrenom().toStdString(),
        unEntraineur.reqDateNaissance(),
        unEntraineur.reqTelephone().toStdString(),
        unEntraineur.reqRAMQ().toStdString(),
        unEntraineur.reqSexe().toStdString().at(0)
    );

    monAnnuaire.ajouterPersonne(nouvellePersonne);
    ui.affichage->setText(monAnnuaire.reqAnnuaireFormate ().c_str());
    }
}
