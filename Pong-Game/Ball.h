#include<SFML/Graphics.hpp>
using namespace sf;

class Ball{


	Vector2f m_Position;   // declare vector2f
	
	CircleShape m_Shape;          //graphical representation of ball
	
	float m_Speed=500.0f;            //Controls how fast the bat moves
	
	bool m_directionX = 0.2f;	 //ball moves to right
	bool m_directionY = 0.2f;	 //ball moves to downward
	
	public:
	//Constructor initializes the balls's position and size
		Ball(float StartX , float StartY);
		FloatRect getPosition();
		CircleShape getShape();
		
		void reboundSides(); 	//Called when the ball hits left or right side wall(Change horizontal position)
		
		void reboundBatOrTop();	    //Called when the ball hits Bat or Top( Chage direction vertically)
		
		void reboundBottom();   /*Called when the ball misses the bat and hits the bottom ; resets the 			ball(player looses a life)*/
		
		void update(Time dt);
		
};
