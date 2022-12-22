#pragma once
#include <Windows.h>

/*
===========================================================
                     FILE DESCRIPTION                     |
===========================================================
File: Ray-tracer.cpp                                       |
Date created : 11/30/2022                                 |
Creator : Neyko Naydenov                                  |
Description : Declaration of the Window Class             |
===========================================================
*/



class Window
{
public:
        Window();
        //to avoid copying the window object!
        Window(const Window&) = delete;
        Window& operator =  (const Window&) = delete;      
       ~Window();
       bool ProcessMessages();
       bool isRunning;
private:
    HINSTANCE m_hInstance;
    static LRESULT CALLBACK WinProc(HWND Win, UINT Message, WPARAM WParam, LPARAM LParam);
    HWND m_hwnd;
    const int winWidth = 1280;
    const int winHeight = 720;
    
};