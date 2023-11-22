#ifndef CircuitSimError_hpp_
#define CircuitSimError_hpp_

#include <string>

namespace cs
{
	namespace error
	{

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		enum ErrorCode
		{
			UNDEFINEDERROR = 84,

			COMPONENTTYPEERROR = 84,
			COMPONENTNAMEERROR = 84,
			COMPONENTSHAREDNAMEERROR = 84,
			NOSUCHPINERROR = 84,
			NONLINKEDOUTPUTERROR = 84,

			LEXINPUTERROR = 84,
			MISSINGINPUTERROR = 84,
			UNKNOWNINPUTERROR = 84,
			NOCHIPSETSECTION = 84,
			NOLINKSSECTION = 84
		};

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		class ICircuitSimError : public std::exception
		{
		public:
			virtual ~ICircuitSimError() = default;

			virtual ICircuitSimError &operator=(const ICircuitSimError &) = 0;

			virtual const char *what() const noexcept = 0;
			virtual std::string ErrorMessage() const noexcept = 0;
			virtual int ErrorCode() const noexcept = 0;
		};

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		class CircuitSimError : public ICircuitSimError
		{
		public:
			CircuitSimError(std::string const &errorMessage = "CircuitSimSpice undefined error", int errorCode = UNDEFINEDERROR);
			CircuitSimError(const ICircuitSimError &);
			~CircuitSimError();

			CircuitSimError &operator=(const ICircuitSimError &);

			const char *what() const noexcept;
			std::string ErrorMessage() const noexcept;
			int ErrorCode() const noexcept;

		protected:
			std::string _errorMessage;
			int _errorCode;
		};

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

	}
}

#endif
