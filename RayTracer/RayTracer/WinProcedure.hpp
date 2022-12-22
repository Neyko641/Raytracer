#pragma once
#include <windows.h>
class WinProcedure
{
    virtual LRESULT CALLBACK Procedure(HWND Win, UINT Message, WPARAM WParam, LPARAM LParam) = 0;

};

