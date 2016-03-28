#include "sdl_util.h"

int main(int argc, char *argv[])
{
    MySDL2Init();
    load_texture("test.jpg");
    load_font("OpenSans-Regular.ttf");

    Text *text = render_text("Hello, world");

    SDL_Rect camera = {
        .x = 0,
        .y = 0,
        .w = SCREEN_WIDTH,
        .h = SCREEN_HEIGHT,
    };

    int speed = 10;

    int quit = 0;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:    camera.y -= speed; break;
                    case SDLK_DOWN:  camera.y += speed; break;
                    case SDLK_LEFT:  camera.x -= speed; break;
                    case SDLK_RIGHT: camera.x += speed; break;
                    default: ;
                }
            }
        }

        if (camera.y < 0) camera.y = 0;
        else if (camera.y + SCREEN_HEIGHT > IMG_HEIGHT) camera.y = IMG_HEIGHT - SCREEN_HEIGHT;

        if (camera.x < 0) camera.x = 0;
        else if (camera.x + SCREEN_WIDTH > IMG_WIDTH) camera.x = IMG_WIDTH - SCREEN_WIDTH;

        //Clear screen
        SDL_RenderClear(gRenderer);

        //Render texture to screen
        SDL_RenderCopy(gRenderer, gTexture, &camera, NULL);
        SDL_RenderCopy(gRenderer, text->texture, NULL, &text->size);

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    SDL_Close();

    return 0;
}