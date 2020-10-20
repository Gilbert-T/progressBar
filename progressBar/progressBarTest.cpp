#include <thread>
#include <chrono>
#include "progressBar.h"
int main(int argc, char** argv) {
	progressBar pb;
	for (int i = 0; i < 1000; i++) {
		pb += 0.1;
		std::cout << pb;
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	return 0;
}