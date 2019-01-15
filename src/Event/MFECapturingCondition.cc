/*
 * Copyright (C) 2019 Dmitry Kozichev. All rights reserved.
 *
 * MFECapturingCondition.cc
 * Created on 15.01.19
 */

#include "MFECapturingCondition.h"

MFECapturingCondition::MFECapturingCondition()
{
}

MFECapturingCondition::ConditionKind getKind()
{
	return 0;
}

bool MFECapturingCondition::isMatches(MFEventTarget *widget)
{
	/* Virtual method for matching algorithm that used in event dispatcher to trace
	 * sequence to target widget
	*/
	return false;
}
MFECapturingCondition::~MFECapturingCondition()
{
}
