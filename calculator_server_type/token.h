#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>

using namespace std;

enum token_value {
	NUMBER, END,
	PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
	PRINT = ';', ASSIGN = '=', LP = '(', RP = ')'
};

extern int no_of_errors;
extern token_value curr_tok;
extern double number_value;

double expr();
double term();
double prim();
token_value get_token();
double error(const char* s);