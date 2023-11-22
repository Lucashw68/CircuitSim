#include "ComponentFactory.hpp"

using namespace cs::component::factory;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

ComponentFactory::ComponentFactory()
{
    _binder["clock"] = [](const std::string &name){return std::unique_ptr<cs::component::IComponent>{new Clock{name}};};
    _binder["input"] = [](const std::string &name){return std::unique_ptr<cs::component::IComponent>{new Input{name}};};
    _binder["output"] = [](const std::string &name){return std::unique_ptr<cs::component::IComponent>{new Output{name}};};
    _binder["true"] = [](const std::string &name){return std::unique_ptr<cs::component::IComponent>{new True{name}};};
    _binder["false"] = [](const std::string &name){return std::unique_ptr<cs::component::IComponent>{new False{name}};};
    _binder["4001"] = [](const std::string &name){return std::unique_ptr<cs::component::IComponent>{new C4001{name}};};
    _binder["4008"] = [](const std::string &name){return std::unique_ptr<cs::component::IComponent>{new C4008{name}};};
    _binder["4011"] = [](const std::string &name){return std::unique_ptr<cs::component::IComponent>{new C4011{name}};};
    _binder["4030"] = [](const std::string &name){return std::unique_ptr<cs::component::IComponent>{new C4030{name}};};
    _binder["4069"] = [](const std::string &name){return std::unique_ptr<cs::component::IComponent>{new C4069{name}};};
    _binder["4071"] = [](const std::string &name){return std::unique_ptr<cs::component::IComponent>{new C4071{name}};};
    _binder["4081"] = [](const std::string &name){return std::unique_ptr<cs::component::IComponent>{new C4081{name}};};
    _binder["4013"] = [](const std::string &name){(void)name; return std::unique_ptr<cs::component::IComponent>{nullptr};};
    _binder["4040"] = [](const std::string &name){(void)name; return std::unique_ptr<cs::component::IComponent>{nullptr};};
    _binder["4017"] = [](const std::string &name){(void)name; return std::unique_ptr<cs::component::IComponent>{nullptr};};
    _binder["4094"] = [](const std::string &name){(void)name; return std::unique_ptr<cs::component::IComponent>{nullptr};};
    _binder["4514"] = [](const std::string &name){(void)name; return std::unique_ptr<cs::component::IComponent>{nullptr};};
    _binder["4801"] = [](const std::string &name){(void)name; return std::unique_ptr<cs::component::IComponent>{nullptr};};
    _binder["2716"] = [](const std::string &name){(void)name; return std::unique_ptr<cs::component::IComponent>{nullptr};};
}

ComponentFactory::~ComponentFactory()
{
}

std::unique_ptr<cs::component::IComponent> ComponentFactory::Build(const std::string &type, const std::string &name)
{
    if (_binder.find(type) == _binder.end())
        throw cs::error::component::ComponentTypeError{};
    return (*_binder[type])(name);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
