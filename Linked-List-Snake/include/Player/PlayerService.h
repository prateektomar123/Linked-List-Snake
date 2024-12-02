#pragma once

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
		std::vector<sf::Vector2i> getCurrentSnakePositionList();
	};
}