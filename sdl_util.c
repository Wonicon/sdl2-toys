// 一些简单的封装

#include "sdl_util.h"

// 屏幕尺寸 640 * 480
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// 图片尺寸
int IMG_WIDTH;
int IMG_HEIGHT;

// 窗口句柄
SDL_Window *gWindow = NULL;

// 图片材质
SDL_Texture *gTexture = NULL;

// 窗口渲染器
SDL_Renderer *gRenderer = NULL;

// 字体句柄
TTF_Font *gFont = NULL;

// 各种初始化
void MySDL2Init()
{
    SDL_Assert(SDL_Init(SDL_INIT_VIDEO) == 0, "SDL could not initialize!");
    SDL_Assert(SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"), "Linear texture filtering not enabled!");

    // Create window
    gWindow = SDL_CreateWindow("SDL2 Toys",
                               SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               SCREEN_WIDTH, SCREEN_HEIGHT,
                               SDL_WINDOW_SHOWN);
    SDL_Assert(gWindow != NULL, "Window could not be created!");

    //Create vsynced renderer for window
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_Assert(gRenderer != NULL, "Renderer could not be created!");

    // Initialize renderer color
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Initialize image loading
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    SDL_Assert(IMG_Init(imgFlags) & imgFlags, "SDL_image could not initialize!");

    SDL_Assert(TTF_Init() == 0, NULL);
}

void load_texture(const char *path)
{
    //The final texture
    gTexture = NULL;

    //Load image at specified path
    SDL_Surface *loaded_surface = IMG_Load(path);
    SDL_Assert(loaded_surface != NULL, "Unable to load image %s", path);

    IMG_WIDTH = loaded_surface->w;
    IMG_HEIGHT = loaded_surface->h;

    //Create texture from surface pixels
    gTexture = SDL_CreateTextureFromSurface(gRenderer, loaded_surface);
    SDL_Assert(gTexture != NULL, "Unable to create texture from %s", path);

    SDL_FreeSurface(loaded_surface);
}

void load_font(const char *path)
{
    gFont = TTF_OpenFont(path, 28);
    SDL_Assert(gFont != NULL, NULL);
}

Text *render_text(const char *str)
{
    SDL_Color font_color = {};
    SDL_Surface *text_surface = TTF_RenderText_Solid(gFont, str, font_color);
    SDL_Assert(text_surface != NULL, NULL);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(gRenderer, text_surface);
    Text *text = malloc(sizeof(Text));
    text->texture = texture;
    text->size.x = 0;
    text->size.y = 0;
    text->size.w = text_surface->w;
    text->size.h = text_surface->h;
    SDL_FreeSurface(text_surface);
    return text;
}

void SDL_Close()
{
    TTF_CloseFont(gFont);
    gFont = NULL;

    SDL_DestroyTexture(gTexture);
    gTexture = NULL;

    SDL_DestroyRenderer(gRenderer);
    gWindow = NULL;

    SDL_DestroyWindow(gWindow);
    gRenderer = NULL;

    //Quit SDL subsystems
    TTF_Init();
    IMG_Quit();
    SDL_Quit();
}

void SDL_Assert(int condition, const char *format, ...)
{
    if (!condition) {
        if (format != NULL) {
            va_list args;
            va_start(args, format);
            vfprintf(stderr, format, args);
            va_end(args);
            fprintf(stderr, ": ");
        }
        fprintf(stderr, "%s\n", SDL_GetError());
        exit(1);
    }
}
