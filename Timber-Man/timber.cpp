#include<SFML/Graphics.hpp>
using namespace sf;

void updateBranches(int seed);
const int NUM_BRANCHES=6;
Sprite branches[NUM_BRANCHES];

enum class side{
	LEFT,  //OR 0
	RIGHT, //OR 1
	NONE
};

side branchPositions [NUM_BRANCHES];

int main(){
	VideoMode vm(960,540);          // OBJECT vm CREATED
	RenderWindow window(vm,"TIMBER MAN"/*, Style::Fullscreen*/);   // Add 3rd field <Style::Fullscreem> to open fullscreen by default
	
	View view(FloatRect(0,0,1920,1080));          // Claculates the coordinates according to the main resolution
	window.setView(view);
	
	Texture textureBackground;		// creates texture background
	textureBackground.loadFromFile("graphics/background.png");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);		//pastes it on the bg like a sticke
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
    
	Clock clock;				// clock is an object of class Clock
	
	RectangleShape timeBar;			// timebar is an object of class RectangeShape
	float timeBarStartWidth = 400;
	float timeBarHeight = 80;
	
	timeBar.setSize(Vector2f(timeBarStartWidth,timeBarHeight));	//set the width and height of the timeBar
	timeBar.setFillColor(Color::Red);
	timeBar.setPosition((1920/2)-200, 980);			//set the position of timeBar in window
	
	Time gameTimeTotal;			// gameTimeTotal is an object of class Time
	float timeRemaining = 6.0f;
	float timeBarWidthPerSecond = timeBarStartWidth/timeRemaining;	//every second the time bar reduces by timeBarWidthPerSecond pixels
	bool paused = true;
	int score = 0;
	
	Text messageText;
	Text scoreText;
	
	Font font;
	font.loadFromFile("font/KOMIKAP_.ttf");
	messageText.setFont(font);
	scoreText.setFont(font);
	
	messageText.setString("Press Enter to start!!!");
	scoreText.setString("Score = 0");
	
	messageText.setCharacterSize(75);
	scoreText.setCharacterSize(100);
	
	messageText.setFillColor(Color::White);
	scoreText.setFillColor(Color::White);
	
	FloatRect textRect = messageText.getLocalBounds();
	messageText.setOrigin(textRect.left + textRect.width/2.0f , textRect.top + textRect.height/2.0);
	messageText.setPosition(960 , 540);
	scoreText.setPosition(20,20);
	
	Texture textureBranch;
	textureBranch.loadFromFile("graphics/branch.png");
	for(int i=0 ; i<NUM_BRANCHES ; i++){
		branches[i].setTexture(textureBranch);
		branches[i].setPosition(1110,200);
		branches[i].setOrigin(0,0);
	}
	
	
	//gaming loop
	
	while(window.isOpen()){
	Event event;
	while(window.pollEvent(event)){
	if(event.type == Event::Closed){		 // ensures window stays open until close button pressed
	window.close();
	}
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Escape)){		// exits games on clicking escape
		window.close();
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Return)){
		paused = false;
		score = 0;
		timeRemaining = 5;
	}
	
	Time dt = clock.restart();
	
	if(!paused){
		timeRemaining -= dt.asSeconds();
		timeBar.setSize(Vector2f(timeBarWidthPerSecond*timeRemaining , timeBarHeight));
		if(timeRemaining <= 0.0f){
			messageText.setString("GAME OVER !");
			messageText.setCharacterSize(75);
			FloatRect textRect = messageText.getLocalBounds();
			messageText.setOrigin(textRect.left + textRect.width/2.0f , textRect.top + textRect.height/2.0);
			messageText.setPosition(960 , 540);
			paused = true;
		}
		
            if(!beeActive)
            {
            	srand((int)time(0));			//srand for generating within a 'fraction of second'
            	beeSpeed = (rand() %200)+200;		//rand for generating within a range
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
            	srand((int)time(0) * 10);
            	cloud1Speed = (rand() %100)+100;
            	float height= (rand() %150)+150;
            	spriteCloud1.setPosition(-100,0);
            	cloud1Active=true;
            }
            
            else
            {
            spriteCloud1.setPosition(spriteCloud1.getPosition(). x + (cloud1Speed*dt.asSeconds()) ,spriteCloud1.getPosition().y);
            
            if(spriteCloud1.getPosition().x>2000)
            {
            cloud1Active=false;
            }
            }
            
            if(!cloud2Active)
            {
            	srand((int)time(0));
            	cloud2Speed = (rand() %150)+150;
            	float height= (rand() %150)+150;
            	spriteCloud2.setPosition(-100,150);
            	cloud2Active=true;
            }
            
            else
            {
            	spriteCloud2.setPosition(spriteCloud2.getPosition(). x + (cloud2Speed*dt.asSeconds()) ,spriteCloud2.getPosition().y);
            
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
            
            updateBranches(1);
            updateBranches(2);
            updateBranches(3);
            updateBranches(4);
            updateBranches(5);
            
            //placed branches in game
            for(int i=0; i<NUM_BRANCHES; i++)
            {
            	float height = i*150;
            	if(branchPositions[i] == side::LEFT)
            	{
            		branches[i].setPosition(610,height);
            		branches[i].setOrigin(220,40);
            		branches[i].setRotation(180);
            	}
            	
            	else if(branchPositions[i] == side::RIGHT)
            	{
            		branches[i].setPosition(1330,height);
            		branches[i].setOrigin(220,40);
            		branches[i].setRotation(0);
            	}
            	else{
            		branches[i].setPosition(3000,height);
            	}
            }
        }//end if paused
        
	window.clear();
	window.draw(spriteBackground);
	window.draw(spriteCloud1);
	window.draw(spriteCloud2);
	window.draw(spriteCloud3);
	window.draw(spriteTree);
	for(int i=0; i<NUM_BRANCHES ;i++){
	window.draw(branches[i]);
	}
	window.draw(spriteBee);
	window.draw(timeBar);
	if(paused){
	window.draw(messageText);
	}
	window.draw(scoreText);
	window.display();
	}
	return 0;
}


void updateBranches(int seed)
{
	for(int j=NUM_BRANCHES-1; j>0 ;j--)
	{
		branchPositions[j] = branchPositions[j-1];
	}
	
	srand((int)time(0)+seed);
	int r=(rand()%5);
	
	switch(r)
	{
		case 0:
		branchPositions[0] = side::LEFT;
		break;
		case 1:
		branchPositions[0] = side::RIGHT;
		break;
		default:
		branchPositions[0] = side::NONE;
	}
	
}
