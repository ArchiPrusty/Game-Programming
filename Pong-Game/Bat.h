#include<SFML/Graphics.hpp>
using namespace sf;

class Bat{

private:
	Vector2f m_Position;   // declare vector2f
	
	RectangleShape m_Shape;          //graphical representation of bat
	
	float m_Speed=600.0f;            //Controls how fast the bat moves
	bool m_movingRight = false;
	bool m_movingLeft = false;
	
public:
	Bat(float startX, float startY);   // store x and y coordinate of bat
	
	FloatRect getPosition();     // Retrive the current position of bat( x and y coordinate)
	RectangleShape getShape();   // retive the windth and height of shape
	
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	
	void update(Time dt);        //
};
