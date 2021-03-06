#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/classique.h"
#include "../include/avance.h"

#define couleur(param) printf("\033[%sm",param)
#define T 100

/**
*\file interface.c
*\brief Interface du Puissance 4

*\author Benjamin, Julien, Arthur
*\version 1.0
*\date Novembre 2016
*/


/**

*\fn int menu()
*\brief Menu pour commencer la partie
*\return Retourne le choix de l'utilisateur

*/
int menu(){
	int choix;

	system("clear");

	printf("\n+-------------------------------+ ");
	printf("\n|	        Menu            |");
	printf("\n|				|");
	printf("\n|  1 - Puissance 4 classique	|");
	printf("\n|  2 - Puissance 4 avance	|");
	printf("\n|  3 - Quitter			|");
	printf("\n|				|");
	printf("\n+-------------------------------+ ");
	
	do{
		printf("\n>> Votre choix : ");
		scanf("%d",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1: puissance_classique(); return choix;
			case 2: puissance_avance(); return choix;
			case 3: return choix;
			default: printf("\nErreur: votre choix doit etre compris entre 1 et 3\n");
			}
	}while(choix < 1 || choix > 3);

	return 0;
}

//Demande et retourne le nombre de joueurs
int nb_joueurs_classique(){
	int choix;

	system("clear");

	printf("\n+-------------------------------+ ");
	printf("\n|	  PUISSANCE 4 classique |");
	printf("\n|				|");
	printf("\n|	  Nombre de joueurs:    |");
	printf("\n| 	      1 joueurs		|");
	printf("\n| 	      2 joueurs		|");
	printf("\n|				|");
	printf("\n+-------------------------------+ ");

	do{
		printf("\n>>Votre choix : ");
		scanf("%d",&choix);
	}while(choix < 1 || choix > 2);

	return choix;
}

/**

*\fn void affich_score_classique()
*\brief Affiche les meilleurs scores

*/
void affich_score_classique(){
	int i, j, taille;
	t_score temp;
	
	FILE * fichier;
	t_score tab[T];

	fichier = fopen("best_classique.txt", "r");

	//Met tout les scores dans un tableau
	i = 0;
	do{
		fscanf(fichier, "%s", tab[i].pseudo);
		fscanf(fichier, "%i", &tab[i].score);
		i++;
	}while(!feof(fichier));
	taille = i;

	//Tri du tableau dans l'ordre croissant des scores pour avoir les meilleurs scores
	for(i = 0; i < taille; i++){							//Parcours complet de la sequence a trier
		
		for(j = taille-1; j > i; j--){						//Parcours de la sequence non triee
			
			if(tab[j-1].score > tab[j].score){				
				temp = tab[j];
				tab[j] = tab[j-1];				//Permute tab[j] et tab[j-1]
				tab[j-1] = temp;
			}
		}
	}

	fclose(fichier);

	//Affichage des 5 meilleurs scores
	printf("	  Records   	");
	printf("\n");
	for(i = 0; i < 5 && i < taille; i++){
		printf("\n	  %i - %s  :  %i", i+1, tab[i].pseudo, tab[i].score);
	}
	printf("\n");
}

/**

*\fn int fin_jeux()
*\brief Menu pour la fin de la partie
*\return Retourne le choix de l'utilisateur 

*/
int fin_jeux(){
	int choix;

	printf("\n+-------------------------------+ ");
	printf("\n|	        FIN             |");
	printf("\n|				|");
	printf("\n| 	 1 - Rejouer		|");
	printf("\n|  	 2 - Retour au menu	|");
	printf("\n|  	 3 - Quitter		|");
	printf("\n|				|");
	printf("\n+-------------------------------+ ");
	
	do{
		printf("\n>> Votre choix : ");
		scanf("%d", &choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1: puissance_classique(); return choix;;
			case 2: menu(); return choix;;
			case 3: return choix;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}
	}while(choix < 1 || choix > 3);
}

/**

*\fn void pseudo_classique(char pseudo1[L], char pseudo2[L], int party, int debut)
*\brief Demande les pseudos des joueurs

*/
void pseudo_classique(char pseudo1[L], char pseudo2[L], int party, int debut, int nb_joueurs){
	system("clear");
	if(party == 1 && debut == 2)
		printf("\nAUCUNE PARTIE ENREGISTRE\n");
		
	printf("\nVeuillez choisir vos pseudos sachant qu'ils ne doivent pas depasser 5 caracteres \n \n");
	
	do{
		couleur("31");
		printf("\nJoueur 1: ");
		scanf("%s", pseudo1);
		couleur("0");
		if(strlen(pseudo1) > 5)
			printf("Erreur: votre pseudo ne doit pas depasser 5 caracteres");
	}while(strlen(pseudo1) > 5);
	couleur("0");

	if(nb_joueurs == 2){
		do{
			couleur("34");
			printf("\nJoueur 2: ");
			scanf("%s", pseudo2);
			couleur("0");
			if(strlen(pseudo2) > 5)
				printf("Erreur: votre pseudo ne doit pas depasser 5 caracteres");
		}while(strlen(pseudo2) > 5);
	}

	else
		strcpy(pseudo2,"Ordi");
}

/**

*\fn int quitter()
*\brief Menu qui demande à l'utilisaeur de quitter et/ou sauvegarder pendant une partie
*\return Choix de l'utilisateur

*/
int quitter(){
	int choix;
	system("clear");

	printf("\n+-------------------------------+ ");
	printf("\n|	       Quitter          |");
	printf("\n|				|");
	printf("\n|  1 - Quitter sans sauvegarder	|");
	printf("\n|  2 - Quitter et sauvegarder	|");
	printf("\n|				|");
	printf("\n+-------------------------------+ ");

	do{
		printf("\n>> Votre choix : ");
		scanf("%d",&choix);

		if(choix < 1 || choix > 2)
			printf("\nErreur: votre choix doit etre 1 ou 2\n");
	}while(choix < 1 || choix > 2);
	
	return choix;
}

/**

*\fn int begin()
*\brief Menu au début de la partie
*\return Choix de l'utilisateur

*/
int begin(){
	int choix;
	system("clear");

	printf("\n+---------------------------------------+ ");
	printf("\n|    		  Début          	|");
	printf("\n|					|");
	printf("\n|  1 - Commencer une nouvelle partie	|");
	printf("\n|  2 - Charger la partie precedente	|");
	printf("\n|  3 - Retour				|");
	printf("\n|					|");
	printf("\n+---------------------------------------+ ");

	do{
		printf("\n>> Votre choix : ");
		scanf("%d",&choix);
		
		if(choix < 1 || choix > 3)
			printf("\nErreur: votre choix doit etre 1 ou 2\n");
	}while(choix < 1 || choix > 3);
	
	return choix;
}
