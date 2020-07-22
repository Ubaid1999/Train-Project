#pragma once
#include <SFML\Graphics.hpp>
class Animation
{
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage; 

	float totalTime;
	float switchTime;


public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount , float switchTime);

	sf::IntRect uvRect;

	void Update(int row, float deltaTime);

	~Animation();
};

