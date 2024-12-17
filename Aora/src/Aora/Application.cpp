#include "aopch.h"
#include "Application.h"

#include "Aora/Events/ApplicationEvent.h"
#include "Aora/Log.h"

namespace Aora {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			AO_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			AO_TRACE(e);
		}

		while (true);
	}
}