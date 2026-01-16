#pragma once

#include "Event.h"

namespace lucent {

	class keyEvent : public Event
	{
		public:
			inline int getKeyCode() const { return m_keyCode; }
			EVENT_CLASS_CATEGORY(eventCategoryKeyboard | eventCategoryInput)
		protected:
			keyEvent(int keycode)
				: m_keyCode(keycode) {}
			int m_keyCode;
	};

	class keyPressedEvent : public keyEvent
	{
		public:
			keyPressedEvent(int keycode, int repeatCount)
				: keyEvent(keycode), m_repeatCount(repeatCount) {}
			inline int getRepeatCount() const { return m_repeatCount; }
			std::string toString() const override
			{
				return std::string(getName()) + ": " + std::to_string(m_keyCode) + " (" + std::to_string(m_repeatCount) + " repeats)";
			}
			EVENT_CLASS_TYPE(keyPressed)
		private:
			int m_repeatCount;
	};

	class keyReleasedEvent : public keyEvent
	{
		public:
			keyReleasedEvent(int keycode)
				: keyEvent(keycode) {}
			std::string toString() const override
			{
				return std::string(getName()) + ": " +  std::to_string(m_keyCode);
			}
			EVENT_CLASS_TYPE(keyReleased)
	};

	class keyTypedEvent : public keyEvent
	{
	public:
		keyTypedEvent(int keycode)
			: keyEvent(keycode) {}

		std::string toString() const override 
		{
			return std::string(getName()) + ": " + std::to_string(m_keyCode);
		}
	};

}