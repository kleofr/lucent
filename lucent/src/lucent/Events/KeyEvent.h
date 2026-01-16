#pragma once

#include "Event.h"

namespace lucent {

	class keyEvent : public Event
	{
		public:
			inline int getKeyCode() const { return keyCode; }
			EVENT_CLASS_CATEGORY(eventCategoryKeyboard | eventCategoryInput)
		protected:
			keyEvent(int keycode)
				: keyCode(keycode) {}
			int keyCode;
	};

	class keyPressedEvent : public keyEvent
	{
		public:
			keyPressedEvent(int keycode, int repeatCount)
				: keyEvent(keycode), repeatCount(repeatCount) {}
			inline int getRepeatCount() const { return repeatCount; }
			std::string toString() const override
			{
				return std::string(getName()) + ": " + std::to_string(keyCode) + " (" + std::to_string(repeatCount) + " repeats)";
			}
			EVENT_CLASS_TYPE(keyPressed)
		private:
			int repeatCount;
	};

	class keyReleasedEvent : public keyEvent
	{
		public:
			keyReleasedEvent(int keycode)
				: keyEvent(keycode) {}
			std::string toString() const override
			{
				return std::string(getName()) + ": " +  std::to_string(keyCode);
			}
			EVENT_CLASS_TYPE(keyReleased)
	};

}