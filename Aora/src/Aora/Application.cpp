#include "aopch.h"
#include "Application.h"

#include "Aora/Events/ApplicationEvent.h"
#include "Aora/Log.h"
#include <vulkan/vulkan.h>
#include <iostream>

namespace Aora {

	Application::Application()
	{
		AoraWindow = std::unique_ptr<Window>(Window::Create());
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (bRunning)
		{
			AoraWindow->OnUpdate();
		}
	}
}