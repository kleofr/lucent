#include <lucent.h>

class Sandbox : public lucent::application
{
public:
	Sandbox()
	{
	
	}
	~Sandbox()
	{
	
	}
};


lucent::application* lucent::createApp()
{
	return new Sandbox();
}