#pragma once
namespace Level
{
	class LevelController {
    private:
        

        
        void destroy();

    public:
        LevelController();
        ~LevelController();

        void initialize();
        void update();
        void render();
	};
}