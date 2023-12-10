/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   SupprimerPersonneGUI.h
 * Author: etudiant
 *
 * Created on 10 décembre 2023, 01 h 37
 */

#ifndef _SUPPRIMERPERSONNEGUI_H
#define _SUPPRIMERPERSONNEGUI_H

#include <QDialog>
#include "ui_SupprimerPersonneGUI.h"
#include "Date.h"

class SupprimerPersonneGUI : public QDialog
{
  Q_OBJECT
public:
  SupprimerPersonneGUI ();
  virtual ~SupprimerPersonneGUI ();
  
  QString reqNom() const;
  QString reqPrenom() const;
  util::Date reqDateNaissance() const;
  
  private slots:
	void valideEnregistrement();
  
private:
  Ui::SupprimerPersonneGUI ui;
  util::Date m_dateNaissance;
};

#endif /* _SUPPRIMERPERSONNEGUI_H */
