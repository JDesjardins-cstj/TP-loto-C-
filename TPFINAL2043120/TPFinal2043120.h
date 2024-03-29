#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;


//constantes
const int LONGEUR_MENU = 60;
const char TYPE_REMPLISSAGE_MENU = '-';
const char TYPE_REMPLISSAGE_MENU_TITRE = ' ';
const string TITRE_LOTO = "LOTO DU BONHEUR";
const string TITRE_PRESENTE = "Pr�sent� par : Desjardins J�r�my";
const string ACHETER_BILLET = "Acheter un billet";
const string NOM_FICHIER = "Billets de loto";
const int LONGEUR_NOM = 25;
const int LONGEUR_TICKET = 30;
const int TOTAL_ENTETE = LONGEUR_NOM + LONGEUR_TICKET;
const char MAX_MENU = '3';
const char MIN_MENU = '0';
const int MIN_SOUS_MENU = 0;
const int MAX_SOUS_MENU = 2;
const int NOMBRE_MIN = 1;
const int NOMBRE_MAX = 49;
const int NB_NOMBRE = 6;
const int MAX = 49;
const int MIN = 1;
const string TIRAGE = "Tirage a 18h";
const string TEMPS = "Mercerdi 15 decembre 2021";




//fonction

void afficherMenu();

int demanderChoixMenu();

bool validerChoixMenu(string clavier);

void afficherSousmenu();

bool validerChoixSousMenu(string clavier);

string DemanderNom();

bool validerChoixNom(string clavier);

int demanderChoixSousMenu();

ofstream sortieCanalFichier(string Fichier);

void ecrireEnTeteBillet(ofstream& canal);

void afficherChoixUn();

vector<int> saisirCombinaison(vector<int> vec);

bool validerChoixCombinaison(string clavier);

bool existe(int nbr, vector<int> vec, int position);

void choisirCombinaisonAuHasard(vector<int>& vec);

int genererAleatoire(int min, int max);

void afficherCombinaison(vector<int> vec);

void ecrireCombinaisonDansBillet(ofstream& canal,vector<int> vec);

ifstream entreCanalFichier(string Fichier);

void afficherBillet();

void ecrirePiedBillet(ofstream& canal,string nom);
