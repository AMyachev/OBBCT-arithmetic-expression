#include "threads.h"

void thread_service(data_in_thread* dat) {
	std::chrono::milliseconds dura(1);
	while (true) {
		while (dat->sc == data_not_ready) this_thread::sleep_for(dura); dat->sc = compute;
		std::istringstream stream(dat->exp);
		streambuf* cin_backup = std::cin.rdbuf(stream.rdbuf());
		while (cin) {
			get_token();
			if (curr_tok == END) break;
			if (curr_tok == PRINT) continue;
			cout << "result: " << expr() << '\n';
		}
		std::cin.rdbuf(cin_backup);
		dat->sc = data_not_ready;
	}
};