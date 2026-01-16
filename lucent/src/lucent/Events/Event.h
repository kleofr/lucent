#pragma once

#include "../core.h"

#include <string>

namespace lucent {


	// Event types
	enum class eventType
	{
		// Add if needed in future windowFocus, windowLostFocus, windowMoved

		none = 0,
		windowClose, windowResize, appTick, appUpdate, appRender,
		keyPressed, keyReleased, keyTyped,
		mouseButtonPressed, mouseButtonReleased, mouseMoved, mouseScrolled
	};


	// Event categories
	enum eventCategory
	{
		none = 0,
		eventCategoryApplication = BIT(0),
		eventCategoryInput = BIT(1),
		eventCategoryKeyboard = BIT(2),
		eventCategoryMouse = BIT(3),
		eventCategoryMouseButton = BIT(4)
	};


	// Macros for event classes
	#define EVENT_CLASS_TYPE(type) static eventType getStaticType() { return eventType::type; }\
									virtual eventType getEventType() const override { return getStaticType(); }\
									virtual const char* getName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }


	// Base event class
	class LCNT_API Event
	{
		friend class eventDispatcher;

	public:
		virtual eventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); }

		inline bool isInCategory(eventCategory category)
		{
			return getCategoryFlags() & category;
		}
	protected:
		bool handled = false;
	};


	// Event dispatcher class
	class eventDispatcher
	{
		template<typename T> using EventFn = std::function<bool(T&)>;

	public:
		eventDispatcher(Event& event)
			: m_Event(event)
		{
		}
		template<typename T>
		bool dispatch(EventFn<T> func)
		{
			if (m_Event.getEventType() == T::getStaticType())
			{
				m_Event.handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

} // namespace lucent
