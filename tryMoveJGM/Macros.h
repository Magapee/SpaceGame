#pragma once
// Converts degrees to radians.
#define degreesToRadians(angleDegrees) (angleDegrees * M_PI / 180.0)

// Converts radians to degrees.
#define radiansToDegrees(angleRadians) (angleRadians * 180.0 / M_PI)


//safe delete (possibly, don't need)
template<typename T> void safe_delete(T*& a) {
	delete a;
	a = NULL;
}