#include <stdio.h>
#include <stdlib.h>


void affichageClient(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], Cocktail tabC[N]){
    printf("  __                              _      _  __  __    \n");
    printf(" / _)  ' _  _      _   _ _    _  /_| /  / )/  )/  )/  \n");
    printf("/(_)()/_) _) ()/)_)  _) (//)_)  (  |(__(__(__/(__/(__ \n");
    for (int i = 0; i<N; i++){
        if(tabA[i].stock > 0){
        puts("\n");
        printf("%s [%d]""   %f Euros\n",tabA[i].nom, i, tabA[i].prix);
        printf("%f cl, %f Degre sucre : g/100 ml\n", tabA[i].contenance, tabA[i].degreSucre);  
        } 
    }
    printf("\n- - - - - - - - - - - - - - - - - \n");
    printf("  _      _  __  __     __ \n");
    printf(" /_| /  / )/  )/  )/  (   \n");
    printf("(  |(__(__(__/(__/(____)  \n");
    for (int j = 0; j<N; j++){
        if(tabB[j].stock > 0){
        puts("\n");
        printf("%s [%d]""   %f Euros\n",tabB[j].nom, j+10, tabB[j].prix);
        printf("%f cl, Degre alcool : %f %%\n", tabB[j].contenance, tabB[j].degreAlcool);  
        } 
    }
    printf("\n- - - - - - - - - - - - - - - - - \n");
    printf("   __    __    __      ____   _           __ \n");
    printf(" /     /  /  /    /__/  /    /_|  /  /   (   \n");        
    printf("(__   (__/  (__  /  )  (    (  | (  (__ __)  \n");
    for (int k = 0; k<N; k++){
        if(tabC[k].Boisson1 > 0 && tabC[k].Boisson2 > 0 && tabC[k].Boisson3 > 0){
            puts("\n");
            printf("%s [%d]""   %f Euros\n",tabC[k].nom, k+20, tabC[k].prix);
            printf("Degre alcool : %f %%, Degre sucre : %f g/100 ml\n", tabC[k].degreAlcool, tabC[k].degreSucre);
        }
    }
}

void affichageBarman(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N]){
    printf("  __                              _      _  __  __    \n");
    printf(" / _)  ' _  _      _   _ _    _  /_| /  / )/  )/  )/  \n");
    printf("/(_)()/_) _) ()/)_)  _) (//)_)  (  |(__(__(__/(__/(__ \n");
    for (int i = 0; i<N; i++){
        puts("\n");
        printf("%s [%d]""   %f Euros\n",tabA[i].nom, i, tabA[i].prix);
        printf("%f cl, %f g/100 ml\n", tabA[i].contenance, tabA[i].degreSucre);
        printf("Stock : %d    Stock cocktail : %d", tabA[i].stock, tabA[i].stockcocktail);  
    }
    printf("\n- - - - - - - - - - - - - - - - - \n");
    printf("  _      _  __  __     __ \n");
    printf(" /_| /  / )/  )/  )/  (   \n");
    printf("(  |(__(__(__/(__/(____)  \n");
    for (int j = 0; j<N; j++){
        puts("\n");
        printf("%s [%d]""   %f Euros\n",tabB[j].nom, j+10, tabB[j].prix);
        printf("%f cl, Degre : %f %%\n", tabB[j].contenance, tabB[j].degreAlcool);
        printf("Stock : %d    Stock cocktail : %d", tabB[j].stock, tabB[j].stockcocktail); 
    }
}
