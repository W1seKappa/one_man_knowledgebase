#pragma once
#include <iostream>
#include "Interface.hpp"

// Наследуемся от класса интерфейса, передавая свой тип в качестве шаблонного параметра
class ParserJsonImpl : public InterfaceParser<ParserJsonImpl> {
	friend class InterfaceParser<ParserJsonImpl>;
private:
	// создаем реализации вызываемых в базовом классе методов
	auto getDataImpl() const noexcept {
		std::cout << "Parser json get data method" << std::endl;
		return 0;
	}
	auto getIDImpl() const noexcept {
		std::cout << "Parser json get ID method" << std::endl;
		return 0;
	}
};
