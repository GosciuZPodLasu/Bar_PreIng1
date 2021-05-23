/**
 * @file interface.h
 * @brief Header contenant les fonctions nécessaires à la création des différents menu permettant de naviguer dans le bar à cocktails
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "affichage.h"
#include "panier.h"
#include "stock.h"



void Client(BoissonNonAlcoolisee tabA[N1], BoissonAlcoolisee tabB[N1], Cocktail tabC[N1], panier panier[30], float CA, char* nom, char* nom2);
void Barman(BoissonNonAlcoolisee tabA[N1], BoissonAlcoolisee tabB[N1], Cocktail tabC[N1], panier panier[30], float CA, char* nom, char* nom2);

/**
 * @brief Choix du personnage entre client et barman
 * 
 * @param[in] tabA Boissons non alcoolisées
 * @param[in] tabB Boissons alcoolisées
 * @param[in] tabC Cocktails
 * @param[in] panier Panier du client
 * @param[in] CA Chiffre d'affaire du barman
 * @param[in] nom Le fichier txt où l'on va stocker le stock des boissons non alcoolisées
 * @param[in] nom2 Le fichier txt où l'on va stocker le stock des boissons alcoolisées
 */

void choixPerso(BoissonNonAlcoolisee tabA[N1], BoissonAlcoolisee tabB[N1], Cocktail tabC[N1], panier panier[30], float CA, char* nom, char* nom2){
    int choix;

    /*Creation de l'interface utilisateur*/
    printf("~ ~ ~ ~ Bienvenue au bar a cocktail ! ~ ~ ~ ~\n\n");
    printf("Choisissez votre role :\n\n");
    printf("  - Barman (Tappez 1)\n  - Client (Tappez 2)\n");
    scanf("%d", &choix);
    switch(choix){
        case 1 :
            system("cls");
            Barman(tabA, tabB, tabC, panier, CA, nom, nom2); //entrée dans le mode barman
        break;
        case 2 :
            system("cls");
            Client(tabA, tabB, tabC, panier, CA, nom, nom2); //entrée dans le mode client
        break;
        default :
            system("cls");
            printf("\nVeuillez choisir 1 ou 2\n\n");
            choixPerso(tabA, tabB, tabC, panier, CA, nom, nom2); //Redemande à l'utilisateur de choisir entre 1 et 2
        break;
    }
}
/**
 * @brief Interface du client
 * 
 * @param[in] tabA Boissons non alcoolisées
 * @param[in] tabB Boissons alcoolisées
 * @param[in] tabC Cocktails
 * @param[in] panier Panier du client
 * @param[in] CA Chiffre d'affaire du barman
 * @param[in] nom Le fichier txt où l'on va stocker le stock des boissons non alcoolisées
 * @param[in] nom2 Le fichier txt où l'on va stocker le stock des boissons alcoolisées
 */

void Client(BoissonNonAlcoolisee tabA[N1], BoissonAlcoolisee tabB[N1],Cocktail tabC[N1], panier panier[30], float CA, char* nom, char* nom2){
    int choix, a, numerococktail = 0, alea = 0;
    int j = 0, recup = 0, b;

    /*Affichage des differentes possibilités pour le client (Commander une boisson, créer un cocktail, changer de personnage, quitter)*/
    printf("\nQue souhaitez-vous faire ?\n");
    printf("     1. Commander une boisson ou un cocktail [Limite = 30/client]\n");
    printf("     2. Creer un cocktail personnalise\n");
    printf("     3. Changer de personnage = Barman\n");
    printf("     4. Quitter\n");
    scanf("%d", &choix);
    system("cls");

    switch(choix){
        case 1 : //Commande une boisson ou cocktail
            alea = 0;
            affichageClient(tabA, tabB, tabC);
            b = commande(tabA, tabB, tabC, panier, j, alea);
            j++;
        break;
        case 2 : //Créer un cocktail
            numerococktail++;
            commande_cocktail(tabA, tabB, panier, numerococktail);
        break;
        case 3 : //Change de personnage
            Barman(tabA, tabB, tabC, panier, CA, nom, nom2);
        break;
        case 4 : //Quitte le jeu
            exit(EXIT_SUCCESS);
        break;
        default :
            system("cls");
            printf("Veuillez choisir entre 1 et 4\n\n");
            Client(tabA, tabB, tabC, panier, CA, nom, nom2); //Redemande à l'utilisateur de choisir un nombre compris dans l'intervalle (1-4)
        break;
    }

    a = validation(tabA, tabB, tabC, panier, j, numerococktail);
    do{
        switch (a){
            case 1 : //Ajouter un cocktail personnalisé dans le panier
                affichageClient(tabA, tabB, tabC);
                numerococktail++;
                commande_cocktail(tabA, tabB, panier, numerococktail);
                a = validation(tabA, tabB, tabC, panier, j, numerococktail);
            break;
            case 2 : //Ajouter une nouvelle boisson dans le panier 
                recup = 0;
                initialisationCocktail(tabA, tabB, tabC , recup, b);
                affichageClient(tabA, tabB, tabC);
                commande(tabA, tabB, tabC, panier, j, alea);
                recup = 1;
                initialisationCocktail(tabA, tabB, tabC, recup, b);
                j++;
                a = validation(tabA, tabB, tabC, panier, j, numerococktail);
            break;
            case 3 : //Valide le panier et met a jour les stocks ainsi que le chiffre d'affaire puis retourne à l'interface client 
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
            case 4 : //Annule la commande et retourne à l'interface client
                system("cls");
                Client(tabA, tabB, tabC, panier, CA, nom, nom2);
            break;
            default : //Retourne à l'interface client en cas de saisie incorrect
                system("cls");
                printf("Erreur saisie\n");
                Client(tabA, tabB, tabC, panier, CA, nom, nom2);
            break;
        }
    }while(a != 0);
}
/**
 * @brief Interface du barman
 * 
 * @param[in] tabA Boissons non alcoolisées
 * @param[in] tabB Boissons alcoolisées
 * @param[in] tabC Cocktails
 * @param[in] panier Panier du client
 * @param[in] CA Chiffre d'affaire du barman
 * @param[in] nom Le fichier txt où l'on va stocker le stock des boissons non alcoolisées
 * @param[in] nom2 Le fichier txt où l'on va stocker le stock des boissons alcoolisées 
 */

void Barman(BoissonNonAlcoolisee tabA[N1], BoissonAlcoolisee tabB[N1], Cocktail tabC[N1], panier panier[30], float CA, char* nom, char* nom2){
    int choix, choix2, choix3, b = 0, j = 0, alea = 0, z, recup = 0;
    float cout;

    /*Affichage des differentes possibilités pour le barman (Attendre un client, gérer le stock, afficher le chiffre d'affaire, changer de personnage, quitter)*/

    printf("\nQue souhaitez-vous faire ?\n");
    printf("     1. Attendre un client\n");
    printf("     2. Gerer le stock de boissons\n");
    printf("     3. Afficher le chiffre d'affaire\n");
    printf("     4. Changer de personnage = Client\n");
    printf("     5. Quitter\n");
    scanf("%d", &choix);
    system("cls");
    
    switch(choix){
        case 1 : //Attendre un client qui va commander aléatoirement des boissons 
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
            printf("\nServir le client (Tappez 1)\nRefusez la commande du client (Tappez un autre nombre)\n"); //Servir le client ou lui refuser sa commande 
            scanf("%d", &choix3);
            system("cls");
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
        case 2 : //Gerer le stock (remplir le stock, changer un prix, consulter le stock)
            printf("\n\nQue souhaitez vous faire ?\n");
            printf("     1. Remplir le stock\n     2. Changer le prix d'un element\n     3. Consulter le stock\n");
            scanf("%d", &choix2);
            system("cls");
            switch(choix2){
                case 1 : //Remplir le stock
                    affichageBarman(tabA, tabB);
                    cout = remplirstock(tabA, tabB, CA);
                    /*Mise a jour des stocks*/
                    majstock1(tabA, nom);
                    majstock2(tabB, nom2);
                    CA = CA - cout; //Retire le cout du restock dans le chiffre d'affaire
                    Barman(tabA, tabB, tabC, panier, CA, nom, nom2);
                break;
                case 2 : //Changer le prix d'un element 
                    affichageBarman(tabA, tabB);
                    changerprix(tabA, tabB);
                    Barman(tabA, tabB, tabC, panier, CA, nom, nom2);
                break;
                case 3 : //Consulte le stock
                    affichageBarman(tabA, tabB);
                    puts("\n");
                    Barman(tabA, tabB, tabC, panier, CA, nom, nom2);
                default :
                    printf("\nErreur saisie\n");
                    Barman(tabA, tabB, tabC, panier, CA, nom, nom2);
                break;
            }
        break;
        case 3 : //Affichage du chiffre d'affaire
            printf("\nLe chiffre d'affaire du jour : %f Euros\n", CA);
            Barman(tabA, tabB, tabC, panier, CA, nom, nom2);
        break;
        case 4 : //Passe dans le mode client 
            Client(tabA, tabB, tabC, panier, CA, nom, nom2);
        break;
        case 5 : //Quitte le jeu 
            exit(EXIT_SUCCESS);
        break;
        default : //Demande à l'utilisateur de resaisir son choix en cas de choix hors intervalle (1-5)
            printf("Veuillez choisir entre 1 et 5\n\n");
            Barman(tabA, tabB, tabC, panier, CA, nom, nom2);
        break;
    }
}