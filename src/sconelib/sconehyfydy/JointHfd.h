/*
** JointHfd.h
**
** Copyright (C) 2013-2019 Thomas Geijtenbeek and contributors. All rights reserved.
**
** This file is part of SCONE. For more information, see http://scone.software.
*/

#pragma once

#include "platform.h"
#include "scone/model/Joint.h"

namespace scone
{
	class SCONE_HFD_API JointHfd : public Joint
	{
	public:
		JointHfd( Body& body, Joint* parent );
		virtual ~JointHfd();

		virtual const String& GetName() const;

		virtual Vec3 GetPos() const override;
		virtual size_t GetDofCount() const override;
		virtual Real GetDofValue( size_t index = 0 ) const override;
		virtual const String& GetDofName( size_t index = 0 ) const override;

		virtual Vec3 GetReactionForce() const override;
	};
}
