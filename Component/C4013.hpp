#ifndef C4013_hpp_
#define C4013_hpp_

#include "IComponent.hpp"

namespace cs
{
	namespace component
	{

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		class C4013 : public Component<12, 10>
		{
		public:
			C4013(const std::string &);
			~C4013();

		private:
		};

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

	}
}

#endif
