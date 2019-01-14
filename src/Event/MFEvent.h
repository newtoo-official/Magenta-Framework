/*
 * Copyright (C) 2019 Dmitry Kozichev. All rights reserved.
 *
 * MFEvent.h
 * Created on 14.01.19
 */

#pragma once

#include "MFEventTarget.h"
#include "../Core/MFTime.h"

struct MFEResult
{
	enum
	Propagation {
		Allowed,
		Stopped,
		ImmediatelyStopped
	};

	bool canceled;
	Propagation propagation;
	MFEResult();
};

class MFEvent
{
public:

	enum
	Phase {
		Tracing,
		AtTarget,
		Bubbling
	};

private:
	MFEResult m_result;
	MFTimeStamp m_timestamp;

	MFEventTarget* m_current_target;
	MFEventTarget* m_target;

	bool m_can_bubble, m_cancelable;

	Phase m_phase;

protected:
	typedef short EventType;

public:
	MFEvent(bool bubbles = false, bool cancelable = false, MFEventTarget* currentTarget = 0,
			MFEventTarget* target = 0, Phase phase = AtTarget);

	virtual EventType getType();

	MFEResult& result();

	MFTimeStamp getTimeStamp() const;

	MFEventTarget* getCurrentTarget() const;
	MFEventTarget* getTarget() const;


	Phase getPhase() const;

	bool canBubble() const;
	bool isCancelable() const;
	bool isCanceled() const;
	void cancel();

	void stopImmediatePropagation();
	void stopPropagation();

	virtual ~MFEvent();
};

