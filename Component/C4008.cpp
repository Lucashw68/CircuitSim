#include "C4008.hpp"

using namespace cs::component;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

C4008::C4008(const std::string &name) : Component::Component{name, "4008"}
{
    for (int i = 9; i < 14; ++i)
        std::get<TYPE>(_pins[i]) = O;
    for (unsigned short int i = 0; i < 8; ++i)
        _internals[i] = new Xor{};
    for (unsigned short int i = 8; i < 16; ++i)
        _internals[i] = new And{};
    for (unsigned short int i = 16; i < 20; ++i)
        _internals[i] = new Or{};
    _internals[0]->SetLink(1, *this, 6, true);
    _internals[0]->SetLink(2, *this, 7, true);
    _internals[1]->SetLink(1, *(_internals[0]), 3);
    _internals[1]->SetLink(2, *this, 9, true);
    SetLink(10, *(_internals[1]), 3, true);
    _internals[8]->SetLink(1, *this, 6, true);
    _internals[8]->SetLink(2, *this, 7, true);
    _internals[9]->SetLink(1, *(_internals[0]), 3, true);
    _internals[9]->SetLink(2, *this, 9, true);
    _internals[16]->SetLink(1, *(_internals[8]), 3, true);
    _internals[16]->SetLink(2, *(_internals[9]), 3, true);
    _internals[2]->SetLink(1, *this, 4, true);
    _internals[2]->SetLink(2, *this, 5, true);
    _internals[3]->SetLink(1, *(_internals[2]), 3);
    _internals[3]->SetLink(2, *(_internals[1]), 3);
    SetLink(11, *(_internals[3]), 3, true);
    _internals[10]->SetLink(1, *this, 4, true);
    _internals[10]->SetLink(2, *this, 5, true);
    _internals[11]->SetLink(1, *(_internals[2]), 3, true);
    _internals[11]->SetLink(2, *(_internals[16]), 3, true);
    _internals[17]->SetLink(1, *(_internals[10]), 3, true);
    _internals[17]->SetLink(2, *(_internals[11]), 3, true);
    _internals[4]->SetLink(1, *this, 2, true);
    _internals[4]->SetLink(2, *this, 3, true);
    _internals[5]->SetLink(1, *(_internals[4]), 3);
    _internals[5]->SetLink(2, *(_internals[3]), 3);
    SetLink(12, *(_internals[5]), 3, true);
    _internals[12]->SetLink(1, *this, 2, true);
    _internals[12]->SetLink(2, *this, 3, true);
    _internals[13]->SetLink(1, *(_internals[4]), 3, true);
    _internals[13]->SetLink(2, *(_internals[17]), 3, true);
    _internals[18]->SetLink(1, *(_internals[12]), 3, true);
    _internals[18]->SetLink(2, *(_internals[13]), 3, true);
    _internals[6]->SetLink(1, *this, 15, true);
    _internals[6]->SetLink(2, *this, 1, true);
    _internals[7]->SetLink(1, *(_internals[6]), 3);
    _internals[7]->SetLink(2, *(_internals[5]), 3);
    SetLink(13, *(_internals[7]), 3, true);
    _internals[14]->SetLink(1, *this, 15, true);
    _internals[14]->SetLink(2, *this, 1, true);
    _internals[15]->SetLink(1, *(_internals[6]), 3, true);
    _internals[15]->SetLink(2, *(_internals[18]), 3, true);
    _internals[19]->SetLink(1, *(_internals[14]), 3, true);
    _internals[19]->SetLink(2, *(_internals[15]), 3, true);
    SetLink(14, *_internals[19], 3, true);
}

C4008::~C4008()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
