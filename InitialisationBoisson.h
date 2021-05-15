#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 10
#define TailleMAX 2000

typedef struct{
    char* nom; //Nom de la boisson
    float prix; //Prix d'une boisson
    float contenance; //Contenance de la boisson en cl = un verre
    int degreSucre; //Degré de sucre dans la boisson en g/cl
    int stock;  //Nombre de boissons disponibles
    float stockcocktail; //Total de la contenance disponible d'une boisson en cl
}BoissonNonAlcoolisee;

typedef struct{
    char* nom; //Nom de l'alcool
    float prix; //Prix d'un alcool
    float contenance; //Contenance de l'alcool en cl = un verre
    int degreAlcool; //Degré d'alcool en °
    int stock; //Nombre de portions disponibles 
    float stockcocktail; //Total de la contenance d'un alcool disponible en cl
}BoissonAlcoolisee;

typedef struct{
    int Boisson1;
    int Boisson2;
    int Boisson3;
    int numcocktail;
    float prix;
}Cocktail;


typedef struct{
    int Boisson;
    float prix;
    Cocktail Cocktail;
}panier;

/*
void test(BoissonNonAlcoolisee tabA[]){
    BoissonNonAlcoolisee jusorange;
    FILE *f = NULL;
    char c[TailleMAX];
    f = fopen("jusorange.txt", "r");
    printf("i");
    if (f != NULL){
        while(fgets(c, TailleMAX, f) != NULL){
            printf("%s", c);
        }
        fclose(f);
    }
    if(f != NULL){
        printf("d");
        fscanf(f, "%s %f %f %f %d %f", tabA[0].nom, &tabA[0].prix, &tabA[0].contenance, &tabA[0].degreSucre, &tabA[0].stock, &tabA[0].stockcocktail);
        printf("p");
        fclose(f);
    }
    printf("g");
    printf("%s", tabA[0].nom);
    printf("%f", tabA[0].degreSucre);
}
*/

void initialisationBoissonNonAlcoolisee(BoissonNonAlcoolisee tabA[N]){
    BoissonNonAlcoolisee jusorange, juspomme, jusananas, jusfraise, limonade, siropgrenadine, pulcocitron, siroppeche, siropmenthe, coca;

    /*BOISSONS NON ALCOOLISEES*/

    /*JUS D'ORANGE*/
    jusorange.nom = "Jus d'orange";
    jusorange.prix = 1;
    jusorange.contenance = 33;
    jusorange.degreSucre = 9.6;
    jusorange.stock = 1;
    jusorange.stockcocktail = 100;

    /*JUS DE POMME*/
    juspomme.nom = "Jus de pomme";
    juspomme.prix = 2;
    juspomme.contenance = 25;
    juspomme.degreSucre = 9.7;
    juspomme.stock = 1;
    juspomme.stockcocktail = 5;

    /*JUS D'ANANAS*/
    jusananas.nom = "Jus d'ananas";
    jusananas.prix = 4;
    jusananas.contenance = 45;
    jusananas.degreSucre = 11.6;
    jusananas.stock = 1;
    jusananas.stockcocktail = 110;

    /*JUS DE FRAISE*/
    jusfraise.nom = "Jus de fraise";
    jusfraise.prix = 4;
    jusfraise.contenance = 221;
    jusfraise.degreSucre = 9.5;
    jusfraise.stock = 1;
    jusfraise.stockcocktail = 14;

    /*LIMONADE*/
    limonade.nom = "Limonade";
    limonade.prix = 1;
    limonade.contenance = 2;
    limonade.degreSucre = 18;
    limonade.stock = 1;
    limonade.stockcocktail = 32;

    /*SIROP DE GRENADINE*/
    siropgrenadine.nom = "Sirop de grenadine";
    siropgrenadine.prix = 4; 
    siropgrenadine.contenance = 1;
    siropgrenadine.degreSucre = 82;
    siropgrenadine.stock = 1;
    siropgrenadine.stockcocktail = 3;

    /*SIROP DE PECHE*/
    siroppeche.nom = "Sirop de peche";
    siroppeche.prix = 4;
    siroppeche.contenance = 21;
    siroppeche.degreSucre = 81;
    siroppeche.stock = 1;
    siroppeche.stockcocktail = 2;

    /*SIROP DE MENTHE*/
    siropmenthe.nom = "Sirop de menthe";
    siropmenthe.prix = 13;
    siropmenthe.contenance = 2;
    siropmenthe.degreSucre = 78;
    siropmenthe.stock = 1;
    siropmenthe.stockcocktail = 210;

    /*PULCO CITRON*/
    pulcocitron.nom = "Pulco citron";
    pulcocitron.prix = 6;
    pulcocitron.contenance = 5;
    pulcocitron.degreSucre = 31.8;
    pulcocitron.stock = 1;
    pulcocitron.stockcocktail = 1;

    /*COCA*/
    coca.nom = "Coca";
    coca.prix = 1;
    coca.contenance = 33;
    coca.degreSucre = 4;
    coca.stock = 1;
    coca.stockcocktail = 2;

    /*Affectation des cases du tableau pour chaque boisson*/
    tabA[0] = jusorange;
    tabA[1] = juspomme;
    tabA[2] = jusananas;
    tabA[3] = jusfraise;
    tabA[4] = limonade;
    tabA[5] = siropgrenadine;
    tabA[6] = siroppeche;
    tabA[7] = siropmenthe;
    tabA[8] = pulcocitron;
    tabA[9] = coca;
    
}

void  initialisationBoissonAlcoolisee(BoissonAlcoolisee tabB[N]){
    BoissonAlcoolisee gin, vodka, rhum, tequila, malibu, whisky, champagne, bourbon, rose, triplesec;


    /*BOISSONS ALCOOLISEES*/

    /*GIN*/
    gin.nom = "Gin";
    gin.prix = 12;
    gin.contenance = 21;
    gin.degreAlcool = 24;
    gin.stock = 12;
    gin.stockcocktail = 12;

    /*VODKA*/
    vodka.nom = "Vodka";
    vodka.prix = 12;
    vodka.contenance = 20;
    vodka.degreAlcool = 45;
    vodka.stock = 14;
    vodka.stockcocktail = 120;

    /*RHUM*/
    rhum.nom = "Rhum";
    rhum.prix = 14;
    rhum.contenance = 21;
    rhum.degreAlcool = 22;
    rhum.stock = 0;
    rhum.stockcocktail = 12;

    /*TEQUILA*/
    tequila.nom = "Tequila";
    tequila.prix = 57;
    tequila.contenance = 12;
    tequila.degreAlcool = 12;
    tequila.stock = 1;
    tequila.stockcocktail = 12;

    /*MALIBU*/
    malibu.nom = "Malibu";
    malibu.prix = 12;
    malibu.contenance = 14;
    malibu.degreAlcool = 54;
    malibu.stock = 0;
    malibu.stockcocktail = 21;

    /*WHISKY*/
    whisky.nom = "Whisky";
    whisky.prix = 45;
    whisky.contenance = 10;
    whisky.degreAlcool = 50;
    whisky.stock = 0;
    whisky.stockcocktail = 0;

    /*CHAMPAGNE*/
    champagne.nom = "Champagne";
    champagne.prix = 41;
    champagne.contenance = 12;
    champagne.degreAlcool = 12;
    champagne.stock = 45;
    champagne.stockcocktail = 12;

    /*BOURBON*/
    bourbon.nom = "Bourbon";
    bourbon.prix = 12;
    bourbon.contenance = 41;
    bourbon.degreAlcool = 12;
    bourbon.stock = 34;
    bourbon.stockcocktail = 2;

    /*ROSE*/
    rose.nom = "Rose";
    rose.prix =  12;
    rose.contenance = 12;
    rose.degreAlcool = 64;
    rose.stock = 2;
    rose.stockcocktail = 20;

    /*TRIPLE SEC*/
    triplesec.nom = "Triple Sec";
    triplesec.prix = 45;
    triplesec.contenance = 121;
    triplesec.degreAlcool = 12;
    triplesec.stock = 1;
    triplesec.stockcocktail = 2;

    /*Affectation des cases du tableau pour chaque boisson*/
    tabB[0] = gin;
    tabB[1] = vodka;
    tabB[2] = rhum;
    tabB[3] = tequila;
    tabB[4] = malibu;
    tabB[5] = whisky;
    tabB[6] = champagne;
    tabB[7] = bourbon;
    tabB[8] = rose;
    tabB[9] = triplesec;
        
}
