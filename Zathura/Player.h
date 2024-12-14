#pragma once
#include "Bullet.h"

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float movementSpeed;
	float attackCoolDown;
	float attackCoolDownMax;
	int hp;
	int hpMax;
	 
	//private functions
	void iniTexture();
	void initSprite();
	void initVariables();

public:
	Player();
	virtual ~Player();

	//Accessor
	const  sf::Vector2f & getPosition() const; 
	const  sf::FloatRect getBounds() const; 
	const int& getHp() const;
	const int& getHpMax() const;

	//Modifiers
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void loseHp(const int damage);

	//Functions 
	void move(const float dirX, const float dirY);
	const bool canAttack(); 

	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);
};

