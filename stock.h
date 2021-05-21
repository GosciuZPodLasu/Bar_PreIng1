/**
 * @file stock.h
 * @brief Header contenant les fonctions nécessaires à la gestion du stock des boissons par le barman
 * 
 */
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Remplissage du stock de boissons
 * 
 * @param[in] tabA Boissons non alcoolisées
 * @param[in] tabB Boisson alcoolisées
 * @param[in] CA Chiffre d'affaire du barman
 * @return Cout du restock de boissons 
 */
float remplirstock(BoissonNonAlcoolisee tabA[N1], BoissonAlcoolisee tabB[N1], float CA){
    int s, a, b;
    float cout;
    /*Choisir la boisson à modifier le stock*/ 

    printf("\n\nSelectionner la boisson ou l'alcool pour augmenter son stock [Entre 0 et 19]\n");
    scanf("%d", &s);
    if (s > 9 && s < 20){ //BOISSON ALCOOLISEE
        printf("Vous avez choisi : %s\n", tabB[s-10].nom);
        printf("Combien de %s voulez vous rajouter ?\n", tabB[s-10].nom);
        scanf("%d", &a);
        tabB[s-10].stock = tabB[s-10].stock + a; //Ajout du stock souhait
        tabB[s-10].stockcocktail = tabB[s-10].stock * tabB[s-10].contenance; //Recalcul le stock cocktail suite à l'ajout de stock de la boisson
        cout = a*tabB[s-10].prix; // alcul du coût
    }else{
        //BOISSON NON ALCOOLISEE
        if(s > -1 && s < 11){
            printf("Vous avez choisi : %s\n", tabA[s].nom);
            printf("Combien de %s voulez vous rajouter ?\n", tabA[s].nom);
            scanf("%d", &b);
            tabA[s].stock = tabA[s].stock + b;
            tabA[s].stockcocktail = tabA[s].stock * tabA[s].contenance;
            cout = b*tabA[s].prix;
        }else{
            //CHOIX INVALIDE ALORS RECOMMENCER 
            printf("Numero invalide\n");
            remplirstock(tabA, tabB, CA);
        }
    }
    printf("\nCout du restock : %f Euros\n", cout); //Affichage du cout du restock 
    Sleep(2000);
    system("cls");
    return cout;
}
/**
 * @brief Changement du prix des boissons
 * 
 * @param[in] tabA Boissons non alcoolisées
 * @param[in] tabB Boissons alcoolisées
 */

void changerprix(BoissonNonAlcoolisee tabA[N1], BoissonAlcoolisee tabB[N1]){
    int s;
    float prix;

    /*Choisir la boisson à modifier le prix*/ 

    printf("\n\nSelectionner la boisson ou l'alcool pour changer son prix [Entre 0 et 19]\n");
    scanf("%d", &s);
    if (s > 9 && s < 20){ //BOISSON ALCOOLISEE
        printf("Vous avez choisi : %s\n\nPrix actuel : %f\n", tabB[s-10].nom, tabB[s-10].prix);
        printf("Entrez le nouveau prix :\n");
        scanf("%f", &prix);
        tabB[s-10].prix = prix; //Mise a jour du prix de la boisson X
        printf("\nNouveau prix de %s = %f", tabB[s-10].nom, tabB[s-10].prix);
    }else{
        //BOISSON NON ALCOOLISEE
        if(s > -1 && s < 11){
            printf("Vous avez choisi : %s\n\nPrix actuel : %f Euros\n", tabA[s].nom, tabA[s].prix);
            printf("Entrez le nouveau prix :\n");
            scanf("%f", &prix);
            tabA[s].prix = prix; //Mise a jour du prix de la boisson X
            printf("\nNouveau prix de %s = %f Euros\n", tabA[s].nom, tabA[s].prix);
        }else{
            //CHOIX INVALIDE ALORS RECOMMENCER
            printf("Numero invalide\n");
            changerprix(tabA, tabB);
        }
        Sleep(2000);
        system("cls");
    }
}