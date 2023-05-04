#ifndef MAIN_H
#define MAIN_H

/******STANDARD LIBRARY******/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

char *omit_letter(char *str);
void single_player(int mode);
int mode_select();
void update_score(int *score);
void easy_mode();
void medium_mode();
void hard_mode();
void multiplayer();
void player_one_turn(int *score);
void player_two_turn(int *score);
int Home();

#endif

