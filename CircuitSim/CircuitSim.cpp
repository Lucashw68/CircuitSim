#include "CircuitSim.hpp"

using namespace cs;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

CircuitSim::CircuitSim(int ac, char *av[])
{
	if (ac >= 2)
	{
		std::ifstream strm;
		strm.open(av[1]);
		if (strm.fail())
			throw cs::error::input::UnknownInputError{"Cannot open file"};
		_parser = std::unique_ptr<cs::parser::Parser>{new cs::parser::Parser{strm}};
		_parser->Parse();
		strm.close();
		for (unsigned short int i = 2; i < ac; ++i)
			_parser->AssignInput(av[i]);
		_parser->Link();
		_parser->Check();
	}
	else
		throw cs::error::input::MissingInputError{};
}

CircuitSim::~CircuitSim()
{
}

void CircuitSim::Simulate()
{
	for (cs::parser::COMPONENTS::iterator first = _parser->Result().first.begin(), second = _parser->Result().first.end(); first != second; ++first)
		if (first->second->Type() == "output")
		{
			first->second->Compute(1);
		}
		else if (first->second->Type() == "clock")
		{
			first->second->Compute(1);
		}
}

void CircuitSim::Run()
{
	std::string buf;
	Simulate();
	std::cout << "> ";
	for (std::cin >> buf; buf.size(); std::cin >> buf)
	{
		if (buf == "exit")
			break;
		else if (buf == "display")
		{
			for (cs::parser::COMPONENTS::iterator first = _parser->Result().first.begin(), second = _parser->Result().first.end(); first != second; ++first)
				if (first->second->Type() == "output")
				{
					std::cout << first->second->Name() << '=';
					first->second->Display(1);
					std::cout << std::endl;
				}
		}
		else if (buf == "simulate")
		{
			Simulate();
		}
		else if (buf == "loop")
		{
			while (1)
				Simulate();
		}
		else if (buf == "dump")
		{
			for (cs::parser::COMPONENTS::iterator first = _parser->Result().first.begin(), second = _parser->Result().first.end(); first != second; ++first)
				first->second->Dump();
		}
		else
			_parser->AssignInput(buf.c_str());
		std::cout << "> ";
		buf.clear();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
