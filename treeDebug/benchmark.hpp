#pragma once

#include<iostream>
#include<chrono>
class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock>m_StartPoint ;
    void stop()
    {
        auto m_EndPoint = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartPoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(m_EndPoint).time_since_epoch().count();
        auto duration = end - start;   
        double ms = duration*0.001;
        std::cout<<"duration : "<<duration<<" ( "<<ms<<" ms)"<<std::endl;
    }
public:
    Timer()
    {
        m_StartPoint = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        stop();
    }
};