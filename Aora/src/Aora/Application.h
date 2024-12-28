#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Aora/Events/ApplicationEvent.h"

#include "Window.h"

namespace Aora {

	class AORA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> AoraWindow;
		bool bRunning = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}