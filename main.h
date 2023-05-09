#ifndef MAIN_H
#define MAIN_H

/*********STRUCTURES************/


/******STANDARD LIBRARY******/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

/************EXTERNAL AND GLOBAL VARIABLES***************/
extern char five_word[][6];
extern char four_word[][5];
extern char six_word[][7];

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
char *replace_word(char *word, char *input);
int decision(char *ans, char *ques);
int Home();

#endif

