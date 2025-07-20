#pragma once
#include <iostream>
#include "Interface.hpp"


class ParserXmlImpl : public InterfaceParser<ParserXmlImpl> {
        friend class InterfaceParser<ParserXmlImpl>;
private:
        int getDataImpl() const noexcept {
                std::cout << "Parser xml get data method" << std::endl;
                return 1;
        }
        int getIDImpl() const noexcept {
                std::cout << "Parser xml get ID method" << std::endl;
                return 1;
        }
};
