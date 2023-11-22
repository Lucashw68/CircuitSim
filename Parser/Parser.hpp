#ifndef Parser_hpp_
#define Parser_hpp_

#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <array>
#include <string>
#include <memory>
#include "ComponentFactory.hpp"
#include "InputError.hpp"
#include "ComponentError.hpp"
#include "IComponent.hpp"

#define WHITE " \t\r\n"

namespace cs
{
	namespace parser
	{

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		using NAME = std::string;
		using PIN = std::size_t;
		using COMPONENT = std::unique_ptr<cs::component::IComponent>;
		using COMPONENTS = std::map<NAME, COMPONENT>;
		using NODE = std::pair<NAME, PIN>;
		using NODEPAIR = std::pair<NODE, NODE>;
		using LINKS = std::vector<NODEPAIR>;
		using RESULT = std::pair<COMPONENTS, LINKS>;

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		enum ParserMode
		{
			NONE,
			COMMENT,
			CHIPSET,
			LINK
		};

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		class Parser
		{
		public:
			Parser(std::istream &);
			Parser(const Parser &) = delete;
			~Parser();

			Parser &operator=(const Parser &) = delete;
			void Parse();
			void Reset();
			RESULT &Result();
			void AssignInput(const char *);
			void Link();
			void Check() const;

		private:
			bool Match(char, std::string) const;
			NODE GetNode();
			std::string GetWord();

			RESULT _result;
			cs::component::factory::ComponentFactory _factory;
			std::pair<int, int> _mode = {NONE, NONE};
			std::pair<std::istream_iterator<char>, std::istream_iterator<char>> _stream;
			std::pair<bool, bool> _check = {false, false};
		};

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

	}
}

#endif
