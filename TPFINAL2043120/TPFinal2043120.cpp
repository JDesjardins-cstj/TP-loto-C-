#include "TPFinal2043120.h"

void afficherMenu()
{
   system("cls"); // on fait un clear de la console

   // on écrit sur la console le menu principale 
   cout << setw(LONGEUR_MENU) << setfill(TYPE_REMPLISSAGE_MENU) << "" << endl;
   cout << setw((LONGEUR_MENU - TITRE_LOTO.length()) /2 ) << setfill(TYPE_REMPLISSAGE_MENU_TITRE) << "" << TITRE_LOTO << setw((LONGEUR_MENU - TITRE_LOTO.length())) << setfill(TYPE_REMPLISSAGE_MENU_TITRE) << "" << endl;
   cout << setw((LONGEUR_MENU - TITRE_PRESENTE.length()) /2) << setfill(TYPE_REMPLISSAGE_MENU_TITRE) << "" << TITRE_PRESENTE << setw((LONGEUR_MENU - TITRE_PRESENTE.length()) / 2) << setfill(TYPE_REMPLISSAGE_MENU_TITRE) << "" << endl;
   cout << setw(LONGEUR_MENU) << setfill(TYPE_REMPLISSAGE_MENU) << "" << endl;
   cout << "1. Acheter un billet" << endl;
   cout << "2. Afficher un billet"<<endl;
   cout << "3. Valider un billtet"<<endl;
   cout << "0. Quitter le programme" << endl;
   cout << setw(LONGEUR_MENU) << setfill(TYPE_REMPLISSAGE_MENU) << "" << endl;

}

int demanderChoixMenu()
{

   string nombre;
   cout << "Veuillez entrer votre choix --> ";
   // on demande un nombre qui doit être entre MIN_MENU et MAX_MENU  
   getline(cin, nombre, '\n');
   // tant que le nombre n'est pas entre MIN_MENU et MAX_MENU on lui redemande un nombre
   while (validerChoixMenu(nombre))
   {
      cout << "le nombre doit etre entre " << MIN_MENU << " et " << MAX_MENU << endl;
      system("pause");
      getline(cin, nombre, '\n');
   }
   //convertion du nombre qui est en string pour le mettre en int 
   int nombreStoi = stoi(nombre);
   //retourne le nombre en format int
   return nombreStoi;
}


bool validerChoixMenu(string clavier)
{
   // Est-ce que clavier commence par un chiffre
   if (clavier.empty() || (clavier.at(0) < MIN_MENU || clavier[0] > MAX_MENU))
   {
      return true;
   }
   //si toutes le conditon sont fausses on retourne faux
   else
   {
      return false;
   }

}

void afficherSousmenu()
{
   system("cls"); // on fait un clear de la console

   // on écrit sur la console le sous menu 
   cout << setw(LONGEUR_MENU) << setfill(TYPE_REMPLISSAGE_MENU) << "" << endl;
   cout << setw((LONGEUR_MENU - ACHETER_BILLET.length()) / 2) << setfill(TYPE_REMPLISSAGE_MENU_TITRE) << "" << ACHETER_BILLET << setw((LONGEUR_MENU - ACHETER_BILLET.length())) << setfill(TYPE_REMPLISSAGE_MENU_TITRE) << "" << endl;
   cout << setw(LONGEUR_MENU) << setfill(TYPE_REMPLISSAGE_MENU) << "" << endl;
   cout << "1. Choisir ses propres numeros" << endl;
   cout << "2. Choisir les numeros au hasard" << endl;
   cout << "0. Revenir au menu precedent" << endl;
   cout << setw(LONGEUR_MENU) << setfill(TYPE_REMPLISSAGE_MENU) << "" << endl;

}

bool validerChoixSousMenu(string clavier)
{
   // Est-ce que clavier commence par un chiffre
   if (clavier.empty() || (clavier.at(0) < '0' || clavier[0] > '2'))
   {
      return true;
   }
   //si toutes le conditon sont fausses on retourne faux
   else
   {
      return false;
   }
}

string DemanderNom()
{
   system("cls");  // on fait un clear de la console

   string nom;
   cout << "Quel est votre nom: ";
   // on lui demande son nom
   getline(cin, nom, '\n');
   // tant que le nom est vide on lui redemande son nom
   while (!validerChoixNom(nom))
   {
      cout << "Erreur ! Quel est votre nom: ";
      // on lui demande son nom
      getline(cin, nom, '\n');
   }
   //retourne le nom avec l'extention .txt
   return nom + ".txt";
}

bool validerChoixNom(string clavier)
{
   // Est-ce que clavier commence par un chiffre
   if (!clavier.empty())
   {
      return true;
   }
   //si toutes le conditon sont fausses on retourne faux
   else
   {
      return false;
   }

}

int demanderChoixSousMenu()
{
   string nombre;
   cout << "Veuillez entrer votre choix --> ";
   getline(cin, nombre, '\n');
   // tant que le nombre n'est pas entre MIN_SOUS_MENU et MAX_SOUS_MENU on lui redemande un nombre
   while (validerChoixMenu(nombre))
   {
      cout << "le nombre doit etre entre 0 et 3" << endl;
      getline(cin, nombre, '\n');
   }
   //convertion du nombre qui est en string pour le mettre en int 
   int nombreStoi = stoi(nombre);
   //retourne le nombre en format int
   return nombreStoi;
}

ofstream sortieCanalFichier(string Fichier)
{
   ofstream canal;

   // Initialiser le canal de sortie : le mode out permet de créer le fichier. S'il existe déjà, le fichier sera écrasé
   canal.open(Fichier, ios::out);           // Pour ne pas écraser un fichier existant et pouvoir lui ajouter des données à la fin, il faut ouvrir dans le mode ios::app (append)      
   // si le canal n'existe pas on lui fait un message d'erreur sur le canal erreur
   if (!canal)
   {
      cerr << "Erreur : Le fichier " << Fichier << " n'a pas été correctement créé. Vérifiez l'espace disque disponible ou vos droits d'accès." << endl;
      system("pause");
      exit(1);
   }

   return canal;
}


void ecrireEnTeteBillet(ofstream& canal)
{
   // on écrit sur la console le menu principale 
   canal << setw(TOTAL_ENTETE) << setfill(TYPE_REMPLISSAGE_MENU) << "" << endl;
   canal << left << setw((TOTAL_ENTETE-TITRE_LOTO.length()) /2) << setfill(TYPE_REMPLISSAGE_MENU_TITRE) << TITRE_LOTO << "";
   canal << setw(TOTAL_ENTETE) << setfill(TYPE_REMPLISSAGE_MENU) << "" << endl;
}

void afficherChoixUn()
{
   vector<int> vecNombre(NB_NOMBRE);
   int choixSousMenu;
   


   afficherSousmenu();
   choixSousMenu = demanderChoixSousMenu();
   while (choixSousMenu != 0)
   {
      switch (choixSousMenu)
      {
         case 1:
         {
            vecNombre = saisirCombinaison(vecNombre);
            afficherCombinaison(vecNombre);
            break;
         }
         case 2:
         {
            choisirCombinaisonAuHasard(vecNombre);
            afficherCombinaison(vecNombre);
            break;
         }
      }
    
      afficherSousmenu();
      choixSousMenu = demanderChoixSousMenu();
   }
}

vector<int> saisirCombinaison(vector<int> vec)
{
   string nombre;
   for (int  i = 0; i < NB_NOMBRE; i++)
   {
    cout << "Veuillez entrer le nombre #" << i+1 << " entre " << NOMBRE_MIN <<" et " << NOMBRE_MAX << " seulement -->";
    getline(cin, nombre, '\n');

    while (validerChoixCombinaison(nombre))
    {
       cout << " ERREUR! le nombre doit etre entre " << NOMBRE_MIN << " et " << NOMBRE_MAX << endl;
       getline(cin, nombre, '\n');
    }
    
  
    while (existe(stoi(nombre),vec, i))
    {
       cout << "Vous avez déjà entré ce nombre" << endl;
       getline(cin, nombre, '\n');

       while (validerChoixCombinaison(nombre))
       {
          cout << " ERREUR! le nombre doit etre entre " << NOMBRE_MIN << " et " << NOMBRE_MAX << endl;
          getline(cin, nombre, '\n');
       }
    }
    vec.at(i)= stoi(nombre);
    
   }
 return vec;
}


bool existe(int nbr, vector<int> vec, int position)
{

   for (int i = 0; i < position ; i++)
   {
      if (vec.at(i) == nbr)
      {
         return true;
      }
   }
   return false;
}

void choisirCombinaisonAuHasard(vector<int>& vec)
{
   int alea;


      for (int i = 0; i < NB_NOMBRE; i++)
      {
         alea = genererAleatoire(MIN, MAX);
         while (existe(alea, vec, i))
         {
            alea = genererAleatoire(MIN, MAX);
         }
         vec.at(i) = alea;
      }
}




bool validerChoixCombinaison(string clavier)
{
   if (clavier != "" && ( clavier.at(0) >= '1' && clavier.at(0) <= '9'))
   {
      int nombreMax = stoi(clavier);

      // Est-ce que clavier commence par un chiffre
      if ( nombreMax < NOMBRE_MIN || nombreMax > NOMBRE_MAX)
      {
         return true;
      }
      //si toutes le conditon sont fausses on retourne faux
      else
      {
         return false;
      }
   } 
}


int genererAleatoire(int min, int max)
{
   // srand JAMAIS dans une fonction autre que le MAIN
   // srand(time(NULL));
   return rand() % (max - min + 1) + min;
}

void afficherCombinaison(vector<int> vec)
{
   for (int i = 0; i < vec.size(); i++)
   {
      cout << vec.at(i);
      if (i != (vec.size()-1))
      {
         cout << "-";
      }
   }
   cout << endl;
   system("pause");
}
