/*
 * Copyright (C) 2018 Dmitry Kozichev. All rights reserved.
 *
 * MFAnimationCycle.h
 * Created on 12 џэт. 2019 у.
 */

#pragma once

#include "MFAnimation.h"

class MFAnimationCycle
{
	MFAnimation* m_animation;
	static const unsigned int RepeatEveryMs = 10;

	bool isAnimationDeleted();
	void terminate();

	static void* threadFunction(void*);

public:
	MFAnimationCycle(MFAnimation*);

	void run();
};

