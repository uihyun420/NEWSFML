#pragma once
#include "Scene.h"

class SceneGame : public Scene
{
protected:

public:
	SceneGame();
	~SceneGame() override;

	void Init() override;

	void Enter() override;
	void Exit() override;
};

