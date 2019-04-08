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


void jeu(SDL_Surface *ecran)
{
SDL_Event event ;
int mouseX,mouseY,yetharek,destination;
  SDL_Surface *BG_Game=NULL;
yetharek=0;
  //init perso
SDL_Surface *persoImg= NULL;
persoImg = IMG_Load("Graphics/perso.png");
SDL_Rect perso,positionperso;
perso.w = persoImg->w /4 ;
perso.h = persoImg->h;
perso.x = 0;
perso.y = 0;

positionperso.x = 305;
positionperso.y = 510;

  BG_Game = IMG_Load("Graphics/BG Game.jpg");

  int continuer = 1;
  while (continuer)
    {
      SDL_GetMouseState(&mouseX,&mouseY);
      SDL_BlitSurface(BG_Game, NULL, ecran, NULL);
      SDL_BlitSurface(persoImg, &perso, ecran, &positionperso);
      SDL_Flip(ecran);


      if (SDL_PollEvent(&event)) {
        switch (event.type) {
          case SDL_QUIT:
            continuer=0;
            break;

          case SDL_MOUSEBUTTONDOWN:
          destination=mouseX-(perso.w/2);
          yetharek=1;
          break;

          case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
              case SDLK_DOWN:
                printf("down\n");
                break;
              case SDLK_UP:
                printf("up\n");
                break;
                case SDLK_RIGHT:
                  positionperso.x += 15;
                  break;
                  case SDLK_LEFT:
                  positionperso.x -= 15;
                    break;
              case SDLK_ESCAPE:
                continuer=0;
                break;

              default:
                break;
            }
            break;

          default:
            break;
        }
      }

      if (yetharek==1)
      {
        if (positionperso.x > destination+10)
        {
          positionperso.x -= 15;
        }
        if (positionperso.x < destination-10)
        {
          positionperso.x += 15;
        }
        if (positionperso.x > destination-10 && positionperso.x < destination+10)
        {
          yetharek = 0;
        }
      }
    }
  }
