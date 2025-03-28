#include "Bat.h"

Bat::Bat(float startX, float startY) {
	m_Position.x=startX;  	 	//sets the bat's horixontal position
	m_Position.y=startY;   	//sets the bat's vertical position
	
	m_Shape.setSize(sf::Vector2f(200 ,50));  	//Define thr bat size
	m_Shape.setPosition(m_Position);     //Defines bat position
}

FloatRect Bat::getPosition() {           //This func returns the RectangleShape object itsef
	return m_Shape.getGlobalBounds();	
}

RectangleShape Bat::getShape() {
	return m_Shape;
}

void Bat::moveLeft(){
	m_movingLeft = true;
}

void Bat::moveRight(){
	m_movingRight = true;
}

void Bat::stopLeft(){
	m_movingLeft = false;
}

void Bat::stopRight(){
	m_movingRight = false;
}

void Bat::update(Time dt){
	if(m_movingLeft){
		m_Position.x-=m_Speed*dt.asSeconds();   //moves left
	}
	if(m_movingRight){
		m_Position.x+=m_Speed*dt.asSeconds();   //moves Right
	}
	
	m_Shape.setPosition(m_Position);
}
