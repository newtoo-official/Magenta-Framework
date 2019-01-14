/*
 * Copyright (C) 2019 Dmitry Kozichev. All rights reserved.
 *
 * MFUserDefinedEvent.cc
 * Created on 14 янв. 2019 г.
 */

#include "MFUserDefinedEvent.h"

MFUserDefinedEvent::MFUserDefinedEvent(std::string eventName, bool bubbles, bool cancelable,
		MFEDetails details)
:MFEvent(bubbles, cancelable), m_name(eventName), m_details(details)
{

}

MFEvent::EventType MFUserDefinedEvent::getType()
{
	return UserDefinedEventType;
}

std::string MFUserDefinedEvent::getEventName()
{
	return m_name;
}

MFEDetails& MFUserDefinedEvent::details()
{
	return m_details;
}

MFUserDefinedEventHandler::MFUserDefinedEventHandler
(MFUserDefinedEventCallback c, MFUserDefinedEvent e) : callback(c), event(e)
{
}

void MFUserDefinedEventListner::operator+=(MFUserDefinedEventHandler callback)
{
	m_sequence.push_back(callback);
}

void MFUserDefinedEventListner::operator-=(MFUserDefinedEventHandler callback)
{
	for(size_t index = 0; index < m_sequence.size(); index++)
	{
		if(m_sequence[index].callback == callback.callback) {
			m_sequence.erase(index + m_sequence.begin());
			break;
		}
	}
}

MFEventTarget* MFUserDefinedEventListner::getAssignedTarget()
{
	return m_assigned_target;
}

void MFUserDefinedEventListner::dispatch(std::string name)
{
	for(MFUserDefinedEventHandler& handler : m_sequence)
	{
		if(handler.event.getEventName() == name)
			handler.callback(m_assigned_target, handler.event);
	}
}

MFUserDefinedEventListner::MFUserDefinedEventListner(MFEventTarget* assignedTarget)
: m_assigned_target(assignedTarget)
{
}

