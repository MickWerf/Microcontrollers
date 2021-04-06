/*
 * Snake.c
 *
 * Created: 24-3-2021 10:07:13
 *  Author: Thaom
 */
#include "Snake.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LCD.h"

#define fieldSize 64

int field_height = 8;
int field_width = 8;

int length;
int score;

struct point history[fieldSize];

struct point fruit;

struct point head;
enum direction dir;

bool playing = false;

void initGame() {
    dir = UP;
    length = 3;
    head.x = field_height / 2;
	head.y = field_width / 2;

    for (int i = 0; i < length; ++i) {
        history[i] = head;
    }

    history[0] = head;
    playing = true;
    srand((unsigned) time(NULL));
}

bool checkValid(struct point next) {
    if (next.x > field_width || next.x < 0 || next.y > field_height || next.y < 0) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (next.x == history[i].x && next.y == history[i].y) {
            return false;
        }
    }
    return true;
}

void move() {
    if (playing) {
        struct point next;
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
        }
        if (checkValid(next)) {
            struct point buffer1;
            for (int i = 0; i < length; i++) {
                buffer1 = history[i];
                history[i] = next;
                next = buffer1;
            }
            if (fruit.x == next.x && fruit.y == next.y) {
                history[length] = next;
                newFruit();
                length++;
            }
        } else {
            playing = false;
        }
    }
}

void changeDirection(enum direction newDir) {
    dir = newDir;
}

void newFruit() {
    bool invalid = true;
    struct point next;
    while (invalid) {
        next.x = rand() % field_width;
		next.y = rand() % field_height;
        if (checkValid(next)) {
            invalid = false;
        }
    }
    fruit = next;
}

int getSizeOfArray(struct point arr[]) {
    int size = sizeof(arr) / sizeof(arr[0]);
    return size;
}