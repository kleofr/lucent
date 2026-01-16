#pragma once

#include "Event.h"

namespace lucent {
	class applicationEvent : public Event
	{
		public:
		EVENT_CLASS_CATEGORY(eventCategoryApplication)
	};

	class appTickEvent : public applicationEvent
	{
		public:
			appTickEvent() = default;
			EVENT_CLASS_TYPE(appTick)
	};

	class appUpdateEvent : public applicationEvent
	{
		public:
			appUpdateEvent() = default;
			EVENT_CLASS_TYPE(appUpdate)
	};

	class appRenderEvent : public applicationEvent
	{
		public:
			appRenderEvent() = default;
			EVENT_CLASS_TYPE(appRender)
	};
}