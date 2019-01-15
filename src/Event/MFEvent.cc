/*
 * Copyright (C) 2019 Dmitry Kozichev. All rights reserved.
 *
 * MFEvent.cc
 * Created on 14.01.19
 */

#include "MFEvent.h"

MFEResult::MFEResult() : canceled(false), propagation(Allowed)
{
}

MFEvent::MFEvent(bool bubbles, bool cancelable, MFEventTarget *currentTarget,
		MFEventTarget *target, Phase phase)
: m_timestamp(MFTime::getTimeStampSinceUnixEpoch()), m_current_target(currentTarget),
  m_target(target), m_can_bubble(bubbles), m_cancelable(cancelable), m_phase(phase)
{
}

MFEvent::EventType MFEvent::getType()
{
	return 0;
}

MFEResult& MFEvent::result()
{
	return m_result;
}

MFTimeStamp MFEvent::getTimeStamp() const
{
	return m_timestamp;
}

MFEventTarget* MFEvent::getCurrentTarget() const
{
	return m_current_target;
}

MFEventTarget* MFEvent::getTarget() const
{
	return m_target;
}


MFEvent::Phase MFEvent::getPhase() const
{
	return m_phase;
}

void MFEvent::setPhase(Phase phase)
{
	m_phase = phase;
}

bool MFEvent::canBubble() const
{
	return m_can_bubble;
}

bool MFEvent::isCancelable() const
{
	return m_cancelable;
}

bool MFEvent::isCanceled() const
{
	return m_result.canceled;
}

void MFEvent::cancel()
{
	m_result.canceled = true;
}

void MFEvent::stopImmediatePropagation()
{
	m_result.propagation = MFEResult::ImmediatelyStopped;
}
void MFEvent::stopPropagation()
{
	m_result.propagation = MFEResult::Stopped;
}

MFEvent::~MFEvent()
{
}

