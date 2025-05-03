/*
Given a string with robot movements like "LMMRMMLMM"
where L: turn left 
      R: turn right 
      M: move one step forward 
      
Find out if robot returns to initial starting position
if movement strings are repeated one or more times.
*/

#include <stdio.h>

typedef enum { NORTH, EAST, SOUTH, WEST } Direction;

typedef struct {
    int x;
    int y;
    Direction dir;
} Robot;

void turn_left(Robot *robot) {
    switch (robot->dir) {
        case NORTH: robot->dir = WEST; break;
        case EAST:  robot->dir = NORTH; break;
        case SOUTH: robot->dir = EAST; break;
        case WEST:  robot->dir = SOUTH; break;
    }
}

void turn_right(Robot *robot) {
    switch (robot->dir) {
        case NORTH: robot->dir = EAST; break;
        case EAST:  robot->dir = SOUTH; break;
        case SOUTH: robot->dir = WEST; break;
        case WEST:  robot->dir = NORTH; break;
    }
}

void move_forward(Robot *robot) {
    switch (robot->dir) {
        case NORTH: robot->y += 1; break;
        case EAST:  robot->x += 1; break;
        case SOUTH: robot->y -= 1; break;
        case WEST:  robot->x -= 1; break;
    }
    printf("New position: (%d, %d)\n", robot->x, robot->y);
}

void execute_instruction(Robot *robot, char instruction) {
    switch (instruction) {
        case 'L': turn_left(robot); break;
        case 'R': turn_right(robot); break;
        case 'M': move_forward(robot); break;
        default: printf("Invalid instruction: %c\n", instruction); break;
    }
}


int isReturnToOriginTrue(Robot robot, char instructions[]) {
    
    Robot backup = robot;

    printf("Initial position: (%d, %d)\n", robot.x, robot.y);
    printf("Initial direction: %d\n", robot.dir);
    
    for (int i = 0; instructions[i] != '\0'; i++) {
        execute_instruction(&robot, instructions[i]);
    }

    printf("Final position: (%d, %d)\n", robot.x, robot.y);
    printf("Final direction: %d\n", robot.dir);
    
    if(((robot.x == backup.x) && (robot.y == backup.y)) || 
       (robot.dir != backup.dir))
    {
        printf("Robot returns to origin\n\n");
    }
    else
    {
          printf("Robot DOES NOT return to origin\n\n");
    }

    return 0;
}

int main()
{
    Robot robot = {0, 0, NORTH};
    char instructions[] = "MMR";
    isReturnToOriginTrue(robot, instructions);
    
    Robot robot2 = {0, 0, NORTH};
    char instructions2[] = "LMLMLMLMM";
    isReturnToOriginTrue(robot2, instructions2);
    
    return 0;
}
