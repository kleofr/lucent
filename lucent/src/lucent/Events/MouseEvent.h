#pragma once

#include "Event.h"

namespace lucent 
{
	class mouseButtonEvent : public Event
	{
	protected:
		int m_keycode;
	};
}