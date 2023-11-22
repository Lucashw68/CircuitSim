#include "Output.hpp"

using namespace cs::component;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

Output::Output(const std::string &name) : Component::Component{name, "output"}
{
}

Output::~Output()
{
}

Tristate Output::ComputeImpl(std::size_t pin)
{
    IComponent *seeker = std::get<LINK>(_pins[pin]);
    if (seeker)
        std::get<STATE>(_pins[pin]) = seeker->Compute(std::get<PIN>(_pins[pin]) + 1);
    std::cout << _name << '=';
    Display(1);
    std::cout << std::endl;
    return std::get<STATE>(_pins[pin]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
