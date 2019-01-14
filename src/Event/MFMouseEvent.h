/*
 * Copyright (C) 2019 Dmitry Kozichev. All rights reserved.
 *
 * MFMouseEvent.h
 * Created on 14.01.19
 */

#pragma once

#include "MFEvent.h"

class MFMouseEvent : public MFEvent
{
public:
	MFMouseEvent();
	~MFMouseEvent() override;
};

