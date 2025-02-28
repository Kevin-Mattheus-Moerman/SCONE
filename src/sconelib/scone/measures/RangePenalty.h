/*
** RangePenalty.h
**
** Copyright (C) 2013-2019 Thomas Geijtenbeek and contributors. All rights reserved.
**
** This file is part of SCONE. For more information, see http://scone.software.
*/

#pragma once

#include "scone/core/math.h"
#include "scone/core/Range.h"
#include "scone/core/Statistic.h"
#include "scone/core/Angle.h"
#include "xo/utility/smart_enum.h"

namespace scone
{
	xo_smart_enum_class( penalty_mode, average, lowest, highest );

	/// Helper class to compute penalty if a value is outside a specific range. The penalty corresponds to
	/// ''abs_penalty * | _E_ | + squared_penalty * _E_^2'',
	/// where _E_ is the amount a value is out of the specified range.
	template< typename T > class RangePenalty
	{
	public:
		RangePenalty() : range( xo::constants<T>::lowest(), xo::constants<T>::max() ), abs_penalty( 0 ), squared_penalty( 0 ) { }

		RangePenalty( const PropNode& prop ) :
			abs_penalty( prop.get_any( { "abs_penalty", "abs_range_penalty" }, T( 0 ) ) ),
			squared_penalty( prop.get_any( { "squared_penalty", "squared_range_penalty" }, T( 0 ) ) ),
			range( prop ),
			mode_( prop.get<penalty_mode>( "mode", penalty_mode::average ) )
		{
		}
		virtual ~RangePenalty() {}

		void AddSample( TimeInSeconds timestamp, const T& value ) {
			auto range_violation = range.GetRangeViolation( value );
			auto abs_pen = abs( range_violation );
			auto pen = abs_penalty * abs( range_violation ) + squared_penalty * GetSquared( range_violation );
			penalty.AddSample( timestamp, pen );
		}

		bool IsNull() const { return abs_penalty == 0.0 && squared_penalty == 0.0; }

		double GetLatest() const { return double( penalty.GetLatest() ); }

		double GetResult() const {
			switch ( mode_ ) {
			case penalty_mode::average: return double( penalty.GetAverage() );
			case penalty_mode::highest: return double( penalty.GetHighest() );
			case penalty_mode::lowest: return double( penalty.GetLowest() );
			default: SCONE_THROW( "Invalid mode" );
			}
		}

		/// Specify the valid range, set through parameters 'min' and 'max'; defaults to { min = -inf max = inf }
		Range< T > range;

		/// Absolute penalty factor when value is out of range; default = 0.
		Real abs_penalty;

		/// Squared penalty factor when value out of range; default = 0.
		Real squared_penalty;

		/// Use the peek range violation instead of average range violation; default = 0.
		penalty_mode mode_;

	private:
		Statistic< T > penalty;
	};
}

namespace xo
{
	template< typename T > bool from_prop_node( const prop_node& pn, scone::RangePenalty< T >& rp ) {
		rp = scone::RangePenalty<T>( pn );
		return true;
	}
}
