#ifndef BOCHKO_UTILS_SINGLETON_HPP
#define BOCHKO_UTILS_SINGLETON_HPP

#include <mutex>

namespace bochko {
	namespace patterns {
		/**
		 * Classic thread-unsafe, interrupt-unsafe singleton.
		 */
		class singleton {

		private:

			static singleton *instance;

			singleton();

			~singleton();

		public:

			singleton(const singleton&) = delete;

			singleton& operator=(const singleton&) = delete;

			static singleton *get_instance();

		};

		/**
		 * Classic thread-safe, mutex-ed singleton.
		 */
		class mutable_singleton {

		private:

			static mutable_singleton *instance;

			mutable_singleton();

			~mutable_singleton();

		protected:
			
			static std::mutex mutex;

		public:
			
			mutable_singleton(const mutable_singleton&) = delete;
			
			mutable_singleton& operator=(const mutable_singleton&) = delete;
			
			static mutable_singleton *get_instance();
		};
	}
}
#endif // BOCHKO_UTILS_SINGLETON_HPP
