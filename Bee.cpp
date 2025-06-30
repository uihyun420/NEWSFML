#include "stdafx.h"
#include "Bee.h"

void Bee::SetPosition(const sf::Vector2f& pos)
{
	bee.setPosition(pos);

}

void Bee::SetSide(Sides side)
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
		SetPosition({ bounds.width + 150.f,0.f });
		break;
	}
	speed = 200.f;
}

void Bee::Init()
{
	texIdBee = "graphics/Bee.png";
	bee.setTexture(TEXTURE_MGR.Get(texIdBee), true);
	Utils::SetOrigin(bee, Origins::ML);
}

void Bee::Release()
{
}

void Bee::Reset()
{
	//bee.setTexture(TEXTURE_MGR.Get(texIdBee), true);
	//Utils::SetOrigin(bee, Origins::ML);
	GameObject::Reset();

	//SetOrigin(Origins::MC);
	//SetSide(Sides::Right);
	//SetPosition({ 500.f,0.f });
	Sides side = (Utils::RandomValue() < 0.5f) ? Sides::Left : Sides::Right;
	SetSide(side);

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	// ���� Y ��ġ (���� ���� 50px)
	float minY = 50.f;
	float maxY = bounds.height - 50.f;
	float randY = Utils::RandomRange(minY, maxY);
	SetPosition({ GetPosition().x, randY });

	// ���� �ӵ�
	speed = Utils::RandomRange(100.f, 300.f);

	// ���� ������
	float scale = Utils::RandomRange(0.5f, 1.2f);
	SetScale({ scale, scale });

}

void Bee::Update(float dt)
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

void Bee::Draw(sf::RenderWindow& window)
{
	window.draw(bee);
}
