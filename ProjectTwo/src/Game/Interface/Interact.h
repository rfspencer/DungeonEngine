#pragma once

class Interact
{
public:
    Interact() {}
    virtual ~Interact() {}
    
    virtual void OnInteract() = 0;
};
