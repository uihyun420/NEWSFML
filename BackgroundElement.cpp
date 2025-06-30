 #include "stdafx.h"
#include "BackgroundElement.h"

BackgroundElement::BackgroundElement(const std::string& texId, const std::string& name)
	: SpriteGo(texId, name)
{
}

void BackgroundElement::SetSide(Sides side)
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	switch (side)
	{
	case Sides::Left:
		direction = { 1.f, 0.f };
		SetScale({ 1.f,0.f });
		SetPosition({ -150.f,0.f });
		break;	

	case Sides::Right:
		direction = { -1.f, 0.f };
		SetScale({ 1.f,0.f });
		SetPosition({ bounds.width+150.f,0.f });
		break;
	}
	speed = 200.f;

}

void BackgroundElement::Reset()
{
	SpriteGo::Reset();

	//SetOrigin(Origins::MC);
	//SetSide(Sides::Right);
	//SetPosition({ 500.f,0.f });
	Sides side = (Utils::RandomValue() < 0.5f) ? Sides::Left : Sides::Right;
	SetSide(side);

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	// 랜덤 Y 위치 (상하 여유 50px)
	float minY = 50.f;
	float maxY = bounds.height - 50.f;
	float randY = Utils::RandomRange(minY, maxY);
	SetPosition({ GetPosition().x, randY });

	// 랜덤 속도
	speed = Utils::RandomRange(100.f, 300.f);

	// 랜덤 스케일
	float scale = Utils::RandomRange(0.5f, 1.2f);
	SetScale({ scale, scale });
}

void BackgroundElement::Update(float dt)
{
	sf::Vector2f pos = GetPosition();
	pos += direction * speed * dt;
	SetPosition(pos);

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	if (pos.x < -200.f || pos.x > bounds.width + 200.f)
	{
		Reset();  
	}
}

