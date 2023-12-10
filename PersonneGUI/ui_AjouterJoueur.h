/********************************************************************************
** Form generated from reading UI file 'AjouterJoueur.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTERJOUEUR_H
#define UI_AJOUTERJOUEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AjouterJoueur
{
public:
    QLabel *label;
    QLineEdit *nom;
    QLabel *label_2;
    QLineEdit *prenom;
    QLabel *label_3;
    QCalendarWidget *date;
    QLabel *label_4;
    QLineEdit *telephone;
    QLabel *label_5;
    QLineEdit *position;
    QPushButton *ok;

    void setupUi(QDialog *AjouterJoueur)
    {
        if (AjouterJoueur->objectName().isEmpty())
            AjouterJoueur->setObjectName(QString::fromUtf8("AjouterJoueur"));
        AjouterJoueur->resize(748, 554);
        label = new QLabel(AjouterJoueur);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 58, 16));
        nom = new QLineEdit(AjouterJoueur);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(210, 18, 281, 20));
        label_2 = new QLabel(AjouterJoueur);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 58, 16));
        prenom = new QLineEdit(AjouterJoueur);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(210, 80, 281, 21));
        label_3 = new QLabel(AjouterJoueur);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 170, 161, 16));
        date = new QCalendarWidget(AjouterJoueur);
        date->setObjectName(QString::fromUtf8("date"));
        date->setGeometry(QRect(210, 160, 432, 194));
        label_4 = new QLabel(AjouterJoueur);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 400, 91, 16));
        telephone = new QLineEdit(AjouterJoueur);
        telephone->setObjectName(QString::fromUtf8("telephone"));
        telephone->setGeometry(QRect(210, 397, 281, 21));
        label_5 = new QLabel(AjouterJoueur);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 470, 71, 16));
        position = new QLineEdit(AjouterJoueur);
        position->setObjectName(QString::fromUtf8("position"));
        position->setGeometry(QRect(210, 470, 281, 21));
        ok = new QPushButton(AjouterJoueur);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(300, 510, 90, 28));

        retranslateUi(AjouterJoueur);
        QObject::connect(ok, SIGNAL(clicked()), AjouterJoueur, SLOT(valideEnregistrement()));

        QMetaObject::connectSlotsByName(AjouterJoueur);
    } // setupUi

    void retranslateUi(QDialog *AjouterJoueur)
    {
        AjouterJoueur->setWindowTitle(QCoreApplication::translate("AjouterJoueur", "AjouterJoueur", nullptr));
        label->setText(QCoreApplication::translate("AjouterJoueur", "Nom :", nullptr));
        label_2->setText(QCoreApplication::translate("AjouterJoueur", "Prenom :", nullptr));
        label_3->setText(QCoreApplication::translate("AjouterJoueur", "Date de naissance :", nullptr));
        label_4->setText(QCoreApplication::translate("AjouterJoueur", "Telephone :", nullptr));
        label_5->setText(QCoreApplication::translate("AjouterJoueur", "Position :", nullptr));
        ok->setText(QCoreApplication::translate("AjouterJoueur", "ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjouterJoueur: public Ui_AjouterJoueur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERJOUEUR_H
