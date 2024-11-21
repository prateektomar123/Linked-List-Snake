#include "Global/ServiceLocator.h"
#include "Main/GameService.h"

namespace Global
{
	using namespace Graphics;
	using namespace Event;
	using namespace Sound;
	using namespace Level;
	using namespace UI;
	using namespace Main;
	using namespace Time;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		sound_service = nullptr;
		level_service = nullptr;
		ui_service = nullptr;
		time_service = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator() { clearAllServices(); }

	void ServiceLocator::createServices()
	{
		event_service = new EventService();
		graphic_service = new GraphicService();
		sound_service = new SoundService();
		level_service = new LevelService();
		ui_service = new UIService();
		time_service = new TimeService();
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		sound_service->initialize();
		event_service->initialize();
		level_service->initialize();
		ui_service->initialize();
		time_service->initialize();
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();

		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			level_service->update();
		}

		ui_service->update();
		time_service->update();
	}

	void ServiceLocator::render()
	{
		graphic_service->render();

		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			level_service->render();
		}

		ui_service->render();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(ui_service);
		delete(level_service);
		delete(graphic_service);
		delete(sound_service);
		delete(event_service);
		delete(time_service);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	EventService* ServiceLocator::getEventService() { return event_service; }

	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

	SoundService* ServiceLocator::getSoundService() { return sound_service; }

	Level::LevelService* ServiceLocator::getLevelService() { return level_service; }

	UIService* ServiceLocator::getUIService() { return ui_service; }

	Time::TimeService* ServiceLocator::getTimeService() { return time_service; }

	void ServiceLocator::deleteServiceLocator() { delete(this); }
}