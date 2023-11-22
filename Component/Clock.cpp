#include "Clock.hpp"

using namespace cs::component;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

Clock::Clock(const std::string &name) : Component::Component{name, "clock"}
{
    std::get<TYPE>(_pins[0]) = O;
}

Clock::~Clock()
{
}

Tristate Clock::ComputeImpl(std::size_t pin)
{
    if (std::get<STATE>(_pins[pin]) == TRUE)
        std::get<STATE>(_pins[pin]) = FALSE;
    else if (std::get<STATE>(_pins[pin]) == FALSE)
        std::get<STATE>(_pins[pin]) = TRUE;
    return std::get<STATE>(_pins[pin]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
