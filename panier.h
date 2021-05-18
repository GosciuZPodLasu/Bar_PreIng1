#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "commande.h"

int PanierBoisson(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], Cocktail tabC[N], panier panier[30], int j){
    int b, compteur;
    float prix1 = 0;
    printf("Boissons/Cocktails :\n");
    if(j > 0){
        for(int i = 0; i<j; i++){  
            if(panier[i].Boisson != 4441){                                                                                       
                b = panier[i].Boisson;
                if(b > 9 && b < 20){
                    compteur = compteur+1; 
                    printf("%d. %s\n", i+1, tabB[b-10].nom);
                    prix1 = prix1 + tabB[b-10].prix;     
                }else{
                    if (b > 19 && b < 25){
                        compteur = compteur+1;
                        printf("%d. %s\n", i+1, tabC[b-20].nom);
                        prix1 = prix1 + tabC[b-20].prix;
                    }else{
                        compteur = compteur+1;
                        printf("%d. %s\n", i+1, tabA[b].nom);
                        prix1 = prix1 + tabA[b].prix;
                    }
                }
            }
        }
    }
    panier[0].prix = prix1;
    printf("\nPrix des boissons / cocktails : %f Euros\n", panier[0].prix);
    return compteur;
}


void PanierCocktail(panier panier[30], int numerococktail){
    float prix = 0;
    printf("\nCocktails personnalises :\n");
    for (int i = 0; i<numerococktail; i++){
        if(panier[i].Cocktail.numcocktail != 4430){
            printf("Cocktail personnalise %d\n",i+1);
            prix = prix + panier[i].Cocktail.prix;
        }
    }
    panier[1].prix = prix;
    printf("\nPrix des cocktails personnalises : %f Euros\n", prix);
}


int validation(BoissonNonAlcoolisee tabA[N],BoissonAlcoolisee tabB[N], Cocktail tabC[N], panier panier[30], int j, int numerococktail){
    int a, b, c, compteur;
    printf("\nVoici votre panier :\n");
    compteur = PanierBoisson(tabA, tabB, tabC, panier, j);
    PanierCocktail(panier, numerococktail);

    printf("\nQue voulez vous faire ?\n");
    printf("     1. Valider votre panier\n     2. Supprimer un element\n     3. Ajouter une boisson/cocktail\n     4. Ajouter un cocktail personnalise\n     5. Annuler votre commande\n");
    scanf("%d", &a);
    switch (a){
        case 1 :
            panier[2].prix = panier[0].prix + panier[1].prix;
            printf("Total de votre panier : %f euros\n", panier[2].prix);
            return 3;
        break;
        case 2 :
            printf("\nBoisson[Tappez 1] ou cocktail[Tappez 2] ?\n");
            scanf("%d", &b);
            switch (b){
                case 1 :
                    if (compteur == 0){
                        printf("Ton panier est vide, tu ne peux pas supprimer de boissons\n");
                        validation(tabA, tabB, tabC, panier, j-1, numerococktail);
                    }
                    printf("\nQuelle boisson voulez vous supprimer ?\n");
                    scanf("%d", &a);
                    panier[a-1].Boisson = 4441;
                    validation(tabA, tabB, tabC, panier, j, numerococktail);
                break;
                case 2 :
                    printf("\nQuel cocktail voulez vous supprimer ?\n");
                    scanf("%d", &c);
                    c = c-1;
                    panier[c].Cocktail.numcocktail = 4430;
                    validation(tabA, tabB, tabC, panier, j, numerococktail);
                break;
                default :
                break;
            }
        break;
        case 3 :   
            return 2;
        break;
        case 4 :
            return 1;
        break;
        case 5 :
            return 4;
        default :
            return 5;
        break;
    }
    return 0;
}

/*
void animation(){

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                 xxxxxxxxxxx\n");
    printf("                        xxxxxxxxxxxxxxxxxxxx\n");
    printf("                xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("                xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("                        xxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxx            xxxxxxxxxx\n");
    printf("  xx               xx\n");
    printf("   xx             xx\n");
    printf("    xx           xx\n");
    printf("     xx         xx\n");
    printf("      xxxxxxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    Sleep(1000);
    system("cls");



    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                 xxxxxxxxxxx\n");
    printf("                        xxxxxxxxxx        xx\n");
    printf("                xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("             xx xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("            xx          xxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxx            xxxxxxxxxx\n");
    printf("  xx       xxx     xx\n");
    printf("   xx      xx     xx\n");
    printf("    xx           xx\n");
    printf("     xx         xx\n");
    printf("      xxxxxxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    Sleep(1000);
    system("cls");



    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                 xxxxxxxxxxx\n");
    printf("                        xxxxxxxxxx         x\n");
    printf("                xxxxxxxxx              xxxxx\n");
    printf("             xx xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("            xx          xxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxx            xxxxxxxxxx\n");
    printf("  xx       xxx     xx\n");
    printf("   xx      xx     xx\n");
    printf("    xx    xxx    xx\n");
    printf("     xx  xxxx   xx\n");
    printf("      xxxxxxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    Sleep(1000);
    system("cls");


    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                 xxxxxxxxxxx\n");
    printf("                        xxxxxxxxxx         x\n");
    printf("                xxxxxxxxx                  x\n");
    printf("             xx xxxxxxxxxxxxxxxxxxxx       x\n");
    printf("            x           xxxxxxxxxxxxxxx    x\n");
    printf(" xxxxxxxxxxxxxxxxxxxxx            xxxxxxxxxx\n");
    printf("  xx        x      xx\n");
    printf("   xx      xx     xx\n");
    printf("    xxxxxxxxxxxxxxx\n");
    printf("     xxxxxxxxxxxxx\n");
    printf("      xxxxxxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    Sleep(1000);
    system("cls");

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                 xxxxxxxxxxx\n");
    printf("                        xxxxxxxxxx         x\n");
    printf("                xxxxxxxxx                  x\n");
    printf("                xxxxxxxxx                  x\n");
    printf("                        xxxxxxxxxxxxxxx    x\n");
    printf(" xxxxxxxxxxxxxxxxxxxxx            xxxxxxxxxx\n");
    printf("  xx        x      xx\n");
    printf("   xx      xx     xx\n");
    printf("    xxxxxxxxxxxxxxx\n");
    printf("     xxxxxxxxxxxxx\n");
    printf("      xxxxxxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    Sleep(1000);
    system("cls");

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                                 xxxxxxxxxxx\n");
    printf("                        xxxxxxxxxx         x\n");
    printf("                xxxxxxxxx                  x\n");
    printf("                xxxxxxxxx                  x\n");
    printf("                        xxxxxxxxxxxxxxx    x\n");
    printf(" xxxxxxxxxxxxxxxxxxxxx            xxxxxxxxxx\n");
    printf("  xx               xx\n");
    printf("   xxxxxxxxxxxxxxxxx\n");
    printf("    xxxxxxxxxxxxxxx\n");
    printf("     xxxxxxxxxxxxx\n");
    printf("      xxxxxxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    Sleep(1000);
    system("cls");

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("      \n");
    printf("       \n");
    printf("       \n");
    printf("       \n");
    printf("        \n");
    printf(" xxxxxxxxxxxxxxxxxxxxx            \n");
    printf("  xx               xx\n");
    printf("   xxxxxxxxxxxxxxxxx\n");
    printf("    xxxxxxxxxxxxxxx\n");
    printf("     xxxxxxxxxxxxx\n");
    printf("      xxxxxxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    Sleep(1000);
    system("cls");

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("      \n");
    printf("       \n");
    printf("       \n");
    printf("       \n");
    printf("                             xx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxx      xx            \n");
    printf("  xx               xx      xx\n");
    printf("   xxxxxxxxxxxxxxxxx      xx\n");
    printf("    xxxxxxxxxxxxxxx      xx\n");
    printf("     xxxxxxxxxxxxx      xx\n");
    printf("      xxxxxxxxxxx      xx\n");
    printf("          xxx         xx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    Sleep(1000);
    system("cls");

    printf("                          xx\n");
    printf("                         xx\n");
    printf("                        xx\n");
    printf("                       xx\n");
    printf("                      xx\n");
    printf("                     xx\n");
    printf("                    xx\n");
    printf("                   xx\n");
    printf("        \n");
    printf(" xxxxxxxxxxxxxxxxxxxxx            \n");
    printf("  xx               xx\n");
    printf("   xxxxxxxxxxxxxxxxx\n");
    printf("    xxxxxxxxxxxxxxx\n");
    printf("     xxxxxxxxxxxxx\n");
    printf("      xxxxxxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    Sleep(1000);
    system("cls");

     printf("\n");
    printf("\n");
    printf("\n");
    printf("                  xx\n");
    printf("                 xx\n");
    printf("                xx\n");
    printf("               xx\n");
    printf("              xx\n");
    printf("             xx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxx            \n");
    printf("  xx        xx     xx\n");
    printf("   xxxxxxxxxxxxxxxxx\n");
    printf("    xxxxxxxxxxxxxxx\n");
    printf("     xxxxxxxxxxxxx\n");
    printf("      xxxxxxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    Sleep(1000);
    system("cls");

     printf("\n");
    printf("\n");
    printf("\n");
    printf("                 \n");
    printf("                 xx\n");
    printf("                xx\n");
    printf("               xx                  xxxx\n");
    printf("              xx                  xxxxx\n");
    printf("             xx                  xxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxx        xxxxxxx\n");
    printf("  xx       xx      xx        x       x\n");
    printf("   xxxxxxxxxxxxxxxxx        x         x\n");
    printf("    xxxxxxxxxxxxxxx         x         x\n");
    printf("     xxxxxxxxxxxxx          x         x\n");
    printf("      xxxxxxxxxxx            x       x\n");
    printf("          xxx                 xxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    Sleep(1000);
    system("cls");

    printf("\n");
    printf("\n");
    printf("\n");
    printf("                 \n");
    printf("                 xx\n");
    printf("                xx\n");
    printf("               xx                  xxxx\n");
    printf("              xx                  xxxxx\n");
    printf("             xx                  xxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxx        xxxxxxx\n");
    printf("  xx       xx      xx        x       x              xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("   xxxxxxxxxxxxxxxxx        x         x             xxxxxxxxxxxxxxxxx            x\n");
    printf("    xxxxxxxxxxxxxxx         x         x              xxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("     xxxxxxxxxxxxx          x         x               xxxxxxxxxxxxxxx\n");
    printf("      xxxxxxxxxxx            x       x                   xxxxxxxxx\n");
    printf("          xxx                 xxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    printf("\n");
    printf("\n");
    printf("Decoupage du Citron");
    Sleep(1000);
    system("cls");

        printf("\n");
    printf("\n");
    printf("\n");
    printf("                 \n");
    printf("                 xx\n");
    printf("                xx\n");
    printf("               xx                  xxxx\n");
    printf("              xx                  xxxxx\n");
    printf("             xx        xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxx xxxxxxxxxxxxxxxxx            x\n");
    printf("  xx       xx      xx   xxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("   xxxxxxxxxxxxxxxxx     xxxxxxxxxxxxxxx\n");
    printf("    xxxxxxxxxxxxxxx         xxxxxxxxx x\n");
    printf("     xxxxxxxxxxxxx          x         x\n");
    printf("      xxxxxxxxxxx            x       x\n");
    printf("          xxx                 xxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    printf("\n");
    printf("\n");
    printf("Decoupage du Citron");
    Sleep(1000);
    system("cls");

     printf("\n");
    printf("\n");
    printf("\n");
    printf("                 \n");
    printf("                 xx\n");
    printf("                xx\n");
    printf("               xx                  xxxx\n");
    printf("              xx                  xxxxx\n");
    printf("             xx                  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxx        xxxxxxxxxxxxxxxxxxxxxx            x\n");
    printf("  xx       xx      xx        x      xxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("   xxxxxxxxxxxxxxxxx        x        xxxxxxxxxxxxxxx\n");
    printf("    xxxxxxxxxxxxxxx         x         x xxxxxxxxx\n");
    printf("     xxxxxxxxxxxxx          x         x\n");
    printf("      xxxxxxxxxxx            x       x\n");
    printf("          xxx                 xxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    printf("\n");
    printf("\n");
    printf("Decoupage du Citron");
    Sleep(1000);
    system("cls");

    printf("\n");
    printf("\n");
    printf("\n");
    printf("                 \n");
    printf("                 xx\n");
    printf("                xx\n");
    printf("               xx                  xxxx\n");
    printf("              xx                  xxxxx\n");
    printf("             xx        xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxx xxxxxxxxxxxxxxxxx            x\n");
    printf("  xx       xx      xx   xxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("   xxxxxxxxxxxxxxxxx     xxxxxxxxxxxxxxx\n");
    printf("    xxxxxxxxxxxxxxx         xxxxxxxxx x\n");
    printf("     xxxxxxxxxxxxx          x         x\n");
    printf("      xxxxxxxxxxx            x       x\n");
    printf("          xxx                 xxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    printf("\n");
    printf("\n");
    printf("Decoupage du Citron");
    Sleep(1000);
    system("cls");

     printf("\n");
    printf("\n");
    printf("\n");
    printf("                 \n");
    printf("                 xx\n");
    printf("                xx\n");
    printf("               xx                  xxxx\n");
    printf("              xx                  xxxxx\n");
    printf("             xx                  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx         \n");
    printf(" xxxxxxxxxxxxxxxxxxxxx        xxxxxxxxxxxxxxxxxxxxxx            x        \n");
    printf("  xx       xx      xx        x      xxxxxxxxxxxxxxxxxxxxxxxxxxxxx          \n");
    printf("   xxxxxxxxxxxxxxxxx        x        xxxxxxxxxxxxxxx\n");
    printf("    xxxxxxxxxxxxxxx         x         x xxxxxxxxx\n");
    printf("     xxxxxxxxxxxxx          x         x\n");
    printf("      xxxxxxxxxxx            x       x\n");
    printf("          xxx                 xxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    printf("\n");
    printf("\n");
    printf("Decoupage du Citron");
    Sleep(1000);
    system("cls");

        printf("\n");
    printf("\n");
    printf("\n");
    printf("                 \n");
    printf("                 xx\n");
    printf("                xx\n");
    printf("               xx                  xxxx\n");
    printf("              xx                  xxxxx\n");
    printf("             xx        xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxx xxxxxxxxxxxxxxxxx            x\n");
    printf("  xx       xx      xx   xxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("   xxxxxxxxxxxxxxxxx     xxxxxxxxxxxxxxx\n");
    printf("    xxxxxxxxxxxxxxx         xxxxxxxxx x\n");
    printf("     xxxxxxxxxxxxx          x         x\n");
    printf("      xxxxxxxxxxx            x       x\n");
    printf("          xxx                 xxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    printf("\n");
    printf("\n");
    printf("Decoupage du Citron");
    Sleep(1000);
    system("cls");

     printf("\n");
    printf("\n");
    printf("\n");
    printf("                 \n");
    printf("                 xx\n");
    printf("                xx\n");
    printf("               xx                  xxxx\n");
    printf("              xx                  xxxxx\n");
    printf("             xx                  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx           \n");
    printf(" xxxxxxxxxxxxxxxxxxxxx        xxxxxxxxxxxxxxxxxxxxxx            x          \n");
    printf("  xx       xx      xx        x      xxxxxxxxxxxxxxxxxxxxxxxxxxxxx           \n");
    printf("   xxxxxxxxxxxxxxxxx        x        xxxxxxxxxxxxxxx\n");
    printf("    xxxxxxxxxxxxxxx         x         x xxxxxxxxx\n");
    printf("     xxxxxxxxxxxxx          x         x\n");
    printf("      xxxxxxxxxxx            x       x\n");
    printf("          xxx                 xxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    printf("\n");
    printf("\n");
    printf("Decoupage du Citron");
    Sleep(1000);
    system("cls");

     printf("\n");
    printf("\n");
    printf("\n");
    printf("                 \n");
    printf("                 xx\n");
    printf("                xx\n");
    printf("               xx\n");
    printf("              xx\n");
    printf("             xx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxx        xxxxxxxxxx          \n");
    printf("  xx       xx      xx        xxxxxx    xx\n");
    printf("   xxxxxxxxxxxxxxxxx         xxxxx      xx\n");
    printf("    xxxxxxxxxxxxxxx          xxxx   xx  xx\n");
    printf("     xxxxxxxxxxxxx           xxxx       xx\n");
    printf("      xxxxxxxxxxx             xxxxxx   xxx\n");
    printf("          xxx                  xxxxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
    Sleep(1000);
    system("cls");

     printf("\n");
    printf("\n");
    printf("\n");
    printf("                 \n");
    printf("                 xx\n");
    printf("                xx\n");
    printf("               xx\n");
    printf("              xx   xxxxxxx\n");
    printf("             xx   xxxxxxxxx\n");
    printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("  xx       xx       xxxxxxxx\n");
    printf("   xxxxxxxxxxxxxxxxxxxxxxxxx\n");
    printf("    xxxxxxxxxxxxxxxxxxxxxx\n");
    printf("     xxxxxxxxxxxxx\n");
    printf("      xxxxxxxxxxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("          xxx\n");
    printf("         xxxxx\n");
}
*/