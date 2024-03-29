#include "True.hpp"

using namespace cs::component;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

True::True(const std::string &name) : Component::Component{name, "true"}
{
    std::get<TYPE>(_pins[0]) = O;
    std::get<STATE>(_pins[0]) = TRUE;
}

True::~True()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
