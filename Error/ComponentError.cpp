#include "ComponentError.hpp"

using namespace cs::error::component;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

ComponentTypeError::ComponentTypeError(std::string const &errorMessage, int errorCode) : CircuitSimError{errorMessage, errorCode}
{
}

ComponentTypeError::ComponentTypeError(const ICircuitSimError &cpy) : CircuitSimError{cpy}
{
}

ComponentTypeError::~ComponentTypeError()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

ComponentNameError::ComponentNameError(std::string const &errorMessage, int errorCode) : CircuitSimError{errorMessage, errorCode}
{
}

ComponentNameError::ComponentNameError(const ICircuitSimError &cpy) : CircuitSimError{cpy}
{
}

ComponentNameError::~ComponentNameError()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

NoSuchPinError::NoSuchPinError(std::string const &errorMessage, int errorCode) : CircuitSimError{errorMessage, errorCode}
{
}

NoSuchPinError::NoSuchPinError(const ICircuitSimError &cpy) : CircuitSimError{cpy}
{
}

NoSuchPinError::~NoSuchPinError()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

ComponentSharedNameError::ComponentSharedNameError(std::string const &errorMessage, int errorCode) : CircuitSimError{errorMessage, errorCode}
{
}

ComponentSharedNameError::ComponentSharedNameError(const ICircuitSimError &cpy) : CircuitSimError{cpy}
{
}

ComponentSharedNameError::~ComponentSharedNameError()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

NonLinkedOutputError::NonLinkedOutputError(std::string const &errorMessage, int errorCode) : CircuitSimError{errorMessage, errorCode}
{
}

NonLinkedOutputError::NonLinkedOutputError(const ICircuitSimError &cpy) : CircuitSimError{cpy}
{
}

NonLinkedOutputError::~NonLinkedOutputError()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
