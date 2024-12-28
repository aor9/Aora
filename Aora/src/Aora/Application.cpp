#include "aopch.h"
#include "Application.h"
#include "Aora/Log.h"

#include <GLFW/glfw3.h>

namespace Aora {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		AoraWindow = std::unique_ptr<Window>(Window::Create());
		AoraWindow->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}


	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		AO_CORE_TRACE("{0}", e);
	}

	void Application::Run()
	{
		while (bRunning)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			AoraWindow->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		bRunning = false;

		return true;
	}
}