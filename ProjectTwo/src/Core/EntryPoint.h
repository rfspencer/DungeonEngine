
int main(int argc, char** argv)
{
    Application* App = GetApplication();
    App->Run();

    delete App;

    std::cin.get();
    return 0;
}