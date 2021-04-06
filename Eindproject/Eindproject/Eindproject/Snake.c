/*
 * Snake.c
 *
 * Created: 24-3-2021 10:07:13
 *  Author: Thaom
 */
#include "Snake.h"
#include "LCD.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int field_height = 8;
int field_width = 8;
int standard_length = 3;

int length;
int score;

struct Point history[64];

struct Point fruit;

struct Point head;
enum direction dir;

bool playing = false;
bool firstStart = true;

bool checkValid(struct Point next) {
	if (next.x >= field_width || next.x < 0 || next.y >= field_height || next.y < 0) {
		return false;
	}
	for (int i = 0; i < length; i++) {
		if (next.x == history[i].x && next.y == history[i].y) {
			return false;
		}
	}
	return true;
}

void newFruit() {
	bool invalid = true;
	struct Point next = {0,0};
	while (invalid) {
		next.x = rand() % field_width;
		next.y = rand() % field_height;
		if (checkValid(next)) {
			invalid = false;
			fruit = next;
		}
	}
}

void initGame(){
	if (firstStart)
	{
		srand((unsigned) time(NULL));
		lcd_init();
		firstStart = false;
	}
    dir = UP;
	score = 0;
    length = standard_length;
    head.x = (field_height / 2) - 1;
	head.y = (field_width / 2) - 1;
	
    for (int i = 0; i < length; ++i) {
        history[i] = head;
    }
	newFruit();
    playing = true;
}

void move() {
	if (playing)
	{
	
        struct Point next = {0,0};
        switch (dir) {
            case UP:
                next.x = head.x;
				next.y = head.y + 1;
                break;
            case DOWN:
                next.x = head.x;
                next.y = head.y - 1;
                break;
            case LEFT:
                next.x = head.x - 1;
                next.y = head.y;
                break;
            case RIGHT:
                next.x = head.x + 1;
                next.y = head.y;
                break;
			default:
			next.x = head.x;
			next.y = head.y;
				break;
        }
        if (checkValid(next)) {
			if (fruit.x == next.x && fruit.y == next.y) {
				newFruit();
				score++;
				length++;
			}
            struct Point buffer1;
            for (int i = 0; i < length; i++) {
                buffer1 = history[i];
                history[i] = next;
                next = buffer1;
            }
			head = history[0];
    }else{
		playing = false;
	}
		}
}

void snake_Update(){
	move();
	if (playing)
	{
		
		char buff[20];
		snprintf(buff, 20, "S %d P %d:%d X %d:%d", score , head.x , head.y ,fruit.x, fruit.y);
		display_text(buff);
	}else{
		display_text("End             ");
		initGame();
	}
	//display_text("Test");
}

void changeDirection(enum direction newDir) {
    dir = newDir;
    move();
}

void moveLeft(){
	if (dir == UP)
	{
		dir = RIGHT;
	}else{
		dir--;
	}
}

void moveRight(){
	if (dir == RIGHT)
	{
		dir = UP;
	}else{
		dir++;
	}
}

int getSizeOfArray(struct Point arr[]) {
    int size = sizeof(*arr) / sizeof(arr[0]);
    return size;
}
