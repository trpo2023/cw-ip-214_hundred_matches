#pragma once
#ifndef PARSER_H
#define PARSER_H

void Game(int PILE);
void GameRules_Text();
int Pause();
int InputUserNumber(int& User_Decision, const char* Bad_User_Decision);
int clear_cosole();
int PlayerNumber(int check);
int Hard_II(int comp, int& cash, int MOD);
int Easy_II(int comp, int& cash);

#endif