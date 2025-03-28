#include<SFML/Graphics.hpp>
#include "Bat.cpp"
using namespace sf;

int main(){

	//define a window
	VideoMode vm(1920,1080);

	//create a window
	RenderWindow window(vm, "Pong Game", Style::Fullscreen);
 
	View view(FloatRect(0,0,1920,1080));         // Claculates the coordinates according to the main resolution
	window.setView(view);

	Bat bat( 900 , 1000 );

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

		//draw
		window.clear();
		window.draw(bat.getShape());
		window.display();
	}
	return 0;

}
