#include "Main.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int ac, char *av[])
{
    std::unique_ptr<cs::CircuitSim> circuitSim = nullptr;
    try
    {
        circuitSim = std::unique_ptr<cs::CircuitSim>{new cs::CircuitSim{ac, av}};
        circuitSim->Run();
    }
    catch (const cs::error::ICircuitSimError &error)
    {
        std::cerr << error.what() << std::endl;
        return error.ErrorCode();
    }
    return SUCCESS;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
