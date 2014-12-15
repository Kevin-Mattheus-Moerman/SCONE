#pragma once

#include <memory>

#ifdef SCONE_SIM_EXPORTS
#define SCONE_SIM_API __declspec(dllexport)
#else
#define SCONE_SIM_API __declspec(dllimport)
#endif

namespace scone
{
	namespace sim
	{
		// forward declarations
		class Simulation;
		class Model;
		class Body;
		class Joint;
		class Muscle;
		class Controller;

		typedef std::unique_ptr< Simulation > SimulationUP;
		typedef std::shared_ptr< Simulation > SimulationSP;
		typedef std::shared_ptr< Model > ModelSP;
		typedef std::shared_ptr< Controller > ControllerSP;
	}
}
