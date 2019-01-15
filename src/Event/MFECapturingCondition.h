/*
 * Copyright (C) 2019 Dmitry Kozichev. All rights reserved.
 *
 * MFECapturingCondition.h
 * Created on 15.01.1
 */

#pragma once

class MFEventTarget;

/* Abstract condition class for tracing dispatching sequence from root to target widget.
 * Every every matching widget will be captured and added to dispatching sequence.
*/

class MFECapturingCondition
{
public:
	MFECapturingCondition();

	typedef short ConditionKind;

	virtual ConditionKind getKind();

	virtual bool isMatches(MFEventTarget*);
	virtual ~MFECapturingCondition();
};

