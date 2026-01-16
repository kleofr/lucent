#pragma once

#include "Event.h"

namespace lucent
{
	 class windowResizeEvent : public Event
	 {
		public:
			windowResizeEvent(unsigned int width, unsigned int height)
				: m_width(width), m_height(height) {}
			inline unsigned int getWidth() const { return m_width; }
			inline unsigned int getHeight() const { return m_height; }
			std::string toString() const override
			{
				return std::string(getName()) + ": " + std::to_string(m_width) + ", " + std::to_string(m_height);
			}

			EVENT_CLASS_TYPE(windowResize)
			EVENT_CLASS_CATEGORY(eventCategoryApplication)
		private:
			unsigned int m_width, m_height;
	 };

	 class windowCloseEvent : public Event
	 {
		 public:
			windowCloseEvent() = default;
			EVENT_CLASS_TYPE(windowClose)
			EVENT_CLASS_CATEGORY(eventCategoryApplication)
	 };

	 class appTickEvent : public Event
	 {
		 public:
			 appTickEvent() = default;
			 EVENT_CLASS_TYPE(appTick)
			 EVENT_CLASS_CATEGORY(eventCategoryApplication)
	 };

	 class appUpdateEvent : public Event
	 {
		 public:
			 appUpdateEvent() = default;
			 EVENT_CLASS_TYPE(appUpdate)
			 EVENT_CLASS_CATEGORY(eventCategoryApplication)
	 };

	 class appRenderEvent : public Event
	 {
		 public:
			 appRenderEvent() = default;
			 EVENT_CLASS_TYPE(appRender)
			 EVENT_CLASS_CATEGORY(eventCategoryApplication)
	 };
}