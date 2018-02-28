#include "threads.h"


token_value curr_tok;
double number_value;
int no_of_errors;


int main() {
	std::chrono::milliseconds dura(1);
	data_in_thread dat;
	thread thr(thread_service, &dat);
	thr.detach();
	string exp;
	char decision;
	while (true) {
		cout << "enter an arithmetic expression:  ";
		cin >> exp;
		exp.push_back('\n');
		dat.exp = exp;
		dat.sc = data_ready;
		while (dat.sc != data_not_ready) this_thread::sleep_for(dura);
		cout << "continue?(y-yes) " << endl;
		cin >> decision;
		if (decision != 'y') break;
	}
	return no_of_errors;
}