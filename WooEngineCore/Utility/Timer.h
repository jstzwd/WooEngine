#pragma once

#include <Windows.h>

namespace Woo {
	namespace Utility {
		class Timer {
		private:
			LARGE_INTEGER m_startTime;
			unsigned _int64 m_frequency;
		public:
			Timer();
			void ResetTimer();
			double ElapsedTime();
		};

	}

}
