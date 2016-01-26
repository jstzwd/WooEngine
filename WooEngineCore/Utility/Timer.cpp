#include "Timer.h"

namespace Woo {
	namespace Utility {
		Timer::Timer()
		{
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			m_frequency = frequency.QuadPart;
			QueryPerformanceCounter(&m_startTime);
		}

		void Timer::ResetTimer() 
		{
			QueryPerformanceCounter(&m_startTime);
		}

		double Timer::ElapsedTime()
		{
			LARGE_INTEGER currentTime;
			QueryPerformanceCounter(&currentTime);
			unsigned _int64 interval = currentTime.QuadPart - m_startTime.QuadPart;
			return (double)((double)interval / (double)m_frequency);

		}

	}
}