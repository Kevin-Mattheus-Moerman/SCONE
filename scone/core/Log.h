#pragma once

#include <iostream>
#include <iomanip>
#include "core.h"

// very basic logging
#define SCONE_LOG( _MESSAGE_ ) { std::stringstream _STR_; _STR_ << _MESSAGE_; scone::Log( _STR_.str() ); }

namespace scone
{
	namespace log
	{
		enum Level { LogAllLevel, TraceLevel, DebugLevel, InfoLevel, WarningLevel, ErrorLevel, CriticalLevel, IgnoreAllLevel };

		class LogStream
		{
		public:
			LogStream() { };
			virtual ~LogStream() { };

			template< typename T >
			LogStream& operator<<( const T& value );
		};

		void CORE_API SetLevel( Level level );
		void CORE_API LogMessage( Level level, const String& msg );

		// string style logging
		void CORE_API Trace( const String& msg );
		void CORE_API Debug( const String& msg );
		void CORE_API Info( const String& msg );
		void CORE_API Warning( const String& msg );
		void CORE_API Error( const String& msg );
		void CORE_API Critical( const String& msg );

		// printf style logging
		void CORE_API TraceF( const char* msg, ... );
		void CORE_API DebugF( const char* msg, ... );
		void CORE_API InfoF( const char* msg, ... );
		void CORE_API WarningF( const char* msg, ... );
		void CORE_API ErrorF( const char* msg, ... );
		void CORE_API CriticalF( const char* msg, ... );
	}
}
