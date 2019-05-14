/*
** DofHfd.h
**
** Copyright (C) 2013-2019 Thomas Geijtenbeek and contributors. All rights reserved.
**
** This file is part of SCONE. For more information, see http://scone.software.
*/

#pragma once

#include "platform.h"
#include "scone/model/Dof.h"

namespace scone
{
	class SCONE_HFD_API DofHfd : public Dof
	{
	public:
		DofHfd( class JointHfd& joint );
		virtual ~DofHfd();

		virtual Real GetPos() const override;
		virtual Real GetVel() const override;

		virtual Real GetLimitForce() const override;
		virtual Real GetMoment() const override;

		virtual const String& GetName() const override;

		virtual void SetPos( Real pos, bool enforce_constraints = true ) override;
		virtual void SetVel( Real vel ) override;

		virtual Vec3 GetRotationAxis() const override;
		virtual Range< Real > GetRange() const override;
	};
}
