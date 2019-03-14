#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_mixer.h"

#define w 1920
#define h 1080


#define n_w 90
#define n_h 70




int main()
{
  int running = 1,i=0;
  SDL_Surface *screen = NULL,*background=NULL,*history=NULL,*geography=NULL,*popularity=NULL;
  SDL_Rect position,pos_his,pos_geo,pos_pop, pos_new, pos_load, pos_settings;
  SDL_Event event;
  
history = IMG_Load("history.png");
geography = IMG_Load("geography.png");
popularity = IMG_Load("popularity.png");
  
  pos_his.x = 700;
  pos_his.y = 592;

  pos_geo.x = 978;
  pos_geo.y = 490;

  pos_pop.x = 1194;
  pos_pop.y = 313;

  
  
  
  position.x = 0;
  position.y = 0;
  
  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN                 );
  if (screen == NULL)
  {
    printf("unable to load screen=%s\n", SDL_GetError());
    return 1;
  }

  background = IMG_Load("carte.png");

  if (background == NULL)
  {

    printf("unable to load image =%s\n", SDL_GetError());
    return 1;
  }
  
  SDL_BlitSurface(background, NULL, screen,&position);
  SDL_Flip(screen);
  while(running)
  {
   SDL_WaitEvent(&event);
    switch (event.type)
    {
    case SDL_MOUSEMOTION:

      if (event.motion.x > pos_his.x && event.motion.x < (n_w + pos_his.x) && event.motion.y > pos_his.y && event.motion.y < (n_h + pos_his.y))
      {if(i==1)
		  break;
		  else
		  {

        i = 1;
       SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(history, NULL, screen, &position);
}
   
         
        
      }
      if (event.motion.x > pos_geo.x && event.motion.x < (n_w + pos_geo.x) && event.motion.y > pos_geo.y && event.motion.y < (n_h + pos_geo.y))
      {if(i==2)
		  break;
		  else
		  {

        i = 2;
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(geography, NULL, screen, &position);

}
         
        
      }
      if (event.motion.x > pos_pop.x && event.motion.x < (n_w + pos_pop.x) && event.motion.y > pos_pop.y && event.motion.y < (n_h + pos_pop.y))
      {if(i==3)
		  break;
		  else
		  {

        i = 3;
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
       SDL_BlitSurface(popularity, NULL, screen, &position  );
}
       }
       
     
     
     
     
     
      SDL_Flip(screen);
       break;
		case SDL_QUIT:
      running = 0;
      break;
      
        case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
      {
      case SDLK_SPACE:
         running=0 ;
      break ;  
      case SDLK_RIGHT :
      if(i==3)
      i=1;
      else
      i++;
        
          switch (i)
          {
          case 1:
              SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(history, NULL, screen, &position);

    
    

            break;
          case 2:
      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(geography, NULL, screen, &position);

    

            break;
          case 3:
      
 SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
       SDL_BlitSurface(popularity, NULL, screen, &position  );

        
            break;
      }
      SDL_Flip(screen);      
      break;
      case SDLK_LEFT :
      if(i==1 || i==0)
      i=3;
      else 
      i--;
        
          switch (i)
          {
          case 1:
              SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(history, NULL, screen, &position);

    
    

            break;
          case 2:
      SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_BlitSurface(geography, NULL, screen, &position);

    

            break;
          case 3:
      
 SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
       SDL_BlitSurface(popularity, NULL, screen, &position  );

        
            break;
      }
      SDL_Flip(screen);
      break;
  
}
}
}
}
