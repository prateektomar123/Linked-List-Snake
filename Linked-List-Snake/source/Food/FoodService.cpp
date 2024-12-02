#include "Food/FoodService.h"
#include "Global/ServiceLocator.h"
#include "Food/FoodItem.h"
#include "Level/LevelModel.h"
#include "Player/PlayerService.h"

namespace Food
{
	using namespace Time;
	using namespace Global;
	using namespace Level;
	using namespace Player;

	FoodService::FoodService()
	{
		current_food_item = nullptr;
	}

	FoodService::~FoodService()
	{
		destroyFood();
	}

	void FoodService::initialize()
	{
		//Yet to implement
	}

	void FoodService::update()
	{
		if (current_food_item) current_food_item->update();
	}

	FoodService::FoodService() : random_engine(random_device())
	{
		current_food_item = nullptr;
	}
	sf::Vector2i FoodService::getRandomPosition()
	{
		// Coordinate distribution for selecting a random position for food
		std::uniform_int_distribution<int> x_distribution(0, LevelModel::number_of_columns - 1);
		std::uniform_int_distribution<int> y_distribution(0, LevelModel::number_of_rows - 1);

		int x_position = x_distribution(random_engine);
		int y_position = y_distribution(random_engine);

		return sf::Vector2i(x_position, y_position);
	}
	bool FoodService::isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position)
	{
		for (int i = 0; i < position_data.size(); i++)
		{
			if (food_position == position_data[i]) return false;
		}
		return true;
	}

	sf::Vector2i FoodService::getValidSpawnPosition()
	{
		std::vector<sf::Vector2i> player_position_data = ServiceLocator::getInstance()->getPlayerService()->getCurrentSnakePositionList();
		std::vector<sf::Vector2i> elements_position_data = ServiceLocator::getInstance()->getElementService()->getElementsPositionList();
		sf::Vector2i spawn_position;

		do spawn_position = getRandomPosition();
		while (!isValidPosition(player_position_data, spawn_position) || !isValidPosition(elements_position_data, spawn_position));

		return spawn_position;
	}

	void FoodService::render()
	{
		if (current_food_item) current_food_item->render();
	}

	FoodType FoodService::getRandomFoodType()
	{
		std::uniform_int_distribution<int> distribution(0, FoodItem::number_of_foods - 1);
		return static_cast<FoodType>(distribution(random_engine));
	}

	void FoodService::spawnFood()
	{
		current_food_item = createFood(getValidSpawnPosition(), getRandomFoodType());
	}
	void FoodService::startFoodSpawning()
	{
		cell_width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		cell_height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();
		spawnFood();
	}

	FoodItem* FoodService::createFood(sf::Vector2i position, FoodType type)
	{
		FoodItem* food = new FoodItem();
		food->initialize(position, cell_width, cell_height, type);
		return food;
	}

	void FoodService::spawnFood()
	{
		current_food_item = createFood(sf::Vector2i(4, 6), FoodType::BURGER);
	}

	void FoodService::destroyFood()
	{
		if (current_food_item) delete(current_food_item);
	}
}