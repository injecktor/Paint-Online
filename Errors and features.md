# Errors and features

This file consists of encountered problems and future features.

## Encountered problems


|Bug|Cause|Possible solution|
|---|---|---|
|Keep drawing if leftmouseup outside a window| **isDrawing** don't set **false** while outside a window |Can be fixed by WM_MOUSELEAVE|
|Dot-like drawing|Refresh rate isn't high enough|Draw lines between last two shots of pen|
|Limit of draw object|||
|If window hides outside the screen and pulling out then it's redraw only last object| Redraw message redrawing only last object||

## Future features