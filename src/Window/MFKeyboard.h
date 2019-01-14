/*
 * Copyright (C) 2019 Dmitry Kozichev. All rights reserved.
 *
 * MFKeyboard.h
 * Created on 13.01.2019
 */

#pragma once

enum class MFKeyCode
{
	Cancel,
	Back,
	Tab,
	Enter,
	Shift,
	Control,
	Alt,
	Pause,
	CapsLock,
	Escape,
	Space,
	PageUp,
	PageDown,
	End,
	Home,
	Left,
	Top,
	Right,
	Bottom,
	Select,
	Print,
	PrintScreen,
	Insert,
	Delete,
	One,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Zero,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	Win,
	F1,
	F2,
	F3,
	F4,
	F5,
	F6,
	F7,
	F8,
	F9,
	F10,
	F11,
	F12,
	NumLock,
	LeftShift,
	RightShift,
	LeftControl,
	RightControl,
	LeftAlt,
	RightAlt,
	OEM_1,
	OEM_102,
	OEM_2,
	OEM_3,
	OEM_4,
	OEM_5,
	OEM_6,
	OEM_7,
	OEM_8,
	OEM_Minus,
	OEM_Comma,
	OEM_Period,
	OEM_Plus,
	Undefined
};

class MFFocusedWidget;
class MFWidget;

class MFKeyboard
{
	MFFocusedWidget *m_focused_widget;
	bool m_control_pressed = false;
	bool m_shift_pressed = false;
	bool m_alt_pressed = false;

public:
	MFKeyboard(MFFocusedWidget*);

	static const unsigned int NotCharacter = 0;
	static unsigned int keyCodeToCharacter(MFKeyCode keyCode);

	MFWidget* getFocusedWidget();

	void emitKeydown(MFKeyCode);
	void emitKeyup(MFKeyCode);

	bool isControlPressed() const;
	bool isShiftPressed() const;
	bool isAltPressed() const;
};

