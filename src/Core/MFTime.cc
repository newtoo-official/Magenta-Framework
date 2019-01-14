/*
 * Copyright (C) 2019 Dmitry Kozichev. All rights reserved.
 *
 * MFTime.cc
 * Created on 14.01.19 г.
 */

#include "MFTime.h"

#include <sys/time.h>
MFTimeStamp MFTime::getTimeStampSinceUnixEpoch()
{
	struct timeval tv;
	gettimeofday(&tv, 0);

	unsigned long long in_milliseconds = (unsigned long long)(tv.tv_sec) * 1000
			+ (unsigned long long)(tv.tv_usec) / 1000;

	return (double)in_milliseconds;
}
MFTimeStamp MFTime::getRelativeTimeStamp(MFTimeStamp timeStamp)
{
	return getTimeStampSinceUnixEpoch() - timeStamp;
}

