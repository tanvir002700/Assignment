#include<graphics.h>
#include<math.h>
#include<conio.h>
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
        if (e2 > -dx)
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
void rotate_point(int x,int y,float angle,int &X,int &Y)
{
        float s = sin(angle);
        float c = cos(angle);

     // translate point back to origin:
       X -= x;
       Y -= y;

     // rotate point
       float xnew = X * c - Y * s;
       float ynew = X * s + Y * c;

  // translate point back:
       X= xnew + x;
       X = ynew +y;
}

int Dir[]={1,-1};
void DrawEllipse (int xc, int yc, int width, int height,double deg)
{
    int a2 = width * width;
    int b2 = height * height;
    int fa2 = 4 * a2, fb2 = 4 * b2;
    int x, y, sigma;
    for (x = 0, y = height, sigma = 2*b2+a2*(1-2*height); b2*x <= a2*y; x++)
    {

        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                int X=xc+(Dir[i]*x);
                int Y=yc+(Dir[j]*y);
                rotate_point(xc,yc,deg,X,Y);
                putpixel(X,Y,WHITE);
            }
        }
        if (sigma >= 0)
        {
            sigma += fa2 * (1 - y);
            y--;
        }
        sigma += b2 * ((4 * x) + 6);
    }
    for (x = width, y = 0, sigma = 2*a2+b2*(1-2*width); a2*y <= b2*x; y++)
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                int X=xc+(Dir[i]*x);
                int Y=yc+(Dir[j]*y);
                rotate_point(xc,yc,deg,X,Y);
                putpixel(X,Y,WHITE);
            }
        }
        if (sigma >= 0)
        {
            sigma += fb2 * (1 - x);
            x--;
        }
        sigma += a2 * ((4 * y) + 6);
    }
}

int main()
{
    int w=400,H=400;
    initwindow(400,400);
    drawLine(0,H/2,w,H/2);
    drawLine(w/2,0,w/2,H);
    DrawEllipse(200,200,80,40,360);
    getch();
    closegraph();
    return 0;
}


