#include "stdafx.h"
#include "Utils.h"

sf::Vector2f Utils::SetOrigin(sf::Transformable& obj, Origins preset, const sf::FloatRect rect)
{
    sf::Vector2f newOrigin(rect.width, rect.height);
    newOrigin.x *= ((int)preset % 3) * 0.5f;
    newOrigin.y *= ((int)preset / 3) * 0.5f;
    obj.setOrigin(newOrigin);
    return newOrigin;
}

sf::Vector2f Utils::SetOrigin(sf::Shape& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}

sf::Vector2f Utils::SetOrigin(sf::Text& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}

sf::Vector2f Utils::SetOrigin(sf::Sprite& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}





void Utils::init()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// 0.0f~1.0f 사이 랜덤 실수
float Utils::RandomValue()
{
    return static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
}

// [min, maxExclude) 사이 랜덤 정수
int Utils::RandomRange(int min, int maxExclude)
{
    if (maxExclude <= min)
        return min;
    return min + (std::rand() % (maxExclude - min));
}

// [min, max) 사이 랜덤 실수
float Utils::RandomRange(float min, float max)
{
    if (max <= min)
        return min;
    return min + RandomValue() * (max - min);
}
