#pragma once
#include <SFML/System/Vector2.hpp>
#include <random>
#include <vector>

namespace Food
{
	enum class FoodType;
	class FoodItem;

	class FoodService
	{
	private:
		FoodItem* current_food_item;

		float cell_width;
		float cell_height;

		// To generate random values.
		std::default_random_engine random_engine;

		// To give random seed to generator.
		std::random_device random_device;


		sf::Vector2i getRandomPosition();

		bool isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);

		sf::Vector2i getValidSpawnPosition();

		FoodType getRandomFoodType();
		FoodItem* createFood(sf::Vector2i position, FoodType type);
		void spawnFood();

		void destroyFood();

	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();
	};
}