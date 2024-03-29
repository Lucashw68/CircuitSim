#ifndef Nand_hpp_
#define Nand_hpp_

#include "IComponent.hpp"

namespace cs
{
	namespace component
	{

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		class Nand : public Component<3>
		{
		public:
			Nand(const std::string &name = "internal");
			~Nand();

			Tristate ComputeImpl(std::size_t pin = 1);

		private:
		};

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

	}
}

#endif
