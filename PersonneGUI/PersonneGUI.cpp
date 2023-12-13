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
#include "Personne.h"
#include "AjouterJoueur.h"
#include "Joueur.h"
#include "PersonneException.h"
#include <QMessageBox>
#include "SupprimerPersonneGUI.h"
#include <vector>

PersonneGUI::PersonneGUI (hockey::Annuaire& annuaire) : monAnnuaire(annuaire)
{
  ui.setupUi (this);
  ui.tableWidget->setColumnWidth(0, 140);
  ui.tableWidget->setColumnWidth(1, 140);
  ui.tableWidget->setColumnWidth(2, 180);
}


PersonneGUI::~PersonneGUI () { }


void PersonneGUI::dialogEntraineur ()
{
  AjouterEntraineur unEntraineur;
  
  if (unEntraineur.exec ())
    {
      /*hockey::Entraineur nouvellePersonne(
        unEntraineur.reqNom().toStdString(),
        unEntraineur.reqPrenom().toStdString(),
        unEntraineur.reqDateNaissance(),
        unEntraineur.reqTelephone().toStdString(),
        unEntraineur.reqRAMQ().toStdString(),
        unEntraineur.reqSexe().toStdString().at(0)
    );

    monAnnuaire.ajouterPersonne(nouvellePersonne);
    ui.affichage->setText(monAnnuaire.reqAnnuaireFormate ().c_str());*/
    
    
    try{
         hockey::Entraineur nouvellePersonne
         (
         unEntraineur.reqNom().toStdString(),
         unEntraineur.reqPrenom().toStdString(),
         unEntraineur.reqDateNaissance(),
         unEntraineur.reqTelephone().toStdString(),
         unEntraineur.reqRAMQ().toStdString(),
         unEntraineur.reqSexe().toStdString().at(0)
         );
		
         if (monAnnuaire.PersonneEstDejaPresente(nouvellePersonne))
           {
	     throw PersonneDejaPresenteException("Impossible d’ajouter cette personne, elle est deja presente dans la liste");
           }
          
         monAnnuaire.ajouterPersonne(nouvellePersonne);
         ui.affichage->setText(monAnnuaire.reqAnnuaireFormate ().c_str());
         
         int nombreDeLigne = ui.tableWidget->rowCount();
		QString date = QString::fromStdString(nouvellePersonne.reqDateNaissance ().reqDateFormatee ());
		ui.tableWidget->setRowCount(nombreDeLigne + 1);
		ui.tableWidget->setItem(nombreDeLigne, 0, new QTableWidgetItem(QString::fromStdString(nouvellePersonne.reqNom ())));
		ui.tableWidget->setItem(nombreDeLigne, 1, new QTableWidgetItem(QString::fromStdString(nouvellePersonne.reqPrenom ())));
		ui.tableWidget->setItem(nombreDeLigne, 2, new QTableWidgetItem(date));
       } 
    
    catch (PersonneDejaPresenteException& e)
      {
	QString message = (e.what());
	QMessageBox::information(this, "ERREUR", message);
      }
    }
}







void PersonneGUI::dialogJoueur ()
{
  AjouterJoueur unJoueur;
  
  if (unJoueur.exec ())
    {
      /*hockey::Joueur nouvellePersonne(
        unJoueur.reqNom().toStdString(),
        unJoueur.reqPrenom().toStdString(),
        unJoueur.reqDateNaissance(),
        unJoueur.reqTelephone().toStdString(),
        unJoueur.reqPosition().toStdString()
              );
      
      monAnnuaire.ajouterPersonne(nouvellePersonne);
      ui.affichage->setText(monAnnuaire.reqAnnuaireFormate ().c_str());*/
    
    
    
    try{
         hockey::Joueur nouvellePersonne
         (
         unJoueur.reqNom().toStdString(),
         unJoueur.reqPrenom().toStdString(),
         unJoueur.reqDateNaissance(),
         unJoueur.reqTelephone().toStdString(),
         unJoueur.reqPosition().toStdString()
         );
		
         if (monAnnuaire.PersonneEstDejaPresente(nouvellePersonne))
           {
	     throw PersonneDejaPresenteException("Impossible d’ajouter cette personne, elle est deja presente dans la liste");
           }
          
         monAnnuaire.ajouterPersonne(nouvellePersonne);
         ui.affichage->setText(monAnnuaire.reqAnnuaireFormate ().c_str());
         
         int nombreDeLigne = ui.tableWidget->rowCount();
		QString date = QString::fromStdString(nouvellePersonne.reqDateNaissance ().reqDateFormatee ());
		ui.tableWidget->setRowCount(nombreDeLigne + 1);
		ui.tableWidget->setItem(nombreDeLigne, 0, new QTableWidgetItem(QString::fromStdString(nouvellePersonne.reqNom ())));
		ui.tableWidget->setItem(nombreDeLigne, 1, new QTableWidgetItem(QString::fromStdString(nouvellePersonne.reqPrenom ())));
		ui.tableWidget->setItem(nombreDeLigne, 2, new QTableWidgetItem(date));
       } 
    
    catch (PersonneDejaPresenteException& e)
      {
	QString message = (e.what());
	QMessageBox::information(this, "ERREUR", message);
      }
    }
}


void PersonneGUI::dialogSupprimerPersonne ()
{
  SupprimerPersonneGUI supp;
  
  if (supp.exec ())
    {
      try
       {
         hockey::Joueur nouvellePersonne
         (
         supp.reqNom().toStdString(),
         supp.reqPrenom().toStdString(),
         supp.reqDateNaissance(),
         "581-456-2456",
         "centre"
         );
		
         if (!(monAnnuaire.PersonneEstDejaPresente(nouvellePersonne)))
           {
	     throw PersonneAbscenteException("Impossible de retirer cette personne, elle n'est pas dans la liste");
           }
         else
           {
             monAnnuaire.supprimerPersonne (supp.reqNom ().toStdString (), supp.reqPrenom ().toStdString (), supp.reqDateNaissance ());
             ui.affichage->setText(monAnnuaire.reqAnnuaireFormate ().c_str());
             for (int row = 0; row < ui.tableWidget->rowCount(); ++row) 
             {
               QTableWidgetItem* itemNom = ui.tableWidget->item(row, 0);
               QTableWidgetItem* itemPrenom = ui.tableWidget->item(row, 1);
               QTableWidgetItem* itemDate = ui.tableWidget->item(row, 2);
               if (itemNom && itemPrenom && itemDate &&
               itemNom->text().toStdString() == nouvellePersonne.reqNom () &&
               itemPrenom->text().toStdString() == nouvellePersonne.reqPrenom () &&
               itemDate->text().toStdString() == nouvellePersonne.reqDateNaissance ().reqDateFormatee ()) 
               {
                 ui.tableWidget->removeRow(row);
                 break;
               }
             }
           }
       } 
    
     catch (PersonneAbscenteException& e)
      {
	QString message = (e.what());
	QMessageBox::information(this, "ERREUR", message);
      }
    }
}



void PersonneGUI::selectionLigneTable(){
	int ligne = ui.tableWidget->currentRow();
	QTableWidgetItem *tNom = ui.tableWidget->item(ligne, 0);
	QTableWidgetItem *tPrenom = ui.tableWidget->item(ligne, 1);
        QTableWidgetItem *tDate = ui.tableWidget->item(ligne, 2);
	
        for (size_t i = 0; i < monAnnuaire.reqNbMembres (); ++i) {
        const hockey::Personne& personne = monAnnuaire.reqPersonne(i);
        if (personne.reqNom() == (*tNom).text().toStdString() && personne.reqPrenom() == (*tPrenom).text().toStdString() && 
            personne.reqDateNaissance ().reqDateFormatee () == (*tDate).text().toStdString())
          {
            ui.affichage->setText(personne.reqPersonneFormate().c_str());
          }
	}
}
