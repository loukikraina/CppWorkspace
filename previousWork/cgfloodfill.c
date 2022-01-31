#include <iostream.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>
//!Boundary Fill Algorithm with 4 points checking
void boundaryFill(int x, int y, int fillcolor, int backgroundcolor)
{
	int current = getpixel(x, y);
	if (current != backgroundcolor && current != fillcolor)
	{
		putpixel(x, y, fillcolor);
		boundaryFill(x + 1, y, fillcolor, backgroundcolor);
		boundaryFill(x, y + 1, fillcolor, backgroundcolor);
		boundaryFill(x - 1, y, fillcolor, backgroundcolor);
		boundaryFill(x, y - 1, fillcolor, backgroundcolor);
	}
}
//! Boundary Fill Algorithm with 8 points checking*** Uncomment to use***
/*
void boundaryFill(int x, int y, int fill_color,int boundary_color)
{
    if(getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color)
    {
	putpixel(x, y, fill_color);
	boundaryFill(x + 1, y, fill_color, boundary_color);
	boundaryFill(x, y + 1, fill_color, boundary_color);
	boundaryFill(x - 1, y, fill_color, boundary_color);
	boundaryFill(x, y - 1, fill_color, boundary_color);
	boundaryFill(x - 1, y - 1, fill_color, boundary_color);
	boundaryFill(x - 1, y + 1, fill_color, boundary_color);
	boundaryFill(x + 1, y - 1, fill_color, boundary_color);
	boundaryFill(x + 1, y + 1, fill_color, boundary_color);
    }
}
*/
//!Flood Fill Algorithm function
void floodFill(int x, int y, int fillcolor, int oldcolor)
{

	//*flood filling starting cordinates

	if (getpixel(x, y) == oldcolor)
	{
		putpixel(x, y, fillcolor);
		floodFill(x + 1, y, fillcolor, oldcolor);
		floodFill(x, y + 1, fillcolor, oldcolor);
		floodFill(x - 1, y, fillcolor, oldcolor);
		floodFill(x, y - 1, fillcolor, oldcolor);
	}
}
//!main Function
int main()
{
	clrscr();
	int gm, gd = DETECT, radius;
	int x, y;
	cout << "Enter X and Y Co-Ordinates of the Circle : ";
	cin >> x >> y;
	cout << "\nEnter the Radius of The Circle : ";
	cin >> radius;
	int option;
	cout << "\n1) Boundary Fill Algorithm\n2) Flood Fill Algorithm\nEnter your Choice : ";
	cin >> option;
	switch (option)
	{
		case 1:
			initgraph(&gd, &gm, "c:\\turboc3\\bgi");
			circle(x, y, radius);
			cout << "\nBOUNDARY FILL ALGORITHM\n";
			boundaryFill(x, y, 1, 15);
			break;
		case 2:
			initgraph(&gd, &gm, "c:\\turboc3\\bgi");
			circle(x, y, radius);
			cout << "\nFLOOD FILL ALGORITHM\n";
			floodFill(x, y, 12, 0);
			break;
		default:
			cout << "\nInvalid option\n";
			break;
	}

	getch();
	closegraph();

	return 0;
}