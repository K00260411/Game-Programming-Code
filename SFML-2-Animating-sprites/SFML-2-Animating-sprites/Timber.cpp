// Include important C++ libraries here
#include <SFML/Graphics.hpp>

// Make code easier to type with "using namespace"
using namespace sf; //add this to every project of sfml

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;

	// Load a graphic into the texture
	textureBackground.loadFromFile("graphics/backMod.png");

	// Create a sprite
	Sprite spriteBackground;

	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);

	// Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0);

	//amplitude for sin function
	int amp = 5;
	//counter for horiz movement
	int horizCount = 0;
	//up down movement
	bool movingUp = true;

	// Make a tree sprite
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	// Prepare the bee
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	//flipped bee for left to right
	Texture textureBeeFlipped;
	textureBeeFlipped.loadFromFile("graphics/beeFlipped.png");

	Sprite spriteBee;
	Sprite spriteBeeExtra;
	Sprite spriteBeeELR;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);
	//Extra bee at different height range and speed
	spriteBeeExtra.setTexture(textureBee);
	spriteBeeExtra.setPosition(50, 500);
	//Bee that starts on the left to go right
	spriteBeeELR.setTexture(textureBeeFlipped);
	spriteBeeELR.setPosition(0, -200);

	// Is the bee currently moving?
	bool beeActive = false;
	bool beeActiveExtra = false;
	bool beeActiveELR = false;

	// How fast can the bee fly
	float beeSpeed = 0.0f;
	float beeExtraSpeed = 0.0f;
	float beeSpeedELR = 0.0f;
	
	// make 3 cloud sprites from 1 texture
	Texture textureCloud;

	// Load 1 new texture
	textureCloud.loadFromFile("graphics/cloud.png");

	// 3 New sprites withe the same texture
	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;
	Sprite spriteCloudExtra; //1.must start at a different height and move at random speed
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);
	spriteCloudExtra.setTexture(textureCloud); //setting texture

	// Position the clouds off screen
	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(0, 150);
	spriteCloud3.setPosition(0, 300);
	spriteCloudExtra.setPosition(0, 400);

	// Are the clouds currently on screen?
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;
	bool cloudExtraActive = false;

	// How fast is each cloud?
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;
	float cloudExtraSpeed = 0.0f;

	// Variables to control time itself
	Clock clock;

	//stuff
	bool firstLoop = true;
	int descend = 0;
	//descend the clouds
	float cloud1Y = 0;
	float cloud2Y = 0;
	float cloud3Y = 0;
	float cloudExtraY = 0;

	//wave motion stuff
	bool waveUp=true;
	bool reachPeaks;
	
	while (window.isOpen())
	{
		
		/*
		****************************************
		Handle the players input
		****************************************
		*/

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		/*
		****************************************
		Update the scene
		****************************************
		*/
		// Measure time
		Time dt = clock.restart();

		// Setup the bee
		if (!beeActive)
		{

			// How fast is the bee
			srand((int)time(0) * 10);
			beeSpeed = (rand() % 200) + 300;
			
			// How high is the bee
			srand((int)time(0) * 10);
			float height = (rand() % 500) + 100;
			spriteBee.setPosition(2000, height);
			beeActive = true;
			


		}
		else	// Move the bee
		{
			float beeTempStore = spriteBee.getPosition().y;
			float beeTempStoreX = spriteBee.getPosition().x - (beeSpeed * dt.asSeconds());
			/*
			float beeTempStore = spriteBee.getPosition().y;
			float beeTempStoreX = spriteBee.getPosition().x-(beeSpeed*dt.asSeconds());
			/*
			if (waveUp == true)
			{
				spriteBee.setPosition(spriteBee.getPosition().x -(beeSpeed * dt.asSeconds()),spriteBee.getPosition().y-35);
				reachPeaks = true;
			}
			else
			{
				spriteBee.setPosition(spriteBee.getPosition().x -(beeSpeed * dt.asSeconds()),spriteBee.getPosition().y+35);
				reachPeaks = true;
			}
			if (reachPeaks == true)
			{
				if (waveUp==true)
				{
					spriteBee.setPosition(spriteBee.getPosition().x -(beeSpeed * dt.asSeconds()),spriteBee.getPosition().y+30);
					reachPeaks = false;

				}
				else
				{
					spriteBee.setPosition(spriteBee.getPosition().x -(beeSpeed * dt.asSeconds()),spriteBee.getPosition().y - 30);
					reachPeaks = false;
				}
				
				spriteBee.setPosition(
					spriteBee.getPosition().x -
					(beeSpeed * dt.asSeconds()),
					spriteBee.getPosition().y);
					
			}
			*/
			
			//spriteBee.setPosition(beeTempStoreX, beeTempStore + (100 * sin(0.1) * spriteBee.getPosition().x));
				
			spriteBee.setPosition(spriteBee.getPosition().x -(beeSpeed * dt.asSeconds()),spriteBee.getPosition().y);
		

			// Has the bee reached the right hand edge of the screen?
			if (spriteBee.getPosition().x < -100)
			{
				// Set it up ready to be a whole new cloud next frame
				beeActive = false;
			}


//get the wave motion done with this one
//boolean waveUp
//boolean reachedpeaks
//at the end of our up motion reachpeaks = true
//if reachpeaks==true then take away what we changed back to its starting y then set waveUp to false
//at the end of our down motion 
		}


		// Setup the bee
		if (!beeActiveExtra)
		{

			// How fast is the bee
			srand((int)time(0) * 10);
			beeExtraSpeed = (rand() % 100) + 200;
			horizCount = horizCount+beeExtraSpeed;

			// How high is the bee
			srand((int)time(0) * 10);
			//float height = (rand() % 200) + 500;
			float height = 600;
			spriteBeeExtra.setPosition(2000, height);
			beeActiveExtra = true;

		}
		else
			// Move the bee
		{
			//if (horizCount % 300==0)
			int store = spriteBeeExtra.getPosition().x;
			if(store % 300==0)
			{
				if (movingUp==true)
				{
					spriteBeeExtra.setPosition(
						spriteBeeExtra.getPosition().x -
						(beeExtraSpeed * dt.asSeconds()),
						spriteBeeExtra.getPosition().y + 20); 
					movingUp = false;
					//horizCount = 0;
					store = 0;
				}
				else
				{
					spriteBeeExtra.setPosition(
						spriteBeeExtra.getPosition().x -
						(beeExtraSpeed * dt.asSeconds()),
						spriteBeeExtra.getPosition().y- 20);
					movingUp = true;
					store = 0;
					//horizCount = 0;
				}
			}
			
			//else
			{
				spriteBeeExtra.setPosition(
					spriteBeeExtra.getPosition().x -
					(beeExtraSpeed * dt.asSeconds()),
					spriteBeeExtra.getPosition().y);
			}
			
			//then an if statement that checks if we've gone 300 pixels
			//if so we go into another if statement
			//var that checks for boolea?

			//if outer one not then just use the generic movement below

			
			// Has the bee reached the right hand edge of the screen?
			if (spriteBeeExtra.getPosition().x < -100)
			{
				// Set it up ready to be a whole new cloud next frame
				beeActiveExtra = false;
			}
		}
		//sin(y stuff)*amp;

		// Setup the bee
		if (!beeActiveELR)
		{

			// How fast is the bee
			srand((int)time(0) * 10);
			beeSpeedELR = (rand() % 200) - 400;

			// How high is the bee
			srand((int)time(0) * 10);
			float height = (rand() % 100) + 250;
			spriteBeeELR.setPosition(0, height);
			beeActiveELR = true;

		}
		else
			// Move the bee
		{

			spriteBeeELR.setPosition(
				spriteBeeELR.getPosition().x -
				(beeSpeedELR * dt.asSeconds()),
				spriteBeeELR.getPosition().y);

			// Has the bee reached the right hand edge of the screen?
			if (spriteBeeELR.getPosition().x < -100)
			{
				// Set it up ready to be a whole new cloud next frame
				beeActiveELR = false;
			}
		}



		// Manage the clouds
		// Cloud 1
		if (!cloud1Active)
		{

			// How fast is the cloud
			srand((int)time(0) * 10);
			cloud1Speed = (rand() % 200)+10;

			// How high is the cloud
			srand((int)time(0) * 10);
			float height = (rand() % 150);
			spriteCloud1.setPosition(-200, height);
			cloud1Active = true;


		}
		else
		{
			if (spriteCloud1.getPosition().x == -200)
			{
				cloud1Y = spriteCloud1.getPosition().y;
			}

			if (spriteCloud1.getPosition().y < (cloud1Y + 200)) 
			{
				spriteCloud1.setPosition(
					spriteCloud1.getPosition().x +
					(cloud1Speed * dt.asSeconds()),
					spriteCloud1.getPosition().y+0.05); //speeds odd

			}
			else {
				spriteCloud1.setPosition(
					spriteCloud1.getPosition().x +
					(cloud1Speed * dt.asSeconds()),
					spriteCloud1.getPosition().y);
			}


			
			// Has the cloud reached the right hand edge of the screen?
			if (spriteCloud1.getPosition().x > 1920)
			{
				// Set it up ready to be a whole new cloud next frame
				cloud1Active = false;
			}
		}
		// Cloud 2
		if (!cloud2Active)
		{

			// How fast is the cloud
			srand((int)time(0) * 20);
			cloud2Speed = (rand() % 200)+10;

			// How high is the cloud
			srand((int)time(0) * 20);
			float height = (rand() % 300) - 150;
			spriteCloud2.setPosition(-200, height);
			cloud2Active = true;


		}
		else
		{
			if (spriteCloud2.getPosition().x == -200)
			{
				cloud2Y = spriteCloud2.getPosition().y;
			}

			if (spriteCloud2.getPosition().y < (cloud2Y + 200))
			{
				spriteCloud2.setPosition(
					spriteCloud2.getPosition().x +
					(cloud2Speed * dt.asSeconds()),
					spriteCloud2.getPosition().y + 0.05); //speeds odd

			}
			else {
				spriteCloud2.setPosition(
					spriteCloud2.getPosition().x +
					(cloud2Speed * dt.asSeconds()),
					spriteCloud2.getPosition().y);
			}


			// Has the cloud reached the right hand edge of the screen?
			if (spriteCloud2.getPosition().x > 1920)
			{
				// Set it up ready to be a whole new cloud next frame
				cloud2Active = false;
			}
		}
		//cloud 3
		if (!cloud3Active)
		{

			// How fast is the cloud
			srand((int)time(0) * 30);
			cloud3Speed = (rand() % 200)+10;

			// How high is the cloud
			srand((int)time(0) * 30);
			float height = (rand() % 450) - 150;
			spriteCloud3.setPosition(-200, height);
			cloud3Active = true;


		}
		else
		{
			if (spriteCloud3.getPosition().x == -200)
			{
				cloud3Y = spriteCloud3.getPosition().y;
			}

			if (spriteCloud3.getPosition().y < (cloud3Y + 200))
			{
				spriteCloud3.setPosition(
					spriteCloud3.getPosition().x +
					(cloud3Speed * dt.asSeconds()),
					spriteCloud3.getPosition().y + 0.05); //speeds odd

			}
			else {
				spriteCloud3.setPosition(
					spriteCloud3.getPosition().x +
					(cloud3Speed * dt.asSeconds()),
					spriteCloud3.getPosition().y);
			}


			// Has the cloud reached the right hand edge of the screen?
			if (spriteCloud3.getPosition().x > 1920)
			{
				// Set it up ready to be a whole new cloud next frame
				cloud3Active = false;
			}
		}
		//Extra cloud 1
		if (!cloudExtraActive)
		{

			// How fast is the cloud
			srand((int)time(0) * 30);
			cloudExtraSpeed = (rand() % 210);

			// How high is the cloud
			srand((int)time(0) * 30);
			float height = (rand() % 500) - 150;
			spriteCloudExtra.setPosition(-200, height);
			cloudExtraActive = true;


		}
		else
		{

			if (spriteCloudExtra.getPosition().x == -200)
			{
				cloudExtraY = spriteCloudExtra.getPosition().y;
			}

			if (spriteCloudExtra.getPosition().y < (cloudExtraY + 200))
			{
				spriteCloudExtra.setPosition(
					spriteCloudExtra.getPosition().x +
					(cloudExtraSpeed * dt.asSeconds()),
					spriteCloudExtra.getPosition().y + 0.05); //speeds odd

			}
			else {
				spriteCloudExtra.setPosition(
					spriteCloudExtra.getPosition().x +
					(cloudExtraSpeed * dt.asSeconds()),
					spriteCloudExtra.getPosition().y);
			}


			// Has the cloud reached the right hand edge of the screen?
			if (spriteCloudExtra.getPosition().x > 1920)
			{
				// Set it up ready to be a whole new cloud next frame
				cloudExtraActive = false;
			}
		}



		/*
		****************************************
		Draw the scene
		****************************************
		*/

		// Clear everything from the last frame
		window.clear();

		// Draw our game scene here
		window.draw(spriteBackground);

		// Draw the clouds
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);
		window.draw(spriteCloudExtra);

		// Draw the tree
		window.draw(spriteTree);

		// Drawraw the insect
		window.draw(spriteBee);

		window.draw(spriteBeeExtra);
		//left to right
		window.draw(spriteBeeELR);

		// Show everything we just drew
		window.display();


	}

	return 0;
}


