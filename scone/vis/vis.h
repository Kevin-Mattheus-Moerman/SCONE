// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the VIS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// VIS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef VIS_EXPORTS
#define VIS_API __declspec(dllexport)
#else
#define VIS_API __declspec(dllimport)
#endif

// This class is exported from the vis.dll
class VIS_API Cvis {
public:
	Cvis(void);
	// TODO: add your methods here.
};

extern VIS_API int nvis;

VIS_API int fnvis(void);

#include <Simbody/sim_simbody.h>