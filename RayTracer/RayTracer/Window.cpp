#include "Window.hpp"


/*
===========================================================
                     FILE DESCRIPTION                     |
===========================================================
File: Raytracer.cpp                                       |
Date created : 11/30/2022                                 |
Creator : Neyko Naydenov                                  |
Description : Implementation of the Window Class          |
===========================================================
*/

LRESULT CALLBACK Window::WinProc(HWND Win, UINT Message, WPARAM WParam, LPARAM LParam)
{
    LRESULT result = 0;
    switch (Message)
    {
    case WM_CLOSE:
    {
        DestroyWindow(Win);
    }
    break;
    case WM_DESTROY:
    {
        PostQuitMessage(0);
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT paint;
       const HDC deviceContext = BeginPaint(Win, &paint);
       const int x = paint.rcPaint.left;
       const int y = paint.rcPaint.top;
       const int height = paint.rcPaint.bottom - paint.rcPaint.top;
       const int width = paint.rcPaint.right - paint.rcPaint.left;
       PatBlt(deviceContext, x, y, width, height, BLACKNESS);
       EndPaint(Win, &paint);

    }
    break;
    default: result = DefWindowProcW(Win, Message, WParam, LParam);
    }
    return result;
}

Window::Window() : isRunning(true),
                   m_hInstance(GetModuleHandle(nullptr))
{
    const wchar_t* CLASS_NAME = L"RayTracer";
    WNDCLASS winClass = { };
    winClass.lpszClassName = CLASS_NAME;
    winClass.hInstance = m_hInstance;
    winClass.lpfnWndProc = WinProc;

    RegisterClass(&winClass);

   constexpr DWORD style = WS_OVERLAPPEDWINDOW;
    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + winWidth;
    rect.bottom = rect.top + winHeight;


    AdjustWindowRect(&rect, style, false);

    m_hwnd = CreateWindowEx(0, 
                             CLASS_NAME, 
                             L"Tracer",
                             style, 
                             rect.left, 
                             rect.top, 
                             rect.right - rect.left, 
                             rect.top - rect.bottom, 
                             nullptr, 
                             nullptr, 
                             m_hInstance,
                             nullptr
    );
    if (m_hwnd == nullptr)
    {
        OutputDebugStringA("Failed initialization");
    }
    else 
    {
        ShowWindow(m_hwnd, SW_SHOW);
    }
}

Window::~Window()
{
    const wchar_t* CLASS_NAME = L"RayTracer";

    UnregisterClass(CLASS_NAME, m_hInstance);
}

bool Window::ProcessMessages()
{
    MSG msg = {};
    while (PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
        {
            return false;
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return true;
}