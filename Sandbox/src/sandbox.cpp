#include <lucent.h>

// Sandbox application class
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

// Factory function to create the application
lucent::application* lucent::createApp()
{
	return new Sandbox();
}