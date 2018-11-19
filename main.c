#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Declaration de la bibliotheque pour pouvoir utiliser sizeof
#define VALMIN 1
#define VALMAX 3999     //Declaration des constantes min et max pour definir les limites accessibles par l'utilisateur
#define M 1000
#define D 500
#define C 100       //Declaration des constantes pour les valeurs de chaque lettre
#define L 50
#define X 10
#define V 5
#define I 1

int ConversionDecimale(int nNb, char cNbRomain[]){      //Fonction de conversion Romain -> Decimale

        int nCpt=0;     //Declaration d'un compteur

        //for(nCpt=0; nCpt<=(sizeof(cNbRomain)/sizeof(char)); nCpt++){
        while (cNbRomain[nCpt]>=(sizeof(cNbRomain)/sizeof(char))){      //Boucle TANT QUE pour regler le soucis de la boucle POUR
           if ((cNbRomain[nCpt]=='C') && (cNbRomain[nCpt+1]=='M')){       //On test toutes les soustractions possibles
                nNb+=(M-C);
                nCpt+=2;    //Si une soustraction est effectuée, on ajoute 2 au compteur pour passer les 2 caracteres
            }
            else if ((cNbRomain[nCpt]=='C') && (cNbRomain[nCpt+1]=='D')){
                nNb+=(D-C);
                nCpt+=2;
            }
            else if ((cNbRomain[nCpt]=='X') && (cNbRomain[nCpt+1]=='C')){
                nNb+=(C-X);
                nCpt+=2;
            }
            else if ((cNbRomain[nCpt]=='X') && (cNbRomain[nCpt+1]=='L')){
                nNb+=(L-X);
                nCpt+=2;
            }
            else if ((cNbRomain[nCpt]=='I') && (cNbRomain[nCpt+1]=='X')){
                nNb+=(X-I);
                nCpt+=2;
            }
            else if ((cNbRomain[nCpt]=='I') && (cNbRomain[nCpt+1]=='V')){
                nNb+=(V-I);
                nCpt+=2;
            }
            else
                if (cNbRomain[nCpt]=='M'){ //Si aucune soustraction n'est a effectuer, on additionne à la variable Nb la valeur de la lettre
                    nNb+=M;
                    nCpt+=1;}
            else
                if (cNbRomain[nCpt]=='D'){
                    nNb+=D;
                    nCpt+=1;}
            else
                if (cNbRomain[nCpt]=='C'){
                    nNb+=C;
                    nCpt+=1;}
            else
                if (cNbRomain[nCpt]=='L'){
                    nNb+=L;
                    nCpt+=1;}
            else
                if (cNbRomain[nCpt]=='X'){
                    nNb+=X;
                    nCpt+=1;}
            else
                if (cNbRomain[nCpt]=='V'){
                    nNb+=V;
                    nCpt+=1;}
            else
                if (cNbRomain[nCpt]=='I'){
                    nNb+=I;
                    nCpt+=1;}
        }
        //}
        return nNb;     //Fin de la fonction
        }
int ConversionRomain(int nNb, char cNbRomain[]){
    while (nNb>0){
        if (nNb>=1000){
            cNbRomain = strncat(cNbRomain,"M",sizeof(cNbRomain)+1);
            nNb-=1000;
        }
        else if (nNb>=900){
            cNbRomain = strncat(cNbRomain,"CM",sizeof(cNbRomain)+1);
            nNb-=900;
        }
        else if (nNb>=500){
            cNbRomain = strncat(cNbRomain,"D",sizeof(cNbRomain)+1);
            nNb-=500;
        }
        else if (nNb>=400){
            cNbRomain = strncat(cNbRomain,"CD",sizeof(cNbRomain)+1);
            nNb-=400;
        }
        else if (nNb>=100){
            cNbRomain = strncat(cNbRomain,"C",sizeof(cNbRomain)+1);
            nNb-=100;
        }
        else if (nNb>=90){
            cNbRomain = strncat(cNbRomain,"CD",sizeof(cNbRomain)+1);
            nNb-=90;
        }
        else if (nNb>=50){
            cNbRomain = strncat(cNbRomain,"L",sizeof(cNbRomain)+1);
            nNb-=50;
        }
        else if (nNb>40){
            cNbRomain = strncat(cNbRomain,"XL",sizeof(cNbRomain)+1);
            nNb-=40;
        }
        else if (nNb>=10){
            cNbRomain = strncat(cNbRomain,"X",sizeof(cNbRomain)+1);
            nNb-=10;
        }
        else if (nNb>=9){
            cNbRomain = strncat(cNbRomain,"IX",sizeof(cNbRomain)+1);
            nNb-=9;
        }
        else if (nNb>=5){
            cNbRomain = strncat(cNbRomain,"V",sizeof(cNbRomain)+1);
            nNb-=5;
        }
        else if (nNb>=4){
            cNbRomain = strncat(cNbRomain,"IV",sizeof(cNbRomain)+1);
            nNb-=4;
        }
        else
            cNbRomain = strncat(cNbRomain,"I",sizeof(cNbRomain)+1);
            nNb-=1;
    }
    return cNbRomain;
}


int main()      //Debut du programme principal
{

    int nNb=0, nChoix=0, nCpt=0;      //Initialisation des variables
    char cNbRomain [15];    //On autorise jusqu'a 15 caracteres, amplement suffisant

    printf("Rentrez 1 pour convertir un chiffre romain en chiffre decimal, 2 pour convertir un chiffre decimal en chiffre romain\n");
    scanf("%d",& nChoix);

    switch (nChoix){

        case 1 :
            printf("Veuillez entrer un nombre romain que vous souhaitez convertir\n");
            scanf("%s",& cNbRomain);
            printf("Le chiffre romain %s vaut en decimale : %d\n",cNbRomain,ConversionDecimale(nNb,cNbRomain));
            break;

        case 2 :
            printf("Veuillez entrer un nombre decimal que vous souhaitez convertir\n");
            scanf("%d",& nNb);
            printf("Le chiffre decimal %d vaut en romain : %s\n",nNb,ConversionRomain(nNb,cNbRomain));
            break;
    }

    return 0;
}
