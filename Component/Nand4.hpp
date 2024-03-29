#ifndef Nand4_hpp_
#define Nand4_hpp_

#include "IComponent.hpp"

namespace cs
{
	namespace component
	{

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		class Nand4 : public Component<4>
		{
		public:
			Nand4(const std::string &name = "internal");
			~Nand4();

			Tristate ComputeImpl(std::size_t pin = 1);

		private:
		};

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

	}
}

#endif
