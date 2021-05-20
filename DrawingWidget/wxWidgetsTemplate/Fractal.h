/****************************************************************
File: Fractal.h
Description: Fractal header file
*****************************************************************/

#ifndef FRACTAL_H
#define FRACTAL_H

#include "wx/wx.h"
#include "Shape.h"
#include <vector>
#include <cmath>

namespace Drawing {
	/**
	Represents am Rectangle, with a start point and a end point.
	*/
	class Fractal : public Shape
	{
	public:
		/**
		Default constructor. Set both start and end points to (0, 0).
		*/
		Fractal();

		/**
		Parameterized constructor. Set both start and end points to given parameters.
		@param a Point object representing start point
		@param b Point object representing end point
		*/
		Fractal(wxPoint a, wxPoint b);

		/**
		Draws a Rectangle on the given device context.
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


		//Recursive function call to split initial rectangle into 5 rectangles.
		/**
		@param startPoint
		@param endPoint
		@oaram iteration (or level)
		*/
		void levelup(wxPoint startPoint, wxPoint endPoint, wxDC &dc, int iteration);


	private:
		wxPoint startPoint;
		wxPoint endPoint;
		const int firstIteration = 0;
		int iteration;

	};
}

#endif
