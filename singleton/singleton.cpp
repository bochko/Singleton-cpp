#include "singleton.hpp"

bochko::patterns::singleton::singleton() = default;

bochko::patterns::singleton::~singleton() {
	if (nullptr == singleton::instance) return;
	delete singleton::instance;
}

bochko::patterns::singleton *bochko::patterns::singleton::get_instance() {
	if (singleton::instance == nullptr) {
		singleton::instance = new singleton();
	}
	return singleton::instance;
}


