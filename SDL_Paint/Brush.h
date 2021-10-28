#pragma once
#include <list>
#include <SDL.h>

typedef struct Color{
	int r, g, b, a;
}Color;

class Brush {
private:
	int brushSize; //Size of the square to be drawn
	Color color;
	std::list<SDL_Rect> strokes; //DLL of squares that have been drawn
	//Using dll to allow for strokes to be erased by popping squraes from the top of the list

public:
	Brush(int size=5, int red=255, int green=255, int blue=255, int alpha=255);

	void setBrushSize(int size);
	float getBrushSize();

	Color getColor();
	void setColor(int red, int green, int blue, int alpha=255);

	void makeStroke(int x, int y); //Draw a square at x,y
	void eraseSome(int depth=50); //Erase the last depth number rectangles off the end of the list
	void eraseAll(); //Erase all rectangles in the list

	void render(SDL_Renderer* renderer); //Draw all rectangles in strokes list to window



};
