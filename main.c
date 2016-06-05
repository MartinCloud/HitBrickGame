#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <string.h>
#include "prepare.h"
#include "move.h"
#include "time.h"

int main( int argc, char* args[])
{
    int *rank_Of_Key = 0,quit = -1;
    SDL_Event event;
    SDL_Surface* background = NULL;
    SDL_Surface* ban = NULL;
    SDL_Surface* dot = NULL;
    SDL_Surface* zhuan = NULL;
    SDL_Surface* screen = NULL;

    Mix_Music *music = NULL;

    screen = init( 640, 480, 32);
    SDL_WM_SetCaption( "HIT BRICK", NULL );
    background = load_image("background.png");
    ban = load_image("ban.png");
    dot = load_image("dot.bmp");
    zhuan = load_image("zhuan1.png");

    struct ban Ban={300,475,0,0,40,4};
    struct dot Dot={315,465,0,0,10,10};
    p1=&Ban;p2=&Dot;
   while( quit == -1 )
    {
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //Handle events for the dot
           handle_input(rank_Of_Key,p1,p2,event);

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                quit = 1;
            }
        }

        musici(music);
        move(p1,p2,100,100);
        //Show the dot on the screen
        show(p1,p2,ban,dot,zhuan,background,screen);
        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
    }
    SDL_FreeSurface( ban );
    SDL_FreeSurface( dot );
    SDL_FreeSurface( zhuan );
    SDL_FreeSurface( background );
    Mix_FreeMusic( music );
    SDL_Quit();
    return 0;
}
