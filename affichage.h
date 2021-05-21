/**
 * @file affichage.h
 * @brief Header contenant les fonctions nécessaires à l'affichage de la carte pour le client ainsi que l'affichage des stocks pour le barman
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
/**
 * @brief Affichage de la carte pour le client
 * 
 * @param[in] tabA Boissons non alcoolisées
 * @param[in] tabB Boissons alcoolisées
 * @param[in] tabC Cocktails
 */

void affichageClient(BoissonNonAlcoolisee tabA[N1], BoissonAlcoolisee tabB[N1], Cocktail tabC[N1]){
    Color(4, 0);
    printf("  __                              _      _  __  __    \n");
    printf(" / _)  ' _  _      _   _ _    _  /_| /  / )/  )/  )/  \n");
    printf("/(_)()/_) _) ()/)_)  _) (//)_)  (  |(__(__(__/(__/(__ \n");
    Color(15, 0);

    /* Affichage de chaque boisson non alcoolisee en stock avec son prix, sa contenance et son degré de sucre */

    for (int i = 0; i<N1; i++){
        if(tabA[i].stock > 0){
        puts("\n");
        Color(12, 0);
        printf("%s", tabA[i].nom);
        Color(15, 0);
        printf(" [%d]""   %f Euros\n", i, tabA[i].prix);
        printf("%f cl, Degre sucre : %f g/100 ml\n", tabA[i].contenance, tabA[i].degreSucre);  
        } 
    }
    printf("\n- - - - - - - - - - - - - - - - - - - - - \n");
    Color(11, 0);
    printf("  _      _  __  __     __ \n");
    printf(" /_| /  / )/  )/  )/  (   \n");
    printf("(  |(__(__(__/(__/(____)  \n");
    Color(15, 0);

    /* Affichage de chaque boisson alcoolisee en stock avec son prix, sa contenance et son degré d'alcool */

    for (int j = 0; j<N1; j++){
        if(tabB[j].stock > 0){
        puts("\n");
        Color(11, 0);
        printf("%s", tabB[j].nom);
        Color(15, 0);
        printf(" [%d]""   %f Euros\n",j+10, tabB[j].prix);
        printf("%f cl, Degre alcool : %f %%\n", tabB[j].contenance, tabB[j].degreAlcool);  
        } 
    }
    printf("\n- - - - - - - - - - - - - - - - - - - - - \n");
    Color(13, 0);
    printf("   __    __    __      ____   _           __ \n");
    printf(" /     /  /  /    /__/  /    /_|  /  /   (   \n");        
    printf("(__   (__/  (__  /  )  (    (  | (  (__ __)  \n");
    Color(15, 0);

    /* Affichage de chaque cocktail en stock avec son prix, sa contenance et son degré d'alcool */

    for (int k = 0; k<N1; k++){
        if((tabC[k].Boisson1 > 0 && tabC[k].Boisson2 > 0) || (tabC[k].Boisson1 > 0 && tabC[k].Boisson2 > 0 && tabC[k].Boisson3 > 0)){
            puts("\n");
            Color(13, 0);
            printf("%s", tabC[k].nom);
            Color(15, 0);
            printf(" [%d]""   %f Euros\n", k+20, tabC[k].prix);
            printf("Degre alcool : %f %%, Degre sucre : %f g/100 ml\n", tabC[k].degreAlcool, tabC[k].degreSucre);
        }
    }
}

/**
 * @brief Affichage de la carte avec les stocks pour le barman
 * 
 * @param[in] tabA Boissons non alcoolisées
 * @param[in] tabB Boissons alcoolisées
 */

void affichageBarman(BoissonNonAlcoolisee tabA[N1], BoissonAlcoolisee tabB[N1]){
    Color(4, 0);
    printf("  __                              _      _  __  __    \n");
    printf(" / _)  ' _  _      _   _ _    _  /_| /  / )/  )/  )/  \n");
    printf("/(_)()/_) _) ()/)_)  _) (//)_)  (  |(__(__(__/(__/(__ \n");
    Color(15, 0);

    /* Affichage de chaque boisson non alcoolisee avec son prix, sa contenance, son degré de sucre et son stock */

    for (int i = 0; i<N1; i++){
        puts("\n");
        Color(12, 0);
        printf("%s", tabA[i].nom);
        Color(15, 0);
        printf(" [%d]""   %f Euros\n", i, tabA[i].prix);
        printf("%f cl, %f g/100 ml\n", tabA[i].contenance, tabA[i].degreSucre);
        printf("Stock : %d    Stock cocktail : %d", tabA[i].stock, tabA[i].stockcocktail);  
    }
    printf("\n- - - - - - - - - - - - - - - - - - - - - \n");
    Color(11, 0);
    printf("  _      _  __  __     __ \n");
    printf(" /_| /  / )/  )/  )/  (   \n");
    printf("(  |(__(__(__/(__/(____)  \n");
    Color(15, 0);

    /* Affichage de chaque boisson alcoolisee avec son prix, sa contenance, son degres d'alcool et son stock */

    for (int j = 0; j<N1; j++){
        puts("\n");
        Color(11, 0);
        printf("%s", tabB[j].nom);
        Color(15, 0);
        printf(" [%d]""   %f Euros\n",j+10, tabB[j].prix);
        printf("%f cl, Degre : %f %%\n", tabB[j].contenance, tabB[j].degreAlcool);
        printf("Stock : %d    Stock cocktail : %d", tabB[j].stock, tabB[j].stockcocktail); 
    }
}
