#include "token.h"

double error(const char* s) {
	cerr << "error: " << s << "\n";
	++no_of_errors;
	return 1;
}

token_value get_token() {
	char ch;
	do {
		if (!cin.get(ch)) return curr_tok = END;
	} while (ch != '\n' && isspace(ch));
	switch (ch) {
	case ';':
	case '\n':
		return curr_tok = PRINT;
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
		return curr_tok = token_value(ch);
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
		cin.putback(ch);
		cin >> number_value;
		return curr_tok = NUMBER;
	default:
		error("invalid lexeme");
		return curr_tok = PRINT;
	}
}

double expr() {
	double left = term();
	for (;;)
		switch (curr_tok) {
		case PLUS:
			get_token();
			left += term();
			break;
		case MINUS:
			get_token();
			left -= term();
			break;
		default:
			return left;
		}
}

double term() {
	double d;
	double left = prim();
	for (;;)
		switch (curr_tok) {
		case MUL:
			get_token();
			left *= prim();
			break;
		case DIV:
			get_token();
			d = prim();
			if (d == 0) return error("delete on 0");
			left /= d;
			break;
		default:
			return left;
		}
}

double prim()
{
	double e;
	switch (curr_tok) {
	case NUMBER:
		get_token();
		return number_value;
	case MINUS:
		get_token();
		return -prim();
	case LP:
		get_token();
		e = expr();
		if (curr_tok != RP) return error("need to )");
		get_token();
		return e;
	case END:
		return 1;
	default:
		return error("the primary is required");
	}
}