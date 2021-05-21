/**
 * @file main.c
 * @author Yenni TADJER / Ilyass OUMLIL / Dawid MALICKI Groupe 1
 * @brief Projet Bar à Cocktails
 * @version 1.0 
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "InitialisationBoisson.h"
#include "interface.h"


int main(void){
    float CA = 0; //Initialistation du chiffre d'Affaire 
    int b = 0, recup = 0;

    /* Creation et remplissage du tableau contenant les boissons non alcoolisées*/
    BoissonNonAlcoolisee tabA[N1];
    char* nom = "BoissonNonAlcoolisee.txt";
    inistock1(tabA, nom);
    initialisationBoissonNonAlcoolisee(tabA);
    inistock1(tabA, nom);

    /* Creation et remplissage du tableau contenant les boissons alcoolisées*/
    BoissonAlcoolisee tabB[N1];
    char* nom2 = "BoissonAlcoolisee.txt";
    inistock2(tabB, nom2);
    initialisationBoissonAlcoolisee(tabB);
    inistock2(tabB, nom2);

    /* Creation et remplissage du tableau contenant les cocktails*/
    Cocktail tabC[N1];
    initialisationCocktail(tabA, tabB, tabC, recup, b);

    panier panier[30] = {0}; //Initialisation du panier à vide 
    
    /* Choix du personnage par l'utilisateur */
    choixPerso(tabA, tabB, tabC, panier, CA, nom, nom2);
    
    return 0;
}
