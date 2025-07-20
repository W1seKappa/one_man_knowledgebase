#include <iostream>
#include "JsonParser.hpp"
#include "XmlParser.hpp"


template<typename Impl>
auto parserFile(std::shared_ptr<Impl> parser) {
	auto result = std::make_pair(parser->getData(), parser->getID());
	return result;

}

int main() {
	auto js = std::make_shared<ParserJsonImpl>();
	auto res =  parserFile(js);
	std::cout << res.first << " " << res.second << std::endl;

	auto xml = std::make_shared<ParserXmlImpl>();
	auto res_xml = parserFile(xml); 
	std::cout << res_xml.first << " " << res_xml.second << std::endl;  

	return EXIT_SUCCESS;
}
