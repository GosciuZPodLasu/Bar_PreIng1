#include <stdio.h>
#include <stdlib.h>

void commande(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], panier panier[30], int j){
    BoissonAlcoolisee b1;
    BoissonNonAlcoolisee b2;
    int a = 0, b;
    printf("\nQue voulez vous commander ? [Entre 0 et 19]\n");
    scanf("%d", &b);
    if (b > 9 && b < 20){
        if(tabB[b-10].stock != 0){
            b1 = tabB[b-10];
            printf("Vous avez ajoute %s a votre commande\n", b1.nom);
            panier[j].Boisson = b;
        }else{
            printf("Numero invalide\n");
            commande(tabA, tabB, panier, j);
        }
    }else{
        if(b > -1 && b < 11){
            if(tabA[b].stock != 0){
                b2 = tabA[b];
                printf("Vous avez ajoute %s a votre commande\n", b2.nom);
                panier[j].Boisson = b;
            }else{
                printf("Numero invalide\n");
                commande(tabA, tabB, panier, j);
            }
        }else{
            printf("Numero invalide\n");
            commande(tabA, tabB, panier, j);
        }
    }
}

void print(BoissonNonAlcoolisee tabA[N],BoissonAlcoolisee tabB[N]){
    for (int i= 0;i<N;i++){
        printf("%d. %s\n",i,tabA[i].nom);
    }
    for (int i=0;i<N-1;i++){
        printf("%d. %s\n",i+N,tabB[i].nom);
    }
    printf("19. %s\n",tabB[N-1].nom);
}

int commande_cocktail(BoissonNonAlcoolisee tabA[N],BoissonAlcoolisee tabB[N], panier panier[30], int numerococktail){
    int nombre, b, compteur;
    float prix = 0;
    int stock = 0;
    printf("\nTu as choisi un Cocktail, tu peux faire une combinaison de maximum 3 boissons\n");
    printf("Combien de boissons ? [Entre 2 et 3] : \n");
    scanf("%d",&nombre);
    if(nombre<2 || nombre>3){
        printf("Tu n'as pas choisi le bon nombre de boissons !\nEssaie une deuxieme fois.\n");
        commande_cocktail(tabA, tabB, panier, numerococktail);
        return 0;
    }
    printf("Tu as choisi de faire une combinaison de %d boissons.\nTu as le choix parmis ces boissons : \n\n", nombre);
    print(tabA,tabB);
    int ChoixMix[nombre], verif=0,choix,erreur;
    while(verif!=nombre){
        printf("\nQuelle est ta boisson numero %d ? : ",(verif+1));
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
    panier[numerococktail-1].Cocktail.Boisson1 = ChoixMix[0];
    panier[numerococktail-1].Cocktail.Boisson2 = ChoixMix[1];
    panier[numerococktail-1].Cocktail.Boisson3 = ChoixMix[2];
    panier[numerococktail-1].Cocktail.numcocktail = numerococktail;
    for (int j = 0; j<verif; j++){
        b = ChoixMix[j];
        if (b>9 && b<20){
            printf("\nCombien de cl de %s souhaitez-vous dans votre cocktail\n", tabB[b-10].nom);
            scanf("%d", &stock);
            tabB[b-10].stock = tabB[b-10].stock - stock;
            prix = prix + tabB[b-10].prix;

        }else{
            printf("\nCombien de cl de %s souhaitez-vous dans votre cocktail \n", tabA[b].nom);
            scanf("%d", &stock);
            tabB[b-10].stock = tabB[b-10].stock - stock;
            prix = prix + tabA[b].prix;
        }
    }
    prix = prix * 1.10;
    panier[numerococktail-1].Cocktail.prix = prix;
    printf("\nLe prix de ce cocktail est de %f Euros\n", prix);
    printf("Voici votre cocktail personnalise numero %d compose de : \n", numerococktail);
    for(int i=0;i<nombre;i++){
        b = ChoixMix[i];
        if(b > 9){
                compteur = compteur+1; 
                printf("%d. %s\n", i+1, tabB[b-10].nom);     
            }else{
                compteur = compteur+1;
                printf("%d. %s\n", i+1, tabA[b].nom);
            }
    }
    return 0;
}