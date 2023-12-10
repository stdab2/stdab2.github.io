/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   AjouterJoueur.cpp
 * Author: etudiant
 *
 * Created on 9 décembre 2023, 23 h 01
 */

#include "AjouterJoueur.h"
#include <QMessageBox>

AjouterJoueur::AjouterJoueur ()
{
  ui.setupUi (this);
}

AjouterJoueur::~AjouterJoueur () { }


QString AjouterJoueur::reqNom() const{
	return ui.nom->text();
}

QString AjouterJoueur::reqPrenom() const{
	return ui.prenom->text();
}

util::Date AjouterJoueur::reqDateNaissance() const{
	return m_dateNaissance;
}

QString AjouterJoueur::reqTelephone () const{
	return ui.telephone->text();
}

QString AjouterJoueur::reqPosition () const{
	return ui.position->text();
}

void AjouterJoueur::valideEnregistrement()
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
  
  if (ui.telephone->text().isEmpty()){
		QString message("Le numero de telephone ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
  
  if (ui.position->text().isEmpty()){
		QString message("La position ne doit pas etre vide");
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