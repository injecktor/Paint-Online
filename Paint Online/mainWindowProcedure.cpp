#include "mainWindowProcedure.h"

PAINTSTRUCT ps;

RECT rect;
HBRUSH brush;

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_CREATE:
        AddMenus(hWnd);
        MainAddWidgets(hWnd);
        RedrawWindow(hWnd, NULL, NULL, RDW_UPDATENOW | RDW_VALIDATE);
        break;
    case WM_COMMAND:
        CommandHandler(hWnd, wp);
        break;
    case WM_PAINT:

        brush = CreateSolidBrush(RGB(255, 255, 255));
        rect = CreateRect(100, 100, 900, 500);

        BeginPaint(hWnd, &ps);

        FillRect(ps.hdc, &rect, brush);

        EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, msg, wp, lp);
    }
}