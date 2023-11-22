#ifndef CircuitSim_hpp_
#define CircuitSim_hpp_

#include <iostream>
#include <fstream>
#include <memory>
#include "Parser.hpp"

namespace cs
{

	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	class CircuitSim
	{
	public:
		CircuitSim(int, char *[]);
		~CircuitSim();

		void Simulate();
		void Run();

	private:
		std::unique_ptr<cs::parser::Parser> _parser = nullptr;
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////////////

}

#endif
