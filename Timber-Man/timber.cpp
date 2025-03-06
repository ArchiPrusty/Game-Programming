#include<SFML/Graphics.hpp>
using namespace sf;

int main(){
	VideoMode vm(960,540);
	RenderWindow window(vm,"TIMBER MAN", Style::Fullscreen);
	
	View view(FloatRect(0,0,1920,1080));
	window.setView(view);
	
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0,0);
	
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810,0);
	
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0,800);


	bool beeActive= false;
    	float beeSpeed= 0.0f;
	
	Texture textureCloud;
	textureCloud.loadFromFile("graphics/cloud.png");
	Sprite spriteCloud1, spriteCloud2, spriteCloud3;
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);
	spriteCloud1.setPosition(0,0);
	spriteCloud2.setPosition(0,150);
	spriteCloud2.setScale(0.5,0.5);
	spriteCloud3.setPosition(0,300);
	
	bool cloud1Active= false;
        float cloud1Speed= 0.0f;
	bool cloud2Active= false;
        float cloud2Speed= 0.0f;
        bool cloud3Active= false;
        float cloud3Speed= 0.0f;
    
	
	Clock clock;
	
	while(window.isOpen()){
	Event event;
	while(window.pollEvent(event)){
	if(event.type == Event::Closed){
	window.close();
	}
	}
	if(Keyboard::isKeyPressed(Keyboard::Escape)){
	window.close();
	}
	
	 Time dt = clock.restart();
	 
            if(!beeActive)
            {
            srand((int)time(0));
            beeSpeed = (rand() %200)+200;
            float height= (rand() %500)+500;
            spriteBee.setPosition(2000,height);
            beeActive=true;
            }
            
            else
            {
            spriteBee.setPosition(spriteBee.getPosition().x-(beeSpeed*dt.asSeconds()) ,spriteBee.getPosition().y);
            
            if(spriteBee.getPosition().x<-100)
            {
            beeActive=false;
            }
            }
            
            if(!cloud1Active)
            {
            srand((int)time(0));
            cloud1Speed = (rand() %120)+120;
            float height= (rand() %150)+150;
            spriteCloud1.setPosition(-100,0);
            cloud1Active=true;
            }
            
            else
            {
            spriteCloud1.setPosition(spriteCloud1.getPosition().x+(cloud1Speed*dt.asSeconds()) ,spriteCloud1.getPosition().y);
            
            if(spriteCloud1.getPosition().x>2000)
            {
            cloud1Active=false;
            }
            }
            
            if(!cloud2Active)
            {
            srand((int)time(0));
            cloud2Speed = (rand() %170)+170;
            float height= (rand() %150)+150;
            spriteCloud2.setPosition(-100,150);
            cloud2Active=true;
            }
            
            else
            {
            spriteCloud2.setPosition(spriteCloud2.getPosition().x+(cloud2Speed*dt.asSeconds()) ,spriteCloud2.getPosition().y);
            
            if(spriteCloud2.getPosition().x>2000)
            {
            cloud2Active=false;
            }
            }
            
            if(!cloud3Active)
            {
            srand((int)time(0));
            cloud3Speed = (rand() %70)+70;
            float height= (rand() %150)+150;
            spriteCloud3.setPosition(-100,280);
            cloud3Active=true;
            }
            
            else
            {
            spriteCloud3.setPosition(spriteCloud3.getPosition().x+(cloud3Speed*dt.asSeconds()) ,spriteCloud3.getPosition().y);
            
            if(spriteCloud3.getPosition().x>2000)
            {
            cloud3Active=false;
            }
            }
            
	window.clear();
	window.draw(spriteBackground);
	window.draw(spriteCloud1);
	window.draw(spriteCloud2);
	window.draw(spriteCloud3);
	window.draw(spriteTree);
	window.draw(spriteBee);
	window.display();
	}
	return 0;
}
