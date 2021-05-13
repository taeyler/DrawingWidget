/****************************************************************
File: Triangle.h
Description: Triangle header file

Author: Taeyler Lyons
Class: CSCI 120
Date: 3.30.16

I hereby certify that this program is entirely my own work.
*****************************************************************/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "wx.h"
#include "Shape.h"

namespace Drawing {
	/**
	Represents a Triangle, with a start point, mid point, and an end point.
	*/
	class Triangle : public Shape
	{
	public:
		/**
		Default constructor. Set both start, mid and end points to (0, 0).
		*/
		Triangle();

		/**
		Parameterized constructor. Sets start, mid, and end points to given parameters.
		@param a Point object representing start point
		@param b Point object representing mid point
		@param c Point object representing end point
		*/
		Triangle(wxPoint a, wxPoint b, wxPoint c);

		/**
		Draws a Triangle on the given device context.
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
		Sets the mid point to the given coordinates.
		@param x int value that is the x-coordinate
		@param y int value that is the y-coordinate
		*/

		void setMidPoint(int x, int y);

		/**
		Sets the end point to the given coordinates.
		@param x int value that is the x-coordinate
		@param y int value that is the y-coordinate
		*/
		void setEndPoint(int x, int y);

	private:
		wxPoint startPoint;
		wxPoint midPoint;
		wxPoint endPoint;
	};
}

#endif
