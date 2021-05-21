#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int commande(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], Cocktail tabC[N], panier panier[30], int j, int alea){
    BoissonAlcoolisee b1;
    BoissonNonAlcoolisee b2;
    Cocktail b3;
    int b = 0;

    if (alea == 1){
        b = rand() % 25;
        if(b > 9 && b<20){
            if(tabB[b-10].stock == 0){
            commande(tabA, tabB, tabC, panier, j, alea = 1);
            }
        }else{
            if(b > -1 && b < 11){
                if(tabA[b].stock == 0){
                commande(tabA, tabB, tabC, panier, j, alea = 1);
                }
            }else{
                if (b >= 20 && b < 25){
                    if(( tabC[b-20].Boisson1 == 0 || tabC[b-20].Boisson2 == 0 ) || ( tabC[b-20].Boisson1 == 0 || tabC[b-20].Boisson2 == 0 || tabC[b-20].Boisson3 ==0 )){
                    commande(tabA, tabB, tabC, panier, j, alea = 1);
                    }
                }
            }   
        }
    }else{
        printf("\nQue voulez vous commander ? [Entre 0 et 24]\n");
        scanf("%d", &b);
        if(b <0 || b>24){
            printf("\nCommande invalide, veuillez resaisir votre commande\n");
            commande(tabA, tabB, tabC, panier, j, alea);
        }
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
            tabB[b-10].stock = tabB[b-10].stock - 1;
            tabB[b-10].stockcocktail = tabB[b-10].stock * tabB[b-10].contenance;
        }else{
            printf("\nCommande invalide, veuillez resaisir votre commande\n");
            commande(tabA, tabB, tabC, panier, j, alea);
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
                tabA[b].stock = tabA[b].stock - 1;
                tabA[b].stockcocktail = tabA[b].stock * tabA[b].contenance;
            }else{
                printf("\nCommande invalide, veuillez resaisir votre commande\n");
                commande(tabA, tabB, tabC, panier, j, alea);
            }
        }else{
            if(b >= 20 && b < 25){
                if((tabC[b-20].Boisson1 !=0 && tabC[b-20].Boisson2 !=0) || (tabC[b-20].Boisson1 !=0 && tabC[b-20].Boisson2 !=0 && tabC[b-20].Boisson3 !=0)){
                    b3 = tabC[b-20];
                    if (alea != 1){
                        printf("Vous avez ajoute %s a votre commande\n", b3.nom);
                    }else{
                        printf("%s \n", b3.nom);
                        panier[4].prix = panier[4].prix + b3.prix;
                    }
                    panier[j].Boisson = b;
                    if (b == 21){
                        tabC[b-20].Boisson1 = tabC[b-20].Boisson1 - 15;
                        tabC[b-20].Boisson2 = tabC[b-20].Boisson2 - 15;
                        if (tabC[b-20].Boisson1 < 0){
                            printf("\nPas assez de stock pour le %s\n", tabC[b-20].nom);
                            tabC[b-20].Boisson1 = 0;
                        } 
                        if (tabC[b-20].Boisson2 < 0){
                            printf("\nPas assez de stock pour le %s\n", tabC[b-20].nom);
                            tabC[b-20].Boisson2 = 0;
                        }      
                    }else{
                        tabC[b-20].Boisson1 = tabC[b-20].Boisson1 - 10;
                        tabC[b-20].Boisson2 = tabC[b-20].Boisson2 - 10;
                        tabC[b-20].Boisson3 = tabC[b-20].Boisson3 - 10;
                        if (tabC[b-20].Boisson1 < 0){
                            printf("\nPas assez de stock pour le %s\n", tabC[b-20].nom);
                            tabC[b-20].Boisson1 = 0;
                            panier[j].Boisson = 4441;
                        }  
                        if (tabC[b-20].Boisson2 < 0){
                            printf("\nPas assez de stock pour le %s\n", tabC[b-20].nom);
                            tabC[b-20].Boisson2 = 0;
                            panier[j].Boisson = 4441;
                        }
                        if (tabC[b-20].Boisson3 < 0){
                            printf("\nPas assez de stock pour le %s\n", tabC[b-20].nom);
                            tabC[b-20].Boisson3 = 0;
                            panier[j].Boisson = 4441;
                        }        
                    }
                    return b;
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
    return 0;
}


void print(BoissonNonAlcoolisee tabA[N],BoissonAlcoolisee tabB[N]){
    printf("  __                              _      _  __  __    \n");
    printf(" / _)  ' _  _      _   _ _    _  /_| /  / )/  )/  )/  \n");
    printf("/(_)()/_) _) ()/)_)  _) (//)_)  (  |(__(__(__/(__/(__ \n");
    for (int i = 0; i<N; i++){
        if(tabA[i].stock > 0){
        puts("\n");
        printf("%s [%d]""   %f Euros\n",tabA[i].nom, i, tabA[i].prix);
        printf("%f cl, Degre sucre : %f g/100 ml\n", tabA[i].contenance, tabA[i].degreSucre);  
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
}

int commande_cocktail(BoissonNonAlcoolisee tabA[N],BoissonAlcoolisee tabB[N], panier panier[30], int numerococktail){
    int nombre, b, compteur, taillecocktail = 30, limite;
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
        if(choix < 0 || choix > 19){
            printf("Numero invalide, veuillez resaisir la boisson\n");
            scanf("%d", &choix);
        }
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
            printf("\nCombien de cl de %s souhaitez-vous dans votre cocktail [%d cl restants]\n", tabB[b-10].nom, taillecocktail);
            scanf("%d", &stock);
            tabB[b-10].stock = tabB[b-10].stock - stock;
            limite = taillecocktail - stock; 
            if(limite < 0){
                printf("\nVous avez ajoute trop de %s\n", tabB[b-10].nom);
                tabB[b-10].stockcocktail = tabA[b].stockcocktail - taillecocktail;
            }else{
                printf("Ajout du %s dans votre cocktail\n", tabB[b-10].nom);
                taillecocktail = taillecocktail - stock;
                tabB[b-10].stockcocktail = tabB[b-10].stockcocktail - stock;
            }
            prix = prix + tabB[b-10].prix;
        }else{
            printf("\nCombien de cl de %s souhaitez-vous dans votre cocktail [%d cl restants]\n", tabA[b].nom, taillecocktail);
            scanf("%d", &stock);
            tabA[b].stock = tabA[b].stock - stock;
            limite = taillecocktail - stock;
            if(limite < 0){
                printf("\nVous avez ajoute trop de %s, la quantite a ete ajustee à celle disponible\n", tabA[b].nom);
                tabA[b].stockcocktail = tabA[b].stockcocktail - taillecocktail;
            }else{
                printf("Ajout du %s dans votre cocktail\n", tabA[b].nom);
                taillecocktail = taillecocktail - stock;
                tabA[b].stockcocktail = tabA[b].stockcocktail - stock;
            }
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

int cocktailBarman (BoissonNonAlcoolisee tabA[N],BoissonAlcoolisee tabB[N], Cocktail tabC[N], panier panier[30]){
    int nombre, stock = 0, taillecocktail = 30, limite, prix, compteur = 0;

    printf("\nTu as choisi un Cocktail, tu peux faire une combinaison de maximum 3 boissons\n");
    printf("Combien de boissons ? [Entre 2 et 3] : \n");
    scanf("%d", &nombre);
    print(tabA,tabB);

    if(nombre<2 || nombre>3){
        printf("Tu n'as pas choisi le bon nombre de boissons !\nEssaie une deuxieme fois.\n");
        cocktailBarman(tabA, tabB, tabC, panier);
        return 0;
    }

    printf("Tu as choisi de faire une combinaison de %d boissons.\nTu as le choix parmis ces boissons : \n\n", nombre);
    print(tabA,tabB);
    int ChoixMix[nombre], verif=0,choix,erreur;
    while(verif!=nombre){
        printf("\nQuelle est ta boisson numero %d ? : ",(verif+1));
        scanf("%d",&choix);
        if(choix < 0 || choix > 19){
            printf("Numero invalide, veuillez resaisir la boisson\n");
            scanf("%d", &choix);
        }
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
    for (int j = 0; j<verif; j++){
        int b = ChoixMix[j];
        if (b>9 && b<20){
            printf("\nCombien de cl de %s souhaitez-vous dans votre cocktail [%d cl restants]\n", tabB[b-10].nom, taillecocktail);
            scanf("%d", &stock);
            tabB[b-10].stock = tabB[b-10].stock - stock;
            limite = taillecocktail - stock; 
            if(limite < 0){
                printf("\nVous avez ajoute trop de %s\n", tabB[b-10].nom);
                tabB[b-10].stockcocktail = tabA[b].stockcocktail - taillecocktail;
            }else{
                printf("Ajout du %s dans votre cocktail\n", tabB[b-10].nom);
                taillecocktail = taillecocktail - stock;
                tabB[b-10].stockcocktail = tabB[b-10].stockcocktail - stock;
            }
            prix = prix + tabB[b-10].prix;
        }else{
            printf("\nCombien de cl de %s souhaitez-vous dans votre cocktail [%d cl restants]\n", tabA[b].nom, taillecocktail);
            scanf("%d", &stock);
            tabA[b].stock = tabA[b].stock - stock;
            limite = taillecocktail - stock;
            if(limite < 0){
                printf("\nVous avez ajoute trop de %s, la quantite a ete ajustee à celle disponible\n", tabA[b].nom);
                tabA[b].stockcocktail = tabA[b].stockcocktail - taillecocktail;
            }else{
                printf("Ajout du %s dans votre cocktail\n", tabA[b].nom);
                taillecocktail = taillecocktail - stock;
                tabA[b].stockcocktail = tabA[b].stockcocktail - stock;
            }
            prix = prix + tabA[b].prix;
        }
    }
    prix = prix * 1.10;

    printf("Voici votre cocktail personnalise numero compose de : \n");
    for(int i=0;i<nombre;i++){
        int c = ChoixMix[i];
        if(c > 9){
                compteur = compteur+1; 
                printf("%d. %s\n", i+1, tabB[c-10].nom);     
            }else{
                compteur = compteur+1;
                printf("%d. %s\n", i+1, tabA[c].nom);
            }
    }

    int choix2;

    printf("\n Ajouter ce cocktail à la carte (Tappez 1)");
    printf("\n Recommencer (Tappez 2)");
    scanf("%d", &choix2);
    if (choix2 == 2){
        cocktailBarman(tabA, tabB, tabC, panier);
    }

    int j = 5;
    while (tabC[j].numcocktail == 0){
        j++;
    }

    tabC[j].numcocktail = 1;
    printf("Donnez un nom pour votre nouveau cocktail");
    scanf("%s", &tabC[j].nom);
    if (nombre == 2){
        tabC[j].Boisson1 = ChoixMix[0];
        tabC[j].Boisson2 = ChoixMix[1];
    }else{
        tabC[j].Boisson1 = ChoixMix[0];
        tabC[j].Boisson2 = ChoixMix[1];
        tabC[j].Boisson3 = ChoixMix[2];
    }

    tabC[j].prix = prix;

    printf("Le cocktail a ete ajoute a la carte avec succes");

    }

