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

int field_height = 8;
int field_width = 8;

int length;
int score;

struct point history[field_width * field_height];

struct point fruit;

struct point head;
enum direction dir;

bool playing = false;

void initGame() {
    dir = UP;
    length = 3;
    head = {field_height / 2, field_width / 2};

    for (int i = 0; i < length; ++i) {
        history[i] = head;
    }

    history[0] = head;
    playing = true;
    srand((unsigned) time(&t));
}

bool checkValid(point next) {
    if (next.x > field_width || next.x < 0 || next.y > field_height || next.y < 0) {
        return false;
    }
    for (int i = 0; i < lenth; i++) {
        if (next.x == history[i] && next.y == history[i]) {
            return false;
        }
    }
    return true;
}

void move() {
    if (play) {
        struct point next;
        switch (dir) {
            case UP:
                next = {head.x, head.y + 1};
                break;
            case DOWN:
                next = {head.x, head.y - 1};
                break;
            case LEFT:
                next = {head.x - 1, head.y};
                break;
            case RIGHT:
                next = {head.x + 1, head.y};
                break;
        }
        if (checkValid(next)) {
            struct point buffer1;
            for (int i = 0; i < length; i++) {
                buffer1 = history[i];
                history[i] = new;
                new = buffer1;
            }
            if (fruit.x == next.x && fruit.y == next.y) {
                history[length] = new;
                newFruit();
                length++;
            }
        } else {
            play = false;
        }
    }
}

void changeDirection(enum direction newDir) {
    dir = newDir;
}

void newFruit() {
    bool invalid = true;
    point new;
    while (invalid) {
        new = {rand() % field_width, rand() % field_height};
        if (checkValid(new)) {
            invalid = false;
        }
    }
    fruits = new;
}

int getSizeOfArray(struct point arr[]) {
    int size = sizeof(arr) / sizeof(arr[0]);
    return size;
}