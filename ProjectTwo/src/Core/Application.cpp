#include "Application.h"

#include <iostream>
#include <ostream>

Application::Application()
{
    std::cout << "Application Constructed" << std::endl;
}

Application::~Application()
{
    std::cout << "Application Destroyed" << std::endl;
}

void Application::Run()
{
    std::cout << "Application Running" << std::endl;
}


