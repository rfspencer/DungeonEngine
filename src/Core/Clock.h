/**
* @file Clock.h
 * @brief Header for the Clock class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

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