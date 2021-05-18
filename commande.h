#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void commande(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], Cocktail tabC[N], panier panier[30], int j, int alea){
    BoissonAlcoolisee b1;
    BoissonNonAlcoolisee b2;
    Cocktail b3;
    int b = 0;

    if (alea == 1){
        b = rand() % 25;
    }else{
        printf("\nQue voulez vous commander ? [Entre 0 et 24]\n");
        scanf("%d", &b);
    }
    if (b > 9 && b < 20){
        if(tabB[b-10].stock != 0){
            b1 = tabB[b-10];
            if (alea != 1){
                printf("Vous avez ajoute %s a votre commande\n", b1.nom);
            }else{
                printf("%s \n", b1.nom);
                panier[4].prix = panier[4].prix + b1.prix;
            }
            panier[j].Boisson = b;
        }
    }else{
        if(b > -1 && b < 11){
            if(tabA[b].stock != 0){
                b2 = tabA[b];
                if (alea != 1){
                    printf("Vous avez ajoute %s a votre commande\n", b2.nom);
                }else{
                    printf("%s \n", b2.nom);
                    panier[4].prix = panier[4].prix + b2.prix;
                }
                panier[j].Boisson = b;
            }
        }else{
            if(b >= 20 && b < 25){
                if(tabC[b-20].Boisson1 !=0 && tabC[b-20].Boisson2 !=0 && tabC[b-20].Boisson3 !=0){
                    b3 = tabC[b-20];
                    if (alea != 1){
                        printf("Vous avez ajoute %s a votre commande\n", b3.nom);
                    }else{
                        printf("%s \n", b3.nom);
                        panier[4].prix = panier[4].prix + b3.prix;
                    }
                    panier[j].Boisson = b;
                }else{
                    if (alea != 1){
                        printf("Numero invalide\n");
                        commande(tabA, tabB, tabC, panier, j, alea);
                    }else{
                        commande(tabA, tabB, tabC, panier, j, alea);
                    }
                        
                }
            }
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