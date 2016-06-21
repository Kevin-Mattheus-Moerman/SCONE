#pragma once

#define USE_SHARK_V2 0

#include "scone/core/core.h"
#include "scone/core/PropNode.h"
#include "scone/core/string_tools.h"
#include "scone/core/memory_tools.h"

#define INIT_PARAM( PROP_, PAR_, VAR_, DEFAULT_ ) \
	VAR_ = PAR_.TryGet( GetCleanVarName( #VAR_ ), PROP_, GetCleanVarName( #VAR_ ), DEFAULT_ )

#define INIT_PARAM_NAMED( PROP_, PAR_, VAR_, NAME_, DEFAULT_ ) \
	VAR_ = PAR_.TryGet( NAME_, PROP_, NAME_, DEFAULT_ )

#define INIT_PARAM_REQUIRED( PROP_, PAR_, VAR_ ) \
	VAR_ = PAR_.Get( GetCleanVarName( #VAR_ ), PROP_, GetCleanVarName( #VAR_ ) )

#define INIT_PARAM_NAMED_REQUIRED( PROP_, PAR_, VAR_, NAME_, DEFAULT_ ) \
	VAR_ = PAR_.Get( NAME_, PROP_, NAME_ )

namespace scone
{
	namespace opt
	{
		// forward declarations
		SCONE_DECLARE_CLASS_AND_PTR( Optimizer );
		SCONE_DECLARE_CLASS_AND_PTR( Objective );
		SCONE_DECLARE_CLASS_AND_PTR( Param );
		SCONE_DECLARE_CLASS_AND_PTR( ParamSet );

		// register factory types
		void SCONE_API RegisterFactoryTypes();

		// TODO: move this to sconeopt?
		void SCONE_API PerformOptimization( int argc, char* argv[] );
		PropNode SCONE_API SimulateObjective( const String& filename );
	}
}
