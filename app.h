#pragma once
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include <d3d9.h>
#include <memory>
#include <tchar.h>

class app
{
private:
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    HWND hwnd;
    WNDCLASSEXW wc;
public:
    app();
    void update();
    void run();
    virtual ~app();
};

