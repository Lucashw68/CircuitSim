#ifndef InputError_hpp_
#define InputError_hpp_

#include "CircuitSimError.hpp"

namespace cs
{
	namespace error
	{
		namespace input
		{

			/////////////////////////////////////////////////////////////////////////////////////////////////////////

			class LexInputError : public CircuitSimError
			{
			public:
				LexInputError(std::string const &errorMessage = "Input lexical or syntactic error", int errorCode = LEXINPUTERROR);
				LexInputError(const ICircuitSimError &);
				~LexInputError();

			private:
			};

			/////////////////////////////////////////////////////////////////////////////////////////////////////////

			class MissingInputError : public CircuitSimError
			{
			public:
				MissingInputError(std::string const &errorMessage = "One or several input values were not provided", int errorCode = MISSINGINPUTERROR);
				MissingInputError(const ICircuitSimError &);
				~MissingInputError();

			private:
			};

			/////////////////////////////////////////////////////////////////////////////////////////////////////////

			class UnknownInputError : public CircuitSimError
			{
			public:
				UnknownInputError(std::string const &errorMessage = "A provided input is unknown", int errorCode = UNKNOWNINPUTERROR);
				UnknownInputError(const ICircuitSimError &);
				~UnknownInputError();

			private:
			};

			/////////////////////////////////////////////////////////////////////////////////////////////////////////

			class NoChipsetSection : public CircuitSimError
			{
			public:
				NoChipsetSection(std::string const &errorMessage = "No chipset section", int errorCode = NOCHIPSETSECTION);
				NoChipsetSection(const ICircuitSimError &);
				~NoChipsetSection();

			private:
			};

			/////////////////////////////////////////////////////////////////////////////////////////////////////////

			class NoLinksSection : public CircuitSimError
			{
			public:
				NoLinksSection(std::string const &errorMessage = "No links section", int errorCode = NOLINKSSECTION);
				NoLinksSection(const ICircuitSimError &);
				~NoLinksSection();

			private:
			};

			/////////////////////////////////////////////////////////////////////////////////////////////////////////

		}
	}
}

#endif
