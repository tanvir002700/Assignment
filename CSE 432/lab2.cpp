
#include<graphics.h>
void drawLine(int x0, int y0, int x1, int y1)
{

    int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
    int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
    int err = (dx>dy ? dx : -dy)/2, e2;
    while(true)
    {
        putpixel(x0,y0,WHITE);
        if (x0==x1 && y0==y1) break;
        e2 = err;
        if (e2 >-dx)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y0 += sy;
        }
    }
}
void DrawCircle(int x0, int y0, int radius)
{
  int x = radius;
  int y = 0;
  int radiusError = 1-x;
  while(x >= y)
  {
    putpixel( x + x0,  y + y0,WHITE);
    putpixel( y + x0,  x + y0,WHITE);
    putpixel(-x + x0,  y + y0,WHITE);
    putpixel(-y + x0,  x + y0,WHITE);
    putpixel(-x + x0, -y + y0,WHITE);
    putpixel(-y + x0, -x + y0,WHITE);
    putpixel( x + x0, -y + y0,WHITE);
    putpixel( y + x0, -x + y0,WHITE);
    y++;
    if (radiusError<0)
    {
      radiusError += 2 * y + 1;
    }
    else
    {
      x--;
      radiusError += 2 * (y - x) + 1;
    }
  }
}
int main()
{
    int w=400,H=400;
    initwindow(400,400);
    for(int i=0; i<400; i++)
    {
        putpixel(200,i,WHITE);
    }
    for(int i=0; i<400; i++)
    {
        putpixel(i,200,WHITE);
    }
    drawLine(w/2,H*3/4,w*3/4,H/2);
    DrawCircle(300,300,100);
    getch();
    closegraph();
    return 0;
}
