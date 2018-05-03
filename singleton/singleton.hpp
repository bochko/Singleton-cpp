#ifndef BOCHKO_UTILS_SINGLETON_HPP
#define BOCHKO_UTILS_SINGLETON_HPP

namespace bochko {
	namespace patterns {
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
	}
}
#endif // BOCHKO_UTILS_SINGLETON_HPP
