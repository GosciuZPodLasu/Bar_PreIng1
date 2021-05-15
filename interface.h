#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "panier.h"
#include "stock.h"


void Client(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], panier panier[30], float CA);
void Barman(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], panier panier[30], float CA);

void choixPerso(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], panier panier[30], float CA){
    int choix;
    printf("~ ~ ~ ~ Bienvenue au bar a cocktail ! ~ ~ ~ ~\n\n");
    printf("Choisissez votre role :\n\n");
    printf("  - Barman (Tappez 1)\n  - Client (Tappez 2)\n");
    scanf("%d", &choix);
    switch(choix){
        case 1 :
            Barman(tabA, tabB, panier, CA);
        break;
        case 2 :
            Client(tabA, tabB, panier, CA);
        break;
        default :
            printf("Veuillez choisir 1 ou 2\n\n");
            choixPerso(tabA, tabB, panier, CA);
    }
}

void Client(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], panier panier[30], float CA){
    int choix, a, numerococktail = 0;
    float prix;
    int j = 0;
    printf("\nQue souhaitez-vous faire ?\n");
    printf("     1. Commander une boisson [Limite = 30/client]\n");
    printf("     2. Creer un cocktail\n");
    printf("     3. Changer de personnage = Barman\n");
    printf("     4. Quitter\n");
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
        case 3 :
            Barman(tabA, tabB, panier, CA);
        case 4 :
            exit(EXIT_SUCCESS);
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
            case 3 :
                CA = CA + panier[2].prix;
                Client(tabA, tabB, panier, CA);
            break;
            case 4 :
                Client(tabA, tabB, panier, CA);
            default:
                printf("\nChoisissez entre 1 et 5\n");
                validation(tabA, tabB, panier, j, numerococktail);
            break;
        }
    }while(a != 0);
}

void Barman(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], panier panier[30], float CA){
    int choix, choix2;
    float cout;

    printf("\nQue souhaitez-vous faire ?\n");
    printf("     1. Attendre un client\n");
    printf("     2. Preparer un cocktail\n");
    printf("     3. Gerer le stock de boissons\n");
    printf("     4. Afficher le chiffre d'affaire\n");
    printf("     5. Changer de personnage = Client\n");
    printf("     6. Quitter\n");
    scanf("%d", &choix);
    switch(choix){
        case 1 :    
            Client(tabA, tabB, panier, CA);
            puts("\n");
            Barman(tabA, tabB, panier, CA);
        break;
        case 2 :
            
        break;
        case 3 :
            affichageBarman(tabA, tabB);
            printf("\n\nQue souhaitez vous faire ?\n");
            printf("     1. Remplir le stock\n     2. Changer le prix d'un element\n     3. Consulter le stock\n");
            scanf("%d", &choix2);
            switch(choix2){
                case 1 :
                    cout = remplirstock(tabA, tabB, CA);
                    CA = CA - cout;
                    Barman(tabA, tabB, panier, CA);
                break;
                case 2 :
                    changerprix(tabA, tabB);
                    Barman(tabA, tabB, panier, CA);
                break;
                case 3 :
                    affichageBarman(tabA, tabB);
                    Barman(tabA, tabB, panier, CA);
                default :
                break;
            }
        break;
        case 4 : 
            printf("Le chiffre d'affaire du jour : %f Euros\n", CA);
            Barman(tabA, tabB, panier, CA);
        break;
        case 5 :
            Client(tabA, tabB, panier, CA);
        break;
        case 6 :
            exit(EXIT_SUCCESS);
        break;
    }
}