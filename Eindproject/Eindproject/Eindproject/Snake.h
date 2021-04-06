/*
 * Snake.h
 *
 * Created: 24-3-2021 10:10:37
 *  Author: Thaom
 */ 

struct Point{
	int x;
	int y;
};

enum direction{UP, LEFT, DOWN, RIGHT};
void initGame();
void snake_Update();
void changeDirection(enum direction newDir);
void moveLeft();
void moveRight();
void move();