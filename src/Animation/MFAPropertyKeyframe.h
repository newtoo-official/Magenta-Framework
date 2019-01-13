/*
 * Copyright (C) 2018 Dmitry Kozichev. All rights reserved.
 *
 * MFAPropertyKeyframe.h
 * Created on 12 џэт. 2019 у.
 */

#pragma once

#include "MFAKeyframe.h"

typedef double* MFAProperty;

class MFAPropertyKeyframe : public MFAKeyframe
{
	MFAProperty m_property;
	double m_value;

	const KeyframeType TypeProperty = 1;

public:
	MFAPropertyKeyframe(MFASeconds, MFAProperty, double);

	KeyframeType getType() override;

	double getNeighborValue();
	double getValue() const;
	void setValue(double);

	MFAProperty getProperty() const;
	void setProperty(MFAProperty);

	MFAKeyframe *findNeighbor() override;
	void play() override;
};

