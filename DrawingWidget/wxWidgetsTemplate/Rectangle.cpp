/****************************************************************
File: Rectangle.cpp
Description: Rectangle source file
*****************************************************************/

#include "wx/wx.h"
#include "Rectangle.h"

/**
Default constructor. Set both start and end points to (0, 0).
*/
Drawing::Rectangle::Rectangle() {

}

/**
Parameterized constructor. Set both start and end points to given parameters.
@param a Point object representing start point
@param b Point object representing end point
*/
Drawing::Rectangle::Rectangle(wxPoint a, wxPoint b) {
	startPoint = a;
	endPoint = b;

}

/**
Draws a Rectangle on the given device context.
@param dc wxPaintDC object representing device context for drawing
*/
void Drawing::Rectangle::draw(wxDC &dc) {
	wxRect Rect(startPoint, endPoint); //creates rectangle out of start and end points
	dc.SetBrush(fillBrush);
	dc.SetPen(outlinePen);
	dc.DrawRectangle(Rect); //draws rectangle out of created rectangle

}

/**
Sets the start point to the given coordinates.
@param x int value that is the x-coordinate
@param y int value that is the y-coordinate
*/
void Drawing::Rectangle::setStartPoint(int x, int y) {
	startPoint.x = x;
	startPoint.y = y;
}

/**
Sets the end point to the given coordinates.
@param x int value that is the x-coordinate
@param y int value that is the y-coordinate
*/
void Drawing::Rectangle::setEndPoint(int x, int y) {
	endPoint.x = x;
	endPoint.y = y;
}

