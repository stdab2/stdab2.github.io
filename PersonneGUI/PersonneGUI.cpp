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
#include "AjouterJoueur.h"
#include "Joueur.h"
#include "PersonneException.h"
#include <QMessageBox>
#include "SupprimerPersonneGUI.h"

PersonneGUI::PersonneGUI (hockey::Annuaire& annuaire) : monAnnuaire(annuaire)
{
  ui.setupUi (this);
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
         
         monAnnuaire.supprimerPersonne (supp.reqNom ().toStdString (), supp.reqPrenom ().toStdString (), supp.reqDateNaissance ());
         ui.affichage->setText(monAnnuaire.reqAnnuaireFormate ().c_str());
       } 
    
     catch (PersonneAbscenteException& e)
      {
	QString message = (e.what());
	QMessageBox::information(this, "ERREUR", message);
      }
    }
}
