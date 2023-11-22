#ifndef Inv_hpp_
#define Inv_hpp_

#include "IComponent.hpp"

namespace cs
{
	namespace component
	{

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		class Inv : public Component<2>
		{
		public:
			Inv(const std::string &name = "internal");
			~Inv();

			Tristate ComputeImpl(std::size_t pin = 1);

		private:
		};

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

	}
}

#endif