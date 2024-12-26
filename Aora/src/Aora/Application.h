#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Aora {

	class AORA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> AoraWindow;
		bool bRunning = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}