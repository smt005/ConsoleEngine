#pragma once

#include <vector>
#include <string>

namespace engine {

	template <class T>
	void separateText(const T& text, std::vector<std::string>& words, const std::string& separator) {
		words.clear();

		std::string textStr(text);
		size_t posBegin = 0;
		size_t posEnd = 0;

		bool breakState = false;
		while (!breakState) {
			posEnd = textStr.find(separator, posBegin);

			if (posEnd == textStr.npos) {
				posEnd = textStr.length();
				breakState = true;
			}

			std::string str = textStr.substr(posBegin, posEnd - posBegin);
			if (!str.empty()) {
				words.emplace_back(str);
			}

			++posEnd;
			posBegin = posEnd;
		}
	}
}
