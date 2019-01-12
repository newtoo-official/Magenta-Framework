/*
 * Copyright (C) 2018 Dmitry Kozichev. All rights reserved.
 *
 * MFAValueKeyframe.h
 * Created on 12 џэт. 2019 у.
 */

#pragma once

#include "MFAKeyframe.h"

typedef double* MFAnimatedValue;

class MFAValueKeyframe : public MFAKeyframe
{
	MFAnimatedValue m_target;
	double m_value;

	const KeyframeType ValueType = 1;
public:
	MFAValueKeyframe(MFASeconds, MFAnimatedValue, double);

	double getNeighborValue();
	double getValue() const;
	void setValue(double);

	MFAnimatedValue getTargetValue() const;
	void setTargetValue(MFAnimatedValue);

	MFAKeyframe *findNeighbor() override;
	void play() override;
};

