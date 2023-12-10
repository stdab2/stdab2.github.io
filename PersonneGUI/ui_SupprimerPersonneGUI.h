/********************************************************************************
** Form generated from reading UI file 'SupprimerPersonneGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERPERSONNEGUI_H
#define UI_SUPPRIMERPERSONNEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SupprimerPersonneGUI
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *ok;
    QLineEdit *nom;
    QLineEdit *prenom;
    QCalendarWidget *date;

    void setupUi(QDialog *SupprimerPersonneGUI)
    {
        if (SupprimerPersonneGUI->objectName().isEmpty())
            SupprimerPersonneGUI->setObjectName(QString::fromUtf8("SupprimerPersonneGUI"));
        SupprimerPersonneGUI->resize(681, 503);
        label = new QLabel(SupprimerPersonneGUI);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 58, 16));
        label_2 = new QLabel(SupprimerPersonneGUI);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 90, 58, 16));
        label_3 = new QLabel(SupprimerPersonneGUI);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 170, 121, 16));
        ok = new QPushButton(SupprimerPersonneGUI);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(250, 440, 90, 28));
        nom = new QLineEdit(SupprimerPersonneGUI);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(180, 30, 341, 21));
        prenom = new QLineEdit(SupprimerPersonneGUI);
        prenom->setObjectName(QString::fromUtf8("prenom"));
        prenom->setGeometry(QRect(180, 90, 341, 21));
        date = new QCalendarWidget(SupprimerPersonneGUI);
        date->setObjectName(QString::fromUtf8("date"));
        date->setGeometry(QRect(180, 170, 432, 194));

        retranslateUi(SupprimerPersonneGUI);
        QObject::connect(ok, SIGNAL(clicked()), SupprimerPersonneGUI, SLOT(valideEnregistrement()));

        QMetaObject::connectSlotsByName(SupprimerPersonneGUI);
    } // setupUi

    void retranslateUi(QDialog *SupprimerPersonneGUI)
    {
        SupprimerPersonneGUI->setWindowTitle(QCoreApplication::translate("SupprimerPersonneGUI", "SupprimerPersonneGUI", nullptr));
        label->setText(QCoreApplication::translate("SupprimerPersonneGUI", "Nom :", nullptr));
        label_2->setText(QCoreApplication::translate("SupprimerPersonneGUI", "Prenom :", nullptr));
        label_3->setText(QCoreApplication::translate("SupprimerPersonneGUI", "Date de naissance :", nullptr));
        ok->setText(QCoreApplication::translate("SupprimerPersonneGUI", "ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimerPersonneGUI: public Ui_SupprimerPersonneGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERPERSONNEGUI_H
