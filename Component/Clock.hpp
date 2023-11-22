#ifndef Clock_hpp_
#define Clock_hpp_

#include "IComponent.hpp"

namespace cs
{
	namespace component
	{

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		class Clock : public Component<1>
		{
		public:
			Clock(const std::string &);
			~Clock();

			Tristate ComputeImpl(std::size_t pin = 1);

		private:
		};

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

	}
}

#endif
