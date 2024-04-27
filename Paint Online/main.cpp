#include "main.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS wnd{ 0 };
    wnd.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd.hInstance = hInstance;
    wnd.lpszClassName = L"MainWindow";
    wnd.lpfnWndProc = WindowProcedure;
    
    if (!RegisterClassW(&wnd)) {
        return -1;
    }

    CreateWindowW(L"MainWindow", L"Paint Online", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 200, 200, 500, 500, NULL, NULL, hInstance, NULL);

    MSG msg = { 0 };
    while (GetMessageW(&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return 0;
}

