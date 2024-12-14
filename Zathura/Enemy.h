#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/Network.hpp>

class Enemy
{
	private:
		unsigned pointCount;
		sf::CircleShape shape;
		int type;
		int hp;
		int hpMax;
		int damage;
		int points;
		float speed;
		sf::Texture enemyTexture;
		sf::Sprite enemySprite;

		// Functions 
		void initTexture();
		void initSprite();
		void initVariables();
		
	public:
		Enemy(float posX, float posY);
		virtual ~Enemy();

		// Accessors
		sf::FloatRect getBounds() const;
		const int& getDamage() const;

		// Mutators
		void setPosition(float posX , float posY);
		const int& getPoints() const;

		// Functions
		void update();
		void render(sf::RenderTarget* target);

};

