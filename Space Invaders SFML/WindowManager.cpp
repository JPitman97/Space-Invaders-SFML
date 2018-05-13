#include "WindowManager.h"

WindowManager::WindowManager()
{

	std::cout << "Window Manager Constructor Running" << std::endl; //Debug log - Hidden during actual gameplay

	/*Creates the window using specified inputs and sets the framerate limiter to 60 with not key repeat*/
	window.create(sf::VideoMode(winWidth, winHeight), winTitle, sf::Style::Close);
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	/*Loads all the background images used for the game and then applies them, this should be within a texture manager class but I never implemented one*/
	if (!Background.loadFromFile("Assets/Background.bmp"))
	{
		std::cout << "Error loading Background" << std::endl;
	}
	BackgroundSpr.setTexture(Background);
	if (!MenuBackground.loadFromFile("Assets/Menu/StartScreen.bmp"))
	{
		std::cout << "Error loading Background" << std::endl;
	}
	MenuBackgroundSpr.setTexture(MenuBackground);
	if (!WinBackground.loadFromFile("Assets/Menu/WinScreen.bmp"))
	{
		std::cout << "Error loading Background" << std::endl;
	}
	WinBackgroundSpr.setTexture(WinBackground);
	if (!LossBackground.loadFromFile("Assets/Menu/LossScreen.bmp"))
	{
		std::cout << "Error loading Background" << std::endl;
	}
	LossBackgroundSpr.setTexture(LossBackground);
	if (!InstructionBackground.loadFromFile("Assets/Menu/InstructionScreen.bmp"))
	{
		std::cout << "Error loading Background" << std::endl;
	}
	InstructionBackgroundSpr.setTexture(InstructionBackground);
	if (!transparentBG.loadFromFile("Assets/Menu/TransparentBG.bmp"))
	{
		std::cout << "Error loading transparent Background" << std::endl;
	}
	transparentSpr.setTexture(transparentBG);
	transparentSpr2.setTexture(transparentBG);
	transparentSpr3.setTexture(transparentBG);

	/*Loads and sets the fonts used for the game*/
	if (!font.loadFromFile("Assets/arial.ttf"))
	{
		std::cout << "Could not load UI font!" << std::endl;
	}
	else
	{
		enemiesUI.setFont(font);
		fpsUI.setFont(font);
	}
	if (!menuFont.loadFromFile("Assets/moonhouse.ttf"))
	{
		std::cout << "Could not load Menu font!" << std::endl;
	}
	else
	{
		beginTxtBtn.setFont(menuFont);
		InstructionsTxtBtn.setFont(menuFont);
		EndTxtBtn.setFont(menuFont);
	}

	//Spawns a wave of 10 enemies at the top of the screen
	enemy1.spawnEnemies();

	//Game Loop - Handles all the game logic each frame
	while (window.isOpen())
	{
		//The menu state handles the main menu
		if (stateManager::getState() == "Menu")
		{
			/*Clears the window and draws the menu background*/
			window.clear();
			window.draw(MenuBackgroundSpr);

			/*Positions and displays the Begin button on screen*/
			beginTxtBtn.setPosition(150, 250);
			beginTxtBtn.setScale(1.5f, 2.0f);
			beginTxtBtn.setString("Begin Game");
			transparentSpr.setPosition(beginTxtBtn.getPosition());
			window.draw(beginTxtBtn);

			/*Positions and displays the Instructions button on screen*/
			InstructionsTxtBtn.setPosition(150, 350);
			InstructionsTxtBtn.setScale(1.5f, 2.0f);
			InstructionsTxtBtn.setString("Instructions");
			transparentSpr2.setPosition(InstructionsTxtBtn.getPosition());
			window.draw(InstructionsTxtBtn);

			/*Positions and displays the End Game button on screen*/
			EndTxtBtn.setPosition(150, 450);
			EndTxtBtn.setScale(1.5f, 2.0f);
			EndTxtBtn.setString("Exit Game");
			transparentSpr3.setPosition(EndTxtBtn.getPosition());
			window.draw(EndTxtBtn);

			/*Handles the events of the player moving the mouse over a button, clicking the button, or closing the window*/
			sf::Event Event;
			while (window.pollEvent(Event))
			{
				switch (Event.type)
				{
				case sf::Event::Closed:
				{
					window.close();
					break;
				}
				case sf::Event::KeyPressed:
				{
					if (Event.key.code == sf::Keyboard::Escape)
					{
						std::cout << "Closing!" << std::endl;
						window.close();
					}
					break;
				}
				case sf::Event::MouseMoved:
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosf((float)mousePos.x, (float)mousePos.y);
					if (transparentSpr.getGlobalBounds().contains(mousePosf))
					{
						beginTxtBtn.setFillColor(sf::Color::Red);
					}
					else
					{
						beginTxtBtn.setFillColor(sf::Color::White);
					}
					if (transparentSpr2.getGlobalBounds().contains(mousePosf))
					{
						InstructionsTxtBtn.setFillColor(sf::Color::Red);
					}
					else
					{
						InstructionsTxtBtn.setFillColor(sf::Color::White);
					}
					if (transparentSpr3.getGlobalBounds().contains(mousePosf))
					{
						EndTxtBtn.setFillColor(sf::Color::Red);
					}
					else
					{
						EndTxtBtn.setFillColor(sf::Color::White);
					}
					break;
				}
				case sf::Event::MouseButtonPressed:
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosf((float)mousePos.x, (float)mousePos.y);
					if (transparentSpr.getGlobalBounds().contains(mousePosf))
					{
						stateManager::setState(1);
					}
					if (transparentSpr2.getGlobalBounds().contains(mousePosf))
					{
						stateManager::setState(4);
					}
					if (transparentSpr3.getGlobalBounds().contains(mousePosf))
					{
						window.close();
					}
					break;
				}
				}
			}

			//Handles if the player presses enter, which is another way of beginning the game
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				stateManager::setState(1);
			}
		}

		//The Instructions state handles the instructions option
		if (stateManager::getState() == "Instructions")
		{
			/*Handles the events of the player moving the mouse over a button, clicking the button, or closing the window*/
			sf::Event Event;
			while (window.pollEvent(Event))
			{
				switch (Event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:
					if (Event.key.code == sf::Keyboard::Escape)
					{
						std::cout << "Closing!" << std::endl;
						window.close();
					}
					break;

				case sf::Event::MouseMoved:
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosf((float)mousePos.x, (float)mousePos.y);

					if (transparentSpr2.getGlobalBounds().contains(mousePosf))
					{
						beginTxtBtn.setFillColor(sf::Color::Red);
					}
					else
					{
						beginTxtBtn.setFillColor(sf::Color::White);
					}

					break;
				}
				case sf::Event::MouseButtonPressed:
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosf((float)mousePos.x, (float)mousePos.y);
					if (transparentSpr2.getGlobalBounds().contains(mousePosf))
					{
						stateManager::setState(1);
					}
					break;
				}

				default:
					break;
				}
			}

			/*Clears the window and displays the instructions background, as well as creating a Begin game button*/
			window.clear();
			window.draw(InstructionBackgroundSpr);
			beginTxtBtn.setPosition(150, 650);
			beginTxtBtn.setScale(1.5f, 2.0f);
			beginTxtBtn.setString("Begin Game");
			transparentSpr2.setPosition(beginTxtBtn.getPosition());
			window.draw(beginTxtBtn);
		}

		//The game state handles the actual game logic
		if (stateManager::getState() == "Game")
		{
			//Clears the background to a default color
			window.clear(sf::Color::Magenta); 
			//Draws the background image
			window.draw(BackgroundSpr); 
			//Checks whether the window has been closed or whether the player has fired
			EM.pollEvents(window, player); 
			//Checks whether the player has attempted to move
			player.pollEvents(); 
			//Draws the player to the screen
			player.draw(window); 

			//Checks whether the enemy has collided with the player, if so use the audio manager to play the death sound
			enemy1.Objectcollisions(player, Audio);

			//Draw all of the enemies and check whether they are colliding with the window, if so destroy them
			for (size_t i = 0; i < enemy1.EnemyVect.size(); i++)
			{
				enemy1.EnemyVect[i].draw(window);
				enemy1.EnemyVect[i].pollEvents();
				if (enemy1.EnemyVect[i].windowCollisions())
				{
					enemy1.EnemyVect.erase(enemy1.EnemyVect.begin() + i);
					enemy1.enemiesRemaining--;
					if (enemy1.enemiesRemaining == 0)
					{
						player.playerLose();
					}
				}
			}

			/*Handle if the player fires, if so then create a new bullet object, set its position to above the player, add it to a vector and play the shot sound*/
			if (player.fire)
			{
				Bullet newBullet;
				newBullet.setPosition((player.getPosition().x) + 40, 700);
				bullet.bulletVect.push_back(newBullet);
				Audio.playShotSound();
				player.fire = false;
			}
			/*Handle the bullet during its lifetime, drawing it and moving it up the screen, while also checking for collision to destroy it*/
			for (size_t i = 0; i < bullet.bulletVect.size(); i++)
			{
				bullet.bulletVect[i].setTexture();
				bullet.bulletVect[i].draw(window);
				bullet.bulletVect[i].pollEvents();

				if (enemy1.Objectcollisions(bullet.bulletVect[i], Audio, player) || bullet.bulletVect[i].windowCollisions())
				{
					bullet.bulletVect.erase(bullet.bulletVect.begin() + i);
				}
			}

			/*Set tempstring equal to the remaining enemies on the screen, then display it and clear the string*/
			tempString << "Enemies remaining: " << enemy1.enemiesRemaining;
			enemiesUiTxt = tempString.str();
			enemiesUI.setString(enemiesUiTxt);
			window.draw(enemiesUI);
			tempString.str("");
		}

		//The win state handles the game when the player wins
		if (stateManager::getState() == "Win")
		{
			//Check to see if the player closes the window
			EM.pollEvents(window, player);
			//Clear the screen
			window.clear();
			//Draw the win background
			window.draw(WinBackgroundSpr);
			/*Check if the player presses the return key, to replay the game and respawn the enemies*/
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				stateManager::setState(1);
				enemy1.spawnEnemies();
			}
		}

		//The loss state handles the game when the player loses
		if (stateManager::getState() == "Loss")
		{
			//Check to see if the player closes the window
			EM.pollEvents(window, player);
			//Clear the screen
			window.clear();
			//Draw the loss background
			window.draw(LossBackgroundSpr);
			/*Check if the player presses the return key, to replay the game and respawn the enemies*/
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				stateManager::setState(1);
				enemy1.spawnEnemies();
			}
		}

		/*Handles setting the FPS text with the current FPS of the screen, the clearing the string*/
		tempString << "FPS: " << 1.0f / time.asSeconds();
		FPSUiTxt = tempString.str();
		fpsUI.setString(FPSUiTxt);
		fpsUI.setPosition(450, 0);
		window.draw(fpsUI);
		tempString.str("");

		//Draws everything to the screen
		window.display();

		/*Handles the Frame rate both for movement and the FPS counter*/
		time = clock.getElapsedTime();
		std::cout << 1.0f / time.asSeconds() << std::endl;
		clock.restart().asSeconds();
	}
}

WindowManager::~WindowManager()
{
}
