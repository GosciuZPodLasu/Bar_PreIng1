#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "panier.h"

void Client();
void Barman();

void choixPerso(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], panier panier[30]){
    int choix;
    printf("~ ~ ~ ~ Bienvenue au bar a cocktail ! ~ ~ ~ ~\n\n");
    printf("Choisissez votre role :\n\n");
    printf("  - Barman (Tappez 1)\n  - Client (Tappez 2)\n");
    scanf("%d", &choix);
    switch(choix){
        case 1 :
            Barman(tabA, tabB, panier);
        break;
        case 2 :
            Client(tabA, tabB, panier);
        break;
        default :
            printf("Veuillez choisir 1 ou 2\n\n");
            choixPerso(tabA, tabB, panier);
    }
}

void Client(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], panier panier[30]){
    int choix, a, numerococktail = 0;
    float prix;
    int j = 0;
    printf("\nQue souhaitez-vous faire ?\n");
    printf("     1. Commander une boisson [Limite = 30/client]\n");
    printf("     2. Creer un cocktail\n");
    scanf("%d", &choix);

    switch(choix){
        case 1 :
            affichageClient(tabA, tabB);
            commande(tabA, tabB, panier, j);
            j++;
        break;
        case 2 :
            numerococktail++;
            affichageClient(tabA, tabB);
            commande_cocktail(tabA, tabB, panier, numerococktail);
        break;
    }

    a = validation(tabA, tabB, panier, j, numerococktail);
    do{
        switch (a){
            case 1 :
                affichageClient(tabA, tabB);
                numerococktail++;
                commande_cocktail(tabA, tabB, panier, numerococktail);
                a = validation(tabA, tabB, panier, j, numerococktail);
            break;
            case 2 :
                affichageClient(tabA, tabB);
                commande(tabA, tabB, panier, j);
                j++;
                a = validation(tabA, tabB, panier, j, numerococktail);
            break;
            default:
            break;
        }
    }while(a != 0);
}

void Barman(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], panier panier[30]){
    int choix;

    printf("\nQue souhaitez-vous faire ?\n");
    printf("     1. Attendre un client\n");
    printf("     2. Preparer un cocktail\n");
    printf("     3. Gerer le stock de boissons\n");
    printf("     4. Afficher le chiffre d'affaire\n");
    scanf("%d", &choix);
    switch(choix){
        case 1 :    
            Client(tabA, tabB, panier);
            puts("\n");
            Barman(tabA, tabB, panier);
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