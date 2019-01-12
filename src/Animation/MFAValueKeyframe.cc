/*
 * Copyright (C) 2018 Dmitry Kozichev. All rights reserved.
 *
 * MFAValueKeyframe.cc
 * Created on 12 џэт. 2019 у.
 */

#include "MFAValueKeyframe.h"
#include <assert.h>

MFAValueKeyframe::MFAValueKeyframe(MFASeconds origin, MFAnimatedValue target, double value)
: MFAKeyframe(ValueType, origin), m_target(target), m_value(value)
{
}

double MFAValueKeyframe::getNeighborValue()
{
	MFAValueKeyframe *neighbor = (MFAValueKeyframe*)findNeighbor();
	if(neighbor == 0)
		return m_value;

	return neighbor->getValue();
}
double MFAValueKeyframe::getValue() const
{
	return m_value;
}
void MFAValueKeyframe::setValue(double value)
{
	m_value = value;
}

MFAnimatedValue MFAValueKeyframe::getTargetValue() const
{
	return m_target;
}
void MFAValueKeyframe::setTargetValue(MFAnimatedValue target)
{
	m_target = target;
}

MFAKeyframe* MFAValueKeyframe::findNeighbor()
{
	assert(m_animation == 0);

	std::size_t index = getIndex() + 1;

	while(index < getAnimation()->keyframes().size())
	{
		MFAKeyframe* keyframe = getAnimation()->keyframes()[index];
		if(keyframe->getType() == ValueType)
		{
			MFAValueKeyframe* valuekeyframe = (MFAValueKeyframe*)keyframe;
			if(valuekeyframe->m_target == m_target)
				return (MFAKeyframe*)valuekeyframe;
		}
		index++;
	}
	return 0;
}
void MFAValueKeyframe::play()
{
	auto neighbor = (MFAValueKeyframe*)findNeighbor();

	if(neighbor == 0)
	{
		*m_target = m_value;
		return;
	}
	double duration = neighbor->getPosition() - m_position;
	double end_value = neighbor->getValue();

	double relativePosition = getAnimation()->getPosition() - m_position;
	if (relativePosition < 0) {
		*m_target = m_value;
		return;
	}
	if (relativePosition > duration) {
		*m_target = end_value;
		return;
	}
	*m_target = (end_value - m_value) / duration * relativePosition + m_value;
}

