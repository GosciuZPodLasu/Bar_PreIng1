#include <stdio.h>
#include <stdlib.h>

void print(BoissonNonAlcoolisee tabA[N],BoissonAlcoolisee tabB[N]){
    for (int i= 0;i<N;i++){
        printf("%d.%s, ",i,tabA[i].nom);
    }
    for (int i=0;i<N-1;i++){
        printf("%d.%s, ",i+N,tabB[i].nom);
    }
    printf("19.%s\n",tabB[N-1].nom);
}

int commande_cocktail(BoissonNonAlcoolisee tabA[N],BoissonAlcoolisee tabB[N], panier panier[30]){
    int nombre;
    printf("Tu a choisi un Cocktail, tu peut faire une combinaison de maximum 3 boisson.\n");
    printf("choisi combien de combinaison tu a envie entre (2-3) : ");
    scanf("%d",&nombre);
    if(nombre<2 || nombre>3){
        printf("Tu a pas choisi un bon nombre de boisson !\nEssai une deuxieme fois.\n");
        commande_cocktail(tabA, tabB, panier);
        return 0;
    }
    printf("tu a choisi de faire une combinaison de %d boisson.\n tu a le chois entre cella :", nombre);
    print(tabA,tabB);
    int ChoixMix[nombre], verif=0,choix,erreur;
    while(verif!=nombre){
        printf("Quelle est t'a %d boisson? : ",(verif+1));
        scanf("%d",&choix);
        erreur=0;
        for(int i=0;i<=verif;i++){
            if (ChoixMix[i]==choix){
                printf("TU ne peut pas choisire la meme boisson deux fois");
                erreur++;
            }
        }
        if(erreur==0){
            ChoixMix[verif]=choix;
            verif++;
        }      
    }
    printf("tu a choisi les boisson numero= ");
    for(int i=0;i<nombre;i++){
        printf("%d ",ChoixMix[i]);
    }
    return 0;
}