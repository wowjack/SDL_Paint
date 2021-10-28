#include <SDL.h>
#include <iostream>
#include "Brush.h"

//PROBLEM WHERE STROKES ARE NOT DRAWN BUT ARE CREATED

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	SDL_Window* window = SDL_CreateWindow("Paint", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	Brush paintBrush(5, 255, 0, 0);

	

	while (true) {
		SDL_RenderClear(renderer);
		//Process input
		int mouseX, mouseY;
		Uint32 mouseButtons;
		mouseButtons = SDL_GetMouseState(&mouseX, &mouseY);

		if (mouseButtons == 1) {
			paintBrush.makeStroke(mouseX, mouseY);
		}

		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				exit(0);
				break;

			default:
				break;
			}
		}

		//Clear then render everything
		paintBrush.render(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderPresent(renderer);

	}

	return 0;
}