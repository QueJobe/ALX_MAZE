#include "raycasting.h"

/**
 * distanceBetweenPoints - Calculates the distance between two points.
 * @x1: x coordinate of the starting point.
 * @y1: y coordinate of the starting point.
 * @x2: x coordinate of the end point.
 * @y2: y coordinate of the end point.
 * Return: The distance between the two points.
 */
float distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

/**
 * isRayFacingDown - Checks if the ray is facing down.
 * @angle: Current ray angle.
 * Return: True if the ray is facing down, otherwise false.
 */
bool isRayFacingDown(float angle)
{
	return (angle > 0 && angle < PI);
}

/**
 * isRayFacingUp - Checks if the ray is facing up.
 * @angle: Current ray angle.
 * Return: True if the ray is facing up, otherwise false.
 */
bool isRayFacingUp(float angle)
{
	return !isRayFacingDown(angle);
}

/**
 * isRayFacingRight - Checks if the ray is facing to the right.
 * @angle: Current ray angle.
 * Return: True if the ray is facing to the right, otherwise false.
 */
bool isRayFacingRight(float angle)
{
	return (angle < 0.5 * PI || angle > 1.5 * PI);
}

/**
 * isRayFacingLeft - Checks if the ray is facing to the left.
 * @angle: Current ray angle.
 * Return: True if the ray is facing to the left, otherwise false.
 */
bool isRayFacingLeft(float angle)
{
	return !isRayFacingRight(angle);
}

