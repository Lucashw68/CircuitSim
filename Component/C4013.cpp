#include "C4013.hpp"

using namespace cs::component;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

C4013::C4013(const std::string &name) : Component::Component{name, "4013"}
{
  std::get<TYPE>(_pins[0]) = O;
  std::get<TYPE>(_pins[12]) = O;
  for (unsigned short int i = 0; i < 2; ++i)
    _internals[i] = new Clock{};
  for (unsigned short int i = 0; i < 2; ++i)
    _internals[i] = new Nand{};

  _internals[0]->SetLink(X, *this, Y);
  SetLink(Y, *_internals[0], X);
}

C4013::~C4013()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
