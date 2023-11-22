#include "Nand.hpp"

using namespace cs::component;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

Nand::Nand(const std::string &name) : Component::Component{name, "nand"}
{
    std::get<TYPE>(_pins[2]) = O;
}

Nand::~Nand()
{
}

Tristate Nand::ComputeImpl(std::size_t pin)
{
    IComponent *seeker;
    if (pin != 2)
    {
        seeker = std::get<LINK>(_pins[pin]);
        if (seeker)
            std::get<STATE>(_pins[pin]) = seeker->Compute(std::get<PIN>(_pins[pin]) + 1);
        return std::get<STATE>(_pins[pin]);
    }
    for (unsigned short int i = 0; i < 2; ++i)
    {
        seeker = std::get<LINK>(_pins[i]);
        if (seeker)
            std::get<STATE>(_pins[i]) = seeker->Compute(std::get<PIN>(_pins[i]) + 1);
    }
    std::get<STATE>(_pins[2]) = std::get<STATE>(_pins[0]) == UNDEFINED || std::get<STATE>(_pins[1]) == UNDEFINED ? UNDEFINED : std::get<STATE>(_pins[0]) == TRUE && std::get<STATE>(_pins[1]) == TRUE ? FALSE
                                                                                                                                                                                                      : TRUE;
    return std::get<STATE>(_pins[pin]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
