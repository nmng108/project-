//erfeqa
#include <iostream>

#include <SDL.h>
using namespace std;
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 510;
const string WINDOW_TITLE = "An Implementation of Code.org Painter";
void logSDLError(std::ostream& os,const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
    SDL_Quit();
    exit(1);
    }
}
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    logSDLError(std::cout, "SDL_Init", true);
    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
    //Khi thông thường chạy với môi trường bình thường ở nhà
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
    SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
    if ( SDL_WaitEvent(&e) != 0 &&
    (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
    return;
    SDL_Delay(100);
    }
}

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    // Your drawing code here
    for(int i=0;i<100;i++) {
        SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 14, 7+i, 123+i, 199); // white
    SDL_RenderDrawPoint(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/4);
        SDL_RenderPresent(renderer);
//        waitUntilKeyPressed();
    SDL_Rect filled_rect;
    filled_rect.x = SCREEN_WIDTH - 611;
    filled_rect.y = SCREEN_HEIGHT - 280;
    filled_rect.w = 119;
    filled_rect.h = 463;
    SDL_SetRenderDrawColor(renderer, 72, 165-i, 11+i, 19); // green
    SDL_RenderFillRect(renderer, &filled_rect);
        SDL_RenderPresent(renderer);
//        waitUntilKeyPressed();

    filled_rect.x = SCREEN_WIDTH - 724;
    filled_rect.y = SCREEN_HEIGHT - 398;
    filled_rect.w = 119-i;
    filled_rect.h = 38+i;
    SDL_SetRenderDrawColor(renderer, 200-i, 104+i, 96-i, 255-i); // red
    SDL_RenderDrawRect(renderer, &filled_rect);
        // use SDL_RenderPresent(renderer) to show it
        SDL_RenderPresent(renderer);
//        waitUntilKeyPressed();
    }
    quitSDL(window, renderer);
    return 0;
}

