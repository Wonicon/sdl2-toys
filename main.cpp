#include <iostream>

extern "C" {
#include "sdl_util.h"
}

using namespace std;

void drawFilledCircle(int x, int y, double r)
{
    for (double i = -r; i < r; i += 0.1) {
        for (double j = -r; j < r; j += 0.1) {
            if (i * i + j * j < r * r) {
                SDL_RenderDrawPoint(gRenderer, x + (int)i, y + (int)j);
            }
        }
    }
}

int main()
{
    cout << "Hello, World!" << endl;

    MySDL2Init();

    bool quit = false;
    while (!quit) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        // Draw Solid Rectangle
        SDL_Rect fillRect = { 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(gRenderer, &fillRect);

        // SDL_RenderDrawRect(renderer, &rect);
        // SDL_RenderDrawPoint(renderer, x, y);
        // SDL_RenderDrawLine(renderer, x1, y1, x2, y2);

        SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
        drawFilledCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 100);

        // Update Screen
        SDL_RenderPresent(gRenderer);
    }

    SDL_Close();
    return 0;
}