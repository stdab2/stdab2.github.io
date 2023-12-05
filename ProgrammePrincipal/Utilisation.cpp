/**
 * \file Utilisation.cpp
 * \brief Programme principal pour la création des objets des classes enfants de la classe parent Personne.
 * \author etudiant
 * \version 1.0
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Personne.h"
#include "Entraineur.h"
#include "Joueur.h"
#include "Annuaire.h"

using namespace std;
using namespace hockey;

int main()
{
  string Club;
  cout << "Entrez votre club sans espace" << endl;
  cin >> Club;
  Annuaire unClub(Club);
  
  while (unClub.reqNbMembres () != 2)
  {
    int choix;

    cout << "Choisissez une option :\n";
    cout << "1. Entraineur\n";
    cout << "2. Joueur\n";

    cout << "Entrez votre choix (1-2) : ";
    cin >> choix;

    if (choix == 1)
      {
        string nom, prenom, telephone, ramq;
        char sexe;
        int jour_naissance, mois_naissance, annee_naissance;

        cout << "Entrez votre nom : ";
        cin >> nom;

        cout << "Entrez votre prénom : ";
        cin >> prenom;

        cout << "Entrez votre jour de naissance : ";
        cin >> jour_naissance;

        cout << "Entrez votre mois de naissance : ";
        cin >> mois_naissance;

        cout << "Entrez votre année de naissance : ";
        cin >> annee_naissance;

        cout << "Entrez votre numéro de téléphone : ";
        cin >> telephone;
        
        cin.ignore();
        char ramq_buffer[255];
        cout << "Entrez votre numéro de RAMQ : ";
        cin.getline(ramq_buffer, 255);
        ramq = ramq_buffer;

        cout << "Quel est votre sexe :\n";
        cout << "1. F\n";
        cout << "2. M\n";

        cout << "Entrez votre choix (F, M) : ";
        cin >> sexe;
        
        Entraineur unEntraineur(nom, prenom, util::Date(jour_naissance, mois_naissance, annee_naissance), telephone, ramq, sexe);
        unClub.ajouterPersonne(unEntraineur);
      }

    else if (choix == 2)
      {
        string nom, prenom, telephone, position;
        int jour_naissance, mois_naissance, annee_naissance;

        cout << "Entrez votre nom : ";
        cin >> nom;

        cout << "Entrez votre prénom : ";
        cin >> prenom;

        cout << "Entrez votre jour de naissance : ";
        cin >> jour_naissance;

        cout << "Entrez votre mois de naissance : ";
        cin >> mois_naissance;

        cout << "Entrez votre année de naissance : ";
        cin >> annee_naissance;

        cout << "Entrez votre numéro de téléphone : ";
        cin >> telephone;

        cout << "Entrez votre position :\n";
        cout << "1. gardien\n";
        cout << "2. défenseur\n";
        cout << "3. centre\n";
        cout << "4. ailier\n";

        cout << "Entrez votre choix (gardien, défenseur, centre, ailier) : ";
        cin >> position;
        
        Joueur unJoueur(nom, prenom, util::Date(jour_naissance, mois_naissance, annee_naissance), telephone, position);
        unClub.ajouterPersonne(unJoueur);
      }
  
    else
      {
        cout << "choix invalide\n";
        int autrechoix;

        cout << "Choisissez une option :\n";
        cout << "1. Entraineur\n";
        cout << "2. Joueur\n";

        cout << "Entrez votre choix (1-2) : ";
        cin >> autrechoix;
      }
  }
  
  cout << unClub.reqAnnuaireFormate ();
          
  return 0;
}

