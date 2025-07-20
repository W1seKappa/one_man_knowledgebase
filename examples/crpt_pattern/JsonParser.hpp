#pragma once
#include <iostream>
#include "Interface.hpp"
class ParserJsonImpl : public InterfaceParser<ParserJsonImpl> {
	friend class InterfaceParser<ParserJsonImpl>;
private:
	auto getDataImpl() const noexcept {
		std::cout << "Parser json get data method" << std::endl;
		return 0;
	}
	auto getIDImpl() const noexcept {
		std::cout << "Parser json get ID method" << std::endl;
		return 0;
	}
};
