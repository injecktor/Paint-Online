#include "windowProcedure.h"

PAINTSTRUCT ps;
RECT rect;
HBRUSH brush;

RECT rect1;
HBRUSH brush1;

LRESULT CALLBACK MainWindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_CREATE:
        AddMenus(hWnd);
        MainAddWidgets(hWnd);
        brush = CreateSolidBrush(RGB(255, 255, 255));
        rect = CreateRect( 100, 100, 900, 500 );
        rect1 = rect;
        brush1 = brush;
        RedrawWindow(hWnd, NULL, NULL, RDW_UPDATENOW | RDW_VALIDATE);
        break;
    case WM_COMMAND:
        CommandHandler(hWnd, wp);
        break;
    case WM_PAINT:
        BeginPaint(hWnd, &ps);

        FillRect(ps.hdc, &rect1, brush1);

        EndPaint(hWnd, &ps);
        break;
    case WM_MOUSEMOVE:
        POINT cursorPos;
        GetCursorPos(&cursorPos);
        ScreenToClient(hWnd, &cursorPos);

        if (PtInRect(&rect, cursorPos)) {
            SetCursor(LoadCursorW(NULL, IDC_CROSS));
            rect1 = CreateRect(cursorPos.x - 1, cursorPos.y - 1, 3, 3);
            brush1 = CreateSolidBrush(RGB(0, 0, 0));
            RedrawWindow(hWnd, NULL, NULL, RDW_UPDATENOW | RDW_INVALIDATE);
        }
        else {
            SetCursor(LoadCursorW(NULL, IDC_ARROW));
        }

        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, msg, wp, lp);
    }
}