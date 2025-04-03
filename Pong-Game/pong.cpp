#include<SFML/Graphics.hpp>
#include "Bat.cpp"
#include "Ball.cpp"
#include<sstream>
using namespace sf;

int main(){

	//define a window
	VideoMode vm(1920,1080);

	//create a window
	RenderWindow window(vm, "Pong Game", Style::Fullscreen);
 
	View view(FloatRect(0,0,1920,1080));         // Claculates the coordinates according to the main resolution
	window.setView(view);

	Bat bat( 900 , 1000 );
	
	//ball object
	Ball ball(960,10);
	
	int score = 0;
	int lives = 3;
	
	Text hud;
	Font font;
	font.loadFromFile("font/KOMIKAP_.ttf");
	hud.setFont(font);
	hud.setCharacterSize(60);
	hud.setFillColor(Color::White);
	
	hud.setPosition(10,10);

	Clock clock;

	//Gaming loop
	while(window.isOpen()){
	Event event;
	while(window.pollEvent(event)){
		if(event.type==Event::Closed){
			window.close();
		}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)){
			window.close();
		}

		if(Keyboard::isKeyPressed(Keyboard::Left)){
			bat.moveLeft();
		}
		else{
			bat.stopLeft();
		}

		if(Keyboard::isKeyPressed(Keyboard::Right)){
			bat.moveRight();
		}
		else{
			bat.stopRight();
		}

		Time dt = clock.restart();  //update the delta time

		bat.update(dt);
		
		ball.update(dt);
		
		std::stringstream ss;   //ued to build a text stream dynamically
		ss<<"Score: "<<score <<std::endl<<"Lives: "<<lives;
		hud.setString(ss.str());

		//draw
		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.display();
		
	}
	return 0;

}
