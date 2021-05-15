#include <stdlib.h>
#include <stdio.h>
#include "InitialisationBoisson.h"
#include "interface.h"


int main(void){
    float CA = 0;
    BoissonNonAlcoolisee tabA[N];
    initialisationBoissonNonAlcoolisee(tabA);
    BoissonAlcoolisee tabB[N];
    initialisationBoissonAlcoolisee(tabB);
    panier panier[30] = {0};
    choixPerso(tabA, tabB, panier, CA);
    
}


/* Liste fonctions :
- Affichage de la disponibilté des boissons (stock) pour le barman V
- Affichage des caractéristiques des boissons : contenance, degré alcool + sucre, prix V
- Mise a jour automatique des informations de disponibilité à chaque ajout/suppression de boisson
- Prise de la commande du client avec boissons et/ou cocktails V
- Gestion des stocks des boissons pour le barman
- Affichage du chiffre d'affaire pour le barman
- Calcul du prix d'un cocktail en fonction des degrés et contenances en majorant le prix de 10% du total du prix des boissons comprises dans le cocktail

*Cocktail du jour*
*Limite taille cocktail*
*prendre en compte le stock affichage cocktail*
*Fichiers txt = initialiser tableaux de structure*
*Préparation cocktail prédéfini pour barman*
*/