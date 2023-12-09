/********************************************************************************
** Form generated from reading UI file 'PersonneGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONNEGUI_H
#define UI_PERSONNEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PersonneGUI
{
public:
    QAction *actionSupprimer_une_Personne;
    QAction *actionQuitter;
    QAction *actionEntraineur;
    QAction *actionJoueur;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_une_Personne;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PersonneGUI)
    {
        if (PersonneGUI->objectName().isEmpty())
            PersonneGUI->setObjectName(QString::fromUtf8("PersonneGUI"));
        PersonneGUI->resize(529, 532);
        actionSupprimer_une_Personne = new QAction(PersonneGUI);
        actionSupprimer_une_Personne->setObjectName(QString::fromUtf8("actionSupprimer_une_Personne"));
        actionQuitter = new QAction(PersonneGUI);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionEntraineur = new QAction(PersonneGUI);
        actionEntraineur->setObjectName(QString::fromUtf8("actionEntraineur"));
        actionJoueur = new QAction(PersonneGUI);
        actionJoueur->setObjectName(QString::fromUtf8("actionJoueur"));
        centralwidget = new QWidget(PersonneGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        PersonneGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PersonneGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 529, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter_une_Personne = new QMenu(menuMenu);
        menuAjouter_une_Personne->setObjectName(QString::fromUtf8("menuAjouter_une_Personne"));
        PersonneGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(PersonneGUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PersonneGUI->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(menuAjouter_une_Personne->menuAction());
        menuMenu->addAction(actionSupprimer_une_Personne);
        menuMenu->addAction(actionQuitter);
        menuAjouter_une_Personne->addAction(actionEntraineur);
        menuAjouter_une_Personne->addAction(actionJoueur);

        retranslateUi(PersonneGUI);
        QObject::connect(actionQuitter, SIGNAL(triggered()), PersonneGUI, SLOT(close()));

        QMetaObject::connectSlotsByName(PersonneGUI);
    } // setupUi

    void retranslateUi(QMainWindow *PersonneGUI)
    {
        PersonneGUI->setWindowTitle(QCoreApplication::translate("PersonneGUI", "PersonneGUI", nullptr));
        actionSupprimer_une_Personne->setText(QCoreApplication::translate("PersonneGUI", "Supprimer une Personne", nullptr));
        actionQuitter->setText(QCoreApplication::translate("PersonneGUI", "Quitter", nullptr));
        actionEntraineur->setText(QCoreApplication::translate("PersonneGUI", "Entraineur", nullptr));
        actionJoueur->setText(QCoreApplication::translate("PersonneGUI", "Joueur", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("PersonneGUI", "Menu", nullptr));
        menuAjouter_une_Personne->setTitle(QCoreApplication::translate("PersonneGUI", "Ajouter une Personne", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonneGUI: public Ui_PersonneGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONNEGUI_H
