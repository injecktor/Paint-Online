#include "menu.h"

HMENU hMenu;

void AddMenus(HWND hWnd)
{
    hMenu = CreateMenu();
    HMENU hMenuFile = CreateMenu();
    HMENU hMenuFileSub = CreateMenu();

    AppendMenuW(hMenuFileSub, MF_STRING, NULL, L"Hello");

    AppendMenuW(hMenuFile, MF_STRING, MenuFileProcedures::New, L"New");
    AppendMenuW(hMenuFile, MF_POPUP, (UINT_PTR)hMenuFileSub, L"Open");
    AppendMenuW(hMenuFile, MF_SEPARATOR, NULL, NULL);
    AppendMenuW(hMenuFile, MF_STRING, MenuFileProcedures::Exit, L"Exit");

    AppendMenuW(hMenu, MF_POPUP, (UINT_PTR)hMenuFile, L"File");
    AppendMenuW(hMenu, MF_STRING, 0, L"Help");

    SetMenu(hWnd, hMenu);
}