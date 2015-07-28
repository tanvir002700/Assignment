/*view port clip*/
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

int wx1,wy1,wx2,wy2, vx1, vy1, vx2, vy2, lx1, ly1, lx2, ly2;
int it = 0;
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



void clip(int x0, int y0, int x1, int y1){
    int b10=0, b11=0, b12=0, b13=0, b20=0, b21=0, b22=0, b23 = 0, tmpx = 0, tmpy=0;

    if(x0 < vx1)b10 = 1;
    if(x1 < vx1)b20 = 1;
    if(x0 > vx2)b11 = 1;
    if(x1 > vx2)b21 = 1;
    if(y0 > vy2)b12 = 1;
    if(y1 > vy2)b22 = 1;
    if(y0 < vy1)b13 = 1;
    if(y1 < vy1)b23 = 1;
    it++;
    if( (b10+b11+b12+b13+b20+b21+b22+b23)==0){
        //all zero, inside view port join points
        drawLine(x0, y0, x1, y1);
        if(it==1){
            printf("\nInside view port, no clipping needed");
        }

    }else if((b10 && b20) || (b11 && b21) || (b12 && b22) || (b13 && b23)){
        //Outside view port, escape
        if(it==1){
            printf("\nOutside view port, no clipping needed");
        }
    }else if(abs(x0-x1) > 1 && abs(y0-y1)>1){
        // partially inside, apply midpoint sub division
        if(it==1){
            printf("\nPartially inside view port, clipping needed");
        }
        tmpx = (x0+x1+1)/2;
        tmpy = (y0+y1+1)/2;
        clip(x0, y0, tmpx, tmpy);
        clip(tmpx, tmpy, x1, y1);
    }
}

int main()
{
    int winW=500;
    int winH=500;

    printf("\nProvide view port coordinate(0 to 500) : ");
    scanf("%d %d %d %d", &vx1, &vy1, &vx2, &vy2);

    initwindow(winW,winH,"test");

    drawLine(vx1,vy1, vx2, vy1);
    drawLine(vx2,vy1, vx2, vy2);
    drawLine(vx2,vy2, vx1, vy2);
    drawLine(vx1,vy2, vx1, vy1);


    while(1){
    printf("\nProvide line coordinate (0 to 500): ");
    scanf("%d %d %d %d", &lx1, &ly1, &lx2, &ly2);
    clip(lx1, ly1, lx2, ly2);
    }

    getch();
    closegraph();

    return 0;
}
