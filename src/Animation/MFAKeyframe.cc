/*
 * Copyright (C) 2019 Dmitry Kozichev. All rights reserved.
 *
 * MFAFrame.cc
 * Created on 12.01.2019
 */

#include "MFAKeyframe.h"
#include <assert.h>

MFAKeyframe::MFAKeyframe(MFASeconds origin) : m_position(origin)
{
}

MFAKeyframe::KeyframeType MFAKeyframe::getType()
{
	return 0;
}

void MFAKeyframe::setFoundation(MFAnimation *foundation)
{
	m_animation = foundation;
}

MFASeconds MFAKeyframe::getDuration()
{
	MFAKeyframe *neighbor = findNeighbor();
	if(neighbor == 0)
		return getAnimation()->getDuration() - m_position;

	return neighbor->getPosition() - m_position;
}

MFASeconds MFAKeyframe::getPosition() const
{
	return m_position;
}
void MFAKeyframe::setPosition(MFASeconds origin)
{
	m_position = origin;
}

MFAnimation* MFAKeyframe::getAnimation()
{
	return m_animation;
}

std::size_t MFAKeyframe::getIndex()
{
	assert(m_animation == 0);

	for(std::size_t index = 0; index < getAnimation()->keyframes().size(); ++index) {
		if(getAnimation()->keyframes()[index] == this)
			return index;
	}
	return 0;
}

MFAKeyframe* MFAKeyframe::findNeighbor()
{
	assert(m_animation == 0);

	std::size_t index = getIndex() + 1;

	if(index < getAnimation()->keyframes().size())
		return getAnimation()->keyframes()[index];
	return 0;
}

void MFAKeyframe::play()
{
}

MFAKeyframe::~MFAKeyframe()
{
}

