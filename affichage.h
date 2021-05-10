#include <stdio.h>
#include <stdlib.h>

void affichageClient(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[T]){
    printf("  __                              _      _  __  __    \n");
    printf(" / _)  ' _  _      _   _ _    _  /_| /  / )/  )/  )/  \n");
    printf("/(_)()/_) _) ()/)_)  _) (//)_)  (  |(__(__(__/(__/(__ \n");
    for (int i = 0; i<N; i++){
        if(tabA[i].stock > 0){
        puts("\n");
        printf("%s""   %f Euros\n",tabA[i].nom, tabA[i].prix);
        printf("%f cl, %d g/cl\n", tabA[i].contenance, tabA[i].degreSucre);  
        } 
    }
    printf("\n- - - - - - - - - - - - - - - - - \n");
    printf("  _      _  __  __     __ \n");
    printf(" /_| /  / )/  )/  )/  (   \n");
    printf("(  |(__(__(__/(__/(____)  \n");
    for (int j = 0; j<T; j++){
        if(tabB[j].stock > 0){
        puts("\n");
        printf("%s""   %f Euros\n",tabB[j].nom, tabB[j].prix);
        printf("%f cl, Degre : %d %%\n", tabB[j].contenance, tabB[j].degreAlcool);  
        } 
    }
}


void affichageBarman(BoissonNonAlcoolisee tabA[], BoissonAlcoolisee tabB[]){
    printf("  __                              _      _  __  __    \n");
    printf(" / _)  ' _  _      _   _ _    _  /_| /  / )/  )/  )/  \n");
    printf("/(_)()/_) _) ()/)_)  _) (//)_)  (  |(__(__(__/(__/(__ \n");
    for (int i = 0; i<N; i++){
        puts("\n");
        printf("%s""   %f Euros\n",tabA[i].nom, tabA[i].prix);
        printf("%f cl, %d g/cl\n", tabA[i].contenance, tabA[i].degreSucre);
        printf("Stock : %d    Stock cocktail : %f", tabA[i].stock, tabA[i].stockcocktail);  
    }
    printf("\n- - - - - - - - - - - - - - - - - \n");
    printf("  _      _  __  __     __ \n");
    printf(" /_| /  / )/  )/  )/  (   \n");
    printf("(  |(__(__(__/(__/(____)  \n");
    for (int j = 0; j<T; j++){
        puts("\n");
        printf("%s""   %f Euros\n",tabB[j].nom, tabB[j].prix);
        printf("%f cl, Degre : %d %%\n", tabB[j].contenance, tabB[j].degreAlcool);
        printf("Stock : %d    Stock cocktail : %f", tabB[j].stock, tabB[j].stockcocktail); 
    }
}

/*
void affichageClient(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[T]){
    printf("  __                              _      _  __  __                        _      _  __  __     __ \n");
    printf(" / _)  ' _  _      _   _ _    _  /_| /  / )/  )/  )/                     /_| /  / )/  )/  )/  (   \n");
    printf("/(_)()/_) _) ()/)_)  _) (//)_)  (  |(__(__(__/(__/(__                   (  |(__(__(__/(__/(____)  \n");     
    for (int m=10; m<13; m++){
        tabA[m].nom = "-";
        tabA[m].prix = 0;
        tabA[m].contenance = 0;
        tabA[m].degreSucre = 0;
        tabA[m].stock = 1;

        tabB[m].nom = "-";
        tabB[m].prix = 0;
        tabB[m].contenance = 0;
        tabB[m].degreAlcool = 0;
        tabB[m].stock = 1;
    }
        
    for (int i = 0; i<N-3; i++){
        for (int j = 0; j<T-3; j++){
            while (tabA[i].stock == 0){
            i++;
            }
            while (tabB[j].stock == 0){
            j++;
            }
        
            if(tabA[i].stock > 0){
            puts("\n");
            printf("%s   %f Euros""                                          %s""     %f Euros\n",tabA[i].nom, tabA[i].prix, tabB[j].nom, tabB[j].prix);
            printf("%f cl, %d g/cl""                                                 %f cl, Degre : %d %%\n", tabA[i].contenance, tabA[i].degreSucre, tabB[j].contenance, tabB[j].degreAlcool);
            i++;
            }
        }   
    }
}
*/