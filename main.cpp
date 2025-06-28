#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <cstdio>
#include <string>

const int Screen_Height = 480;
const int Screen_Width = 640;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHello = NULL;
std::string path = "C:\\Users\\nikgv\\Downloads\\helloworld.bmp";

bool loadMedia(std::string* Path) {
    bool success = true;
    gHello = SDL_LoadBMP(Path->c_str());
    if (gHello == NULL) { success = false; printf("Error in loading image", Path); }

    return success;
}

void close()
{
    SDL_FreeSurface( gHello );
    gHello = NULL;

    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    SDL_Quit();
}

bool init()
{
    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Screen_Width, Screen_Height, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

int main( int argc, char* args[] )
{
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        if( !loadMedia(&path) )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            SDL_BlitSurface( gHello, NULL, gScreenSurface, NULL );
            SDL_UpdateWindowSurface(gWindow);
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
            close();
        }    
    }
}