/*
 * Copyright (C) 2019 Dmitry Kozichev. All rights reserved.
 *
 * MFUserDefinedEvent.h
 * Created on 14.01.19 г.
 */

#pragma once

#include "MFEvent.h"

#include <string>
struct MFEDetail
{
	enum
	DetailType {
		TypeInteger,
		TypeString,
		TypePointer
	};
	DetailType type;

	// union
	double Integer;
	std::string String;
	void *Pointer;
};

#include <map>
typedef std::map<std::string, MFEDetail> MFEDetails;

class MFUserDefinedEvent : public MFEvent
{
	std::string m_name;
	MFEDetails m_details;

protected:
	static const EventType UserDefinedEventType = 101;

public:
	MFUserDefinedEvent(std::string, bool bubbles = false, bool cancelable = false,
			MFEDetails details = MFEDetails());

	EventType getType() override;

	std::string getEventName();
	MFEDetails& details();
};

class MFEventTarget;

typedef void(*MFUserDefinedEventCallback)(MFEventTarget* self, MFUserDefinedEvent e);

struct MFUserDefinedEventHandler
{
	MFUserDefinedEventCallback callback;
	MFUserDefinedEvent event;

	MFUserDefinedEventHandler(MFUserDefinedEventCallback, MFUserDefinedEvent);
};

#include <vector>
class MFUserDefinedEventListner
{
	std::vector<MFUserDefinedEventHandler> m_sequence;
	MFEventTarget* m_assigned_target;
public:
	void operator+=(MFUserDefinedEventHandler);
	void operator-=(MFUserDefinedEventHandler);
	MFEventTarget* getAssignedTarget();

	void dispatch(std::string);

	MFUserDefinedEventListner(MFEventTarget* assignedTarget);
};


