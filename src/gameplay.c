#include "selen.h"

void Gameplay() {
	SDL_bool gameplayRunning = SDL_TRUE;

	Uint32 startTicks, passedTicks;

	SDL_Event event;
	while (gameplayRunning) {
		startTicks = SDL_GetTicks();

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				gameRunning = SDL_FALSE;
				gameplayRunning = SDL_FALSE;
			}
			GlobalInputHandler(event);
		}
		// test battle
		gameplayRunning = SDL_FALSE;
		currentState = BATTLE;

		SDL_RenderClear(ren);
		SDL_RenderPresent(ren);

		passedTicks = SDL_GetTicks() - startTicks;
		if (passedTicks < deltaTime) SDL_Delay(deltaTime - passedTicks);
	}
}