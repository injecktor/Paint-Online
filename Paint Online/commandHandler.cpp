#include "commandHandler.h"

LRESULT CALLBACK CommandHandler(WPARAM wp)
{
    switch (wp)
    {
    case 1: {
        MessageBeep(MB_OK);
    } break;
    }
}