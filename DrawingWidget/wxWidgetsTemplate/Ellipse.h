/****************************************************************
File: Ellipse.h
Description: Ellipse header file
*****************************************************************/

#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "wx/wx.h"
#include "Shape.h"

namespace Drawing {
	/**
	Represents am Ellipse, with a start point and a end point.
	*/
	class Ellipse : public Shape
	{
	public:
		/**
		Default constructor. Set both start and end points to (0, 0).
		*/
		Ellipse();

		/**
		Parameterized constructor. Set both start and end points to given parameters.
		@param a Point object representing start point
		@param b Point object representing end point
		*/
		Ellipse(wxPoint a, wxPoint b);

		/**
		Draws an ellipse on the given device context.
		@param dc wxPaintDC object representing device context for drawing
		*/
		void draw(wxDC &dc);

		/**
		Sets the start point to the given coordinates.
		@param x int value that is the x-coordinate
		@param y int value that is the y-coordinate
		*/
		void setStartPoint(int x, int y);

		/**
		Sets the end point to the given coordinates.
		@param x int value that is the x-coordinate
		@param y int value that is the y-coordinate
		*/
		void setEndPoint(int x, int y);

	private:
		wxPoint startPoint;
		wxPoint endPoint;
	};
}

#endif
