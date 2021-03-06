#pragma once

#define NOMINMAX

#include <string>
#include <Windows.h>
#include <eseed/math/types.hpp>
#include <eseed/math/vec.hpp>
#include "window.hpp"

namespace esd::graphics {

class WindowWin32 : public Window {
public:
    WindowWin32(esdm::Vec2<I32> size, std::string title);

    ~WindowWin32();
    
    void poll() override;

    bool isCloseRequested() override;

    void update() override;

    std::vector<const char*> getRequiredInstanceExtensionNames() override;

    vk::SurfaceKHR createSurface(vk::Instance instance) override;

    esdm::Vec2<I32> getSize() override;

private:
    HINSTANCE hInstance;
    WNDCLASS wc;
    HWND hWnd;
    bool closeRequested = false;

    static LRESULT CALLBACK windowProc(
        HWND hWnd, 
        UINT uMsg, 
        WPARAM wParam, 
        LPARAM lParam
    );
};

}