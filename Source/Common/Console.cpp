#include "Console.h"
#include "Common.h"

void engine::line(const int size, const char ch) {
	std::string str;
	for (int i = 0; i < size; ++i) {
		str += ch;
	}
	std::cout << str << std::endl;
}

std::string engine::enterText(const std::string& textInfo) {
	if (!textInfo.empty()) {
		std::cout << textInfo << std::endl;
	}
	std::string enteredText;
	getLineText(enteredText);
	return enteredText;
}

void engine::runCommand(std::map<std::string, CommanFunction> mapFunction) {
	if (mapFunction.size() == 0) {
		return;
	}

	std::string command;
	bool state = true;

	while (state) {
		command = enterText();

		std::vector<std::string> words;
		if (!command.empty()) {
			separateText(command, words, " ");
		}

		if (words.empty()) return;

		if (words[0] == "exit") {
			return;
		}

		auto it = mapFunction.find(words[0]);
		if (it == mapFunction.end()) {
			log("Command not founded.");
			continue;
		}

		CommanFunction function = it->second;
		function(words);
	}
}
