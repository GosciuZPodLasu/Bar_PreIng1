/**
 * @file Panier.h
 * @brief Header contenant les fonctions permettant de constituer le panier du client
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "commande.h"

/**
 * @brief Panier des boissons et cocktails
 * 
 * @param[in] tabA Boissons non alcoolisées
 * @param[in] tabB Boissons alcoolisées
 * @param[in] tabC Cocktails
 * @param[in] panier Panier du client
 * @param[in] j Entier permettant de passer à l'élément suivant du panier
 * @return Nombre de boissons/cocktails dans le panier
 */
int PanierBoisson(BoissonNonAlcoolisee tabA[N1], BoissonAlcoolisee tabB[N1], Cocktail tabC[N1], panier panier[30], int j){
    int b, compteur;
    float prix1 = 0;
    printf("Boissons/Cocktails :\n");

    /*Affichage des boissons dans le panier et calcul le prix total*/
    if(j > 0){
        for(int i = 0; i<j; i++){  
            if(panier[i].Boisson != 4441){  //N'affiche pas les boissons supprimées (les boissons supprimés sont affectés à 4441)                                                                                 
                b = panier[i].Boisson;
                if(b > 9 && b < 20){
                    compteur = compteur+1; 
                    printf("%d. %s\n", i+1, tabB[b-10].nom);
                    prix1 = prix1 + tabB[b-10].prix;     
                }else{
                    if (b > 19 && b < 25){
                        compteur = compteur+1;
                        printf("%d. %s\n", i+1, tabC[b-20].nom);
                        prix1 = prix1 + tabC[b-20].prix;
                    }else{
                        compteur = compteur+1;
                        printf("%d. %s\n", i+1, tabA[b].nom);
                        prix1 = prix1 + tabA[b].prix;
                    }
                }
            }
        }
    }
    panier[0].prix = prix1; //Stockage du prix total dans une case du panier
    printf("\nPrix des boissons / cocktails : %f Euros\n", panier[0].prix);
    return compteur;
}

/**
 * @brief Panier des cocktails personnalisés
 * 
 * @param[in] panier Panier du client 
 * @param[in] numerococktail Numero du cocktail
 */

void PanierCocktail(panier panier[30], int numerococktail){
    float prix = 0;

    /*Affichage des cocktails personnalisés dans le panier*/
    printf("\nCocktails personnalises :\n");
    for (int i = 0; i<numerococktail; i++){
        if(panier[i].Cocktail.numcocktail != 4430){ //N'affiche pas les cocktails supprimés (les cocktails supprimés sont affectés à 4430)
            printf("Cocktail personnalise %d\n",i+1);
            prix = prix + panier[i].Cocktail.prix;
        }
    }
    panier[1].prix = prix; //Stock le prix total des cocktails dans une case du panier
    printf("\nPrix des cocktails personnalises : %f Euros\n", prix);
}

/**
 * @brief Gestion de la commande du client
 * 
 * @param[in] tabA Boissons non alcoolisées
 * @param[in] tabB Boissons alcoolisées
 * @param[in] tabC Cocktails
 * @param[in] panier Panier du client
 * @param[in] j Entier permettant de passer à l'élément suivant du panier
 * @return Choix du client par rapport à sa commande
 */

int validation(BoissonNonAlcoolisee tabA[N1],BoissonAlcoolisee tabB[N1], Cocktail tabC[N1], panier panier[30], int j, int numerococktail){
    int a , b, c, compteur;
    printf("\nVOTRE PANIER :\n\n");
    compteur = PanierBoisson(tabA, tabB, tabC, panier, j);
    PanierCocktail(panier, numerococktail);

    printf("\nQue voulez vous faire ?\n");
    printf("     1. Valider votre panier\n     2. Supprimer un element\n     3. Ajouter une boisson/cocktail\n     4. Ajouter un cocktail personnalise\n     5. Annuler votre commande\n");
    scanf("%d", &a);
    switch (a){
        case 1 :
            panier[2].prix = panier[0].prix + panier[1].prix; //Calcul du prix total du panier (cocktail + boissons)
            printf("Total de votre panier : %f euros\n", panier[2].prix);
            Sleep(2000);
            system("cls");
            return 3;
        break;
        case 2 :
            printf("\nBoisson/cocktails[Tappez 1] ou cocktail personnalise[Tappez un autre nombre] ?\n");
            scanf("%d", &b);
            switch (b){
                case 1 : //Supprime la boisson souhaitée
                    if (compteur == 0){ //Si aucune boisson n'est dans le panier, alors impossible de supprimer 
                        printf("Ton panier est vide, tu ne peux pas supprimer de boissons\n");
                        validation(tabA, tabB, tabC, panier, j-1, numerococktail);
                    }
                    printf("\nQuelle boisson voulez vous supprimer ?\n");
                    scanf("%d", &a);
                    system("cls");
                    panier[a-1].Boisson = 4441; //Supprime la boisson souhaitée en lui affectant la valeur 4441 
                    validation(tabA, tabB, tabC, panier, j, numerococktail);
                break;
                default :
                    printf("\nQuel cocktail voulez vous supprimer ?\n");
                    scanf("%d", &c);
                    system("cls");
                    c = c-1;
                    panier[c].Cocktail.numcocktail = 4430; //Supprime le cocktail souhaitée en lui affectant la valeur 4430
                    validation(tabA, tabB, tabC, panier, j, numerococktail);
                break;
            }
        break;
        case 3 :
            return 2;
        break;
        case 4 :
            return 1;
        break;
        case 5 :
            return 4;
        default :
            return 5;
        break;
    }
}