/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/main.cc to edit this template
 */

/*
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 9 décembre 2023, 17 h 07
 */

#include <QApplication>

#include "PersonneGUI.h"

int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  // create and show your widgets here
  hockey::Annuaire monAnnuaire("equipe");
  PersonneGUI FenetrePrincipale (monAnnuaire);
  FenetrePrincipale.show ();

  return app.exec ();
}
