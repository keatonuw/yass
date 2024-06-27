#ifndef YASS_H_
#define YASS_H_

#include <raylib.h>
#include <stdlib.h>

#define MAX_SNAKE_LEN 128
#define MAX_NUM_SNAKES 2
#define MAX_NUM_FOOD 1

typedef enum SnakeAction { TURN_LEFT, TURN_RIGHT, NO_OP } SnakeAction_t;
typedef enum Direction { UP, RIGHT, DOWN, LEFT } Direction_t;

typedef struct WorldPoint WorldPoint;
typedef struct Snake Snake;
typedef struct SnakeController SnakeController;
typedef struct World World;

typedef SnakeAction_t (*SnakeControllerAction)(World *);

typedef struct WorldPoint {
  uint8_t x;
  uint8_t y;
} WorldPoint;

typedef struct Snake {
  WorldPoint positions_queue[MAX_SNAKE_LEN];
  size_t head; // positions_queue[head] = posn. of head. -1 means dead.
  size_t tail; // likewise for tail - difference is length.
} Snake;

typedef struct SnakeController {
  SnakeControllerAction get_action;
} SnakeController;

typedef struct World {
  Snake snakes[MAX_NUM_SNAKES];           // snakes!
  SnakeController brains[MAX_NUM_SNAKES]; // snake brains!
  WorldPoint food[MAX_NUM_FOOD];          // positions of food
  WorldPoint size;                        // size of grid
} World;

// Functions
Snake *create_snake(WorldPoint head, WorldPoint tail);
Snake *clone_snake(Snake *s);
Snake *grow_snake(Snake *s);
Snake *move_snake(Snake *s, Direction_t d);
void destroy_snare(Snake *s);

#endif // !YASS_H_
