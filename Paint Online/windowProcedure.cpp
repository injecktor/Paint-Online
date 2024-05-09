#include "windowProcedure.h"

PAINTSTRUCT ps;
RECT canvasRect;
HBRUSH canvasBrush;

RECT penRestrict;

RECT drawRect;
HBRUSH drawBrush;

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
        canvasBrush = CreateSolidBrush(RGB(255, 255, 255));
        canvasRect = CreateRect( 100, 100, 900, 500 );
        drawRect = canvasRect;
        drawBrush = canvasBrush;

        RedrawWindow(hWnd, NULL, NULL, RDW_UPDATENOW | RDW_VALIDATE);

        penRestrict = canvasRect;
        penRestrict.left += penRadius;
        penRestrict.top += penRadius;
        penRestrict.right -= penRadius - 1;
        penRestrict.bottom -= penRadius - 1;

        break;
    case WM_COMMAND:
        CommandHandler(hWnd, wp);
        break;
    case WM_PAINT:
        RECT gradientRect = CreateRect(0, 0, 500, 100);
        CreateGradientRect(GetDC(hWnd), &gradientRect, { 255, 0, 0 }, { 0, 0, 255 });
        BeginPaint(hWnd, &ps);

        FillRect(ps.hdc, &drawRect, drawBrush);

        EndPaint(hWnd, &ps);
        break;
    case WM_MOUSEMOVE:
        POINT cursorPos;
        GetCursorPos(&cursorPos);
        ScreenToClient(hWnd, &cursorPos);

        if (PtInRect(&penRestrict, cursorPos)) {
            SetCursor(LoadCursorW(NULL, IDC_CROSS));
            if (isDrawing) {
                drawRect = CreateRect(cursorPos.x - penWidth / 2, cursorPos.y - penWidth / 2, penWidth, penWidth);
                drawBrush = CreateSolidBrush(RGB(0, 0, 0));
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