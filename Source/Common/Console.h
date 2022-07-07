#pragma once

#include <string>
#include <iostream>
#include <map>
#include <functional>

namespace engine {
	template <typename T>
	void log(T& text) {
		std::cout << text << std::endl;
	}

	template <typename T>
	void getLineText(T& value) {
		char chars[1024];
		std::cin.getline(chars, 1024);
		value = chars;
	}

	void line(const int size = 10, const char ch = '-');
	std::string enterText(const std::string& textInfo = std::string());

	typedef std::function<void(const std::vector<std::string>& words)> CommanFunction;
	bool runCommand(std::map<std::string, CommanFunction> mapFunction);
}
