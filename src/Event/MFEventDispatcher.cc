/*
 * Copyright (C) 2019 Dmitry Kozichev. All rights reserved.
 *
 * MFEventProvider.cc
 * Created on 14.01.19
 */

#include "MFEventDispatcher.h"

void MFEventDispatcher::traceRecursive(MFEDispatchingSequence& sequence,
		MFEventDispatcher* dispatcher, MFEventTarget* current)
{
	//TODO: make tracing
}

MFEDispatchingSequence MFEventDispatcher::traceRoot()
{
	MFEDispatchingSequence sequence;
	traceRecursive(sequence, this, m_root);
	return sequence;
}

MFEventDispatcher::MFEventDispatcher(MFEventTarget *root, MFEvent *event,
		MFECapturingCondition *condition, MFEDispatchingCallback callback)
:m_condition(condition), m_root(root), m_event(event), m_callback(callback)
{
}

MFECapturingCondition* MFEventDispatcher::getCapturingCondition() const
{
	return m_condition;
}
MFEventTarget* MFEventDispatcher::getRoot() const
{
	return m_root;
}
MFEvent* MFEventDispatcher::getEvent() const
{
	return m_event;
}

MFEDispatchingCallback MFEventDispatcher::getCallback() const
{
	return m_callback;
}

void MFEventDispatcher::fire()
{
	MFEDispatchingSequence sequence = traceRoot();

	//Capturing
	m_event->setPhase(MFEvent::Tracing);
	for(std::size_t i = 0; i < sequence.size() - 1; ++i) {
		m_callback(sequence[i], m_event, true);
	}
	m_event->setPhase(MFEvent::AtTarget);
	m_callback(sequence[sequence.size() - 1], m_event, true);

	//Bubbling
	m_callback(sequence[sequence.size() - 1], m_event, false);
	m_event->setPhase(MFEvent::Bubbling);
	for(std::size_t i = sequence.size() - 1; i > 0; --i) {
		m_callback(sequence[i], m_event, false);
	}
}

