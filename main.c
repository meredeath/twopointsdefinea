#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  clear_screen(s);
  
  c.red = 0;
  c.green = 0;
  c.blue = MAX_COLOR;

  int counter= 0;
  for(int i = MAX_COLOR; i >= 0; i--){
    c.blue = i;
    draw_line(250,250,250,250+counter,s,c);
    counter++;
  }

  //display(s);
  save_extension(s, "lines.png");
}
