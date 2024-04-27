#include "menu.h"

void AddMenus(HWND hWnd)
{
    hMenu = CreateMenu();

    AppendMenuW(hMenu, MF_STRING, 1, L"File");
    AppendMenuW(hMenu, MF_STRING, 0, L"Help");

    SetMenu(hWnd, hMenu);
}