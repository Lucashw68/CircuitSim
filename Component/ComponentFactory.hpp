#ifndef ComponentFactory_hpp_
#define ComponentFactory_hpp_

#include <iostream>
#include <memory>
#include <map>
#include "IComponent.hpp"
#include "Clock.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "True.hpp"
#include "False.hpp"
#include "C4081.hpp"
#include "C4001.hpp"
#include "C4008.hpp"
#include "C4011.hpp"
#include "C4030.hpp"
#include "C4069.hpp"
#include "C4071.hpp"

namespace cs
{
	namespace component
	{
		namespace factory
		{

			/////////////////////////////////////////////////////////////////////////////////////////////////////////

			class ComponentFactory
			{
			public:
				ComponentFactory();
				~ComponentFactory();

				std::unique_ptr<cs::component::IComponent> Build(const std::string &, const std::string &);

			private:
				std::map<std::string, std::unique_ptr<cs::component::IComponent> (*)(const std::string &)> _binder;
			};

			/////////////////////////////////////////////////////////////////////////////////////////////////////////

		}
	}
}

#endif
