#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "Player/SnakeController.h"

namespace Player
{
	class SnakeController;

	class PlayerService
	{
	private:
		SnakeController* snake_controller;

		void createController();
		void destroy();

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void spawnPlayer();

		int getSnakeSize();
		int getPlayerScore();
		bool isSnakeSizeMinimum();
		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();
		SnakeState getSnakeState();
		std::vector<sf::Vector2i> getCurrentSnakePositionList();
	};
}