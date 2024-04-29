#include "windowProcedure.h"

PAINTSTRUCT ps;
RECT rect;
HBRUSH brush;

RECT penRestrict;

RECT rect1;
HBRUSH brush1;

RECT clientRect;

int penWidth = 10;

LRESULT CALLBACK MainWindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    static bool isDrawing = false;
    static int penRadius = penWidth - penWidth / 2;
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

        penRestrict = rect;
        penRestrict.left += penRadius;
        penRestrict.top += penRadius;
        penRestrict.right -= penRadius - 1;
        penRestrict.bottom -= penRadius - 1;

        GetClientRect(hWnd, &clientRect);

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

        if (PtInRect(&penRestrict, cursorPos)) {
            SetCursor(LoadCursorW(NULL, IDC_CROSS));
            if (isDrawing) {
                rect1 = CreateRect(cursorPos.x - penWidth / 2, cursorPos.y - penWidth / 2, penWidth, penWidth);
                brush1 = CreateSolidBrush(RGB(0, 0, 0));
                RedrawWindow(hWnd, NULL, NULL, RDW_UPDATENOW | RDW_INVALIDATE);
            }
        }
        else {
            SetCursor(LoadCursorW(NULL, IDC_ARROW));
        }

        break;
    case WM_LBUTTONDOWN:
        isDrawing = true;
        break;
    case WM_LBUTTONUP:
        if (isDrawing) {
            isDrawing = false;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, msg, wp, lp);
    }
}