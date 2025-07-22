#pragma once
#include <memory>
#include <iostream>
#include <utility>


// Модифицированная версия класса интерфейса для паттерна CRTP
template <class Implementation>
class InterfaceParser : public std::enable_shared_from_this<InterfaceParser<Implementation>> { // Делаем его наследником
	// чтобы использовать умные указатели
public:
	auto getData() noexcept -> int {
		return impl()->getDataImpl(); // вызываем в методы, которые будут у наследников
	}

	auto getID() noexcept -> int {
		return impl()->getIDImpl();
	}

private:
	std::shared_ptr<Implementation> impl() noexcept {
		return static_pointer_cast<Implementation>(this->shared_from_this());
	}
};




