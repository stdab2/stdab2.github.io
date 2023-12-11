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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
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
    QTextEdit *affichage;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_une_Personne;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PersonneGUI)
    {
        if (PersonneGUI->objectName().isEmpty())
            PersonneGUI->setObjectName(QString::fromUtf8("PersonneGUI"));
        PersonneGUI->resize(936, 661);
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
        affichage = new QTextEdit(centralwidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));
        affichage->setGeometry(QRect(473, 14, 461, 591));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 20, 461, 581));
        PersonneGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PersonneGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 936, 22));
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
        QObject::connect(actionEntraineur, SIGNAL(triggered()), PersonneGUI, SLOT(dialogEntraineur()));
        QObject::connect(actionJoueur, SIGNAL(triggered()), PersonneGUI, SLOT(dialogJoueur()));
        QObject::connect(actionSupprimer_une_Personne, SIGNAL(triggered()), PersonneGUI, SLOT(dialogSupprimerPersonne()));
        QObject::connect(tableWidget, SIGNAL(cellClicked(int,int)), PersonneGUI, SLOT(selectionLigneTable()));

        QMetaObject::connectSlotsByName(PersonneGUI);
    } // setupUi

    void retranslateUi(QMainWindow *PersonneGUI)
    {
        PersonneGUI->setWindowTitle(QCoreApplication::translate("PersonneGUI", "PersonneGUI", nullptr));
        actionSupprimer_une_Personne->setText(QCoreApplication::translate("PersonneGUI", "Supprimer une Personne", nullptr));
        actionQuitter->setText(QCoreApplication::translate("PersonneGUI", "Quitter", nullptr));
        actionEntraineur->setText(QCoreApplication::translate("PersonneGUI", "Entraineur", nullptr));
        actionJoueur->setText(QCoreApplication::translate("PersonneGUI", "Joueur", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("PersonneGUI", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("PersonneGUI", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("PersonneGUI", "Date de naissance", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("PersonneGUI", "Menu", nullptr));
        menuAjouter_une_Personne->setTitle(QCoreApplication::translate("PersonneGUI", "Ajouter une Personne", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonneGUI: public Ui_PersonneGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONNEGUI_H
