/****************************************************************
File: Ellipse.cpp
Description: Ellipse source file
*****************************************************************/

#include "wx/wx.h"
#include "Ellipse.h"

/**
Default constructor. Set both start and end points to (0, 0).
*/
Drawing::Ellipse::Ellipse() {

}

/**
Parameterized constructor. Set both start and end points to given parameters.
@param a Point object representing start point
@param b Point object representing end point
*/
Drawing::Ellipse::Ellipse(wxPoint a, wxPoint b) {
	startPoint = a;
	endPoint = b;
	
	}

/**
Draws a ellipse on the given device context.
@param dc wxPaintDC object representing device context for drawing
*/
void Drawing::Ellipse::draw(wxDC &dc) {
	//creats a rectangle out of the start and end points
	wxRect Rect(startPoint, endPoint);

	dc.SetBrush(fillBrush);
	dc.SetPen(outlinePen);

	//draws ellipse using the rectangle parameter
	dc.DrawEllipse(Rect);

}

/**
Sets the start point to the given coordinates.
@param x int value that is the x-coordinate
@param y int value that is the y-coordinate
*/
void Drawing::Ellipse::setStartPoint(int x, int y) {
	startPoint.x = x;
	startPoint.y = y;
}

/**
Sets the end point to the given coordinates.
@param x int value that is the x-coordinate
@param y int value that is the y-coordinate
*/
void Drawing::Ellipse::setEndPoint(int x, int y) {
	endPoint.x = x;
	endPoint.y = y;
}

