#ifndef IComponent_hpp_
#define IComponent_hpp_

#include <iostream>
#include <tuple>
#include <array>
#include "ComponentError.hpp"

namespace cs
{
	namespace component
	{

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		enum Tristate
		{
			UNDEFINED = -1,
			FALSE,
			TRUE
		};

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		enum IO
		{
			I,
			O
		};

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		enum TupleAccessor
		{
			STATE,
			TYPE,
			LINK,
			PIN
		};

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		class IComponent
		{
		public:
			virtual ~IComponent() = default;

			virtual Tristate Compute(std::size_t) = 0;
			virtual Tristate ComputeImpl(std::size_t) = 0;
			virtual std::tuple<Tristate, IO, IComponent *, std::size_t> &GetPin(std::size_t) = 0;
			virtual std::size_t Pins() const = 0;
			virtual void SetLink(std::size_t, IComponent &, std::size_t, bool force = false) = 0;
			virtual void Display(std::size_t) const = 0;
			virtual std::string Name() const = 0;
			virtual std::string Type() const = 0;
			virtual void Dump() const = 0;
		};

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

		template <std::size_t PINS, std::size_t INTERNALS = 0>
		class Component : public IComponent
		{
		public:
			Component(const std::string &name, const std::string &type) : _name{name}, _type(type)
			{
				for (std::size_t i = 0; i < PINS; ++i)
				{
					std::get<STATE>(_pins[i]) = UNDEFINED;
					std::get<TYPE>(_pins[i]) = I;
					std::get<LINK>(_pins[i]) = nullptr;
					std::get<PIN>(_pins[i]) = 0;
				}
			};
			~Component()
			{
				for (std::size_t i = 0; i < INTERNALS; ++i)
					delete _internals[i];
			};

			std::size_t Pins() const
			{
				return _pins.size();
			};
			std::string Name() const
			{
				return _name;
			};
			std::string Type() const
			{
				return _type;
			};
			void Display(std::size_t pin) const
			{
				--pin;
				if (pin >= _pins.size())
					throw cs::error::component::NoSuchPinError{};
				Tristate state = std::get<STATE>(_pins[pin]);
				std::cout << (state == -1 ? "U" : state ? "1"
																								: "0");
			};
			Tristate Compute(std::size_t pin = 1)
			{
				--pin;
				if (pin >= _pins.size())
					throw cs::error::component::NoSuchPinError{};
				return ComputeImpl(pin);
			};
			Tristate ComputeImpl(std::size_t pin)
			{
				IComponent *seeker = std::get<LINK>(_pins[pin]);
				if (seeker)
					std::get<STATE>(_pins[pin]) = seeker->Compute(std::get<PIN>(_pins[pin]) + 1);
				return std::get<STATE>(_pins[pin]);
			};
			std::tuple<Tristate, IO, IComponent *, std::size_t> &GetPin(std::size_t pin = 1)
			{
				--pin;
				if (pin >= _pins.size())
					throw cs::error::component::NoSuchPinError{};
				return _pins[pin];
			};
			void SetLink(std::size_t pin, IComponent &component, std::size_t componentPin, bool force = false)
			{
				--pin;
				--componentPin;
				std::cout << "Pin: " << pin << std::endl;
				std::cout << "Pin: " << componentPin << std::endl;
				if (pin >= _pins.size() || componentPin >= component.Pins())
					throw cs::error::component::NoSuchPinError{};
				if (std::get<TYPE>(_pins[pin]) == I && std::get<TYPE>(component.GetPin(componentPin + 1)) == O)
				{
					std::get<LINK>(_pins[pin]) = &component;
					std::get<PIN>(_pins[pin]) = componentPin;
				}
				else if (std::get<TYPE>(component.GetPin(componentPin + 1)) == I && std::get<TYPE>(_pins[pin]) == O)
				{
					std::get<LINK>(component.GetPin(componentPin + 1)) = this;
					std::get<PIN>(component.GetPin(componentPin + 1)) = pin;
				}
				else
				{
					if (force)
					{
						std::get<LINK>(_pins[pin]) = &component;
						std::get<PIN>(_pins[pin]) = componentPin;
					}
					else
						throw cs::error::CircuitSimError{"Cannot bind two same IO together"};
				}
			};
			void Dump() const
			{
				std::cout << '[' << _type << "] " << _name << ":\n";
				for (std::size_t i = 1; i <= PINS;)
				{
					std::cout << '[' << i << "]\t";
					Display(i++);
					std::cout << '\n';
				}
				std::cout << std::endl;
			};

		protected:
			const std::string _name;
			const std::string _type;
			std::array<std::tuple<Tristate, IO, IComponent *, std::size_t>, PINS> _pins;
			std::array<IComponent *, INTERNALS> _internals;
		};

		/////////////////////////////////////////////////////////////////////////////////////////////////////////

	}
}

#endif
