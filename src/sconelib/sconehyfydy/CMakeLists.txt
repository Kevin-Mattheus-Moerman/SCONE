set(MODEL_HYFYDY_FILES
	BodyHfd.cpp
	BodyHfd.h
	DofHfd.cpp
	DofHfd.h
	JointHfd.cpp
	JointHfd.h
	ModelHfd.cpp
	ModelHfd.h
	MuscleHfd.cpp
	MuscleHfd.h
	platform.h
)

include( PrecompiledHeaders )
use_precompiled_headers( MODEL_HYFYDY_FILES "${CMAKE_CURRENT_SOURCE_DIR}/stdafx.h" "stdafx.cpp" 256 )

add_library( sconehyfydy SHARED ${MODEL_HYFYDY_FILES} )

target_link_libraries( sconehyfydy sconelib )

# Require C++17 standard
set_target_properties(sconehyfydy PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
	target_compile_definitions( sconehyfydy PRIVATE SCONE_MODEL_HFD_EXPORTS )
	target_compile_definitions( sconehyfydy PRIVATE SCONE_ENABLE_XO_PROFILING )
endif()

source_group("" FILES ${MODEL_HYFYDY_FILES})
