/*
 * File:   AjouterEntraineur.cpp
 * Author: etudiant
 *
 * Created on 9 décembre 2023, 18 h 52
 */

#include "AjouterEntraineur.h"
#include <QMessageBox>

AjouterEntraineur::AjouterEntraineur ()
{
  ui.setupUi (this);
}

AjouterEntraineur::~AjouterEntraineur () { }

QString AjouterEntraineur::reqNom() const{
	return ui.Nom->text();
}

QString AjouterEntraineur::reqPrenom() const{
	return ui.Prenom->text();
}

util::Date AjouterEntraineur::reqDateNaissance() const{
	return m_dateNaissance;
}

QString AjouterEntraineur::reqTelephone () const{
	return ui.Telephone->text();
}

QString AjouterEntraineur::reqRAMQ () const{
	return ui.RAMQ->text();
}

QString AjouterEntraineur::reqSexe () const{
	return ui.Sexe->text();
}

void AjouterEntraineur::valideEnregistrement()
{
  if (ui.Nom->text().isEmpty()){
		QString message("Le nom ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
  if (ui.Prenom->text().isEmpty()){
		QString message("Le prenom ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
  
  if (ui.Telephone->text().isEmpty()){
		QString message("Le numero de telephone ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
  
  if (ui.RAMQ->text().isEmpty()){
		QString message("Le numero de RAMQ ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
  
  if (ui.Sexe->text().isEmpty()){
		QString message("Le sexe ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
  
  QDate dateCourante = QDate::currentDate();
  
  if (ui.dateN->selectedDate() >= dateCourante){
		QString message("La date de naissance n’est pas valide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	} 
  
  else {
		m_dateNaissance.asgDate(ui.dateN->selectedDate().day(), ui.dateN->selectedDate().month(), ui.dateN->selectedDate().year());
		accept();
	}
}