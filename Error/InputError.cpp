#include "InputError.hpp"

using namespace cs::error::input;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

LexInputError::LexInputError(std::string const &errorMessage, int errorCode) : CircuitSimError{errorMessage, errorCode}
{
}

LexInputError::LexInputError(const ICircuitSimError &cpy) : CircuitSimError{cpy}
{
}

LexInputError::~LexInputError()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

MissingInputError::MissingInputError(std::string const &errorMessage, int errorCode) : CircuitSimError{errorMessage, errorCode}
{
}

MissingInputError::MissingInputError(const ICircuitSimError &cpy) : CircuitSimError{cpy}
{
}

MissingInputError::~MissingInputError()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

UnknownInputError::UnknownInputError(std::string const &errorMessage, int errorCode) : CircuitSimError{errorMessage, errorCode}
{
}

UnknownInputError::UnknownInputError(const ICircuitSimError &cpy) : CircuitSimError{cpy}
{
}

UnknownInputError::~UnknownInputError()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

NoChipsetSection::NoChipsetSection(std::string const &errorMessage, int errorCode) : CircuitSimError{errorMessage, errorCode}
{
}

NoChipsetSection::NoChipsetSection(const ICircuitSimError &cpy) : CircuitSimError{cpy}
{
}

NoChipsetSection::~NoChipsetSection()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

NoLinksSection::NoLinksSection(std::string const &errorMessage, int errorCode) : CircuitSimError{errorMessage, errorCode}
{
}

NoLinksSection::NoLinksSection(const ICircuitSimError &cpy) : CircuitSimError{cpy}
{
}

NoLinksSection::~NoLinksSection()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
