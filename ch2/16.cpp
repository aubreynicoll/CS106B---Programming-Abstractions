/* Exercise 2.16
 *
 * This program uses the Stanford CPP Lib to draw a rainbow. Yay!
 *
 * Note: the Standford Graphics module needs access to spl.jar, and the file
 * must be present in the same directory as the compiled C++ executable.
 * */

#include "gwindow.h"

const int WIDTH = 500;
const int HEIGHT = 300;
const int BANDWIDTH = WIDTH / 20;

int main() {
  GWindow gw(WIDTH, HEIGHT);

  gw.setColor("CYAN");
  gw.fillRect(0, 0, WIDTH, HEIGHT);

  gw.setColor("RED");
  gw.fillOval(-(WIDTH / 2), HEIGHT / 4, WIDTH * 2, WIDTH * 2);

  gw.setColor("ORANGE");
  gw.fillOval(-(WIDTH / 2), HEIGHT / 4 + BANDWIDTH * 1, WIDTH * 2, WIDTH * 2);

  gw.setColor("YELLOW");
  gw.fillOval(-(WIDTH / 2), HEIGHT / 4 + BANDWIDTH * 2, WIDTH * 2, WIDTH * 2);

  gw.setColor("GREEN");
  gw.fillOval(-(WIDTH / 2), HEIGHT / 4 + BANDWIDTH * 3, WIDTH * 2, WIDTH * 2);

  gw.setColor("BLUE");
  gw.fillOval(-(WIDTH / 2), HEIGHT / 4 + BANDWIDTH * 4, WIDTH * 2, WIDTH * 2);

  gw.setColor("MAGENTA");
  gw.fillOval(-(WIDTH / 2), HEIGHT / 4 + BANDWIDTH * 5, WIDTH * 2, WIDTH * 2);

  gw.setColor("CYAN");
  gw.fillOval(-(WIDTH / 2), HEIGHT / 4 + BANDWIDTH * 6, WIDTH * 2, WIDTH * 2);

  return 0;
}