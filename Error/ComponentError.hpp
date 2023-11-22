#ifndef ComponentError_hpp_
#define ComponentError_hpp_

#include "CircuitSimError.hpp"

namespace cs
{
	namespace error
	{
		namespace component
		{

			/////////////////////////////////////////////////////////////////////////////////////////////////////////

			class ComponentTypeError : public CircuitSimError
			{
			public:
				ComponentTypeError(std::string const &errorMessage = "Unknown component type", int errorCode = COMPONENTTYPEERROR);
				ComponentTypeError(const ICircuitSimError &);
				~ComponentTypeError();

			private:
			};

			/////////////////////////////////////////////////////////////////////////////////////////////////////////

			class ComponentNameError : public CircuitSimError
			{
			public:
				ComponentNameError(std::string const &errorMessage = "Unknown component name", int errorCode = COMPONENTTYPEERROR);
				ComponentNameError(const ICircuitSimError &);
				~ComponentNameError();

			private:
			};

			/////////////////////////////////////////////////////////////////////////////////////////////////////////

			class NoSuchPinError : public CircuitSimError
			{
			public:
				NoSuchPinError(std::string const &errorMessage = "No such pin", int errorCode = NOSUCHPINERROR);
				NoSuchPinError(const ICircuitSimError &);
				~NoSuchPinError();

			private:
			};

			/////////////////////////////////////////////////////////////////////////////////////////////////////////

			class ComponentSharedNameError : public CircuitSimError
			{
			public:
				ComponentSharedNameError(std::string const &errorMessage = "Several componecs share the same name", int errorCode = COMPONENTSHAREDNAMEERROR);
				ComponentSharedNameError(const ICircuitSimError &);
				~ComponentSharedNameError();

			private:
			};

			/////////////////////////////////////////////////////////////////////////////////////////////////////////

			class NonLinkedOutputError : public CircuitSimError
			{
			public:
				NonLinkedOutputError(std::string const &errorMessage = "One or several outputs are not linked", int errorCode = NONLINKEDOUTPUTERROR);
				NonLinkedOutputError(const ICircuitSimError &);
				~NonLinkedOutputError();

			private:
			};

			/////////////////////////////////////////////////////////////////////////////////////////////////////////

		}
	}
}

#endif
