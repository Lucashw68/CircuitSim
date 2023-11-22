#include "C4069.hpp"

using namespace cs::component;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

C4069::C4069(const std::string &name) : Component::Component{name, "4069"}
{
    for (unsigned short int i = 0; i < 12; ++i)
        if (i % 2)
            std::get<TYPE>(_pins[i]) = O;
    for (unsigned short int i = 0; i < 6; ++i)
        _internals[i] = new Inv{};
    _internals[0]->SetLink(1, *this, 1, true);
    SetLink(2, *(_internals[0]), 2, true);
    _internals[1]->SetLink(1, *this, 3, true);
    SetLink(4, *(_internals[1]), 2, true);
    _internals[2]->SetLink(1, *this, 5, true);
    SetLink(6, *(_internals[2]), 2, true);
    _internals[3]->SetLink(1, *this, 9, true);
    SetLink(8, *(_internals[3]), 2, true);
    _internals[4]->SetLink(1, *this, 11, true);
    SetLink(10, *(_internals[4]), 2, true);
    _internals[5]->SetLink(1, *this, 13, true);
    SetLink(12, *(_internals[5]), 2, true);
}

C4069::~C4069()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
