/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   SupprimerPersonneGUI.cpp
 * Author: etudiant
 *
 * Created on 10 décembre 2023, 01 h 37
 */

#include "SupprimerPersonneGUI.h"
#include <QMessageBox>

SupprimerPersonneGUI::SupprimerPersonneGUI ()
{
  ui.setupUi (this);
}

SupprimerPersonneGUI::~SupprimerPersonneGUI () { }

QString SupprimerPersonneGUI::reqNom() const{
	return ui.nom->text();
}

QString SupprimerPersonneGUI::reqPrenom() const{
	return ui.prenom->text();
}

util::Date SupprimerPersonneGUI::reqDateNaissance() const{
	return m_dateNaissance;
}

void SupprimerPersonneGUI::valideEnregistrement()
{
  if (ui.nom->text().isEmpty()){
		QString message("Le nom ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
  if (ui.prenom->text().isEmpty()){
		QString message("Le prenom ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
  
  QDate dateCourante = QDate::currentDate();
  
  if (ui.date->selectedDate() >= dateCourante){
		QString message("La date de naissance n’est pas valide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	} 
  
  else {
		m_dateNaissance.asgDate(ui.date->selectedDate().day(), ui.date->selectedDate().month(), ui.date->selectedDate().year());
		accept();
	}
}
