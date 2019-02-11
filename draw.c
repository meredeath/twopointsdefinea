#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int x = x0;
  int y = y0;
  int a = (y1 - y0);
  int b = -(x1 - x0);
  int d = 2*a + b;

  int m;
  if(b != 0){
    m = a/-b;
  }else{
    m = 0;
  }
  
  //if it's in octant 1 or 5:
  if(0 <= m || m <= 1){
    while(x <= x1){
      plot(s,c,x,y);
      if(d > 0){
	y++;
	d += 2*b;
      }
      x++;
      d += 2*a;
    }
  }

  //if it's in octant 2 or 6:
  if(1 < m){
    d = a + 2*b;
    while(y <= y1){
      plot(s,c,x,y);
      if(d <= 0){
	x++;
	d += 2*a;
      }
      y++;
      d += 2*a;
    }
  }

  //if it's in octant 3 or 7:
  if(m < -1){
    d = a - 2*b;
    while(y >= y1){
      plot(s,c,x,y);
      if(d > 0){
	x++;
	d += 2*a;
      }
      y--;
      d -= 2*b;
    }
  }
  
  //if it's in octant 4 or 8:
  if(0 > m || m >= -1){
    d = 2*a - b;
    while (x <= x1){
      plot(s,c,x,y);
      if(d < 0){
	y--;
	d -= 2*b;
      }
      x++;
      d += 2*a;
    }
  }
  
}
