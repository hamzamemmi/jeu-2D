#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <time.h>
#include "enig.h"

//void afficher_enigme(SDL_Surface ecran,char image[20]);

int main(int argc, char *argv[])
{
srand(time(NULL));
int nbalea=0;
int *x1=0,*y1=0,*x2=0,*y2=0,*x3=0,*y3=0;
char image[20],categorie1[20]="h",categorie2[20]="g",categorie3[20]="p";

SDL_Surface *ecran = NULL, *imagefond=NULL, *enigme=NULL;

SDL_Rect positionFond;
    SDL_Event event;
    int continuer = 1;

    positionFond.x = 0;
    positionFond.y = 0;

SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL

ecran = SDL_SetVideoMode(1024, 415, 32, SDL_HWSURFACE); // Ouverture de la fenêtre

SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

SDL_WM_SetCaption("IN GAME", NULL);

imagefond = IMG_Load("fond.png");

SDL_BlitSurface(imagefond, NULL, ecran, &positionFond);
while (continuer)

{

    SDL_PollEvent(&event);//attendre l'evenement

    switch(event.type)

    {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)

            {
                case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
                    //continuer = 0;
ecran = SDL_SetVideoMode(1024, 415, 32, SDL_HWSURFACE); // Ouverture de la fenêtre

SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
                    SDL_BlitSurface(imagefond, NULL, ecran, &positionFond);
SDL_Flip(ecran);
                    break;
            }//event.key.keysym.sym

            break;
            case SDL_QUIT: /* Si c'est un événement QUITTER */
            continuer = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
            break;
case SDL_MOUSEBUTTONDOWN:
switch(event.button.button)
{
case SDL_BUTTON_LEFT:
if((event.button.x<316.3)&&(event.button.x>101)&&(event.button.y>44)&&(event.button.y<335.6))
            {
            strcpy(image,"");
            strcpy(categorie1,"h");
            nbalea=1+rand()%2;
            sprintf(image,"%d",nbalea);
            strcat(image,".png");
            strcat(categorie1,image);
            strcpy(image,categorie1);
            afficher_enigme(image);
            SDL_Flip(ecran);//mise a jour ecran
            }
else if((event.button.x<616.2)&&(event.button.x>401.8)&&(event.button.y>44)&&(event.button.y<335.6))
            {
            strcpy(image,"");
            strcpy(categorie2,"g");
            nbalea=1+rand()%3;
            sprintf(image,"%d",nbalea);
            strcat(image,".png");
            strcat(categorie2,image);
            strcpy(image,categorie2);
            afficher_enigme(image);
            SDL_Flip(ecran);//mise a jour ecran
            }
else if((event.button.x<920)&&(event.button.x>712.2)&&(event.button.y>44)&&(event.button.y<335.6))
            {
            strcpy(image,"");
            strcpy(categorie3,"h");
            sprintf(image,"%d",nbalea);
            strcat(image,".png");
            strcat(categorie1,image);
            strcpy(image,categorie1);
            afficher_enigme(image);
            SDL_Flip(ecran);//mise a jour ecran
            }
break;
}//event.button.button
    }//switch(event.type)

}//while
SDL_Flip(ecran);//mise a jour ecran

    SDL_FreeSurface(imagefond);
    SDL_FreeSurface(enigme);
    SDL_Quit(); // Arrêt de la SDL
    return EXIT_SUCCESS; // Fermeture du programme
}
