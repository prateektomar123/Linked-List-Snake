#pragma once
namespace Level
{
	class LevelData {
    private:
       
        void destroy();

    public:
        LevelData();
        ~LevelData();

        void initialize();
        void update();
        void render();
	};
}