#include "Parser.hpp"

using namespace cs::parser;

/////////////////////////////////////////////////////////////////////////////////////////////////////////

Parser::Parser(std::istream &stream)
{
    std::noskipws(stream);
    _stream.first = std::istream_iterator<char>{stream};
    _stream.second = std::istream_iterator<char>{};
}

Parser::~Parser()
{
}

std::string Parser::GetWord()
{
    std::string buf;

    for (; _stream.first != _stream.second && !Match(*_stream.first, WHITE); ++_stream.first)
        buf += *_stream.first;
    return buf;
}

NODE Parser::GetNode()
{
    NODE node;
    std::string buf;
    for (; _stream.first != _stream.second && *_stream.first != ':' && !Match(*_stream.first, WHITE); ++_stream.first)
        buf += *_stream.first;
    if (':' != *_stream.first || !buf.size())
        throw cs::error::input::MissingInputError{};
    node.first = buf;
    buf.clear();
    for (++_stream.first; _stream.first != _stream.second && !Match(*_stream.first, WHITE); ++_stream.first)
        buf += *_stream.first;
    if (!buf.size())
        throw cs::error::input::MissingInputError{};
    node.second = std::stoi(buf);
    return node;
}

void Parser::Parse()
{
    bool pair = false;
    NODE node;
    NODEPAIR nodepair;
    std::pair<std::string, NAME> component;
    for (std::string buf; _stream.first != _stream.second; ++_stream.first)
    {
        if (_mode.first == COMMENT)
        {
            if (*_stream.first == '\n')
                _mode.first = _mode.second;
        }
        else
        {
            if (*_stream.first == '#')
            {
                _mode.second = _mode.first;
                _mode.first = COMMENT;
            }
            else if (*_stream.first == '.')
            {
                buf = GetWord();
                if (".chipsets:" == buf)
                {
                    if (pair)
                        throw cs::error::input::MissingInputError{};
                    pair = false;
                    _mode.first = CHIPSET;
                    _check.first = true;
                }
                else if (".links:" == buf)
                {
                    if (pair)
                        throw cs::error::input::MissingInputError{};
                    pair = false;
                    _mode.first = LINK;
                    _check.second = true;
                }
                else
                    throw cs::error::input::LexInputError{};
            }
            else if (!Match(*_stream.first, WHITE))
            {
                if (_mode.first == LINK)
                {
                    node = GetNode();
                    if (pair)
                    {
                        if (_result.first.find(node.first) == _result.first.end())
                            throw cs::error::component::ComponentNameError{};
                        nodepair.second = node;
                        _result.second.push_back(nodepair);
                        pair = false;
                    }
                    else
                    {
                        if (_result.first.find(node.first) == _result.first.end())
                            throw cs::error::component::ComponentNameError{};
                        nodepair.first = node;
                        pair = true;
                    }
                }
                else if (_mode.first == CHIPSET)
                {
                    if (pair)
                    {
                        component.second = GetWord();
                        if (_result.first.find(component.second) != _result.first.end())
                            throw cs::error::component::ComponentSharedNameError{};
                        _result.first[component.second] = _factory.Build(component.first, component.second);
                        pair = false;
                    }
                    else
                    {
                        component.first = GetWord();
                        pair = true;
                    }
                }
                else
                    // HERE
                    throw cs::error::input::UnknownInputError{};
            }
        }
    }
    if (!_check.first)
        throw cs::error::input::NoChipsetSection{};
    else if (!_check.second)
        throw cs::error::input::NoLinksSection{};
}

bool Parser::Match(char c, std::string str) const
{
    for (std::string::const_iterator first = str.begin(), second = str.end(); first != second; ++first)
        if (c == *first)
            return true;
    return false;
}

void Parser::Reset()
{
    _result.first.clear();
    _result.second.clear();
    _mode.first = NONE;
    _check.first = false;
    _check.second = false;
}

void Parser::Link()
{
    for (LINKS::iterator first = _result.second.begin(), second = _result.second.end(); first != second; ++first)
        _result.first[first->first.first]->SetLink(first->first.second, *_result.first[first->second.first], first->second.second);
}

RESULT &Parser::Result()
{
    return _result;
}

void Parser::Check() const
{
    for (COMPONENTS::const_iterator first = _result.first.begin(), second = _result.first.end(); first != second; ++first)
        if (first->second->Type() == "output" && !std::get<PIN>(first->second->GetPin(1)))
            throw cs::error::component::NonLinkedOutputError{};
        else if (first->second->Type() == "input" && -1 == std::get<cs::component::STATE>(first->second->GetPin(1)))
            throw cs::error::input::MissingInputError{};
        else if (first->second->Type() == "clock" && -1 == std::get<cs::component::STATE>(first->second->GetPin(1)))
            throw cs::error::input::MissingInputError{};
}

void Parser::AssignInput(const char *str)
{
    std::pair<std::string, std::string> buf;
    int j;
    buf.first.clear();
    buf.second.clear();
    for (j = 0; str[j] && str[j] != '=' && !Match(str[j], WHITE); ++j)
        buf.first += str[j];
    for (++j; str[j] && str[j] <= '9' && str[j] >= '0'; ++j)
        buf.second += str[j];
    if (_result.first.find(buf.first) == _result.first.end())
        throw cs::error::input::UnknownInputError{};
    if (!_result.first[buf.first])
        throw cs::error::component::ComponentTypeError{"Type not handled : is nullptr"};
    if (_result.first[buf.first]->Pins() != 1)
        throw cs::error::input::LexInputError{"Trying to initialize by command a component containing more than one pin"};
    std::get<cs::component::STATE>(_result.first[buf.first]->GetPin(1)) = buf.second == "1" ? cs::component::TRUE : buf.second == "0" ? cs::component::FALSE
                                                                                                                                      : throw cs::error::input::UnknownInputError{};
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
