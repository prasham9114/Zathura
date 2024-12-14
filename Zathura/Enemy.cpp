#include "Enemy.h"

void Enemy::initVariables()
{ 
	this->type = 0;
	this->hpMax = 10;
	this->hp = this->hpMax;
	this->damage = 1;
	this->points = 0;
	this->speed = 0.f;
}

void Enemy::initTexture()
{
	switch (rand()%5 + 1)
	{
		case 1: this->enemyTexture.loadFromFile("Textures/enemyTypeOne.png");
			this->type = 1;
			this->hp = this->type;
			this->damage = this->type;
			this->points = this->type;
			this->speed = this->type + 2;
			break;
		case 2: this->enemyTexture.loadFromFile("Textures/enemyTypeTwo.png");
			this->type = 2;
			this->hp = this->type;
			this->damage = this->type;
			this->points = this->type;
			this->speed = this->type + 2;
			break;
		case 3: this->enemyTexture.loadFromFile("Textures/enemyTypeThree.png");
			this->type = 3;
			this->hp = this->type;
			this->damage = this->type;
			this->points = this->type;
			this->speed = this->type + 1;
			break;
		case 4: this->enemyTexture.loadFromFile("Textures/enemyTypeFour.png");
			this->type = 4;
			this->hp = this->type;
			this->damage = this->type;
			this->points = this->type;
			this->speed = this->type + 1;
			break;
		case 5: this->enemyTexture.loadFromFile("Textures/enemyTypeFive.png");
			this->type = 5;
			this->hp = this->type;
			this->damage = this->type;
			this->points = this->type;
			this->speed = this->type + 1;
			break;
		default:
			break;
	}
}

void Enemy::initSprite()
{
	this->enemySprite.setTexture(this->enemyTexture);
	this->enemySprite.scale(0.2, 0.2);
}



Enemy::Enemy(float posX , float posY)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->enemySprite.setPosition(posX, posY);
}

Enemy::~Enemy()
{

}

sf::FloatRect Enemy::getBounds() const
{
	return this->enemySprite.getGlobalBounds();
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

void Enemy::setPosition(float posX, float posY)
{
	this->enemySprite.setPosition(posX, posY);
}

const int& Enemy::getPoints() const
{
	return this->points;
}

void Enemy::update()
{
	this->enemySprite.move(0.f, this->speed);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->enemySprite);
}
