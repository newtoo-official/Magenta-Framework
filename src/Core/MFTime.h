/*
 * Copyright (C) 2019 Dmitry Kozichev. All rights reserved.
 *
 * MFTime.h
 * Created on 14.01.19 г.
 */

#pragma once

typedef double MFTimeStamp;

class MFTime {
public:

/* Low resolution time stamp in milliseconds
 */

static MFTimeStamp getTimeStampSinceUnixEpoch();
static MFTimeStamp getRelativeTimeStamp(MFTimeStamp);
};

