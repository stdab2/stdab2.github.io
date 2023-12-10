# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = PersonneGUI
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += AjouterEntraineur.cpp AjouterJoueur.cpp PersonneGUI.cpp SupprimerPersonneGUI.cpp main.cpp
HEADERS += AjouterEntraineur.h AjouterJoueur.h PersonneGUI.h SupprimerPersonneGUI.h
FORMS += AjouterEntraineur.ui AjouterJoueur.ui PersonneGUI.ui SupprimerPersonneGUI.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += ../LE_TP2 
LIBS += ../LE_TP2/dist/Debug/GNU-Linux/lible_tp2.a  
