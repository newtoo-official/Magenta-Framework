/*
 * Copyright (C) 2019 Dmitry Kozichev. All rights reserved.
 *
 * MFAPropertyKeyframe.h
 * Created on 12.01.2019
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

