#include "Game.h"
#include <iostream>
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800,600), "Zathura: The Space Adventure", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	this->textures["Bullet"] = new sf::Texture();
	this->textures["Bullet"]->loadFromFile("Textures/bullet.png");

}

void Game::initGUI()
{
	//Load font 
	if (!this->font.loadFromFile("C:/Users/Prasham Desai/Desktop/Coding/C++ Games/Zathura/x64/Debug/fonts/KnightWarrior-w16n8.otf"))
	{
		std::cout << "failed";
	}

	//Init point text
	this->pointText.setFont(this->font);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setOutlineThickness(2.f);
	this->pointText.setCharacterSize(30.f);
	this->pointText.setString("Points:");
	this->pointText.setPosition(sf::Vector2f(10.f, 10.f));
	
	//Init game over text
	this->gameOverText.setFont(this->font);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setOutlineThickness(2.f);
	this->gameOverText.setCharacterSize(70.f);
	this->gameOverText.setString("GAME OVER !!!");
	this->gameOverText.setPosition(this->window->getSize().x/2 - this->gameOverText.getGlobalBounds().width/2
		, this->window->getSize().y / 2 - this->gameOverText.getGlobalBounds().height/2);


	// Init player GUI
	this->playerHpBar.setSize(sf::Vector2f(250.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Green);
	this->playerHpBar.setPosition(sf::Vector2f(this->window->getSize().x - 260.f, 10.f));


	this->playerHpBarBack.setFillColor(sf::Color(25,25,25,128));
	this->playerHpBarBack.setOutlineColor(sf::Color::White);
	this->playerHpBarBack.setOutlineThickness(2.f);
	this->playerHpBarBack.setSize(sf::Vector2f(250.f, 25.f));
	this->playerHpBarBack.setPosition(sf::Vector2f(this->window->getSize().x - 260.f, 10.f));
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initEnemies()
{
	this->spawnTimerMax = 15.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Game::initWorld()
{
	this->worldBackgroundTexture.loadFromFile("C:/Users/Prasham Desai/Desktop/Coding/C++ Games/Zathura/Zathura/Textures/worldBackground.jpg");
	this->worldBackground.setTexture(this->worldBackgroundTexture);
}

void Game::initSystems()
{
	this->points = 0;
}

Game::Game()
{
	this->initWindow();
	this->initWorld(); 
	this->initPlayer();
	this->initTextures();
	this->initGUI();
	this->initEnemies();
	this->initSystems();
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	// Delete textures
	for (auto& i : this->textures)
	{
		delete i.second;
	}

	// Delete bullets
	for (auto *i : this->bullets )
	{
		delete i;
	}
	// Delete enemies
	for (auto *i : this->enemies )
	{
		delete i;
	}
}

// Functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvents();
		if(this->player->getHp()>0)
		{
			this->update();
		}
		this->render();
	}
}

void Game::updatePollEvents()
{
	sf::Event e;

	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
		{
			this->window->close();
		}

		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
		{
			this->window->close();
		}
	}
}

void Game::updateInput()
{
	// Move Player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(this->textures["Bullet"],
			this->player->getPosition().x + this->player->getBounds().width/2.f - 12.f,
			this->player->getPosition().y - 10.f, 
			0.f, -1.f, 5.f));
	}
}

void Game::updateBullet()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();

		// Bullet culling (top of the screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;
	}
}

void Game::updateWorld()
{

}

void Game::updateCollisions()
{
	//Left 
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}

	//Right
	if (this->player->getBounds().left + this->player->getBounds().width > this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}

	//Top
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
	}
	
	//Bottom
	if (this->player->getBounds().top + this->player->getBounds().height > this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left , this->window->getSize().y - this->player->getBounds().height);
	}
}

void Game::updateEnemies()
{
	// Spawning
	this->spawnTimer += 0.5f;
	if(this->spawnTimer >= this->spawnTimerMax)
	{
		// Create a new enemy
		Enemy* newEnemy = new Enemy(rand() % this->window->getSize().x, -100.f);

		// Get the width of the enemy's bounding box
		float enemyWidth = newEnemy->getBounds().width;

		// Adjust x position to ensure the enemy stays within the window
		float spawnPosX = rand() % (this->window->getSize().x - static_cast<int>(enemyWidth));

		// Update the enemy's position
		newEnemy->setPosition(spawnPosX, -100.f);

		// Add the enemy to the list
		this->enemies.push_back(newEnemy);

		// Reset the spawn timer
		this->spawnTimer = 0.f;
	}

	// Updating
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();

		// Delete enemies
		if (enemy->getBounds().top + enemy->getBounds().height > this->window->getSize().y)
		{
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			
		}
		// Enemy Player Collision
		else if (enemy->getBounds().intersects(this->player->getBounds()))
		{
			this->player->loseHp(this->enemies.at(counter)->getDamage());
			
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			

		}
		++counter;
	}
}

void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool enemy_deleted = false;
		for (int k = 0; k < this->bullets.size() && !enemy_deleted; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()) && this->bullets[k]->getBounds().top > 0)
			{ 
				this->points += this->enemies[i]->getPoints();
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);
				
				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				enemy_deleted = true;
			}
		}
	}
}

void Game::updateGUI()
{
	std::stringstream ss;
	ss << "Points: " << this->points;
	this->pointText.setString(ss.str());

	//Update player GUI
	
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	
	this->playerHpBar.setSize(sf::Vector2f(250.f * hpPercent,this->playerHpBar.getSize().y));
}

void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void Game::update()
{
	
	this->updateInput();
	this->player->update();
	this->updateCollisions();
	this->updateBullet();
	this->updateEnemies();
	this->updateCombat();
	this->updateGUI();
}

void Game::render()
{
	// CLear the old frame
	this->window->clear();

	// Draw the new frame
	this->renderWorld();

	this->player->render(*this->window);
 

	// Rendering the bullets
	for(auto *bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	// Rendering the enemies
	for(auto *enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	this->renderGUI();

	//Game Over Screen
	if (this->player->getHp()<=0)
	{
		this->window->clear();
		this->renderWorld();
		this->window->draw(this->gameOverText);
	}

 	// Render the new frame
	this->window->display();
}
