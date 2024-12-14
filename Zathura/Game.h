#pragma once
#include "Player.h"
#include <map>
#include <sstream>
class Game
{
private :
	// Window
	sf::RenderWindow* window;

	//Resources
	std::map <std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets; 

	// Player
	Player* player;

	// Player GUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	
	// Enemies
	std::vector<Enemy*> enemies;
	float spawnTimer;
	float spawnTimerMax;

	// GUI
	sf::Font font;
	sf::Text pointText;
	sf::Text gameOverText;

	// World
	sf::Texture worldBackgroundTexture;
	sf::Sprite worldBackground; 

	// Systems
	unsigned points;
	 
	// Private Functions 
	void initWindow();
	void initTextures();
	void initGUI();
	void initPlayer();
	void initEnemies();
	void initWorld();
	void initSystems();

public :
	Game();
	virtual ~Game();
	
	// Functions
	void run();

	void updatePollEvents();
	void updateInput();
	void updateBullet();
	void updateWorld();
	void updateCollisions();
	void updateEnemies();
	void updateCombat();
	void updateGUI();
	void update();

	void renderGUI();
	void renderWorld();
	void render();
};

