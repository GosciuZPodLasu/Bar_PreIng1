/**
 * @file commande.h
 * @brief Header contenant les fonctions nécessaires à la prise de commande d'une boisson ou d'un cocktail
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void animation();

/**
 * @brief Prise de commande du client
 * 
 * @param[in] tabA Les boissons non alcoolisées
 * @param[in] tabB Les boissons alcoolisées
 * @param[in] tabC Les cocktails
 * @param[in] panier Le panier du client
 * @param[in] j Entier permettant de passer à l'élément suivant du panier
 * @param[in] alea Prise de commande aléatoire
 * @return Boisson ou cocktail commandé
 */
int commande(BoissonNonAlcoolisee tabA[N1], BoissonAlcoolisee tabB[N1], Cocktail tabC[N1], panier panier[30], int j, int alea){
    BoissonAlcoolisee b1;
    BoissonNonAlcoolisee b2;
    Cocktail b3;
    int b = 0;

    /* Création d'une boucle permettant de choisir aleatoirement des boissons en stock (uniquement en mode Barman lors de l'arrivée d'un client)*/
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

        /* Prise de la commande de l'utilisateur */

        printf("\nQue voulez vous commander ? [Entre 0 et 24]\n");
        scanf("%d", &b);
        if(b <0 || b>24){ //Réexecution de la fonction en cas de chiffre hors intervalle (0-24)
            printf("\nCommande invalide, veuillez resaisir votre commande\n");
            commande(tabA, tabB, tabC, panier, j, alea);
        }
    }

    /*Verification du stock si la boisson choisie est alcoolisee et ajout dans le panier si elle est en stock*/

    if (b > 9 && b < 20){
        if(tabB[b-10].stock != 0){
            b1 = tabB[b-10];
            if (alea != 1){
                system("cls");
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

        /*Verification du stock si la boisson choisie est non alcoolisee et ajout dans le panier si elle est en stock*/

        if(b > -1 && b < 11){
            if(tabA[b].stock != 0){
                b2 = tabA[b];
                if (alea != 1){
                    system("cls");
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

            /*Verification du stock si la boisson choisie est un cocktail et ajout dans le panier s'il est en stock*/

            if(b >= 20 && b <= 25){
                if((tabC[b-20].Boisson1 !=0 && tabC[b-20].Boisson2 !=0) || (tabC[b-20].Boisson1 !=0 && tabC[b-20].Boisson2 !=0 && tabC[b-20].Boisson3 !=0)){
                    b3 = tabC[b-20];
                    if (alea != 1){
                        system("cls");
                        printf("Vous avez ajoute %s a votre commande\n", b3.nom);
                    }else{
                        printf("%s \n", b3.nom);
                        panier[4].prix = panier[4].prix + b3.prix;
                    }
                    panier[j].Boisson = b;

                    /* Verification du stock des boissons contenant le cocktail choisi après avoir calculé le stock cocktail de chaque boisson composant le cocktail*/

                    if (b == 21){
                        tabC[b-20].Boisson1 = tabC[b-20].Boisson1 - 15;
                        tabC[b-20].Boisson2 = tabC[b-20].Boisson2 - 15;
                        if (tabC[b-20].Boisson1 < 0 || tabC[b-20].Boisson2){
                            printf("\nPas assez de stock pour le %s\n", tabC[b-20].nom);
                            if(tabC[b-20].Boisson1 < 0){
                                tabC[b-20].Boisson1 = 0;
                            }
                            if(tabC[b-20].Boisson2 < 0){
                                tabC[b-20].Boisson2 = 0;
                            } 
                            panier[j].Boisson = 4441;
                        }  
                    }else{
                        tabC[b-20].Boisson1 = tabC[b-20].Boisson1 - 10;
                        tabC[b-20].Boisson2 = tabC[b-20].Boisson2 - 10;
                        tabC[b-20].Boisson3 = tabC[b-20].Boisson3 - 10;
                        if (tabC[b-20].Boisson1 < 0 || tabC[b-20].Boisson2 || tabC[b-20].Boisson3 < 0){
                            printf("\nPas assez de stock pour le %s\n", tabC[b-20].nom);
                            if(tabC[b-20].Boisson1 < 0){
                                tabC[b-20].Boisson1 = 0;
                            }
                            if(tabC[b-20].Boisson2 < 0){
                                tabC[b-20].Boisson2 = 0;
                            } 
                            if(tabC[b-20].Boisson3 < 0){
                                tabC[b-20].Boisson3 = 0;
                            }
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

/**
 * @brief Affichage de la carte pour la composition des cocktails sans les cocktails prédéfinis
 * 
 * @param[in] tabA Boissons non alcoolisées
 * @param[in] tabB Boissons alcoolisées
 */

void print(BoissonNonAlcoolisee tabA[N1],BoissonAlcoolisee tabB[N1]){
    Color(4, 0);
    printf("  __                              _      _  __  __    \n");
    printf(" / _)  ' _  _      _   _ _    _  /_| /  / )/  )/  )/  \n");
    printf("/(_)()/_) _) ()/)_)  _) (//)_)  (  |(__(__(__/(__/(__ \n");
    Color(15, 0);

    /* Affichage des boissons non alcoolisées*/

    for (int i = 0; i<N1; i++){
        if(tabA[i].stock > 0){
        puts("\n");
        Color(12, 0);
        printf("%s", tabA[i].nom);
        Color(15, 0);
        printf(" [%d]""   %f Euros\n", i, tabA[i].prix);
        printf("%f cl, Degre sucre : %f g/100 ml\n", tabA[i].contenance, tabA[i].degreSucre);  
        } 
    }
    printf("\n- - - - - - - - - - - - - - - - - - - - - \n");
    Color(11, 0);
    printf("  _      _  __  __     __ \n");
    printf(" /_| /  / )/  )/  )/  (   \n");
    printf("(  |(__(__(__/(__/(____)  \n");
    Color(15, 0);

    /* Affichage des boissons alcoolisées*/

    for (int j = 0; j<N1; j++){
        if(tabB[j].stock > 0){
        puts("\n");
        Color(11, 0);
        printf("%s", tabB[j].nom);
        Color(15, 0);
        printf(" [%d]""   %f Euros\n",j+10, tabB[j].prix);
        printf("%f cl, Degre alcool : %f %%\n", tabB[j].contenance, tabB[j].degreAlcool);  
        } 
    }
}
/**
 * @brief Prise de commande d'un cocktail
 * 
 * @param[in] tabA Boissons non alcoolisées
 * @param[in] tabB Boissons alcoolisées
 * @param[in] panier Panier du client
 * @param[in] numerococktail Numero du cocktail
 */

int commande_cocktail(BoissonNonAlcoolisee tabA[N1],BoissonAlcoolisee tabB[N1], panier panier[30], int numerococktail){
    int nombre, b, compteur, taillecocktail, limite;
    float prix = 0;
    int stock = 0;

    /*L'utilisateur choisit combien de boissons vont composer son cocktail*/
    printf("\nTu as choisi un Cocktail, tu peux faire une combinaison de maximum 3 boissons\n");
    printf("Combien de boissons ? [Entre 2 et 3] : \n");
    scanf("%d",&nombre);
    if(nombre<2 || nombre>3){ //On Recommence si le nombre de boissons choisi est hors de l'intervalle (2-3)
        printf("Tu n'as pas choisi le bon nombre de boissons !\nEssaie une deuxieme fois.\n");
        commande_cocktail(tabA, tabB, panier, numerococktail);
        return 0;
    }

    /*Affichage des différentes boissons disponibles à la realisation d'un cocktail*/
    printf("Tu as choisi de faire une combinaison de %d boissons.\nTu as le choix parmis ces boissons : \n\n", nombre);
    print(tabA,tabB);
    int ChoixMix[nombre], verif=0,choix,erreur;

    /*Prise de commande des differentes boissons qui vont composer le cocktail*/
    while(verif!=nombre){
        printf("\nQuelle est ta boisson numero %d ? : ",(verif+1));
        scanf("%d",&choix);
        if(choix < 0 || choix > 19){
            printf("Numero invalide, veuillez resaisir la boisson\n"); // Rejet si le choix depasse l'intervalle (0-19)
            scanf("%d", &choix);
        }
        erreur=0;
        for(int i=0;i<=verif;i++){
            // Rejet si l'utilisateur choisit deux fois la même boisson
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
    system("cls");
    printf("Vous pouvez creer un cocktail d'une contenance maximale de 30 cl\n");
    /*On initialise le panier avec le choix de chaque boisson présente dans le cocktail*/
    panier[numerococktail-1].Cocktail.Boisson1 = ChoixMix[0];
    panier[numerococktail-1].Cocktail.Boisson2 = ChoixMix[1];
    panier[numerococktail-1].Cocktail.Boisson3 = ChoixMix[2];
    panier[numerococktail-1].Cocktail.numcocktail = numerococktail;
    for (int j = 0; j<verif; j++){ //On définit la quantité de cl maximale pour chaque boisson selon si on choisit un mix de 2 ou 3 boissons
        switch (verif){
            case 2 :
                taillecocktail = 15;
            break;
            case 3 :
                taillecocktail = 10;
            break;
            default :
            break;
        }
        /*L'utilisateur choisit la quantité de chaque boisson pour son cocktail */
        b = ChoixMix[j];
        if (b>9 && b<20){
            //PARTIE BOISSON ALCOOLISEE

            printf("\nCombien de cl de %s souhaitez-vous dans votre cocktail [%d cl restants]\n", tabB[b-10].nom, taillecocktail);
            scanf("%d", &stock);
            limite = taillecocktail - stock; 
            if(limite < 0){ // Ajustement si la quantité choisi depasse le stockcocktail disponible
                printf("\nVous avez ajoute trop de %s, la quantite a ete ajustee a celle disponible\n", tabB[b-10].nom);
                tabB[b-10].stockcocktail = tabB[b-10].stockcocktail - taillecocktail;
            }else{
                tabB[b-10].stockcocktail = tabB[b-10].stockcocktail - stock;
            }
            prix = prix + tabB[b-10].prix; // Ajout du prix de la boisson dans le prix total du cocktail
        }else{
            //PARTIE BOISSON NON ALCOOLISEE

            printf("\nCombien de cl de %s souhaitez-vous dans votre cocktail [%d cl restants]\n", tabA[b].nom, taillecocktail);
            scanf("%d", &stock);
            limite = taillecocktail - stock;
            if(limite < 0){ // Ajustement si la quantité choisi depasse le stockcocktail disponible
                printf("\nVous avez ajoute trop de %s, la quantite a ete ajustee a celle disponible\n", tabA[b].nom);
                tabA[b].stockcocktail = tabA[b].stockcocktail - taillecocktail;
            }else{
                tabA[b].stockcocktail = tabA[b].stockcocktail - stock;
            }
            prix = prix + tabA[b].prix; // Ajout du prix de la boisson dans le prix total du cocktail 
        }
    }
    printf("\nPreparation de votre cocktail\n\n");
    Sleep(2000);
    animation();
    prix = prix * 1.10; // Majoration de 10% du prix du cocktail 
    panier[numerococktail-1].Cocktail.prix = prix; // Stockage du prix du cocktail dans le panier 

    /* Recapitulatif du cocktail crée avec les boissons qui le composent et son prix */
    printf("\nLe prix de ce cocktail est de %f Euros\n", prix);
    printf("\nVoici votre cocktail personnalise numero %d compose de : \n", numerococktail);
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

/**
 * @brief Animation de la création d'un cocktail
 * 
 */

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
