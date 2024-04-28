#include "commandHandler.h"

LRESULT CALLBACK CommandHandler(HWND hWnd, WPARAM wp)
{
    switch (wp)
    {
    case MenuFileProcedures::Exit: {
        DestroyWindow(hWnd);
    } break;
    }
    return 0;
}