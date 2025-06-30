#pragma once
#include "GameObject.h"
class Bee :
    public GameObject
{
protected:
	sf::Sprite bee;	
	std::string texIdBee;
	float speed = 0.f;
	sf::Vector2f direction;

public:
	Bee() = default;
	~Bee() override = default;

	void SetPosition(const sf::Vector2f& pos) override;
	
	void SetSide(Sides side);

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

