/****************************************************************
File: Triangle.cpp
Description: Triangle source file
*****************************************************************/

#include "wx/wx.h"
#include "Triangle.h"

/**
Default constructor. Set both start, mid, and end points to (0, 0).
*/
Drawing::Triangle::Triangle() {

}

/**
Parameterized constructor. Sets start, mid, and end points to given parameters.
@param a Point object representing start point
@param b Point object representing mid point
@param c Point object representing end point
*/
Drawing::Triangle::Triangle(wxPoint a, wxPoint b, wxPoint c) {
	startPoint = a;
	midPoint = b;
	endPoint = c;

}

/**
Draws a Triangle on the given device context.
@param dc wxPaintDC object representing device context for drawing
*/
void Drawing::Triangle::draw(wxDC &dc) {
	static const int NUM_CORNERS = 3;
	//creates an array of 3 points
	wxPoint points[NUM_CORNERS];
	//set points to array
	points[0] = { startPoint };
	points[1] = {midPoint};
	points[2] = { endPoint };
	dc.SetBrush(fillBrush);
	dc.SetPen(outlinePen);
	dc.DrawPolygon(NUM_CORNERS, points);

}

/**
Sets the start point to the given coordinates.
@param x int value that is the x-coordinate
@param y int value that is the y-coordinate
*/
void Drawing::Triangle::setStartPoint(int x, int y) {
	startPoint.x = x;
	startPoint.y = y;
}

/**
Sets the mid point to the given coordinates.
@param x int value that is the x-coordinate
@param y int value that is the y-coordinate
*/
void Drawing::Triangle::setMidPoint(int x, int y) {
	midPoint.x = x;
	midPoint.y = y;
}
/**
Sets the end point to the given coordinates.
@param x int value that is the x-coordinate
@param y int value that is the y-coordinate
*/
void Drawing::Triangle::setEndPoint(int x, int y) {
	endPoint.x = x;
	endPoint.y = y;
}

