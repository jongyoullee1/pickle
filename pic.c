#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define XRES 500
#define YRES 500

int main() {
  int fd, r, g, b, x, y;
  char line[20];

  fd = open( "img.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644 );
   
  snprintf(line, sizeof(line), "P3 %d %d 255", XRES, YRES);
  write(fd, line, sizeof(line));

  for ( x = 0; x < 500; x++ ) {
    for ( y = 0; y < 500; y++ ) {
      if (x-250)*(x-250)+(y-250)*(y-250)< 250*250 {
        r = y % 256;
        g = x % 256;
        b = 0;
      }
      else {
        r = y % 256;
        g = 0;
        b = 0;
      }
      snprintf(line, sizeof(line), "%d %d %d", r, g, b);
      write(fd, line, sizeof(line));
    }
  }

  close(fd);
}
