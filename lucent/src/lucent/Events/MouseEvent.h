#pragma once

#include "Event.h"

namespace lucent 
{
	class mouseEvent : public Event
	{
		public:
			mouseEvent(float x, float y)
				: mouseX(x), mouseY(y) {}
			inline float getX() const { return mouseX; }
			inline float getY() const { return mouseY; }
			std::string toString() const override
			{
				return std::string(getName()) + ": " + std::to_string(mouseX) + ", " + std::to_string(mouseY);
			}
			EVENT_CLASS_TYPE(mouseMoved)
			EVENT_CLASS_CATEGORY(eventCategoryMouse | eventCategoryInput)
		private:
			float mouseX, mouseY;
	};
	// TODO: Add more mouse event types (e.g., mouseScrolled, mouseButtonPressed, mouseButtonReleased)
}