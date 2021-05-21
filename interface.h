#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "affichage.h"
#include "panier.h"
#include "stock.h"


void Client(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], Cocktail tabC[N], panier panier[30], float CA, char* nom, char* nom2);
void Barman(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], Cocktail tabC[N], panier panier[30], float CA, char* nom, char* nom2);

void choixPerso(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], Cocktail tabC[N], panier panier[30], float CA, char* nom, char* nom2){
    int choix;
    printf("~ ~ ~ ~ Bienvenue au bar a cocktail ! ~ ~ ~ ~\n\n");
    printf("Choisissez votre role :\n\n");
    printf("  - Barman (Tappez 1)\n  - Client (Tappez 2)\n");
    scanf("%d", &choix);
    switch(choix){
        case 1 :
            Barman(tabA, tabB, tabC, panier, CA, nom, nom2);
        break;
        case 2 :
            Client(tabA, tabB, tabC, panier, CA, nom, nom2);
        break;
        default :
            printf("Veuillez choisir 1 ou 2\n\n");
            choixPerso(tabA, tabB, tabC, panier, CA, nom, nom2);
        break;
    }
}

void Client(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N],Cocktail tabC[N], panier panier[30], float CA, char* nom, char* nom2){
    int choix, a, numerococktail = 0, alea = 0;
    int j = 0, recup = 0, b;
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
            b = commande(tabA, tabB, tabC, panier, j, alea);
            j++;
        break;
        case 2 :
            numerococktail++;
            commande_cocktail(tabA, tabB, panier, numerococktail);
        break;
        case 3 :
            Barman(tabA, tabB, tabC, panier, CA, nom, nom2);
        case 4 :
            exit(EXIT_SUCCESS);
        break;
        default :
            printf("Veuillez choisir entre 1 et 4\n\n");
            Client(tabA, tabB, tabC, panier, CA, nom, nom2);
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
                recup = 0;
                initialisationCocktail(tabA, tabB, tabC , recup, b);
                affichageClient(tabA, tabB, tabC);
                commande(tabA, tabB, tabC, panier, j, alea);
                recup = 1;
                initialisationCocktail(tabA, tabB, tabC, recup, b);
                j++;
                a = validation(tabA, tabB, tabC, panier, j, numerococktail);
            break;
            case 3 :
                recup = 1;
                initialisationCocktail(tabA, tabB, tabC, recup, b);
                calculstock(tabA, tabB);
                majstock1(tabA, nom);
                majstock2(tabB, nom2);
                recup = 0;
                initialisationCocktail(tabA, tabB, tabC, recup, b);
                CA = CA + panier[2].prix; 
                Client(tabA, tabB, tabC, panier, CA, nom, nom2);
            break;
            case 4 :
                Client(tabA, tabB, tabC, panier, CA, nom, nom2);
            break;
            default :
                printf("Erreur saisie\n");
                Client(tabA, tabB, tabC, panier, CA, nom, nom2);
            break;
        }
    }while(a != 0);
}

void Barman(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], Cocktail tabC[N], panier panier[30], float CA, char* nom, char* nom2){
    int choix, choix2, choix3, b = 0, j = 0, alea = 0, z, recup = 0;
    float cout;

    printf("\nQue souhaitez-vous faire ?\n");
    printf("     1. Attendre un client\n");
    printf("     2. Gerer le stock de boissons\n");
    printf("     3. Afficher le chiffre d'affaire\n");
    printf("     4. Changer de personnage = Client\n");
    printf("     5. Quitter\n");
    scanf("%d", &choix);
    switch(choix){
        case 1 :
            printf("\nLe client souhaite commander du : \n");
            srand(time(NULL));
            z = rand() %(6-2) + 2;
            for (int i = 0; i<z; i++){
                alea = 1;
                commande(tabA, tabB, tabC, panier, j, alea);
                recup = 1;
                initialisationCocktail(tabA, tabB, tabC, recup, b);
            }
            printf("\nLe prix total est de : %f\n", panier[4].prix);
            printf("\nServir le client (Tappez 1)\nRefusez la commande du client (Tappez un autre nombre)\n");
            scanf("%d", &choix3);
            if (choix3 == 1){
                printf("\nLe client a ete servi avec succes");
                majstock1(tabA, nom);
                majstock2(tabB, nom2);
            
                CA = CA + panier[4].prix;
                panier[4].prix = 0;
                Barman(tabA, tabB,tabC, panier, CA, nom, nom2);
            }else{
            printf("\nLe client a ete chasse avec succes\n"); 
            panier[4].prix = 0;
            Barman(tabA, tabB,tabC, panier, CA, nom, nom2);
            }

        break;
        case 2 :
            printf("\n\nQue souhaitez vous faire ?\n");
            printf("     1. Remplir le stock\n     2. Changer le prix d'un element\n     3. Consulter le stock\n");
            scanf("%d", &choix2);
            switch(choix2){
                case 1 :
                    cout = remplirstock(tabA, tabB, CA);
                    majstock1(tabA, nom);
                    majstock2(tabB, nom2);
                    CA = CA - cout;
                    Barman(tabA, tabB, tabC, panier, CA, nom, nom2);
                break;
                case 2 :
                    changerprix(tabA, tabB);
                    Barman(tabA, tabB, tabC, panier, CA, nom, nom2);
                break;
                case 3 :
                    affichageBarman(tabA, tabB);
                    puts("\n");
                    Barman(tabA, tabB, tabC, panier, CA, nom, nom2);
                default :
                    printf("\nErreur saisie\n");
                    Barman(tabA, tabB, tabC, panier, CA, nom, nom2);
                break;
            }
        break;
        case 3 : 
            printf("\nLe chiffre d'affaire du jour : %f Euros\n", CA);
            Barman(tabA, tabB, tabC, panier, CA, nom, nom2);
        break;
        case 4 :
            Client(tabA, tabB, tabC, panier, CA, nom, nom2);
        break;
        case 5 :
            exit(EXIT_SUCCESS);
        break;
        default :
            printf("Veuillez choisir entre 1 et 6\n\n");
            Barman(tabA, tabB, tabC, panier, CA, nom, nom2);
        break;
    }
}