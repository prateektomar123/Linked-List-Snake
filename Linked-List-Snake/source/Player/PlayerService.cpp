#include "Player/PlayerService.h"
#include "Player/SnakeController.h"

namespace Player
{
	PlayerService::PlayerService()
	{
		snake_controller = nullptr;

		createController();
	}

	PlayerService::~PlayerService()
	{
		destroy();
	}

	void PlayerService::createController()
	{
		snake_controller = new SnakeController();
	}

	void PlayerService::initialize()
	{
		snake_controller->initialize();
	}

	void PlayerService::update()
	{
		snake_controller->update();
	}

	void PlayerService::render()
	{
		snake_controller->render();
	}

	void PlayerService::spawnPlayer()
	{
		snake_controller->spawnSnake();
	}

	std::vector<sf::Vector2i> PlayerService::getCurrentSnakePositionList()
	{
		return snake_controller->getCurrentSnakePositionList();
	}

	int PlayerService::getSnakeSize()
	{
		return snake_controller->getSnakeSize();
	}

	int PlayerService::getPlayerScore()
	{
		return snake_controller->getPlayerScore();
	}

	TimeComplexity PlayerService::getTimeComplexity()
	{
		return snake_controller->getTimeComplexity();
	}

	LinkedListOperations PlayerService::getLastOperation()
	{
		return snake_controller->getLastOperation();
	}

	SnakeState PlayerService::getSnakeState()
	{
		return snake_controller->getSnakeState();
	}

	bool PlayerService::isSnakeSizeMinimum()
	{
		return snake_controller->isSnakeSizeMinimum();
	}

	void PlayerService::destroy()
	{
		delete (snake_controller);
	}
}