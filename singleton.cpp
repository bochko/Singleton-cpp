#include "singleton.h"

namespace bochko {
	namespace patterns {
		
		// singular instance of the singleton class
		// field is declared static in header
		singleton* singleton::instance = nullptr;

		// default constructor
		// can't be accessed as it is private in header
		singleton::singleton() = default;

		// this is private as well so can't be accessed by user
		// delete only if created
		singleton::~singleton() 
		{
			if (singleton::instance != nullptr) 
			{
				delete singleton::instance;
			}
		}

		// gets the singular instance of the singleton
		// creates one only if nonexisting
		singleton* singleton::get_instance() 
		{
			
			if (singleton::instance == nullptr) 
			{
				singleton::instance = new singleton();
			}
			return singleton::instance;
		}


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
	}
}



