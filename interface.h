#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "panier.h"
#include "stock.h"
#include <time.h>

void Client(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], Cocktail tabC[N], panier panier[30], float CA);
void Barman(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], Cocktail tabC[N], panier panier[30], float CA);

void choixPerso(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], Cocktail tabC[N], panier panier[30], float CA){
    int choix;
    printf("~ ~ ~ ~ Bienvenue au bar a cocktail ! ~ ~ ~ ~\n\n");
    printf("Choisissez votre role :\n\n");
    printf("  - Barman (Tappez 1)\n  - Client (Tappez 2)\n");
    scanf("%d", &choix);
    switch(choix){
        case 1 :
            Barman(tabA, tabB, tabC, panier, CA);
        break;
        case 2 :
            Client(tabA, tabB, tabC, panier, CA);
        break;
        default :
            printf("Veuillez choisir 1 ou 2\n\n");
            choixPerso(tabA, tabB, tabC, panier, CA);
    }
}

void Client(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N],Cocktail tabC[N], panier panier[30], float CA){
    int choix, a, numerococktail = 0, alea = 0;
    float prix;
    int j = 0;
    printf("\nQue souhaitez-vous faire ?\n");
    printf("     1. Commander une boisson ou un cocktail [Limite = 30/client]\n");
    printf("     2. Creer un cocktail personnalise\n");
    printf("     3. Changer de personnage = Barman\n");
    printf("     4. Quitter\n");
    scanf("%d", &choix);

    switch(choix){
        case 1 :
            alea = 0;
            affichageClient(tabA, tabB, tabC);
            commande(tabA, tabB, tabC, panier, j, alea);
            j++;
        break;
        case 2 :
            numerococktail++;
            affichageClient(tabA, tabB, tabC);
            commande_cocktail(tabA, tabB, panier, numerococktail);
        break;
        case 3 :
            Barman(tabA, tabB, tabC, panier, CA);
        case 4 :
            exit(EXIT_SUCCESS);
        break;
    }

    a = validation(tabA, tabB, tabC, panier, j, numerococktail);
    do{
        switch (a){
            case 1 :
                affichageClient(tabA, tabB, tabC);
                numerococktail++;
                commande_cocktail(tabA, tabB, panier, numerococktail);
                a = validation(tabA, tabB, tabC, panier, j, numerococktail);
            break;
            case 2 :
                affichageClient(tabA, tabB, tabC);
                commande(tabA, tabB, tabC, panier, j, alea);
                j++;
                a = validation(tabA, tabB, tabC, panier, j, numerococktail);
            break;
            case 3 :
                CA = CA + panier[2].prix;
                Client(tabA, tabB, tabC, panier, CA);
            break;
            case 4 :
                Client(tabA, tabB, tabC, panier, CA);
            default:
                printf("\nChoisissez entre 1 et 5\n");
                validation(tabA, tabB, tabC, panier, j, numerococktail);
            break;
        }
    }while(a != 0);
}

void Barman(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], Cocktail tabC[N], panier panier[30], float CA){
    int choix, choix2, choix3, j = 0, alea = 0;
    float cout;
    int numerococktail, z;

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
            printf("\nLe client souhaite commander du : \n");
            srand(time(NULL));
            z = rand() %(6-2) + 2;
            for (int i = 0; i<z; i++){
                alea = 1;
                commande(tabA, tabB, tabC, panier, j, alea);
            }
            printf("\nLe prix total est de : %f\n", panier[4].prix);
            printf("\nServir le client (Tappez 1)\nRefusez la commande du client (Tappez 2)\n");
            scanf("%d", &choix3);
            if (choix3 == 1){
                printf("\nLe client a ete servi avec succes");
                CA = CA + panier[4].prix;
                panier[4].prix = 0;
                Barman(tabA, tabB,tabC, panier, CA);
            }else{
            printf("\nLe client a ete chasse avec succes\n"); 
            panier[4].prix = 0;
            Barman(tabA, tabB,tabC, panier, CA);
            }

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
                    Barman(tabA, tabB, tabC, panier, CA);
                break;
                case 2 :
                    changerprix(tabA, tabB);
                    Barman(tabA, tabB, tabC, panier, CA);
                break;
                case 3 :
                    affichageBarman(tabA, tabB);
                    Barman(tabA, tabB, tabC, panier, CA);
                default :
                break;
            }
        break;
        case 4 : 
            printf("\nLe chiffre d'affaire du jour : %f Euros\n", CA);
            Barman(tabA, tabB, tabC, panier, CA);
        break;
        case 5 :
            Client(tabA, tabB, tabC, panier, CA);
        break;
        case 6 :
            exit(EXIT_SUCCESS);
        break;
    }
}