// C++ code to implement 
// Sierpinski Triangle using Graphics 

#include <math.h>
#include <stdlib.h>
#include <graphics.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>

// #define Y 900
// #define X 1600
float X,Y;

// Defining a function to draw a triangle 
// with thickness 'delta' 
void triangle(float x, float y, 
			float h, int colorVal) 
{ 
	setcolor(colorVal % 15 + 1); 

	for (float delta = 0; delta > -5; delta -= 1) { 
		line(x - (h + delta) / sqrt(3), 
			y - (h + delta) / 3, 
			x + (h + delta) / sqrt(3), 
			y - (h + delta) / 3); 
		line(x - (h + delta) / sqrt(3), 
			y - (h + delta) / 3, 
			x, 
			y + 2 * (h + delta) / 3); 
		line(x, 
			y + 2 * (h + delta) / 3, 
			x + (h + delta) / sqrt(3), 
			y - (h + delta) / 3); 
	} 
} 

// Defining a function to draw 
// an inverted triangle 
// with thickness 'delta' 
void trianglev2(float x, float y, 
				float h, int colorVal) 
{ 
	setcolor(colorVal % 15 + 1); 

	for (float delta = 0; delta > -1 + 5; delta -= 1) { 

		line(x - (h + delta) / sqrt(3), 
			y + (h + delta) / 3, 
			x + (h + delta) / sqrt(3), 
			y + (h + delta) / 3); 
		line(x - (h + delta) / sqrt(3), 
			y + (h + delta) / 3, 
			x, 
			y - 2 * (h + delta) / 3); 
		line(x, 
			y - 2 * (h + delta) / 3, 
			x + (h + delta) / sqrt(3), 
			y + (h + delta) / 3); 
	} 
} 

// A recursive function to draw out 
// three adjacent smaller triangles 
// while the height is greater than 5 pixels. 
int drawTriangles(float x = X / 2, 
				float y = 2 * Y / 3, 
				float h = Y / 2, 
				int colorVal = 0) 
{ 

	if (h < 5) { 
		return 0; 
	} 

	if (x > 0 && y > 0 && x < X && y < Y) { 
		triangle(x, y, h, colorVal); 
	} 

	drawTriangles(x, 
				y - 2 * h / 3, 
				h / 2, 
				colorVal + 1); 
	drawTriangles(x - h / sqrt(3), 
				y + h / 3, 
				h / 2, 
				colorVal + 1); 
	drawTriangles(x + h / sqrt(3), 
				y + h / 3, 
				h / 2, 
				colorVal + 1); 

	return 0; 
} 

// Driver code 
int main() 
{ 
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	X=getmaxx ()/2;
	Y=getmaxy ()/2;
	trianglev2(X / 2, 2 * Y / 3, Y, 2); 

	drawTriangles(); 
	getch(); 
	closegraph(); 

	return 0; 
} 
