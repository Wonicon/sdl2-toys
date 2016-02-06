#ifndef SDL_UTIL_H
#define SDL_UTIL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

// 屏幕尺寸 640 * 480
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

// 图片尺寸
extern int IMG_WIDTH;
extern int IMG_HEIGHT;

// 窗口句柄
extern SDL_Window *gWindow;

// 图片材质
extern SDL_Texture *gTexture;

// 窗口渲染器
extern SDL_Renderer *gRenderer;

void SDL_Assert(int condition, const char *format, ...);

void init();

void load_texture(const char *path);

void load_font(const char *path);

void SDL_Close();

typedef struct Text Text;
struct Text {
    SDL_Texture *texture;
    SDL_Rect size;
};

Text *render_text(const char *str);

#endif //SDL_UTIL_H
