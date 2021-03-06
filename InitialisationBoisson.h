/**
 * @file InitialisationBoisson.h
 * @brief Header contenant toutes les fonctions nécessaires à l'initialisation des boissons et cocktails du bar ainsi que leurs informations 
 */

#include <stdlib.h>
#include <stdio.h>
#define N1 10


typedef struct{
    char* nom; //Nom de la boisson
    float prix; //Prix d'une boisson
    float contenance; //Contenance de la boisson en cl = un verre
    float degreSucre; //Degré de sucre dans la boisson en g/100 ml (une fois diluée pour les sirops)
    int stock;  //Nombre de boissons disponibles
    int stockcocktail; //Total de la contenance disponible d'une boisson en cl
}BoissonNonAlcoolisee;

typedef struct{
    char* nom; //Nom de l'alcool
    float prix; //Prix d'un alcool
    float contenance; //Contenance de l'alcool en cl = un verre
    float degreAlcool; //Degré d'alcool en °
    int stock; //Nombre de portions disponibles 
    int stockcocktail; //Total de la contenance d'un alcool disponible en cl
}BoissonAlcoolisee;

typedef struct{
    char* nom; //Nom du cocktail
    int Boisson1; //Numero de la boisson 1 composant le cocktail
    int Boisson2; //Numero de la boisson 2 composant le cocktail 
    int Boisson3; //Numero de la boisson 3 composant le cocktail
    int numcocktail; //Numero du cocktail
    float degreSucre; //Degré sucre du cocktail
    float degreAlcool; //Degré alcool du cocktail
    float prix; //Prix du cocktail
}Cocktail;

typedef struct{
    int Boisson; //Numero des boissons contenues dans le panier 
    float prix; //Prix du panier 
    Cocktail Cocktail;
}panier;

/**
 * @brief Initialisation du stock des boissons non alcoolisées
 * 
 * @param[in] tabA Les boissons non alcoolisées
 * @param[in] nom Le fichier txt où l'on va stocker le stock des boissons non alcoolisées
 */

void inistock1(BoissonNonAlcoolisee tabA[N1], char* nom){
    char stock[10][255];
    int so, sp, sa, sf, sl, sg, spc, spe, sm, scoca;

    /*Récupération du stock des boissons non alcoolisées dans le fichier txt*/

    FILE *f = fopen(nom, "r");
    for (int j = 0; j<10; j++){
        fgets(stock[j], 255, (FILE*)f);
    }
    so = atoi(stock[0]); tabA[0].stock = so;
    sp = atoi(stock[1]); tabA[1].stock = sp;
    sa = atoi(stock[2]); tabA[2].stock = sa;
    sf = atoi(stock[3]); tabA[3].stock = sf;
    sl = atoi(stock[4]); tabA[4].stock = sl;
    sg = atoi(stock[5]); tabA[5].stock = sg;
    spc = atoi(stock[6]); tabA[6].stock = spc;
    spe = atoi(stock[7]); tabA[7].stock = spe;
    sm = atoi(stock[8]); tabA[8].stock = sm;
    scoca = atoi(stock[9]); tabA[9].stock = scoca;
    fclose(f);
}

/**
 * @brief Initialisation du stock des boissons alcoolisées
 * 
 * @param[in] tabB Les boissons alcoolisées
 * @param[in] nom2 Le fichier txt où l'on va stocker le stock des boissons alcoolisées
 */

void inistock2(BoissonAlcoolisee tabB[N1], char* nom2){
    char stock[10][255];
    int sg, sv, sr, st, sm, sw, sc, sb, sro, str;
    FILE *f = fopen(nom2, "r");

    /*Récupération du stock des boissons alcoolisées dans le fichier txt*/

    for (int j = 0; j<10; j++){
        fgets(stock[j], 255, (FILE*)f);
    }
    fclose(f);
    sg = atoi(stock[0]); tabB[0].stock = sg;
    sv = atoi(stock[1]); tabB[1].stock = sv;
    sr = atoi(stock[2]); tabB[2].stock = sr;
    st = atoi(stock[3]); tabB[3].stock = st; 
    sm = atoi(stock[4]); tabB[4].stock = sm;
    sw = atoi(stock[5]); tabB[5].stock = sw; 
    sc = atoi(stock[6]); tabB[6].stock = sc; 
    sb = atoi(stock[7]); tabB[7].stock = sb;
    sro = atoi(stock[8]); tabB[8].stock = sro; 
    str = atoi(stock[9]); tabB[9].stock = str;   
}

/**
 * @brief Mise à jour automatique des stocks des boissons non alcoolisées
 * 
 * @param[in] tabA Les boissons non alcoolisées
 * @param[in] nom Le fichier txt où l'on va stocker le stock des boissons non alcoolisées
 */

void majstock1(BoissonNonAlcoolisee tabA[N1], char* nom){
    /*Met à jour les stocks des boissons non alcoolisées dans le fichier txt */

    FILE *f = fopen(nom, "w");
    for(int i = 0; i<N1; i++){
        fprintf(f,"%d\n", tabA[i].stock);
    }
    fclose(f);
    for(int j = 0; j<N1 ;j++){
        tabA[j].stockcocktail = tabA[j].stock * tabA[j].contenance;
    }
}

/**
 * @brief Mise à jour automatique des stocks des boissons alcoolisées
 * 
 * @param[in] tabB Les boissons alcoolisées
 * @param[in] nom2 Le fichier txt où l'on va stocker le stock des boissons alcoolisées
 */

void majstock2(BoissonAlcoolisee tabB[N1], char* nom2){
    /*Met à jour les stocks des boissons alcoolisées dans le fichier txt */

    FILE *f = fopen(nom2, "w");
    for(int i = 0; i<N1; i++){
        fprintf(f,"%d\n", tabB[i].stock);
    }
    fclose(f);
    for (int j = 0; j<N1; j++){
        tabB[j].stockcocktail = tabB[j].stock * tabB[j].contenance;
    }
}

/**
 * @brief Initialisation des boissons non alcoolisées avec leurs détails
 * 
 * @param[in] tabA Les boissons non alcoolisées
 */

void initialisationBoissonNonAlcoolisee(BoissonNonAlcoolisee tabA[N1]){
    BoissonNonAlcoolisee jusorange, juspomme, jusananas, tonic, limonade, siropgrenadine, pulcocitron, siroppeche, siropmenthe, coca;

    //BOISSONS NON ALCOOLISEES

    //JUS D'ORANGE
    jusorange.nom = "Jus d'orange";
    jusorange.prix = 2.5;
    jusorange.contenance = 35;
    jusorange.degreSucre = 8;
    jusorange.stockcocktail = (tabA[0].stock * jusorange.contenance);

    //JUS DE POMME
    juspomme.nom = "Jus de pomme";
    juspomme.prix = 2.5;
    juspomme.contenance = 35;
    juspomme.degreSucre = 10;
    juspomme.stockcocktail  = (tabA[1].stock * juspomme.contenance);

    //JUS D'ANANAS
    jusananas.nom = "Jus d'ananas";
    jusananas.prix = 2.5;
    jusananas.contenance = 35;
    jusananas.degreSucre = 14;
    jusananas.stockcocktail = (tabA[2].stock * jusananas.contenance);

    //TONIC
    tonic.nom = "Tonic";
    tonic.prix = 2.5;
    tonic.contenance = 35;
    tonic.degreSucre = 9;
    tonic.stockcocktail = (tabA[3].stock * tonic.contenance);
 
    //LIMONADE
    limonade.nom = "Limonade";
    limonade.prix = 2.5;
    limonade.contenance = 35;
    limonade.degreSucre = 10;
    limonade.stockcocktail = (tabA[4].stock * limonade.contenance);

    //SIROP DE GRENADINE
    siropgrenadine.nom = "Sirop de grenadine";
    siropgrenadine.prix = 3; 
    siropgrenadine.contenance = 35;
    siropgrenadine.degreSucre = 7.7;
    siropgrenadine.stockcocktail = (tabA[5].stock * siropgrenadine.contenance);

    //SIROP DE PECHE
    siroppeche.nom = "Sirop de peche";
    siroppeche.prix = 3;
    siroppeche.contenance = 35;
    siroppeche.degreSucre = 7.7;
    siroppeche.stockcocktail = (tabA[6].stock * siroppeche.contenance);

    //SIROP DE MENTHE
    siropmenthe.nom = "Sirop de menthe";
    siropmenthe.prix = 3;
    siropmenthe.contenance = 35;
    siropmenthe.degreSucre = 7.7;
    siropmenthe.stockcocktail = (tabA[7].stock * siropmenthe.contenance);

    //PULCO CITRON
    pulcocitron.nom = "Pulco citron";
    pulcocitron.prix = 2.5;
    pulcocitron.contenance = 35;
    pulcocitron.degreSucre = 0.5;
    pulcocitron.stockcocktail = (tabA[8].stock * pulcocitron.contenance);

    //COCA
    coca.nom = "Coca";
    coca.prix = 2.5;
    coca.contenance = 35;
    coca.degreSucre = 10.6;
    coca.stockcocktail = (tabA[0].stock * coca.contenance);

    //Affectation des cases du tableau pour chaque boisson
    tabA[0] = jusorange;
    tabA[1] = juspomme;
    tabA[2] = jusananas;
    tabA[3] = tonic;
    tabA[4] = limonade;
    tabA[5] = siropgrenadine;
    tabA[6] = siroppeche;
    tabA[7] = siropmenthe;
    tabA[8] = pulcocitron;
    tabA[9] = coca;
    
}

/**
 * @brief Initialisation des boissons alcoolisées avec leurs détails
 * 
 * @param[in] tabB Les boissons alcoolisées
 */


void initialisationBoissonAlcoolisee(BoissonAlcoolisee tabB[N1]){
    BoissonAlcoolisee gin, vodka, rhum, tequila, malibu, whisky, champagne, bourbon, rose, triplesec;

    //BOISSONS ALCOOLISEES

    //GIN
    gin.nom = "Gin";
    gin.prix = 6;
    gin.contenance = 4;
    gin.degreAlcool = 37.5;
    gin.stockcocktail = (tabB[0].stock * gin.contenance);

    //VODKA
    vodka.nom = "Vodka";
    vodka.prix = 5;
    vodka.contenance = 4;
    vodka.degreAlcool = 40;
    vodka.stockcocktail = (tabB[1].stock * vodka.contenance);

    //RHUM
    rhum.nom = "Rhum";
    rhum.prix = 5;
    rhum.contenance = 4;
    rhum.degreAlcool = 37.5;
    rhum.stockcocktail = (tabB[2].stock * rhum.contenance);

    //TEQUILA
    tequila.nom = "Tequila";
    tequila.prix = 5;
    tequila.contenance = 4;
    tequila.degreAlcool = 35;
    tequila.stockcocktail = (tabB[3].stock * tequila.contenance);

    //MALIBU
    malibu.nom = "Malibu";
    malibu.prix = 5;
    malibu.contenance = 4;
    malibu.degreAlcool = 18;
    malibu.stockcocktail = (tabB[4].stock * malibu.contenance);

    //WHISKY
    whisky.nom = "Whisky";
    whisky.prix = 5;
    whisky.contenance = 4;
    whisky.degreAlcool = 40;
    whisky.stockcocktail = (tabB[5].stock * whisky.contenance);

    //CHAMPAGNE
    champagne.nom = "Champagne";
    champagne.prix = 6;
    champagne.contenance = 14;
    champagne.degreAlcool = 12;
    champagne.stockcocktail = (tabB[6].stock * champagne.contenance);

    //BOURBON
    bourbon.nom = "Bourbon";
    bourbon.prix = 3.5;
    bourbon.contenance = 14;
    bourbon.degreAlcool = 45;
    bourbon.stockcocktail = (tabB[7].stock * bourbon.contenance);

    //ROSE
    rose.nom = "Rose";
    rose.prix =  3;
    rose.contenance = 14;
    rose.degreAlcool = 12;
    rose.stockcocktail = (tabB[8].stock * rose.contenance);

    //TRIPLE SEC
    triplesec.nom = "Triple Sec";
    triplesec.prix = 5;
    triplesec.contenance = 4;
    triplesec.degreAlcool = 40;
    triplesec.stockcocktail = (tabB[9].stock * triplesec.contenance);

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

/**
 * @brief Initialisation des cocktails
 * 
 * @param[in] tabA Les boissons non alcoolisées
 * @param[in] tabB Les boissons alcoolisées
 * @param[in] tabC Les cocktails
 * @param[in] recup entier permettant de mettre à jour le stock cocktail
 * @param[in] b Choix du cocktail par le client
 */

void initialisationCocktail(BoissonNonAlcoolisee tabA[N1], BoissonAlcoolisee tabB[N1], Cocktail tabC[N1], int recup, int b){
    Cocktail mojito, pinacolada, margarita, cosmopolitan, gintonic;
    /*Initalistion des cocktails avec leur boissons respectives avec calcul du stock, du degreAlcool et degreSucre de chaque cocktail*/

    //MOJITO
    mojito.nom = "Mojito";
    mojito.prix = (tabA[8].prix + tabA[7].prix + tabB[2].prix) * 1.10;
    if (recup != 1){ //Initialisation du stockcocktail de chaque boisson composant le cocktail avec les informations du fichier txt
        mojito.Boisson1 = tabB[2].stockcocktail;
        mojito.Boisson2 = tabA[8].stockcocktail;
        mojito.Boisson3 = tabA[7].stockcocktail;
    }else{ //Si recup = 1, le stock cocktail se mettra à jour avec le nouveau stockcocktail de chaque boisson composant le cocktail qui a été calculé dans la prise de commande d'un cocktail
        if (b == 20){
        tabB[2].stockcocktail = tabC[0].Boisson1;
        tabA[8].stockcocktail = tabC[0].Boisson2;
        tabA[7].stockcocktail = tabC[0].Boisson3;
        }
    }
    mojito.degreAlcool = tabB[2].degreAlcool;
    mojito.degreSucre = (tabA[2].degreSucre + tabA[8].degreSucre)/2;


    //PINACOLADA
    pinacolada.nom = "Pina Colada";
    pinacolada.prix = (tabA[2].prix + tabB[2].prix) * 1.10;
    if (recup != 1){
        pinacolada.Boisson1 = tabA[2].stockcocktail;
        pinacolada.Boisson2 = tabB[2].stockcocktail;
        pinacolada.Boisson3 = 1;
    }else{
        if(b == 21){
        tabA[2].stockcocktail = tabC[1].Boisson1;
        tabB[2].stockcocktail = tabC[1].Boisson2;
        }
    }
    pinacolada.degreAlcool = tabB[2].degreAlcool;
    pinacolada.degreSucre = tabA[2].degreSucre;

    //MARGARITA
    margarita.nom = "Margarita";
    margarita.prix = (tabA[8].prix + tabB[3].prix + tabB[9].prix) * 1.10;
    if (recup != 1){
        margarita.Boisson1 = tabA[8].stockcocktail;
        margarita.Boisson2 = tabB[3].stockcocktail;
        margarita.Boisson3 = tabB[9].stockcocktail;
    }else{
        if(b == 22){
        tabA[8].stockcocktail = tabC[2].Boisson1;
        tabB[3].stockcocktail = tabC[2].Boisson2;
        tabB[9].stockcocktail = tabC[2].Boisson3;
        }
    }
    margarita.degreAlcool = (tabB[3].degreAlcool + tabB[9].degreAlcool)/2;
    margarita.degreSucre = tabA[8].degreSucre;

    //COSMOPOLITAN
    cosmopolitan.nom = "Cosmopolitan";
    cosmopolitan.prix = (tabA[8].prix + tabB[1].prix + tabB[9].prix) * 1.10;
    if (recup != 1){
        cosmopolitan.Boisson1 = tabB[1].stockcocktail;
        cosmopolitan.Boisson2 = tabA[8].stockcocktail;
        cosmopolitan.Boisson3 = tabB[9].stockcocktail;
    }else{
        if(b == 23){
        tabB[1].stockcocktail = tabC[3].Boisson1;
        tabA[8].stockcocktail = tabC[3].Boisson2;
        tabB[9].stockcocktail = tabC[3].Boisson3;
        }
    }
    cosmopolitan.degreAlcool = (tabB[1].degreAlcool + tabB[9].degreAlcool)/2;
    cosmopolitan.degreSucre = tabA[8].degreSucre;

    //GIN TONIC
    gintonic.nom = "Gin Tonic";
    gintonic.prix = (tabA[8].prix + tabA[3].prix + tabB[0].prix) * 1.10;
    if (recup != 1){
        gintonic.Boisson1 = tabB[0].stockcocktail;
        gintonic.Boisson2 = tabA[3].stockcocktail;
        gintonic.Boisson3 = tabA[8].stockcocktail;
    }else{
        if(b == 24){
        tabB[0].stockcocktail = tabC[4].Boisson1;
        tabA[3].stockcocktail = tabC[4].Boisson2;
        tabA[8].stockcocktail = tabC[4].Boisson3;
        }
    }
    gintonic.degreAlcool = tabB[0].degreAlcool;
    gintonic.degreSucre = (tabA[3].degreSucre + tabA[8].degreSucre)/2;
    
    /*Affectation des cases du tableau pour chaque cocktail*/

    tabC[0] = mojito;
    tabC[1] = pinacolada;
    tabC[2] = margarita;
    tabC[3] = cosmopolitan;
    tabC[4] = gintonic;
}


void calculstock(BoissonNonAlcoolisee tabA[N1], BoissonAlcoolisee tabB[N1]){
    /*Calcul du stock des boissons à partir des nouveaux stock cocktails*/

    for(int i = 0; i<N1; i++){
        tabA[i].stock = (tabA[i].stockcocktail / tabA[i].contenance);
    }
    for (int j = 0; j<N1; j++){
        tabB[j].stock = (tabB[j].stockcocktail / tabB[j].contenance);
    }
}