#pragma once
#include <thread>
#include "token.h"

volatile enum sync {
	data_not_ready, data_ready, compute, result_ready
};

struct data_in_thread {
	string exp;
	volatile sync sc = data_not_ready;
};

void thread_service(data_in_thread* dat);