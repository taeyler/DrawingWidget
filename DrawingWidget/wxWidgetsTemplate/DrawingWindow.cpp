/****************************************************************
File: DrawingWindow.cpp
Description: DrawingWindow source file

Author: Taeyler Lyons
Class: CSCI 120
Date: 3.30.16

I hereby certify that this program is entirely my own work.
*****************************************************************/

#include "DrawingWindow.h"
#include <wx/dcbuffer.h>


/**
Parameterized constructor given the parent window control.
@param parent parent wxWindow object
*/
DrawingWindow::DrawingWindow(wxWindow* parent)
	: wxWindow(parent, wxID_ANY) {
	corners = 0;
	x = -1;
	y = -1;
	// set size of window
	wxSize size(WINDOW_WIDTH, WINDOW_HEIGHT);
	SetSize(size);
	// set background color
	wxColour col1;
	col1.Set(BACKGROUND_COLOR);
	SetBackgroundColour(col1);
	// default line width and colors
	lineWidth = 1;
	outlineColor = *wxBLACK;
	fillColor = *wxWHITE;
	
}

/**
Mouse event handler.
Constructs and stores the geometrical shapes being drawn.
@param event wxMouseEvent object
*/
void DrawingWindow::OnMouseEvent(wxMouseEvent& event) {
	// mouse position
	x = event.GetX();
	y = event.GetY();

	switch (state) {

	case LINE:
		if (event.LeftDown()) {
			if (corners == 0) { // just started dragging
				// set start point
				Drawing::Line line;
				
				line.setStartPoint(x, y);
				line.setEndPoint(x, y);
				line.setOutlineColor(outlineColor);
				line.setFillColor(fillColor);
				line.setLineWidth(lineWidth);
				lineVector.push_back(line);
				shapeVector.push_back(&line);
				corners++;
				Refresh();
			}
		}
		if (event.LeftIsDown()) { // still dragging
			if (corners > 0) {
				lineVector.at(lineVector.size() - 1).setEndPoint(x, y);
				Refresh();
			}
		}
		if (event.LeftUp()) { // done with dragging
			if (corners > 0) {
				// set end point
				lineVector.at(lineVector.size() - 1).setEndPoint(x, y);
				corners = 0;
				Refresh();
			}
		}

		break;

	case ELLIPSE:
		if (event.LeftDown()) {
			if (corners == 0) { // just started dragging
				// set start point
				Drawing::Ellipse ellipse;
				ellipse.setStartPoint(x, y);
				ellipse.setEndPoint(x, y);
				ellipse.setOutlineColor(outlineColor);
				ellipse.setFillColor(fillColor);
				ellipse.setLineWidth(lineWidth);
				ellipseVector.push_back(ellipse);
				shapeVector.push_back(&ellipse);
			
				/*Drawing::Ellipse* ellipse1;
				ellipse1->setStartPoint(x, y);
				ellipse1->setEndPoint(x, y);
				*/
				//shapePtr = new Drawing::Shape;
				//shapePtr = &ellipse;
				//shapeVector.push_back(&ellipse);
				corners++;
				Refresh();
			}
		}
		if (event.LeftIsDown()) { // still dragging
			if (corners > 0) {
				ellipseVector.at(ellipseVector.size() - 1).setEndPoint(x, y);
				Refresh();
			}
		}
		if (event.LeftUp()) { // done with dragging
			if (corners > 0) {
				// set end point
				ellipseVector.at(ellipseVector.size() - 1).setEndPoint(x, y);
				corners = 0;
				Refresh();
			}
		}
		break;

	case RECTANGLE:
		if (event.LeftDown()) {
			if (corners == 0) { // just started dragging
				// set start point
				Drawing::Rectangle rectangle;
				rectangle.setStartPoint(x, y);
				rectangle.setEndPoint(x, y);
				rectangle.setOutlineColor(outlineColor);
				rectangle.setFillColor(fillColor);
				rectangle.setLineWidth(lineWidth);
				rectangleVector.push_back(rectangle);
				shapeVector.push_back(&rectangle);
				corners++;
				Refresh();
			}
		}
		if (event.LeftIsDown()) { // still dragging
			if (corners > 0) {
				rectangleVector.at(rectangleVector.size() - 1).setEndPoint(x, y);
				Refresh();
			}
		}
		if (event.LeftUp()) { // done with dragging
			if (corners > 0) {
				// set end point
				rectangleVector.at(rectangleVector.size() - 1).setEndPoint(x, y);
				corners = 0;
				Refresh();
			}
		}
		break;

	case TRIANGLE:		
		if (corners == 0) {
			if (event.LeftDown()) {
				// sets start point
				Drawing::Triangle triangle;
				triangle.setStartPoint(x, y); //sets all points to first click position as a default constructor
				triangle.setMidPoint(x, y);
				triangle.setEndPoint(x, y);
				triangle.setOutlineColor(outlineColor);
				triangle.setFillColor(fillColor);
				triangle.setLineWidth(lineWidth);
				triangleVector.push_back(triangle); //adds triangle to triangle vector
				shapeVector.push_back(&triangle);
				Refresh();
			}
			else if (event.LeftUp()){
				
				corners++; //registers the completed click
				Refresh();
			}
		}
		else if (corners == 1){
			if (event.LeftDown()) {
				//second click sets midpoint
				triangleVector.at(triangleVector.size() - 1).setMidPoint(x, y);

				Refresh();
			}
			else if (event.LeftUp()) {
				corners++; //registers the completed click
				Refresh();
			}
		}
		else if (corners == 2) {
			if (event.LeftDown()) {
				//third click sets endpoint
				triangleVector.at(triangleVector.size() - 1).setEndPoint(x, y);
				Refresh();
			}
			else if (event.LeftUp()) {
				corners = 0; //resets the clicker count
				Refresh();
			}
		}
		break;

	case FRACTAL:
		if (event.LeftDown()) {
			if (corners == 0) { // just started dragging
				// set start point
				Drawing::Fractal fractal;
				fractal.setStartPoint(x, y);
				fractal.setEndPoint(x, y);
				fractal.setOutlineColor(outlineColor);
				fractal.setFillColor(fillColor);
				fractal.setLineWidth(lineWidth);
				fractalVector.push_back(fractal);
				shapeVector.push_back(&fractal);
				corners++;
				Refresh();
			}
		}
		if (event.LeftIsDown()) { // still dragging
			if (corners > 0) {
				fractalVector.at(fractalVector.size() - 1).setEndPoint(x, y);
				Refresh();
			}
		}
		if (event.LeftUp()) { // done with dragging
			if (corners > 0) {
				// set end point
				fractalVector.at(fractalVector.size() - 1).setEndPoint(x, y);
				corners = 0;
				Refresh();
			}
		}
		break;

	default:
		break;
	}
}

/**
Paints the window.
@param event wxPaintEvent object
*/
void DrawingWindow::OnPaint(wxPaintEvent& event) {
	wxPaintDC dc(this);

	if (state != NONE) {
		// draw each rectangle on the window
		for (unsigned int i = 0; i < rectangleVector.size(); ++i) {
				rectangleVector.at(i).draw(dc);
			}
		// draw each ellipse on the window
		for (unsigned int i = 0; i < ellipseVector.size(); ++i) {
				ellipseVector.at(i).draw(dc);
			}
		// draw each line on the window
		for (unsigned int i = 0; i < lineVector.size(); ++i) {
				lineVector.at(i).draw(dc);
			}
		// draw each triangle on the window
		for (unsigned int i = 0; i < triangleVector.size(); ++i) {
				triangleVector.at(i).draw(dc);
			}
		// draw each fractal on the window
		for (unsigned int i = 0; i < fractalVector.size(); ++i) {
				fractalVector.at(i).draw(dc);
			}
	}
}

/**
Sets the current drawing state.
@param state DrawingState object
*/
void DrawingWindow::setState(DrawingState state) {
	this->state = state;
	if (state == NONE) {
		// clear all shapes
		shapeVector.clear();
		lineVector.clear();
		ellipseVector.clear();
		rectangleVector.clear();
		triangleVector.clear();
		fractalVector.clear();
		corners = 0;
		Refresh();
	}
}

/**
Sets the current drawing line width.
@param width new line width value (integer)
*/
void DrawingWindow::setLineWidth(int width) {
	lineWidth = width;
}

/**
Sets the current drawing outline color.
@param color wxColour value
*/
void DrawingWindow::setOutlineColor(wxColour color) {
	outlineColor = color;
}

/**
Sets the current drawing fill color.
@param color wxColour value
*/
void DrawingWindow::setFillColor(wxColour color) {
	fillColor = color;
}
