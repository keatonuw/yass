// yass implementation :)

#include "yass.h"
#include <stdlib.h>

int abs(int i) {
  if (i < 0) {
    return i * -1;
  }
  return i;
}

int max(int a, int b) {
  if (a > b)
    return a;
  return b;
}

int world_point_equal(WorldPoint a, WorldPoint b) {
  return a.x == b.x && a.y == b.y;
}

// dont worry abt stack use these are like 2 int args lolol
WorldPoint up(WorldPoint p) { return (WorldPoint){p.x, p.y + 1}; }
WorldPoint down(WorldPoint p) { return (WorldPoint){p.x, p.y - 1}; }
WorldPoint right(WorldPoint p) { return (WorldPoint){p.x + 1, p.y}; }
WorldPoint left(WorldPoint p) { return (WorldPoint){p.x - 1, p.y}; }

Snake *create_snake(WorldPoint head, WorldPoint tail) {
  if (head.x != tail.x && head.y != tail.y) {
    // i need function composition.....
    // no diagonals
    return 0;
  }
  Snake *snake = (Snake *)malloc(sizeof(Snake));
  size_t len = max(abs(head.x - tail.x), abs(head.y - tail.y));
  WorldPoint (*stepfn)(WorldPoint);
  if (head.x != tail.x) {
    if (head.x > tail.x) {
      stepfn = left;
    } else { // <
      stepfn = right;
    }
  } else if (head.y != tail.y) { // y
    if (head.y > tail.y) {
      stepfn = down;
    } else { // <
      stepfn = up;
    }
  } else {
    stepfn = up; // should be no-op but not ran anyway
  }
  size_t pos = 1;
  snake->positions_queue[0] = head;
  while (!world_point_equal(head, tail)) {
    head = stepfn(head);
    snake->positions_queue[pos] = head;
    pos++;
  }
  snake->tail = pos - 1;
  return snake;
}

// TODO
Snake *clone_snake(Snake *s) { return s; }
Snake *grow_snake(Snake *s) { return s; };
Snake *move_snake(Snake *s, Direction_t d) { return s; };
void destroy_snare(Snake *s) { return; };
