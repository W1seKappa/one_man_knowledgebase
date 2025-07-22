#pragma once
#include <iostream>
#include "Interface.hpp"

// Второй наследник, который также передает в качестве параметра шаблона базового класса себя
class ParserXmlImpl : public InterfaceParser<ParserXmlImpl> {
        friend class InterfaceParser<ParserXmlImpl>;
private:
        // реализации методов, вызываемых к базовом классе
        int getDataImpl() const noexcept {
                std::cout << "Parser xml get data method" << std::endl;
                return 1;
        }
        int getIDImpl() const noexcept {
                std::cout << "Parser xml get ID method" << std::endl;
                return 1;
        }
};
