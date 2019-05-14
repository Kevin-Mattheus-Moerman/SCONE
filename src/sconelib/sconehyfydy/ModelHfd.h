/*
** ModelHfd.h
**
** Copyright (C) 2013-2019 Thomas Geijtenbeek and contributors. All rights reserved.
**
** This file is part of SCONE. For more information, see http://scone.software.
*/

#pragma once

#include "platform.h"
#include "scone/model/Model.h"

#include "BodyHfd.h"
#include "MuscleHfd.h"

namespace scone
{
	/// Model of type Hfd.
	class SCONE_HFD_API ModelHfd : public Model
	{
	public:
		ModelHfd( const PropNode& props, Params& par );
		virtual ~ModelHfd();

		/// File containing the OpenSim model.
		String model_file;

		virtual Vec3 GetComPos() const override;
		virtual Vec3 GetComVel() const override;
		virtual Vec3 GetComAcc() const override;
		virtual Real GetTotalEnergyConsumption() const override;

		virtual Real GetMass() const override;
		virtual Real GetBW() const override;
		virtual Vec3 GetGravity() const override final;

		virtual void AdvanceSimulationTo( double time ) override;

		virtual double GetSimulationEndTime() const override;
		virtual void SetSimulationEndTime( double t ) override;
		virtual std::vector<xo::path> WriteResults( const path& file_base ) const override;

		virtual void RequestTermination();

		virtual double GetTime() const override;
		virtual double GetPreviousTime() const override;
		virtual int GetIntegrationStep() const override;
		virtual int GetPreviousIntegrationStep() const override;
		virtual TimeInSeconds GetSimulationStepSize() override;

		virtual const String& GetName() const override;
		virtual std::ostream& ToStream( std::ostream& str ) const override;

		void StoreCurrentFrame() override;

		virtual const State& GetState() const override;
		virtual State& GetState() override;
		virtual void SetState( const State& state, TimeInSeconds timestamp ) override;
		virtual void SetStateValues( const std::vector< Real >& state, TimeInSeconds timestamp ) override;

		virtual void SetController( ControllerUP c ) override;
	};
}
