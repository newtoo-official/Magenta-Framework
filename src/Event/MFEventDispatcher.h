/*
 * Copyright (C) 2019 Dmitry Kozichev. All rights reserved.
 *
 * MFEventDispatcher.h
 * Created on 14.01.19
 */

#pragma once

#include "MFECapturingCondition.h"
#include "MFEventTarget.h"
#include "MFEvent.h"

#include <vector>
typedef std::vector<MFEventTarget*> MFEDispatchingSequence;

typedef MFEResult(*MFEDispatchingCallback)(MFEventTarget*, MFEvent*, bool capturing);

class MFEventDispatcher
{
	MFECapturingCondition *m_condition;
	MFEventTarget *m_root;
	MFEvent *m_event;

	MFEDispatchingCallback m_callback;

	void traceRecursive(MFEDispatchingSequence &sequence, MFEventDispatcher *dispatcher,
			MFEventTarget *current);
	MFEDispatchingSequence traceRoot();

public:
	MFEventDispatcher(MFEventTarget*, MFEvent*, MFECapturingCondition*,
			MFEDispatchingCallback);

	MFECapturingCondition *getCapturingCondition() const;
	MFEventTarget *getRoot() const;
	MFEvent *getEvent() const;

	MFEDispatchingCallback getCallback() const;

	void fire();
};

