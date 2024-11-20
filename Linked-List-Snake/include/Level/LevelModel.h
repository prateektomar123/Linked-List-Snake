#pragma once
namespace Level
{
	class LevelModel {
    private:
       
        void destroy();

    public:
        LevelModel();
        ~LevelModel();

        void initialize();
        void update();
        void render();
	};
}