#include "Ball.h"

Ball::Ball(float startX, float startY) {
	m_Position.x=startX;  	 	//sets the ball's horixontal position
	m_Position.y=startY;   	//sets the ball's vertical position
	
	m_Shape.setRadius(15);  	//Define the ball size
	m_Shape.setPosition(m_Position);     //Defines ball position
}

FloatRect Ball::getPosition() {           //This func returns the RectangleShape object itsef
	return m_Shape.getGlobalBounds();	
}

CircleShape Ball::getShape() {
	return m_Shape;
}

void Ball :: reboundSides() {
	m_directionX = -m_directionX;
}

void Ball :: reboundBatOrTop() {
	m_directionY = -m_directionY;
}

void Ball :: reboundBottom() {
	m_Position.y=10;	//Reset ball to top
	m_Position.x=960;	//Reset to default x position
	m_directionY = -m_directionY;
} 

void Ball :: update(Time dt){
	//Update the ball's position
	m_Position.y += m_directionY * m_Speed * dt.asSeconds();
	m_Position.x += m_directionX * m_Speed * dt.asSeconds();
	
	//move the ball
	m_Shape.setPosition(m_Position);
}
