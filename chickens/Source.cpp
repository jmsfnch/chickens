#include <string>
#include <iostream>
#include <SDL.h>
using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


enum gender {
	male=0,
	female=1
};

class chicken {
	int id;
	string name;
	chicken *ptrChickenMother;
	chicken *ptrChickenFather;
	gender gender;
};


/// FUNCTIONS ////

/**
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void logSDLError(std::ostream &os, const std::string &msg) {
	os << msg << " error: " << SDL_GetError() << std::endl;
}

/**
* Loads a BMP image into a texture on the rendering device
* @param file The BMP image file to load
* @param ren The renderer to load the texture onto
* @return the loaded texture, or nullptr if something went wrong.
*/
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren) {
	//Initialize to nullptr to avoid dangling pointer issues
	SDL_Texture *texture = nullptr;
	//Load the image
	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
	//If the loading went ok, convert to texture and return the texture
	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
		SDL_FreeSurface(loadedImage);
		//Make sure converting went ok too
		if (texture == nullptr) {
			logSDLError(std::cout, "CreateTextureFromSurface");
		}
	}
	else {
		logSDLError(std::cout, "LoadBMP");
	}
	return texture;
}

/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
* the texture's width and height
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
*/
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y) {
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Query the texture to get its width and height to use
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}



int TestSDL()
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




int originalSdlStartup(){
		// Start SDL

		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
			return 1;
		}

	// Open a window

	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	// Create a renderer

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	// Load a bitmap

	std::string imagePath = "bitmap1.bmp";
	SDL_Surface *bmp = SDL_LoadBMP(imagePath.c_str());
	if (bmp == nullptr) {
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	// Create a texture from bitmap
	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
	SDL_FreeSurface(bmp);
	if (tex == nullptr) {
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}


	// Draw the texture

	//A sleepy rendering loop, wait for 3 seconds and render and present the screen each time
	for (int i = 0; i < 3; ++i) {
		//First clear the renderer
		SDL_RenderClear(ren);
		//Draw the texture
		SDL_RenderCopy(ren, tex, NULL, NULL);
		//Update the screen
		SDL_RenderPresent(ren);
		//Take a quick break after all that hard work
		SDL_Delay(1000);
	}

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}


/**
* Clean up specified SDL components
* the texture's width and height
* @param tex The texture
* @param ren The renderer
* @param win The window
*/
void cleanup(SDL_Texture *tex = nullptr) {

	if (tex != nullptr) {
		SDL_DestroyTexture(tex);
	}
	return;
}
void cleanup(SDL_Renderer *ren = nullptr) {

	if (ren != nullptr) {
		SDL_DestroyRenderer(ren);
	}
	return;
}
void cleanup(SDL_Window *win = nullptr) {
	if (win != nullptr) {
		SDL_DestroyWindow(win);
	}

	return;
}


int main(int argc, char * argv[]) {
	//TestSDL();
	//originalSdlStartup();
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		logSDLError(std::cout, "SDL_Init");
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow("Lesson 2", 100, 100, SCREEN_WIDTH,
		SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		logSDLError(std::cout, "CreateWindow");
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr) {
		logSDLError(std::cout, "CreateRenderer");
		cleanup(window);
		SDL_Quit();
		return 1;
	}
		//const std::string resPath = getResourcePath("Lesson2");
		
	SDL_Texture *background = loadTexture("bitmap2.bmp", renderer);
	SDL_Texture *image = loadTexture("bitmap1.bmp", renderer);

	if (background == nullptr || image == nullptr){
			cleanup(background);
			cleanup(image);
			cleanup(renderer);
			cleanup(window);
		SDL_Quit();
		return 1;
		}	
	
	SDL_RenderClear(renderer);

	int bW, bH;
	SDL_QueryTexture(background, NULL, NULL, &bW, &bH);
	renderTexture(background, renderer, 0, 0);
	renderTexture(background, renderer, bW, 0);
	renderTexture(background, renderer, 0, bH);
	renderTexture(background, renderer, bW, bH);


	int iW, iH;
	SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
	int x = SCREEN_WIDTH / 2 - iW / 2;
	int y = SCREEN_HEIGHT / 2 - iH / 2;
	renderTexture(image, renderer, x, y);

	SDL_RenderPresent(renderer);
	SDL_Delay(10000);

	
	return 0;
}