// Auteur : jérémy desjardins
// Date : 22-11-2021
/* but: Il s’agit de réaliser un programme en C++ utilisant les fonctions compilées dans des fichiers séparés, les fichiers et
   les vecteurs, permettant d'acheter un billet pouvant contenir une ou plusieurs combinaisons de 6 numéros compris
   entre 1 et 49. La combinaison de 6 numéros peut être choisie par le joueur ou au hasard.Le billet est enregistré dans
   un fichier pour faciliter sa validation par la suite */

#include "TPFinal2043120.h"

int main()
{
   setlocale(LC_ALL, "");

   int choix;

   srand(time(NULL));

   afficherMenu();
   choix = demanderChoixMenu();
   while (choix != 0)
   {
      
      switch (choix)
      {
      case 1:
      {
         int choixSousMenu;
         string nom = DemanderNom();
         ofstream canalSortie = sortieCanalFichier(nom);
         ecrireEnTeteBillet(canalSortie);
        
        
           afficherChoixUn(); 

           afficherSousmenu();
           choixSousMenu = demanderChoixSousMenu();
           canalSortie.close();
         break;
      }
      case 2:
      {
         cout << "Afficher un billet" << endl;
         system("pause");
         break;
      }
      case 3:
      {
         cout << "Valider un billet" << endl;
         system("pause");
         break;
      }
     

      }

      afficherMenu();
      choix = demanderChoixMenu();
   }
}
