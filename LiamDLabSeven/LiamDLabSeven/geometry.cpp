//  File geometry.cpp

#include <iostream>
#include <cmath>

#include "geometry.h"

// Compute and return the distance between the points 
// (x1, y1) and (x2, y2)
// Parameter x1 is the x-coordinate of (x1, y1).
// Parameter y1 is the y-coordinate of (x1, y1).
// Parameter x2 is the x-coordinate of (x2, y2).
// Parameter y2 is the y-coordinate of (x2, y2).
double distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)*1.0);
	// Replace with your code
}


// Compute and return the slope of the line that passes 
// between the points (x1, y1) and (x2, y2).  Returns INFINITY 
// if the points lie on a vertical line.
// Parameter x1 is the x-coordinate of (x1, y1).
// Parameter y1 is the y-coordinate of (x1, y1).
// Parameter x2 is the x-coordinate of (x2, y2).
// Parameter y2 is the y-coordinate of (x2, y2).
double slope(double x1, double y1, double x2, double y2) {
	//return ((y2 - y1) / (x2 - x1));
	if (x2 - x1 == 0) {
		return INFINITY;
	}
	else {
		return (y2 - y1) / (x2 - x1);

	}

}


// Compute and return the intercept of the line that passes 
// between the points (x1, y1) and (x2, y2).  Returns the 
// x-intercept if the line is vertical; otherwise, returns 
// the line's y-intercept.
// Parameter x1 is the x-coordinate of (x1, y1).
// Parameter y1 is the y-coordinate of (x1, y1).
// Parameter x2 is the x-coordinate of (x2, y2).
// Parameter y2 is the y-coordinate of (x2, y2).
double intercept(double x1, double y1, double x2, double y2) {
	double m = slope(x1, y1, x2, y2);
	if (m == INFINITY) {
		return x1;
	}
	else {
		return (y1 - (m * x1));
	}

}


// Determines the (x, y) point of intersection of the lines 
// y = m1x + b1 and y = m2x + b2, if possible.  The function's
// behavior is undefined if the lines are parallel.
// Parameter m1 is the slope of the first line.
// Parameter b1 is the y-intercept of the first line (x-intercept
//      for vertical lines).
// Parameter m2 is the slope of the second line.
// Parameter b2 is the y-intercept of the second line (x-intercept
//      for vertical lines).
// Parameter x is the x-coordinate of the point of intersection.
// Parameter y is the y-coordinate of the point of intersection.
// The function computes the coordinates and assigns them to x and y.
void intersection(double m1, double b1, double m2, double b2,
	double& x, double& y) {

	if( m1 == INFINITY) { 
		x = b1;
		y = (m2 * b1 + b2);
	}
	else if (m2 == INFINITY) {
		x = b2;
		y = (m1 * b2 + b1);
	}
	else {
		x = ((b2 - b1) / (m1 - m2));
		y = (m1 * x + b1);
	}
}


// Prints the coordinates of a point to an output stream in
// the form (x, y).
// Parameter x is the x-coordinate.
// Parameter y is the y-coordinate.
// Parameter os is the destination output stream.
// Returns the output stream object passed to it.
std::ostream& print_point(double x, double y, std::ostream& os) {
	os << "(" << x << "," << y << ")";  // Replace with your code
	return os;
}


// Prints to an output stream the equation of the line y = mx + b.
// Parameter m is the line's slope.
// Parameter b is the line's intercept.
// Parameter os is the destination output stream.
// Returns the output stream object passed to it.
// If the line is vertical (m = INFINITY), b is the x-intercept;
// otherwise, b is the line's y-intercept.
std::ostream& print_line(double m, double b, std::ostream& os) {
	if (m == INFINITY) {
		os << "x = " << b;
	}
	else if (m == 1) {
		if (b < 0) {
			b = b * -1;
			os << "y = x - " << b;
		}
		else if (b == 0) {
			os << "y = x";
		}
		else {
			os << "y = x + " << b;
		}
	}
	else if (m == -1) {
		if (b < 0) {
			b = b * -1;
			os << "y = -x - " << b;
		}
		else if (b == 0) {
			os << "y = -x";
		}
		else {
			os << "y = -x + " << b;
		}
	}
	else if (m == 0) {
		if (b == 0) {
			os << "UNDEFINED";
		}
		else {
			os << "y = " << b;
		}
	}
	else if (b == 0) {
		os << "y = " << m << "x";
	}
	else {
		if (b < 0) {
			b = b * -1;
			os << "y = " << m << "x - " << b;
		}
		else {
			os << "y = " << m << "x" << " + " << b;
		}
	}
	return os;
}

