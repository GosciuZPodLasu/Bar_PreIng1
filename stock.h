#include <stdlib.h>
#include <stdio.h>

float remplirstock(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], float CA){
    int s, a, b;
    float cout;
    printf("Selectionner la boisson ou l'alcool pour augmenter son stock [Entre 0 et 19]\n");
    scanf("%d", &s);
    if (s > 9 && s < 20){
        printf("Vous avez choisi : %s\n", tabB[s-10].nom);
        printf("Combien de %s voulez vous rajouter ?\n", tabB[s-10].nom);
        scanf("%d", &a);
        tabB[s-10].stock = tabB[s-10].stock + a;
        tabB[s-10].stockcocktail = tabB[s-10].stock * tabB[s-10].contenance;
        cout = a*tabB[s-10].prix;
    }else{
        if(s > -1 && s < 11){
            printf("Vous avez choisi : %s\n", tabA[s].nom);
            printf("Combien de %s voulez vous rajouter ?\n", tabA[s].nom);
            scanf("%d", &b);
            tabA[s].stock = tabA[s].stock + b;
            tabA[s].stockcocktail = tabA[s].stock * tabA[s].contenance;
            cout = b*tabA[s].prix;
        }else{
            printf("Numero invalide\n");
            remplirstock(tabA, tabB, CA);
        }
    }
    printf("Cout du restock : %f Euros\n", cout);
    return cout;
}

void changerprix(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N]){
    int s;
    float prix;
    printf("Selectionner la boisson ou l'alcool pour changer son prix [Entre 0 et 19]\n");
    scanf("%d", &s);
    if (s > 9 && s < 20){
        printf("Vous avez choisi : %s\nPrix actuel : %f\n", tabB[s-10].nom, tabB[s-10].prix);
        printf("Entrez le nouveau prix :\n");
        scanf("%f", &prix);
        tabB[s-10].prix = prix;
        printf("Nouveau prix de %s = %f", tabB[s-10].nom, tabB[s-10].prix);
    }else{
        if(s > -1 && s < 11){
            printf("Vous avez choisi : %s\nPrix actuel : %f Euros\n", tabA[s].nom, tabA[s].prix);
            printf("Entrez le nouveau prix :\n");
            scanf("%f", &prix);
            tabA[s].prix = prix;
            printf("Nouveau prix de %s = %f Euros\n", tabA[s].nom, tabA[s].prix);
        }else{
            printf("Numero invalide\n");
            changerprix(tabA, tabB);
        }
    }
}