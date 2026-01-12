#pragma once
#include "core.h"

namespace lucent
{
	class LCNT_API application
	{
	public:
		application();
		virtual ~application();

		void run();

		
	};
	// to be defined in CLIENT
	application* createApp();
}


