#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>

using namespace std;

void filledRectangleRGBA(SDL_Renderer* renderer, int x, int y, int w, int h, int r, int g, int b, int a)
{
    SDL_Rect fillRect;
    fillRect.x = x;
    fillRect.y = y;
    fillRect.w = w;
    fillRect.h = h;
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, &fillRect);
}
void upRoundedButton(SDL_Renderer* renderer, int x, int y, int w, int h, int rad, int r, int g, int b, int a)
{
    roundedBoxRGBA(renderer, x, y, x+w-1, y+h, rad, r, g, b, a);
    filledRectangleRGBA(renderer, x, y+rad, w, h-rad+1, r, g, b, a);
}
int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return 1;

    SDL_Window* window = SDL_CreateWindow(
        "Scratch",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1536,
        790,
        SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP
    );

    if (window == NULL) {
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 220, 220, 255, 255);
    SDL_RenderClear(renderer);

    filledRectangleRGBA(renderer, 0, 0, 1536, 40, 20, 110, 180, 170);

    filledRectangleRGBA(renderer, 0, 90, 60, 771, 245, 245, 245, 255);
    rectangleRGBA(renderer, 0, 91, 60, 860, 160, 160, 160, 240);

    roundedBoxRGBA(renderer, 301, 91, 1001, 860, 10, 245, 245, 245, 255);
    roundedRectangleRGBA(renderer, 299, 91, 1000, 860, 10, 160, 160, 160, 240);

    roundedBoxRGBA(renderer, 1010, 91, 1526, 520, 10, 245, 245, 245, 255);
    roundedRectangleRGBA(renderer, 1010, 91, 1526, 520, 10, 160, 160, 160, 240);

    roundedBoxRGBA(renderer, 1010, 530, 1526, 860, 10, 245, 245, 245, 255);
    roundedRectangleRGBA(renderer, 1010, 530, 1526, 860, 10, 160, 160, 160, 240);

    filledRectangleRGBA(renderer, 61, 90, 250, 771, 245, 245, 245, 255);
    rectangleRGBA(renderer, 59, 91, 310, 860, 160, 160, 160, 240);

    upRoundedButton(renderer, 180, 48, 103, 43, 17, 50, 50, 50, 255);
    upRoundedButton(renderer, 183, 51, 97, 37, 15, 220, 220, 220, 255);

    upRoundedButton(renderer, 90, 48, 103, 43, 17, 50, 50, 50, 255);
    upRoundedButton(renderer, 93, 51, 97, 37, 15, 220, 220, 220, 255);

    upRoundedButton(renderer, 0, 48, 103, 43, 17, 50, 50, 50, 255);
    upRoundedButton(renderer, 3, 51, 97, 37, 15, 220, 220, 220, 255);
    SDL_RenderPresent(renderer);

    bool running = true;
    SDL_Event exitButton;
    while (running)
        while (SDL_PollEvent(&exitButton))
            if ((exitButton.type == SDL_KEYDOWN && exitButton.key.keysym.sym == SDLK_ESCAPE) || exitButton.type == SDL_QUIT)
                running = false;

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}