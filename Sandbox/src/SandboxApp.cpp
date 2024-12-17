#include <Aora.h>

class Sandbox : public Aora::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Aora::Application* Aora::CreateApplication()
{
	return new Sandbox();
}