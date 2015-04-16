#include <unordered_map>
#include <iostream>

struct T : public std::string {	
	T(const char * s) : std::string(s) {
		std::cerr << "construct" << std::endl;
	}
	~T(){
		std::cerr << "destruct" << std::endl;
	}
};

namespace std {
	template<>
	struct hash<T> {
		size_t operator()(const T& s) const {
			std::cerr << "hash" << std::endl;
			return 0;
		}
	};
}

int main() {
	std::unordered_map<T, int> h;
	std::cerr << h.count("qwe") << std::endl;

	return 0;
}