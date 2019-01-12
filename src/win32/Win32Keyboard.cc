/*
 * Copyright (C) 2018 Dmitry Kozichev. All rights reserved.
 *
 * Win32Keyboard.cc
 * Created on 13 џэт. 2019 у.
 */

#include "Win32Keyboard.h"

#ifdef _WIN32
#include <windows.h>

MFKeyCode keyCodeFromVirtualKey(short vkey)
{
	switch (vkey)
	{
	default: return MFKeyCode::Undefined; break;
	case 0x03: return MFKeyCode::Cancel; break;
	case 0x08: return MFKeyCode::Back; break;
	case 0x09: return MFKeyCode::Tab; break;
	case 0x0D: return MFKeyCode::Enter; break;
	case 0x10: return MFKeyCode::Shift; break;
	case 0x11: return MFKeyCode::Control; break;
	case 0x12: return MFKeyCode::Alt; break;
	case 0x13: return MFKeyCode::Pause; break;
	case 0x14: return MFKeyCode::CapsLock; break;
	case 0x1B: return MFKeyCode::Escape; break;
	case 0x20: return MFKeyCode::Space; break;
	case 0x21: return MFKeyCode::PageUp; break;
	case 0x22: return MFKeyCode::PageDown; break;
	case 0x23: return MFKeyCode::End; break;
	case 0x24: return MFKeyCode::Home; break;
	case 0x25: return MFKeyCode::Left; break;
	case 0x26: return MFKeyCode::Top; break;
	case 0x27: return MFKeyCode::Right; break;
	case 0x28: return MFKeyCode::Bottom; break;
	case 0x29: return MFKeyCode::Select; break;
	case 0x2A: return MFKeyCode::Print; break;
	case 0x2C: return MFKeyCode::PrintScreen; break;
	case 0x2D: return MFKeyCode::Insert; break;
	case 0x2E: return MFKeyCode::Delete; break;
	case 0x30: return MFKeyCode::One; break;
	case 0x31: return MFKeyCode::Two; break;
	case 0x32: return MFKeyCode::Three; break;
	case 0x33: return MFKeyCode::Four; break;
	case 0x34: return MFKeyCode::Five; break;
	case 0x35: return MFKeyCode::Six; break;
	case 0x36: return MFKeyCode::Seven; break;
	case 0x37: return MFKeyCode::Eight; break;
	case 0x38: return MFKeyCode::Nine; break;
	case 0x39: return MFKeyCode::Zero; break;
	case 0x41: return MFKeyCode::A; break;
	case 0x42: return MFKeyCode::B; break;
	case 0x43: return MFKeyCode::C; break;
	case 0x44: return MFKeyCode::D; break;
	case 0x45: return MFKeyCode::E; break;
	case 0x46: return MFKeyCode::F; break;
	case 0x47: return MFKeyCode::G; break;
	case 0x48: return MFKeyCode::H; break;
	case 0x49: return MFKeyCode::I; break;
	case 0x4A: return MFKeyCode::J; break;
	case 0x4B: return MFKeyCode::K; break;
	case 0x4C: return MFKeyCode::L; break;
	case 0x4D: return MFKeyCode::M; break;
	case 0x4E: return MFKeyCode::N; break;
	case 0x4F: return MFKeyCode::O; break;
	case 0x50: return MFKeyCode::P; break;
	case 0x51: return MFKeyCode::Q; break;
	case 0x52: return MFKeyCode::R; break;
	case 0x53: return MFKeyCode::S; break;
	case 0x54: return MFKeyCode::T; break;
	case 0x55: return MFKeyCode::U; break;
	case 0x56: return MFKeyCode::V; break;
	case 0x57: return MFKeyCode::W; break;
	case 0x58: return MFKeyCode::X; break;
	case 0x59: return MFKeyCode::Y; break;
	case 0x5A: return MFKeyCode::Z; break;
	case 0x5B: return MFKeyCode::Win; break;
	case 0x70: return MFKeyCode::F1; break;
	case 0x71: return MFKeyCode::F2; break;
	case 0x72: return MFKeyCode::F3; break;
	case 0x73: return MFKeyCode::F4; break;
	case 0x74: return MFKeyCode::F5; break;
	case 0x75: return MFKeyCode::F6; break;
	case 0x76: return MFKeyCode::F7; break;
	case 0x77: return MFKeyCode::F8; break;
	case 0x78: return MFKeyCode::F9; break;
	case 0x79: return MFKeyCode::F10; break;
	case 0x7A: return MFKeyCode::F11; break;
	case 0x7B: return MFKeyCode::F12; break;
	case 0x90: return MFKeyCode::NumLock; break;
	case 0xA0: return MFKeyCode::LeftShift; break;
	case 0xA1: return MFKeyCode::RightShift; break;
	case 0xA2: return MFKeyCode::LeftControl; break;
	case 0xA3: return MFKeyCode::RightControl; break;
	case 0xA4: return MFKeyCode::LeftAlt; break;
	case 0xA5: return MFKeyCode::RightAlt; break;
	case 0xBA: return MFKeyCode::OEM_1; break;
	case 0xE2: return MFKeyCode::OEM_102; break;
	case 0xBF: return MFKeyCode::OEM_2; break;
	case 0xC0: return MFKeyCode::OEM_3; break;
	case 0xDB: return MFKeyCode::OEM_4; break;
	case 0xDC: return MFKeyCode::OEM_5; break;
	case 0xDD: return MFKeyCode::OEM_6; break;
	case 0xDE: return MFKeyCode::OEM_7; break;
	case 0xDF: return MFKeyCode::OEM_8; break;
	case 0xBD: return MFKeyCode::OEM_Minus; break;
	case 0xBC: return MFKeyCode::OEM_Comma; break;
	case 0xBE: return MFKeyCode::OEM_Period; break;
	case 0xBB: return MFKeyCode::OEM_Plus; break;
	}
}

short characterVirtualKeyFromKeyCode(MFKeyCode keyCode)
{
	switch (keyCode)
	{
	default: return MFKeyboard::NotCharacter;
	case MFKeyCode::One: return 0x30; break;
	case MFKeyCode::Two: return 0x31; break;
	case MFKeyCode::Three: return 0x32; break;
	case MFKeyCode::Four: return 0x33; break;
	case MFKeyCode::Five: return 0x34; break;
	case MFKeyCode::Six: return 0x35; break;
	case MFKeyCode::Seven: return 0x36; break;
	case MFKeyCode::Eight: return 0x37; break;
	case MFKeyCode::Nine: return 0x38; break;
	case MFKeyCode::Zero: return 0x39; break;
	case MFKeyCode::A: return 0x41; break;
	case MFKeyCode::B: return 0x42; break;
	case MFKeyCode::C: return 0x43; break;
	case MFKeyCode::D: return 0x44; break;
	case MFKeyCode::E: return 0x45; break;
	case MFKeyCode::F: return 0x46; break;
	case MFKeyCode::G: return 0x47; break;
	case MFKeyCode::H: return 0x48; break;
	case MFKeyCode::I: return 0x49; break;
	case MFKeyCode::J: return 0x4A; break;
	case MFKeyCode::K: return 0x4B; break;
	case MFKeyCode::L: return 0x4C; break;
	case MFKeyCode::M: return 0x4D; break;
	case MFKeyCode::N: return 0x4E; break;
	case MFKeyCode::O: return 0x4F; break;
	case MFKeyCode::P: return 0x50; break;
	case MFKeyCode::Q: return 0x51; break;
	case MFKeyCode::R: return 0x52; break;
	case MFKeyCode::S: return 0x53; break;
	case MFKeyCode::T: return 0x54; break;
	case MFKeyCode::U: return 0x55; break;
	case MFKeyCode::V: return 0x56; break;
	case MFKeyCode::W: return 0x57; break;
	case MFKeyCode::X: return 0x58; break;
	case MFKeyCode::Y: return 0x59; break;
	case MFKeyCode::Z: return 0x5A; break;
	case MFKeyCode::OEM_1: return 0xBA; break;
	case MFKeyCode::OEM_102: return 0xE2; break;
	case MFKeyCode::OEM_2: return 0xBF; break;
	case MFKeyCode::OEM_3: return 0xC0; break;
	case MFKeyCode::OEM_4: return 0xDB; break;
	case MFKeyCode::OEM_5: return 0xDC; break;
	case MFKeyCode::OEM_6: return 0xDD; break;
	case MFKeyCode::OEM_7: return 0xDE; break;
	case MFKeyCode::OEM_8: return 0xDF; break;
	case MFKeyCode::OEM_Minus: return 0xBD; break;
	case MFKeyCode::OEM_Comma: return 0xBC; break;
	case MFKeyCode::OEM_Period: return 0xBE; break;
	case MFKeyCode::OEM_Plus: return 0xBB; break;
	case MFKeyCode::Space: return 0x20; break;
	case MFKeyCode::Enter: return 0x0D; break;
	}
}

#endif

