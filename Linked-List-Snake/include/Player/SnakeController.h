#pragma once
namespace Player
{
	class SnakeController
	{

	private:
		void Destroy();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();
	};

	

}