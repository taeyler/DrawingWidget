/****************************************************************
File: Fractal.cpp
Description: Fractal source file

Author: Taeyler Lyons
Class: CSCI 120
Date: 3.30.16

I hereby certify that this program is entirely my own work.
*****************************************************************/

#include "wx/wx.h"
#include "Fractal.h"

/**
Default constructor. Set both start and end points to (0, 0).
*/
Drawing::Fractal::Fractal() {

}

/**
Parameterized constructor. Set both start and end points to given parameters.
@param a Point object representing start point
@param b Point object representing end point
*/
Drawing::Fractal::Fractal(wxPoint a, wxPoint b) {
	startPoint = a;
	endPoint = b;

}

/**
Draws a Fractal on the given device context.
@param dc wxPaintDC object representing device context for drawing
*/
void Drawing::Fractal::draw(wxDC &dc) {
	dc.SetBrush(fillBrush);
	dc.SetPen(outlinePen);
	levelup(startPoint, endPoint, dc, firstIteration);
}

/**
Sets the start point to the given coordinates.
@param x int value that is the x-coordinate
@param y int value that is the y-coordinate
*/
void Drawing::Fractal::setStartPoint(int x, int y) {
	startPoint.x = x;
	startPoint.y = y;
}

/**
Sets the end point to the given coordinates.
@param x int value that is the x-coordinate
@param y int value that is the y-coordinate
*/
void Drawing::Fractal::setEndPoint(int x, int y) {
	endPoint.x = x;
	endPoint.y = y;
}

//Recursive function call to split initial rectangle into 5 rectangles.
/**
@param startPoint
@param endPoint
@oaram iteration (or level)
*/

void Drawing::Fractal::levelup(wxPoint startPoint, wxPoint endPoint, wxDC &dc, int iteration) {
	if (iteration == 3){
		wxRect recursRect = wxRect(startPoint.x, startPoint.y, (endPoint.x - startPoint.x), (endPoint.y - startPoint.y)); //creates rectangle
		dc.DrawRectangle(recursRect); //Draws Completed recursive rectangle
	}
	
	else {
		wxPoint newPoint; //new point declared for recursive function
		newPoint.x = (endPoint.x - startPoint.x) / 3;
		newPoint.y = (endPoint.y - startPoint.y) / 3;

		//recursive call for top left set of boxes
		levelup(startPoint, startPoint + newPoint, dc, 1+iteration);

		//recursive call for middle set of boxes
		levelup(startPoint + newPoint, startPoint + (2 * newPoint), dc, 1+iteration);

		//recursive call for bottom right set of boxes
		levelup(startPoint + (2 * newPoint), startPoint + (3 * newPoint), dc, 1+iteration);

		//recursive call for bottom left set of boxes
		levelup(wxPoint(startPoint.x, (startPoint.y + (2 * newPoint.y))), wxPoint(startPoint.x + newPoint.x, startPoint.y + (3 * newPoint.y)), dc, 1+iteration);

		//recursive call for top right set of boxes
		levelup(wxPoint(startPoint.x + (2 * newPoint.x), startPoint.y), wxPoint((startPoint.x + (3 * newPoint.x)), (startPoint.y + newPoint.y)), dc, 1+iteration);
		
		
		}
	
}
