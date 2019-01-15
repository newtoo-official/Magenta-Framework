/*
 * Copyright (C) 2019 Dmitry Kozichev. All rights reserved.
 *
 * MFKeyboard.cc
 * Created on 13.01.2019
 */

#include "MFKeyboard.h"

#ifdef _WIN32
#include "../win32/Win32Keyboard.h"
#endif

MFKeyboard::MFKeyboard(MFFocusedWidget* focusedWidget) : m_focused_widget(focusedWidget)
{
}

unsigned int MFKeyboard::keyCodeToCharacter(MFKeyCode keyCode)
{
	return 0; //TODO: make KeyCode to character conversion
}

MFWidget* MFKeyboard::getFocusedWidget()
{
	MFWidget** widget = (MFWidget**)m_focused_widget;
	return *widget;
}

void MFKeyboard::emitKeydown(MFKeyCode keycode)
{
	switch(keycode)
	{
	case MFKeyCode::Control:
		m_control_pressed = true;
		break;
	case MFKeyCode::RightControl:
		m_control_pressed = true;
		break;
	case MFKeyCode::LeftControl:
		m_control_pressed = true;
		break;
	case MFKeyCode::Shift:
		m_shift_pressed = true;
		break;
	case MFKeyCode::RightShift:
		m_shift_pressed = true;
		break;
	case MFKeyCode::LeftShift:
		m_shift_pressed = true;
		break;
	case MFKeyCode::Alt:
		m_alt_pressed = true;
		break;
	case MFKeyCode::RightAlt:
		m_alt_pressed = true;
		break;
	case MFKeyCode::LeftAlt:
		m_alt_pressed = true;
		break;
	default:
		break;
	}
	//TODO: Dispatch keydown event on focused widget
}
void MFKeyboard::emitKeyup(MFKeyCode keycode)
{
	switch(keycode)
	{
	case MFKeyCode::Control:
		m_control_pressed = false;
		break;
	case MFKeyCode::RightControl:
		m_control_pressed = false;
		break;
	case MFKeyCode::LeftControl:
		m_control_pressed = false;
		break;
	case MFKeyCode::Shift:
		m_shift_pressed = false;
		break;
	case MFKeyCode::RightShift:
		m_shift_pressed = false;
		break;
	case MFKeyCode::LeftShift:
		m_shift_pressed = false;
		break;
	case MFKeyCode::Alt:
		m_alt_pressed = false;
		break;
	case MFKeyCode::RightAlt:
		m_alt_pressed = false;
		break;
	case MFKeyCode::LeftAlt:
		m_alt_pressed = false;
		break;
	default:
		break;
	}
	//TODO: Dispatch keydown event on focused widget
}

bool MFKeyboard::isControlPressed() const
{
	return m_control_pressed;
}
bool MFKeyboard::isShiftPressed() const
{
	return m_shift_pressed;
}
bool MFKeyboard::isAltPressed() const
{
	return m_alt_pressed;
}
