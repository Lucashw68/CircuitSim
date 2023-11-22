#include "Inv.hpp"

using namespace cs::component;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

Inv::Inv(const std::string &name) : Component::Component{name, "inv"}
{
    std::get<TYPE>(_pins[1]) = O;
}

Inv::~Inv()
{
}

Tristate Inv::ComputeImpl(std::size_t pin)
{
    IComponent *seeker;
    seeker = std::get<LINK>(_pins[0]);
    if (seeker)
        std::get<STATE>(_pins[0]) = seeker->Compute(std::get<PIN>(_pins[0]) + 1);
    if (!pin)
        return std::get<STATE>(_pins[pin]);
    std::get<STATE>(_pins[1]) = std::get<STATE>(_pins[0]) == UNDEFINED ? UNDEFINED : std::get<STATE>(_pins[0]) == TRUE ? FALSE
                                                                                                                       : TRUE;
    return std::get<STATE>(_pins[1]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
