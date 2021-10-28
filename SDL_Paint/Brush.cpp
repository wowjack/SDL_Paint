#include "Brush.h"

Brush::Brush(int size, int red, int green, int blue, int alpha) {
	brushSize = size;
	color = { red, green, blue, alpha };
}

void Brush::setBrushSize(int size) {
	brushSize = size;
}
float Brush::getBrushSize() {
	return brushSize;
}

Color Brush::getColor(){
	return color;
}
void Brush::setColor(int red, int green, int blue, int alpha) {
	color.r = red;
	color.g = green;
	color.b = blue;
	color.a = alpha;
}

void Brush::makeStroke(int x, int y) {
	SDL_Rect rect = { x,y,brushSize, brushSize };
	strokes.push_back(rect);
}
void Brush::eraseSome(int depth) {
	for (int i = 0; i < depth; i++) {
		strokes.pop_back();
	}
}
void Brush::eraseAll() {
	strokes.clear();
}

void Brush::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	std::list<SDL_Rect>::iterator iter = strokes.begin();
	while (iter != strokes.end()) {
		SDL_RenderFillRect(renderer, &*iter);
		iter++;
	}
}