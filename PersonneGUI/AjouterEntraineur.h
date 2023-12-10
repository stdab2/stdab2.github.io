/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   AjouterEntraineur.h
 * Author: etudiant
 *
 * Created on 9 décembre 2023, 18 h 52
 */

#ifndef _AJOUTERENTRAINEUR_H
#define _AJOUTERENTRAINEUR_H

#include <QDialog>
#include "ui_AjouterEntraineur.h"
#include "Date.h"

class AjouterEntraineur : public QDialog
{
  Q_OBJECT
public:
  AjouterEntraineur ();
  virtual ~AjouterEntraineur ();
  
  QString reqNom() const;
  QString reqPrenom() const;
  util::Date reqDateNaissance() const;
  QString reqTelephone() const;
  QString reqRAMQ() const;
  QString reqSexe() const;
  
  private slots:
	void valideEnregistrement();
  
private:
  Ui::AjouterEntraineur ui;
  util::Date m_dateNaissance;
};

#endif /* _AJOUTERENTRAINEUR_H */
