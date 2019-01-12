/*
 * Copyright (C) 2018 Dmitry Kozichev. All rights reserved.
 *
 * MFAnimationCycle.cc
 * Created on 12 џэт. 2019 у.
 */

#include "MFAnimationCycle.h"
#include <pthread.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define MFACycleState MFAnimation::AnimationCycleState // alias

bool MFAnimationCycle::isAnimationDeleted()
{
	return m_animation->getCycleState() == MFACycleState::PendingToTerminate;
}
void MFAnimationCycle::terminate()
{
	m_animation->setCycleState(MFACycleState::Terminated);
}

void* MFAnimationCycle::threadFunction(void* arg)
{
	MFAnimationCycle* self = (MFAnimationCycle*)arg;

	while(!self->isAnimationDeleted())
	{
		self->m_animation->playFrame();
#ifdef _WIN32
		Sleep(RepeatEveryMs);
#elif _OSX
		//TODO: repeat duration for macOS
#endif
	}
	self->terminate();
	pthread_exit(0);
	return 0;
}

MFAnimationCycle::MFAnimationCycle(MFAnimation *animation) : m_animation(animation)
{
}

void MFAnimationCycle::run()
{
	pthread_t thread;
	pthread_create(&thread, 0, threadFunction, (void*)this);
	pthread_detach(thread);
}
