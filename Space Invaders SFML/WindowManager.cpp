#include "WindowManager.h"

WindowManager::WindowManager()
{

	std::cout << "Window Manager Constructor Running" << std::endl;

	window.create(sf::VideoMode(winWidth, winHeight), winTitle, sf::Style::Close);
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	if (!Background.loadFromFile("Assets/Background.jpg"))
	{
		std::cout << "Error loading Background" << std::endl;
	}
	BackgroundSpr.setTexture(Background);
	if (!MenuBackground.loadFromFile("Assets/Menu/StartScreen.jpg"))
	{
		std::cout << "Error loading Background" << std::endl;
	}
	MenuBackgroundSpr.setTexture(MenuBackground);
	if (!WinBackground.loadFromFile("Assets/Menu/WinScreen.jpg"))
	{
		std::cout << "Error loading Background" << std::endl;
	}
	WinBackgroundSpr.setTexture(WinBackground);
	if (!LossBackground.loadFromFile("Assets/Menu/LossScreen.jpg"))
	{
		std::cout << "Error loading Background" << std::endl;
	}
	LossBackgroundSpr.setTexture(LossBackground);
	if (!InstructionBackground.loadFromFile("Assets/Menu/InstructionScreen.jpg"))
	{
		std::cout << "Error loading Background" << std::endl;
	}
	InstructionBackgroundSpr.setTexture(InstructionBackground);
	if (!transparentBG.loadFromFile("Assets/Menu/TransparentBG.png"))
	{
		std::cout << "Error loading transparent Background" << std::endl;
	}
	transparentSpr.setTexture(transparentBG);
	transparentSpr2.setTexture(transparentBG);
	transparentSpr3.setTexture(transparentBG);

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

	enemy1.spawnEnemies();

	while (window.isOpen())
	{
		if (stateManager::getState() == "Menu")
		{
			window.clear();
			window.draw(MenuBackgroundSpr);

			beginTxtBtn.setPosition(150, 250);
			beginTxtBtn.setScale(1.5f, 2.0f);
			beginTxtBtn.setString("Begin Game");
			transparentSpr.setPosition(beginTxtBtn.getPosition());

			window.draw(beginTxtBtn);
			window.draw(transparentSpr);

			InstructionsTxtBtn.setPosition(150, 350);
			InstructionsTxtBtn.setScale(1.5f, 2.0f);
			InstructionsTxtBtn.setString("Instructions");
			transparentSpr2.setPosition(InstructionsTxtBtn.getPosition());
			window.draw(InstructionsTxtBtn);

			EndTxtBtn.setPosition(150, 450);
			EndTxtBtn.setScale(1.5f, 2.0f);
			EndTxtBtn.setString("Exit Game");
			transparentSpr3.setPosition(EndTxtBtn.getPosition());
			window.draw(EndTxtBtn);

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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				stateManager::setState(1);
			}
		}

		if (stateManager::getState() == "Instructions")
		{
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

			window.clear();
			window.draw(InstructionBackgroundSpr);
			beginTxtBtn.setPosition(150, 650);
			beginTxtBtn.setScale(1.5f, 2.0f);
			beginTxtBtn.setString("Begin Game");
			transparentSpr2.setPosition(beginTxtBtn.getPosition());
			window.draw(beginTxtBtn);
		}

		if (stateManager::getState() == "Game")
		{
			window.clear(sf::Color::Magenta);
			window.draw(BackgroundSpr);
			EM.pollEvents(window, player);
			player.pollEvents();
			player.draw(window);

			enemy1.Objectcollisions(player, Audio);

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

			if (player.fire)
			{
				Bullet newBullet;
				newBullet.setPosition((player.getPosition().x) + 40, 700);
				bullet.bulletVect.push_back(newBullet);
				Audio.playShotSound();
				player.fire = false;
			}

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

			tempString << "Enemies remaining: " << enemy1.enemiesRemaining;
			enemiesUiTxt = tempString.str();

			enemiesUI.setString(enemiesUiTxt);
			window.draw(enemiesUI);
			tempString.str("");
		}

		if (stateManager::getState() == "Win")
		{
			EM.pollEvents(window, player);
			window.clear();
			window.draw(WinBackgroundSpr);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				stateManager::setState(1);
				enemy1.spawnEnemies();
			}
		}

		if (stateManager::getState() == "Loss")
		{
			EM.pollEvents(window, player);
			window.clear();
			window.draw(LossBackgroundSpr);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				stateManager::setState(1);
				enemy1.spawnEnemies();
			}
		}

		tempString << "FPS: " << 1.0f / time.asSeconds();
		FPSUiTxt = tempString.str();

		fpsUI.setString(FPSUiTxt);
		fpsUI.setPosition(450, 0);
		window.draw(fpsUI);
		tempString.str("");

		window.display();

		time = clock.getElapsedTime();

		std::cout << 1.0f / time.asSeconds() << std::endl;

		clock.restart().asSeconds();
	}
}

WindowManager::~WindowManager()
{
}
