#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "UI/UIElement/ImageView.h"
#include "Direction.h"

namespace Player 
{
	
	class BodyPart
	{
	protected:
		UI::UIElement::ImageView* bodypart_image;

		sf::Vector2i grid_position;
		Direction direction;

		float bodypart_width;
		float bodypart_height;

		sf::Vector2f getBodyPartScreenPosition();

		float getRotationAngle();

		void createBodyPartImage();
		void initializeBodyPartImage();

		sf::Vector2i getNextPositionDown();

		sf::Vector2i getNextPositionUp();
		sf::Vector2i getNextPositionRight();
		sf::Vector2i getNextPositionLeft();
		sf::Vector2i getNextPosition();

		void destroy();

	public:
		BodyPart();
		~BodyPart();

		void initialize(float width, float height, sf::Vector2i pos, Direction dir);
		void updatePosition();
		void render();

		Direction getDirection();
		sf::Vector2i getPosition();
		void setDirection(Direction new_direction);

		void setPosition(sf::Vector2i position);
	};
}