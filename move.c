#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <string.h>
#include "prepare.h"
#include "move.h"

void handle_input(int *rank_Of_Key,struct ban *p1,struct dot *p2,SDL_Event event)
{

            if( event.type == SDL_KEYDOWN  )
            {
                switch( event.key.keysym.sym )
                {
                    case SDLK_LEFT: p1->ban_vx -= 5; break;
                    case SDLK_RIGHT: p1->ban_vx += 5; break;
                    if(*rank_Of_Key==0)
                    {
                        case SDLK_UP:p2->dot_vy=-1;p2->dot_vx=-1;break;
                    }
                }
            }
            else if( event.type == SDL_KEYUP )
            {
                switch( event.key.keysym.sym )
                {
                    case SDLK_LEFT: p1->ban_vx += 1; break;
                    case SDLK_RIGHT: p1->ban_vx -= 1; break;
                }
            }

}
void move(struct ban *p1,struct dot *p2,int zhuanx,int zhuany)
{
    (p1->ban_x)+=(p1->ban_vx);
    (p2->dot_x)+=(p2->dot_vx);
    (p2->dot_y)+=(p2->dot_vy);
    // judge the up of the dot.
    if(((p1->ban_x<0))||((p1->ban_x+40)>640))
    {
        p1->ban_x-=p1->ban_vx;
    }
    //judge the botton of the dot.
    if((p2->dot_y)<=0||(p2->dot_y+10>=480))
    {
        (p2->dot_vy)=-(p2->dot_vy);
    }
    //judge the left and right.
    if((p2->dot_x)<=0||(p2->dot_x+10>=640))
    {
        (p2->dot_vx)=-(p2->dot_vx);
    }
    // judge the ban
    if((p2->dot_x>=p1->ban_x)&&((p2->dot_x-40)<=p1->ban_x)&&(p2->dot_y+10)==p1->ban_y)
    {
        (p2->dot_vy)=-(p2->dot_vy);
    }
    //judge the zhuan.
    if(((p2->dot_x)>=zhuanx)&&((p2->dot_x-40)<=zhuanx)&&((p2->dot_y)+10==zhuany))
    {
        (p2->dot_vy)=-(p2->dot_vy);
    }
    if(((p2->dot_x)>=zhuanx)&&((p2->dot_x-40)<=zhuanx)&&((p2->dot_y)-20==zhuany))
    {
        (p2->dot_vy)=-(p2->dot_vy);
    }
    if(((p2->dot_y+10)>zhuany)&&((p2->dot_y-20)<zhuany)&&((p2->dot_x)+10==zhuanx))
    {
        (p2->dot_vx)=-(p2->dot_vx);
    }
    if(((p2->dot_y+10)>zhuany)&&((p2->dot_y-20)<zhuany)&&((p2->dot_x)-40==zhuanx))
    {
        (p2->dot_vx)=-(p2->dot_vx);
    }

}
void show(struct ban *p1,struct dot *p2,
          SDL_Surface* ban ,SDL_Surface* dot ,
          SDL_Surface* zhuan,SDL_Surface* background,SDL_Surface* screen )
{
       //apply_surface( 0, 0, background, screen );
       apply_surface( p1->ban_x,p1->ban_y,ban, screen );
       apply_surface( p2->dot_x,p2->dot_y,dot, screen );
       apply_surface( 100, 100, zhuan, screen );
}
