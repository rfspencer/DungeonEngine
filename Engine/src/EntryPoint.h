// Copyright (c) 2024 Rich Spencer. All rights reserved.

/**
 * @brief The entry point of the application.
 *
 * This function is the main entry point of the application.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 *
 * @return The exit code of the application.
 */
int main(int argc, char** argv)
{
    Application* App = GetApplication();
    App->Run();

    delete App;

    std::cin.get();
    return 0;
}