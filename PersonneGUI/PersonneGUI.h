/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   PersonneGUI.h
 * Author: etudiant
 *
 * Created on 9 décembre 2023, 17 h 11
 */

#ifndef _PERSONNEGUI_H
#define _PERSONNEGUI_H

#include "ui_PersonneGUI.h"
#include "Annuaire.h"

class PersonneGUI : public QMainWindow
{
  Q_OBJECT
public:
  PersonneGUI (hockey::Annuaire& annuaire);
  virtual ~PersonneGUI ();
  
  private slots:
    void dialogEntraineur ();
    void dialogJoueur ();
    void dialogSupprimerPersonne ();
    
private:
  Ui::PersonneGUI ui;
  hockey::Annuaire monAnnuaire;
  
};

#endif /* _PERSONNEGUI_H */
