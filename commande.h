#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10

void commande(BoissonNonAlcoolisee tabA[N], BoissonAlcoolisee tabB[N], panier panier[30]){
    BoissonAlcoolisee b1;
    BoissonNonAlcoolisee b2;
    int a = 0, b;
    printf("Que voulez vous commander ? [Entre 0 et 19]\n");
    scanf("%d", &b);
    if (b > 9){
        b1 = tabB[b-10];
        printf("Vous avez ajoute %s a votre commande\n", b1.nom);
    }else{
        b2 = tabA[b];
        printf("Vous avez ajoute %s a votre commande\n", b2.nom);
    }
}


int validation(panier panier[30]){
    int a;

    printf("     1.Valider votre panier\n     2.Supprimer un element\n     3.Ajouter un element\n     4.Annuler votre commande\n");
    scanf("%d", &a);
    switch (a){
        case 1 :
            return 0;
        break;
        case 2 :
            if(panier[0].nomBoisson == NULL){
                printf("Ton panier est vide, tu ne peux pas supprimer d'elements\n");
                validation(panier);
            }
            printf("Quel element voulez vous supprimer ?\n");
        break;
        case 3 :    
            return 1;
        break;
        case 4 :
            return 2;
        break;
        default :
            printf("Choisissez entre 1 et 3");
            validation(panier);
            return 0;
        break;
    }

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