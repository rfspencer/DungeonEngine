// Copyright (c) 2024 Rich Spencer. All rights reserved.

#pragma once

#include <chrono>

/**
 * @class Clock
 * @brief Represents a high-resolution clock to measure time intervals.
 *
 * This class provides functionality to measure elapsed time and restart the clock.
 */
class Clock
{
public:
    Clock()
    {
        m_Time = Clock_T::now();
    }

    float GetElapsed() const
    {
        const std::chrono::duration<float> Elapsed = Clock_T::now() - m_Time;
        return Elapsed.count();
    }
    
    float Restart()
    {
        const float Elapsed = GetElapsed();
        m_Time = Clock_T::now();
        return Elapsed;
    }
    
private:
    using Clock_T = std::chrono::high_resolution_clock;
    using Time_T = std::chrono::time_point<Clock_T>;
    Time_T m_Time;
    
};