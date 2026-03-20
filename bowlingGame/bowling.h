#ifndef BOWLING_H
#define BOWLING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FRAMES 10
#define MAX_PLAYER_NAME 9

typedef struct {
    int rolls[3];       // To accommodate the 10th frame, which can have 3 rolls
    int frame_score;    // Score for this frame, not including bonus from later frames
    int cumulative_score; // Score up to this frame
    bool is_strike;
    bool is_spare;
    int bonus;
} Frame;

typedef struct {
    char player_name[MAX_PLAYER_NAME + 1];
    Frame frames[MAX_FRAMES];
    int current_frame;
} Game;

void play_game();
void view_records();

#endif // BOWLING_H
