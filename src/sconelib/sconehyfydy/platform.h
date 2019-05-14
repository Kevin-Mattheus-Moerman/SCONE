/*
** platform.h
**
** Copyright (C) 2013-2019 Thomas Geijtenbeek and contributors. All rights reserved.
**
** This file is part of SCONE. For more information, see http://scone.software.
*/

#pragma once

#if defined(_MSC_VER)
#	ifdef SCONE_MODEL_HFD_EXPORTS
#		define SCONE_HFD_API __declspec(dllexport)
#	else
#		define SCONE_HFD_API __declspec(dllimport)
#	endif
#else
#	define SCONE_HFD_API
#endif
