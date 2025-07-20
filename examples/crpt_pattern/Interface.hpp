#pragma once
#include <memory>
#include <iostream>
#include <utility>

template <class Implementation>
class InterfaceParser : public std::enable_shared_from_this<Implementation> {
public:
	auto getData() noexcept -> int {
		return impl()->getDataImpl();
	}

	auto getID() noexcept -> int {
		return impl()->getIDImpl();
	}

private:
	std::shared_ptr<Implementation> impl() noexcept {
		return static_pointer_cast<Implementation>(this->shared_from_this());
	}
};




