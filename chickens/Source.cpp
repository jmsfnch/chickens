#include <iostream>
#include <SDL.h>
using namespace std;

int main(int argc, char * argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
	}
	else
	{
		cout << "SDL initialization succeeded!";
	}

	cin.get();
	return 0;
}

// Tutorial to follow : https://www.willusher.io/sdl2%20tutorials/2013/08/17/lesson-1-hello-world