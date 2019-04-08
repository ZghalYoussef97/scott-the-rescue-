#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL/SDL_ttf.h"
#include <string.h>
#include "jeu.c"

void menu()
{


    SDL_Event event ;
    int inOptions=0;
    int inPlay=0;
        SDL_Rect positionecran,positiontext,positioncadre1,positioncadre2,positioncadre3,positioncadre4,positionOptions;
        int i=400;
        int changed=1;
        int mouseX,mouseY;

    SDL_Surface *ecran = NULL,*BG_Game=NULL;
    SDL_Surface *splashScreen = NULL;
    SDL_Surface *optionsMenu= NULL,*jouerS=NULL,*optionsS=NULL,*exitS=NULL,*helpS=NULL,*jouerNS=NULL,*optionsNS=NULL,*exitNS=NULL,*helpNS=NULL;
   //Fond
      positionecran.x = 0;
      positionecran.y = 0;

      positioncadre1.x=100;
      positioncadre1.y=350;
      positioncadre2.x=100;
      positioncadre2.y=450;
      positioncadre3.x=100;
      positioncadre3.y=550;
      positioncadre4.x=100;
      positioncadre4.y=650;


  SDL_Init(SDL_INIT_EVERYTHING);
  //SDL_SetColorKey(cadre3, SDL_SRCCOLORKEY, SDL_MapRGB(cadre3->format,255,255,255));
    ecran = SDL_SetVideoMode(1366,768,32, SDL_HWSURFACE);
    SDL_WM_SetCaption("scotttherescuer", NULL);

    splashScreen = IMG_Load("Graphics/splashScreen.png");

    SDL_BlitSurface(splashScreen, NULL, ecran, NULL);
    SDL_Flip(ecran);

    int compteur_bg;
    char * filename = (char *) malloc (34);
    char * compteur = (char *) malloc (3);

    SDL_Surface *image[305];

    for(compteur_bg=0;compteur_bg<305;compteur_bg++)
    {

      if (compteur_bg<10)
      {
        strcpy(filename, "Graphics/Menu/Background/0000");
        sprintf(compteur,"%d",compteur_bg);
        strcat(filename, compteur);
        strcat(filename, ".jpg");
        image[compteur_bg] = IMG_Load(filename);
      }
      if (compteur_bg>=10 && compteur_bg<=99)
      {
        strcpy(filename, "Graphics/Menu/Background/000");
        sprintf(compteur,"%d",compteur_bg);
        strcat(filename, compteur);
        strcat(filename, ".jpg");
        image[compteur_bg] = IMG_Load(filename);
      }
      if (compteur_bg>=100)
      {
        strcpy(filename, "Graphics/Menu/Background/00");
        sprintf(compteur,"%d",compteur_bg);
        strcat(filename, compteur);
        strcat(filename, ".jpg");
        image[compteur_bg] = IMG_Load(filename);
      }

    }

      jouerNS= IMG_Load("Graphics/Menu/boutonplay.png");
      jouerS= IMG_Load("Graphics/Menu/boutonplayallumé.png");

      optionsS= IMG_Load("Graphics/Menu/boutonsettingallumé.png");
      optionsNS= IMG_Load("Graphics/Menu/boutonsetting.png");
      optionsMenu= IMG_Load("Graphics/Menu/OptionsMenu.png");

      exitS= IMG_Load("Graphics/Menu/boutonquitallumé.png");
      exitNS= IMG_Load("Graphics/Menu/boutonquit.png");

      helpS = IMG_Load("Graphics/Menu/boutonhelpallumé.png");
      helpNS = IMG_Load("Graphics/Menu/boutonhelp.png");



      if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
      {
        printf("%s",Mix_GetError());
      }
      Mix_Music *musique;
      musique=Mix_LoadMUS("menu.mp3");
      Mix_PlayMusic(musique, -1);
      int musica = 1;
      int volumeMus = 128;
  /*

             font = TTF_OpenFont("ARIALI.TTF",28);
             if (font == NULL){printf("jerhlr" );}
             SDL_Color textColor= { 255,255,255 };
             message = TTF_RenderText_Solid(font,"Jouer",textColor);
             SDL_BlitSurface(message, NULL, ecran, &positiontext);
             SDL_Flip(ecran);
  */

      int continuer = 1;
      compteur_bg=0;

      positionOptions.x= (ecran->w / 2) - (optionsMenu->w/2);
      positionOptions.y= (ecran->h / 2) - (optionsMenu->h/2);



      while (continuer)
      {
        SDL_BlitSurface(image[compteur_bg], NULL, ecran, &positionecran);

        if (compteur_bg==304) compteur_bg=0;
        else compteur_bg++;

        if (inOptions == 1)
        {

          SDL_BlitSurface(optionsMenu, NULL, ecran, &positionOptions);
        }
        else if (inPlay == 1)
        {
          jeu(ecran);
          inPlay = 0 ;
        }
        else
        {
          if (i%4==0)
          {
            SDL_BlitSurface(jouerS, NULL, ecran, &positioncadre1);

            SDL_BlitSurface(optionsNS, NULL, ecran, &positioncadre2);

            SDL_BlitSurface(exitNS, NULL, ecran, &positioncadre3);

            SDL_BlitSurface(helpNS, NULL, ecran, &positioncadre4);
          }
          if (i%4==1)
          {
            SDL_BlitSurface(jouerNS, NULL, ecran, &positioncadre1);

            SDL_BlitSurface(optionsS, NULL, ecran, &positioncadre2);

            SDL_BlitSurface(exitNS, NULL, ecran, &positioncadre3);

            SDL_BlitSurface(helpNS, NULL, ecran, &positioncadre4);
          }
          if (i%4==2)
          {
            SDL_BlitSurface(jouerNS, NULL, ecran, &positioncadre1);

            SDL_BlitSurface(optionsNS, NULL, ecran, &positioncadre2);

            SDL_BlitSurface(exitS, NULL, ecran, &positioncadre3);

            SDL_BlitSurface(helpNS, NULL, ecran, &positioncadre4);
          }
          if (i%4==3)
          {
            SDL_BlitSurface(jouerNS, NULL, ecran, &positioncadre1);

            SDL_BlitSurface(optionsNS, NULL, ecran, &positioncadre2);

            SDL_BlitSurface(exitNS, NULL, ecran, &positioncadre3);

            SDL_BlitSurface(helpS, NULL, ecran, &positioncadre4);
          }
        }



        SDL_Flip(ecran);

        SDL_GetMouseState(&mouseX,&mouseY);
        if (mouseX > positioncadre1.x && mouseX < positioncadre1.x+jouerS->w && mouseY > positioncadre1.y && mouseY < positioncadre1.y+jouerS->h )
        {
          i=400;
        }if (mouseX > positioncadre2.x && mouseX < positioncadre2.x+optionsS->w && mouseY > positioncadre2.y && mouseY < positioncadre2.y+optionsS->h )
        {
          i=401;
        }if (mouseX > positioncadre3.x && mouseX < positioncadre3.x+exitS->w && mouseY > positioncadre3.y && mouseY < positioncadre3.y+exitS->h )
        {
          i=402;
        }if (mouseX > positioncadre4.x && mouseX < positioncadre4.x+helpS->w && mouseY > positioncadre4.y && mouseY < positioncadre4.y+helpS->h )
        {
          i=403;
        }


        while (SDL_PollEvent(&event)) {
          switch (event.type) {
            case SDL_QUIT:
              continuer=0;
              break;

            case SDL_MOUSEBUTTONDOWN:
            printf("%d ----------- %d\n",mouseX,mouseY );



            if(inOptions == 0)
            {
              if (i%4 == 1) inOptions = 1;
              else if (i%4 == 0) inPlay = 1;
              else if (i%4 == 2) continuer=0;
              break;
            }
            if (musica == 1 && inOptions==1 && mouseX > 607 && mouseX < 636 && mouseY > 270 && mouseY < 295 )
            {
              Mix_PauseMusic();
              musica = 0;
            }
            else if (musica == 0 && inOptions==1 && mouseX > 607 && mouseX < 636 && mouseY > 270 && mouseY < 295 )
            {
              Mix_ResumeMusic();
              musica = 1;
            }
            if (musica == 1 && inOptions==1 && mouseX > 704 && mouseX < 729 && mouseY > 270 && mouseY < 295  && volumeMus > 9)
            {
              volumeMus -= 10;
              Mix_VolumeMusic(volumeMus);
            }

            if (musica == 1 && inOptions==1 && mouseX > 704 && mouseX < 729 && mouseY > 270 && mouseY < 295  && volumeMus == 8)
            {
              volumeMus = 0;
              Mix_VolumeMusic(volumeMus);
            }
            if (musica == 1 && inOptions==1 && mouseX > 745 && mouseX < 768 && mouseY > 270 && mouseY < 295  && volumeMus < 119)
            {
              volumeMus += 10;
              Mix_VolumeMusic(volumeMus);
            }
            if (inOptions==1 && mouseX > 891 && mouseX < 953 && mouseY > 349 && mouseY < 396)
            {
              ecran = SDL_SetVideoMode(1366,768,32, SDL_HWSURFACE);
            }
            if (inOptions==1 && mouseX > 528 && mouseX < 570 && mouseY > 349 && mouseY < 396)
            {
              ecran = SDL_SetVideoMode(1366,768,32, SDL_FULLSCREEN);
            }



            if (inOptions==1 && mouseX > 860 && mouseX < 900 && mouseY > 185 && mouseY < 220)
            {
              inOptions=0;
              i = 401;
            }


            if (inOptions==1 && mouseX > 570 && mouseX < 770 && mouseY > 445 && mouseY < 500)
            {
              inOptions=0;
              i = 401;
            }
            break;

            case SDL_KEYUP:
              switch (event.key.keysym.sym)
              {
                case SDLK_DOWN:
                  i++;
                  changed=1;
                  break;
                case SDLK_UP:
                  i--;
                  changed=1;
                  break;
                case SDLK_RETURN:
                  if (i%4 == 1) inOptions = 1;
                  else if (i%4 == 0) inPlay = 1;
                  else if (i%4 == 2) continuer=0;
                  break;
                case SDLK_ESCAPE:
                  if (inOptions == 1)
                    {
                      inOptions = 0;
                      i = 401;
                    }
                    else if (inPlay == 1)
                    {
                      inPlay = 0;
                      i = 400;
                    }
                  break;

                default:
                  break;
              }
              break;

            default:
              break;
          }
        }
      }
      SDL_Quit();
}

int main(int argc, char *argv[])
{
  menu();
}
