/* Exercise 2.17
 *
 * This program draws a checkerboard.
 *
 * Note: the Standford Graphics module needs access to spl.jar, and the file
 * must be present in the same directory as the compiled C++ executable.
 * */

#include "gwindow.h"

const int WIDTH = 500;
const int HEIGHT = 500;
const int SQUARES = 8;
const int CHIP_OFFSET = WIDTH / 100;

int main() {
  GWindow gw(WIDTH, HEIGHT);

  for (int row = 0; row < SQUARES; row++) {
    for (int col = 0; col < SQUARES; col++) {
      if ((row + col) % 2 == 0) {
        gw.setColor("GRAY");
      } else {
        gw.setColor("BLACK");
      }
      gw.fillRect(col * WIDTH / SQUARES, row * HEIGHT / SQUARES,
                  WIDTH / SQUARES, HEIGHT / SQUARES);

      if ((row + col) % 2 != 0 && row >= 0 && row <= 2) {
        gw.setColor("RED");
        gw.fillOval(col * WIDTH / SQUARES + CHIP_OFFSET,
                    row * HEIGHT / SQUARES + CHIP_OFFSET,
                    WIDTH / SQUARES - CHIP_OFFSET * 2,
                    HEIGHT / SQUARES - CHIP_OFFSET * 2);
      }

      if ((row + col) % 2 != 0 && row >= 5 && row <= 7) {
        gw.setColor("WHITE");
        gw.fillOval(col * WIDTH / SQUARES + CHIP_OFFSET,
                    row * HEIGHT / SQUARES + CHIP_OFFSET,
                    WIDTH / SQUARES - CHIP_OFFSET * 2,
                    HEIGHT / SQUARES - CHIP_OFFSET * 2);
      }
    }
  }

  return 0;
}