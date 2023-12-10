/********************************************************************************
** Form generated from reading UI file 'AjouterEntraineur.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTERENTRAINEUR_H
#define UI_AJOUTERENTRAINEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AjouterEntraineur
{
public:
    QLabel *label;
    QLineEdit *Nom;
    QLabel *label_2;
    QLineEdit *Prenom;
    QLabel *label_3;
    QCalendarWidget *dateN;
    QLabel *label_4;
    QLineEdit *Telephone;
    QLabel *label_5;
    QLineEdit *RAMQ;
    QLabel *label_6;
    QLineEdit *Sexe;
    QPushButton *ok;

    void setupUi(QDialog *AjouterEntraineur)
    {
        if (AjouterEntraineur->objectName().isEmpty())
            AjouterEntraineur->setObjectName(QString::fromUtf8("AjouterEntraineur"));
        AjouterEntraineur->resize(766, 603);
        label = new QLabel(AjouterEntraineur);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 58, 16));
        Nom = new QLineEdit(AjouterEntraineur);
        Nom->setObjectName(QString::fromUtf8("Nom"));
        Nom->setGeometry(QRect(210, 20, 291, 21));
        label_2 = new QLabel(AjouterEntraineur);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 58, 16));
        Prenom = new QLineEdit(AjouterEntraineur);
        Prenom->setObjectName(QString::fromUtf8("Prenom"));
        Prenom->setGeometry(QRect(210, 70, 291, 21));
        label_3 = new QLabel(AjouterEntraineur);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 130, 121, 16));
        dateN = new QCalendarWidget(AjouterEntraineur);
        dateN->setObjectName(QString::fromUtf8("dateN"));
        dateN->setGeometry(QRect(210, 130, 431, 194));
        label_4 = new QLabel(AjouterEntraineur);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 340, 81, 16));
        Telephone = new QLineEdit(AjouterEntraineur);
        Telephone->setObjectName(QString::fromUtf8("Telephone"));
        Telephone->setGeometry(QRect(210, 340, 291, 21));
        label_5 = new QLabel(AjouterEntraineur);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 400, 58, 16));
        RAMQ = new QLineEdit(AjouterEntraineur);
        RAMQ->setObjectName(QString::fromUtf8("RAMQ"));
        RAMQ->setGeometry(QRect(210, 400, 291, 21));
        label_6 = new QLabel(AjouterEntraineur);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 460, 58, 16));
        Sexe = new QLineEdit(AjouterEntraineur);
        Sexe->setObjectName(QString::fromUtf8("Sexe"));
        Sexe->setGeometry(QRect(210, 460, 291, 21));
        ok = new QPushButton(AjouterEntraineur);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(230, 560, 90, 28));

        retranslateUi(AjouterEntraineur);
        QObject::connect(ok, SIGNAL(clicked()), AjouterEntraineur, SLOT(valideEnregistrement()));

        QMetaObject::connectSlotsByName(AjouterEntraineur);
    } // setupUi

    void retranslateUi(QDialog *AjouterEntraineur)
    {
        AjouterEntraineur->setWindowTitle(QCoreApplication::translate("AjouterEntraineur", "AjouterEntraineur", nullptr));
        label->setText(QCoreApplication::translate("AjouterEntraineur", "Nom :", nullptr));
        label_2->setText(QCoreApplication::translate("AjouterEntraineur", "Prenom :", nullptr));
        label_3->setText(QCoreApplication::translate("AjouterEntraineur", "Date de naissance :", nullptr));
        label_4->setText(QCoreApplication::translate("AjouterEntraineur", "Telephone :", nullptr));
        label_5->setText(QCoreApplication::translate("AjouterEntraineur", "RAMQ :", nullptr));
        label_6->setText(QCoreApplication::translate("AjouterEntraineur", "Sexe :", nullptr));
        ok->setText(QCoreApplication::translate("AjouterEntraineur", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjouterEntraineur: public Ui_AjouterEntraineur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERENTRAINEUR_H
