struct ban
{
  int ban_x;
  int ban_y;
  int ban_vx;
  int ban_vy;
  int ban_width;
  int ban_length;
}*p1;
struct bricks
{
    int brick_x;
    int brick_y;
    int brick_width;
    int brick_length;
}Bricks[35];
struct dot
{
  int dot_x;
  int dot_y;
  int dot_vx;
  int dot_vy;
  int dot_width;

}*p2;

SDL_Surface *load_image( char* filename );
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
SDL_Surface* init(int SCREEN_WIDTH ,int SCREEN_HEIGHT ,int SCREEN_BPP );
void musici(Mix_Music *music);
