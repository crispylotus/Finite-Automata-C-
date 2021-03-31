#include <iostream>
#include <vector>

#include "LexicalAnalyser.cpp"

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& v) {
	stream << "[";
	if (!v.empty()) {
		for (auto i = 0; i < v.size() - 1; ++i) {
			stream << v.at(i) << ", ";
		}
		stream << v.back();
	}
	stream << "]";
	return stream;
}


int main() {
	try {
		std::cout << analyse("11+640") << std::endl;
	}
	catch (NumberException e) {
		std::cout << "Threw a NumberException." << std::endl;
	}
	catch (ExpressionException e) {
		std::cout << "Threw an ExpressionException." << std::endl;
	}
}
