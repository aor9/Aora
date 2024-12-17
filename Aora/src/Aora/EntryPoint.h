#pragma once

#ifdef AO_PLATFORM_WINDOWS

extern Aora::Application* Aora::CreateApplication();

int main(int argc, char** argv)
{
	Aora::Log::Init();
	AO_CORE_WARN("Initialized Log!");
	int a = 5;
	AO_INFO("Hello! Var={0}", a);

	auto app = Aora::CreateApplication();
	app->Run();
	delete app;
}

#endif	