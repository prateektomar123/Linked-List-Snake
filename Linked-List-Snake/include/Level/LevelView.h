#pragma once
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shader.hpp>

namespace Level
{
	class LevelView {
    private:
       
        const sf::Color background_color = sf::Color(180, 200, 160);
        

        UI::UIElement::RectangleShapeView* background_rectangle;

        sf::Color border_color = sf::Color::Black;

        float grid_width;
        float grid_height;

        void createLevelController();
        void calculateGridExtents();
        void destroy();

    public:
        LevelView();
        ~LevelView();

        static const int border_thickness = 10;
        static const int border_offset_left = 40;
        static const int border_offset_top = 40;

        void initialize();
        void initializeBackground();
        void initializeBorder();
        void update();
        void render();

        float getGridWidth();
        float getGridHeight();
	};
}