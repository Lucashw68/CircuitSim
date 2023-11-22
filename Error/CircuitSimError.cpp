#include "CircuitSimError.hpp"

using namespace cs::error;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

CircuitSimError::CircuitSimError(std::string const &errorMessage, int errorCode) : _errorMessage{errorMessage}, _errorCode{errorCode}
{
}

CircuitSimError::CircuitSimError(const ICircuitSimError &cpy) : _errorMessage{cpy.ErrorMessage()}, _errorCode{cpy.ErrorCode()}
{
}

CircuitSimError::~CircuitSimError()
{
}

CircuitSimError &CircuitSimError::operator=(const ICircuitSimError &cpy)
{
    _errorMessage = cpy.ErrorMessage();
    _errorCode = cpy.ErrorCode();
    return *this;
}

const char *CircuitSimError::what() const noexcept
{
    return _errorMessage.c_str();
}

std::string CircuitSimError::ErrorMessage() const noexcept
{
    return _errorMessage;
}

int CircuitSimError::ErrorCode() const noexcept
{
    return _errorCode;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
