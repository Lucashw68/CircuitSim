#include "C4030.hpp"

using namespace cs::component;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

C4030::C4030(const std::string &name) : Component::Component{name, "4030"}
{
    std::get<TYPE>(_pins[2]) = O;
    std::get<TYPE>(_pins[3]) = O;
    std::get<TYPE>(_pins[9]) = O;
    std::get<TYPE>(_pins[10]) = O;
    for (unsigned short int i = 0; i < 4; ++i)
        _internals[i] = new Xor{};
    _internals[0]->SetLink(1, *this, 1, true);
    _internals[0]->SetLink(2, *this, 2, true);
    SetLink(3, *(_internals[0]), 3, true);
    _internals[1]->SetLink(1, *this, 5, true);
    _internals[1]->SetLink(2, *this, 6, true);
    SetLink(4, *(_internals[1]), 3, true);
    _internals[2]->SetLink(1, *this, 8, true);
    _internals[2]->SetLink(2, *this, 9, true);
    SetLink(10, *(_internals[2]), 3, true);
    _internals[3]->SetLink(1, *this, 12, true);
    _internals[3]->SetLink(2, *this, 13, true);
    SetLink(11, *(_internals[3]), 3, true);
}

C4030::~C4030()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
