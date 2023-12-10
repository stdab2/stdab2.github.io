/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   AjouterJoueur.h
 * Author: etudiant
 *
 * Created on 9 décembre 2023, 23 h 01
 */

#ifndef _AJOUTERJOUEUR_H
#define _AJOUTERJOUEUR_H

#include <QDialog>
#include "ui_AjouterJoueur.h"
#include "Date.h"

class AjouterJoueur : public QDialog
{
  Q_OBJECT
public:
  AjouterJoueur ();
  virtual ~AjouterJoueur ();
  
  QString reqNom() const;
  QString reqPrenom() const;
  util::Date reqDateNaissance() const;
  QString reqTelephone() const;
  QString reqPosition() const;
  
  private slots:
	void valideEnregistrement();
        
        
private:
  Ui::AjouterJoueur ui;
  util::Date m_dateNaissance;
};

#endif /* _AJOUTERJOUEUR_H */
