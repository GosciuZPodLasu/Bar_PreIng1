#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "commande.h"
#include "commandecocktail.h"

typedef struct{
    int nomBoisson;
    int Cocktailverif;
    Cocktail Cocktail;
}panier;


void Client();
void Barman();

void choixPerso(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N]){
    int choix;
    printf("~ ~ ~ ~ Bienvenue au bar a cocktail ! ~ ~ ~ ~\n\n");
    printf("Choisissez votre role :\n\n");
    printf("  - Barman (Tappez 1)\n  - Client (Tappez 2)\n");
    scanf("%d", &choix);
    switch(choix){
        case 1 :
            Barman(tabA, tabB);
        break;
        case 2 :
            Client(tabA, tabB);
        break;
        default :
            printf("Veuillez choisir 1 ou 2\n\n");
            choixPerso(tabA, tabB);
    }
}

void Client(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N]){
    int choix, a;
    panier panier[30] = {NULL};
    printf("\nQue souhaitez-vous faire ?\n");
    printf("     1. Commander une boisson [Limite = 30/client]\n");
    printf("     2. Creer un cocktail\n");
    scanf("%d", &choix);

    switch(choix){
        case 1 :
            affichageClient(tabA, tabB);
            commande(tabA, tabB, panier);
        break;
        case 2 :
            affichageClient(tabA, tabB);
            commande_cocktail(tabA, tabB, panier);
        break;
    }
    a = validation(panier);
    switch (a){
        case 1 :
            Client(tabA, tabB);
        default:
        break;
    }
    
}

void Barman(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N]){
    int choix;

    printf("\nQue souhaitez-vous faire ?\n");
    printf("     1. Attendre un client\n");
    printf("     2. Preparer un cocktail\n");
    printf("     3. Gerer le stock de boissons\n");
    printf("     4. Afficher le chiffre d'affaire\n");
    scanf("%d", &choix);
    switch(choix){
        case 1 :    
            
        break;
        case 2 :

        break;
        case 3 :
            affichageBarman(tabA, tabB);
            
        break;
        case 4 :

        break;
    }
}