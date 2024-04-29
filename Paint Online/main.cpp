#include "main.h"

#define WINDOW_WIDTH 780
#define WINDOW_HEIGHT 600
#define WINDOW_START_X 350
#define WINDOW_START_Y 150

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS wnd{ 0 };
    wnd.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wnd.hInstance = hInstance;
    wnd.lpszClassName = L"MainWindow";
    wnd.lpfnWndProc = MainWindowProcedure;
    
    if (!RegisterClassW(&wnd)) {
        return GetLastError();
    }

    HWND mainWindow = CreateWindowW(L"MainWindow", L"Paint Online", WS_OVERLAPPEDWINDOW | WS_VISIBLE, WINDOW_START_X, WINDOW_START_Y, 
        WINDOW_START_X + WINDOW_WIDTH, WINDOW_START_Y + WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

    if (!mainWindow) {
        return GetLastError();
    }

    MSG msg = { 0 };
    while (GetMessageW(&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return 0;
}

