#include "Window.hpp"
/*
=======================================
           FILE DESCRIPTION           |
=======================================
File: Raytracer.cpp                   |
Date created : 11/30/2022             |
Creator : Neyko Naydenov              |
=======================================
*/





int CALLBACK WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    const auto win = new Window();
    while (win->isRunning)
    {
        if (!win->ProcessMessages())
        {
            OutputDebugStringA("Closing Window...\n");
            win->isRunning = false;
        }
    }
}
