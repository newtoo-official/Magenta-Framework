/*
 * Copyright (C) 2018 Dmitry Kozichev. All rights reserved.
 *
 * MFAFrame.h
 * Created on 12 џэт. 2019 у.
 */

#pragma once

#include "MFAnimation.h"

class MFAKeyframe
{
protected:
	MFASeconds m_position;
	MFAnimation *m_animation = 0;

	typedef short KeyframeType;

private:
	KeyframeType m_type;

public:
	MFAKeyframe(KeyframeType type = 0, MFASeconds origin = 0.0f);

	KeyframeType getType() const;

	void setFoundation(MFAnimation *foundation);
	MFASeconds getDuration();

	MFASeconds getPosition() const;
	void setPosition(MFASeconds);

	MFAnimation *getAnimation();

	std::size_t getIndex();

	virtual MFAKeyframe *findNeighbor();
	virtual void play();

	virtual ~MFAKeyframe();
};

