#include <stdio.h>
#include <stdlib.h>

void print(BoissonNonAlcoolisee tabA[N],BoissonAlcoolisee tabB[N]){
    for (int i= 0;i<N;i++){
        printf("%d. %s\n",i,tabA[i].nom);
    }
    for (int i=0;i<N-1;i++){
        printf("%d. %s\n",i+N,tabB[i].nom);
    }
    printf("19.%s\n",tabB[N-1].nom);
}

int commande_cocktail(BoissonNonAlcoolisee tabA[N],BoissonAlcoolisee tabB[N], panier panier[30]){
    int nombre;
    printf("\nTu as choisi un Cocktail, tu peux faire une combinaison de maximum 3 boissons\n");
    printf("Combien de boissons ? [Entre 2 et 3] : \n");
    scanf("%d",&nombre);
    if(nombre<2 || nombre>3){
        printf("Tu n'as pas choisi le bon nombre de boissons !\nEssaie une deuxieme fois.\n");
        commande_cocktail(tabA, tabB, panier);
        return 0;
    }
    printf("Tu as choisi de faire une combinaison de %d boissons.\nTu as le choix parmis ces boissons : \n", nombre);
    print(tabA,tabB);
    int ChoixMix[nombre], verif=0,choix,erreur;
    while(verif!=nombre){
        printf("Quelle est ta boisson numero %d ? : ",(verif+1));
        scanf("%d",&choix);
        erreur=0;
        for(int i=0;i<=verif;i++){
            if (ChoixMix[i]==choix){
                printf("Tu ne peux pas choisir la meme boisson deux fois\n");
                erreur++;
            }
        }
        if(erreur==0){
            ChoixMix[verif]=choix;
            verif++;
        }      
    }
    printf("Tu as choisi les boissons : ");
    for(int i=0;i<nombre;i++){
        printf("%d ",ChoixMix[i]);
    }
    return 0;
}