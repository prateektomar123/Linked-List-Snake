#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>

class PlayerController;
enum class TimeComplexity;

class PlayerService
{
private:
	PlayerController* player_controller;

	void createController();
	void destroy();

public:
	PlayerService();
	~PlayerService();

	void initialize();
	void update();
	void render();

	void spawnPlayer();
	std::vector<sf::Vector2i> getCurrentPlayerPositionList();

	int getPlayerScore();
	TimeComplexity getTimeComplexity();
};