#include "singleton.hpp"

/*
 * class: singleton
 */
bochko::patterns::singleton *bochko::patterns::singleton::instance = nullptr;
bochko::patterns::singleton::singleton() = default;

bochko::patterns::singleton::~singleton() {
	if (bochko::patterns::singleton::instance == nullptr) return;
	delete bochko::patterns::singleton::instance;
}

bochko::patterns::singleton *bochko::patterns::singleton::get_instance() {
	if (bochko::patterns::singleton::instance == nullptr) {
		bochko::patterns::singleton::instance = new singleton();
	}
	return bochko::patterns::singleton::instance;
}

/*
 * class: mutable_singleton
 */
bochko::patterns::mutable_singleton *bochko::patterns::mutable_singleton::instance = nullptr;
std::mutex bochko::patterns::mutable_singleton::mutex;
bochko::patterns::mutable_singleton::mutable_singleton() = default;

bochko::patterns::mutable_singleton::~mutable_singleton() {
	if (bochko::patterns::mutable_singleton::instance == nullptr) return;
	delete bochko::patterns::mutable_singleton::instance;
}

bochko::patterns::mutable_singleton *bochko::patterns::mutable_singleton::get_instance() {
	mutex.lock();
	if (bochko::patterns::mutable_singleton::instance == nullptr) {
		bochko::patterns::mutable_singleton::instance = new mutable_singleton();
	}
	mutex.unlock();
	return bochko::patterns::mutable_singleton::instance;
}

