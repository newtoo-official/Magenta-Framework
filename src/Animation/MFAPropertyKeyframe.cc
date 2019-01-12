/*
 * Copyright (C) 2018 Dmitry Kozichev. All rights reserved.
 *
 * MFAPropertyKeyframe.cc
 * Created on 12 џэт. 2019 у.
 */

#include <assert.h>
#include "MFAPropertyKeyframe.h"

MFAPropertyKeyframe::MFAPropertyKeyframe(MFASeconds origin, MFAProperty target, double value)
: MFAKeyframe(TypeProperty, origin), m_property(target), m_value(value)
{
}

double MFAPropertyKeyframe::getNeighborValue()
{
	MFAPropertyKeyframe *neighbor = (MFAPropertyKeyframe*)findNeighbor();
	if(neighbor == 0)
		return m_value;

	return neighbor->getValue();
}
double MFAPropertyKeyframe::getValue() const
{
	return m_value;
}
void MFAPropertyKeyframe::setValue(double value)
{
	m_value = value;
}

MFAProperty MFAPropertyKeyframe::getProperty() const
{
	return m_property;
}
void MFAPropertyKeyframe::setProperty(MFAProperty target)
{
	m_property = target;
}

MFAKeyframe* MFAPropertyKeyframe::findNeighbor()
{
	assert(m_animation == 0);

	std::size_t index = getIndex() + 1;

	while(index < getAnimation()->keyframes().size())
	{
		MFAKeyframe* keyframe = getAnimation()->keyframes()[index];
		if(keyframe->getType() == TypeProperty)
		{
			MFAPropertyKeyframe* valuekeyframe = (MFAPropertyKeyframe*)keyframe;
			if(valuekeyframe->m_property == m_property)
				return (MFAKeyframe*)valuekeyframe;
		}
		index++;
	}
	return 0;
}
void MFAPropertyKeyframe::play()
{
	auto neighbor = (MFAPropertyKeyframe*)findNeighbor();

	if(neighbor == 0)
	{
		*m_property = m_value;
		return;
	}
	double duration = neighbor->getPosition() - m_position;
	double end_value = neighbor->getValue();

	double relativePosition = getAnimation()->getPosition() - m_position;
	if (relativePosition < 0) {
		*m_property = m_value;
		return;
	}
	if (relativePosition > duration) {
		*m_property = end_value;
		return;
	}
	*m_property = (end_value - m_value) / duration * relativePosition + m_value;
}

