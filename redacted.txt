#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <cstdio>

const int Screen_Height = 480;
const int Screen_Width = 640;

SDL_Window* window = NULL;

SDL_Surface* screenSurface = NULL;

SDL_Surface* Hello = NULL;

bool loadMedia() {
    bool success = true;
    Hello = SDL_LoadBMP("C:\\Users\\nikgv\\Downloads\\helloworld.bmp");
    if( Hello == NULL ) {
        success = false;
    }
    return success;
}

int main(int argc, char* args[]) {

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );}
    else
    {
        window = SDL_CreateWindow( "SDL test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Screen_Width, Screen_Height, SDL_WINDOW_SHOWN );

        if (window == NULL) {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else {
            screenSurface = SDL_GetWindowSurface(window); 
            loadMedia();
            SDL_BlitSurface(Hello, NULL, screenSurface, NULL);
            SDL_UpdateWindowSurface(window);

            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
            SDL_FreeSurface(Hello);
            Hello = NULL;
            SDL_DestroyWindow(window);
            window = NULL;
            SDL_Quit();
            return 0;
        }

    }
}
