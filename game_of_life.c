#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#define WIDTH 640
#define HEIGHT 480

#define FPS 1
#define FRAME_DELAY 1000/FPS

void update_state(int *state);
void render_state(int *state, SDL_Renderer *renderer);
int check_neighbors(int *state, int x, int y);
void create_glider(int *state, int x, int y);

int main(int argc, char *argv[])
{
	// Initializations
	static int *state = NULL;
	static uint32_t frame_start, frame_time;
	SDL_Event e;
	SDL_Window *window = NULL;
	SDL_Renderer *screen_renderer = NULL;
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL couldn't initialize! SDL_Error: %s \n", SDL_GetError());
		SDL_Quit();
		return 0;
	}
	window = SDL_CreateWindow("Cellular Automata",
														SDL_WINDOWPOS_UNDEFINED,
														SDL_WINDOWPOS_UNDEFINED,
														WIDTH,
														HEIGHT,
														SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		printf("Window couldn't be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 0;
	}
	else
	{
		screen_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
		if(screen_renderer == NULL)
		{
			printf("Couldn't create renderer! SDL_Error: %s\n", SDL_GetError());
			SDL_DestroyWindow(window);
			SDL_Quit();
			return 0;
		}
	}
	// Start Screen
	size_t size = (WIDTH * HEIGHT);
	// Define and allocate size of virtual world
	state = (int*)malloc(size * sizeof(*state));
	// Stop condition flag
	int condition = 0;
	while(!condition)
	{
		// Start fps timer
		frame_start = SDL_GetTicks();
		// Handle key events
		while(SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT)
			{
				condition = 1;
			}
		}
		// Calculate changes on world
		update_state(state);
		// Update Screen
		render_state(state, screen_renderer);
		// Finish frame calc
		frame_time = SDL_GetTicks() - frame_start;
		if(FRAME_DELAY > frame_time)
		{
			SDL_Delay((int) (FRAME_DELAY - frame_time));
		}
	}
	free(state);
	SDL_DestroyRenderer(screen_renderer);
	screen_renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
	return 0;
}

void update_state(int *state)
{
	int i;
	int j;
	int	live_neighbors = 0;
	for(i = 0; i < HEIGHT; i++)
	{
		for(j = 0; j < WIDTH; j++)
		{
			live_neighbors = check_neighbors(state, i, j);
			if(*(state + (i*HEIGHT)+j) && !(live_neighbors == 2 || live_neighbors == 3))
			{
				*(state + (i*HEIGHT)+j) = 0;
			}
			if(*(state + (i*HEIGHT)+j) && (live_neighbors == 3))
			{
				*(state + (i*HEIGHT)+j) = 1;
			}
		}
	}
}

void render_state(int *state, SDL_Renderer *renderer)
{
	int i;
	int j;
	for(i = 0; i < HEIGHT; i++)
	{
		for(j = 0; j < WIDTH; j++)
		{
			if(*(state + (i*HEIGHT)+j) == 0)
			{
				SDL_SetRenderDrawColor(renderer, 0,0,0,255);
				SDL_RenderDrawPoint(renderer, j, i);
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 255,255,255,255);
				SDL_RenderDrawPoint(renderer, j, i);
			}
		}
	}
	SDL_RenderPresent(renderer);
}

int check_neighbors(int *state, int x, int y)
{
	// Current position -> *(state + (y*WIDTH)+x)
	int count_alive = 0;
	// Upper_left
	if(*(state + ((y-1)*WIDTH)+(x-1)))
	{
		count_alive++;
	}
	// Upper_mid
	if(*(state + ((y-1)*WIDTH)+(x)))
	{
		count_alive++;
	}
	// Upper_right
	if(*(state + ((y-1)*WIDTH)+(x+1)))
	{
		count_alive++;
	}
	// Left
	if(*(state + ((y)*WIDTH)+(x-1)))
	{
		count_alive++;
	}
	// Right
	if(*(state + ((y)*WIDTH)+(x+1)))
	{
		count_alive++;
	}
	// Bottom_left
	if(*(state + ((y+1)*WIDTH)+(x-1)))
	{
		count_alive++;
	}
	// Bottom
	if(*(state + ((y+1)*WIDTH)+(x)))
	{
		count_alive++;
	}
	// Bottom_right
	if(*(state + ((y+1)*WIDTH)+(x+1)))
	{
		count_alive++;
	}
	return count_alive;
}

void create_glider(int *state, int x, int y)
{
	*(state + ((y)*WIDTH)+x) = 1;
	
}
