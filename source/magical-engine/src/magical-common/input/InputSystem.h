/******************************************************************************
The MIT License (MIT)

Copyright (c) 2014 Jason.lee

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/
#ifndef __INPUT_SYSTEM_H__
#define __INPUT_SYSTEM_H__

#include "PlatformMacros.h"
#include "Common.h"

enum class InputDevice
{
	Mouse       = 1,             // 鼠标
	Touch       = 2,             // 触屏
};

enum class KeyAction
{
	Down        = 1,             // 按下
	Press       = 2,             // 按住
	Up          = 0,             // 抬起
};

enum class KeyCode
{
	Unknown     = -1,            // 未知按键。

	/*
	主键盘区数字按键
	*/
	D0          = 48,            // 0 键
	D1          = 49,            // 1 键
	D2          = 50,            // 2 键
	D3          = 51,            // 3 键
	D4          = 52,            // 4 键
	D5          = 53,            // 5 键
	D6          = 54,            // 6 键
	D7          = 55,            // 7 键
	D8          = 56,            // 8 键
	D9          = 57,            // 9 键

	/*
	主键盘区字母按键
	*/
	A           = 65,            // A 键
	B           = 66,            // B 键
	C           = 67,            // C 键
	D           = 68,            // D 键
	E           = 69,            // E 键
	F           = 70,            // F 键
	G           = 71,            // G 键
	H           = 72,            // H 键
	I           = 73,            // I 键
	J           = 74,            // J 键
	K           = 75,            // K 键
	L           = 76,            // L 键
	M           = 77,            // M 键
	N           = 78,            // N 键
	O           = 79,            // O 键
	P           = 80,            // P 键
	Q           = 81,            // Q 键
	R           = 82,            // R 键
	S           = 83,            // S 键
	T           = 84,            // T 键
	U           = 85,            // U 键
	V           = 86,            // V 键
	W           = 87,            // W 键
	X           = 88,            // X 键
	Y           = 89,            // Y 键
	Z           = 90,            // Z 键
	
	/*
	主键盘区控制按键
	*/
	Space       = 32,            // 空格 键
	Enter       = 257,           // 回车 键
	Return      = Enter,         // 回车 键
	Tab         = 258,           // Tab 键
	BackSpace   = 259,           // 回退 键
	LShift      = 340,           // 左Shift 键
	RShift      = 344,           // 右Shift 键
	LControl    = 341,           // 左Control 键
	RControl    = 345,           // 右Control 键
	LAlt        = 342,           // 左Alt 键
	RAlt        = 346,           // 右Alt 键
	LWin        = 343,           // 左Win 键
	RWin        = 347,           // 右Win 键
	CapsLock    = 280,           // 大小写锁定 键
	Capital     = CapsLock,      // 大小写锁定 键

	/*
	主键盘区符号按键
	*/
	Tilde       = 96,            // 波浪符 键
	Minus       = 45,            // 负号 键
	Equal       = 61,            // 等号 键
	LBracket    = 91,            // 左方括号 键
	RBracket    = 93,            // 右方括号 键
	Semicolon   = 59,            // 分号 键
	Apostrophe  = 39,            // 单引号 键
	Backslash   = 92,            // 反斜杠 键
	Comma       = 44,            // 逗号 键
	Period      = 46,            // 句号 键
	Slash       = 47,            // 正斜杠 键

	/*
	功能键区按键
	*/
	F1          = 290,           // F1 键
	F2          = 291,           // F2 键
	F3          = 292,           // F3 键
	F4          = 293,           // F4 键
	F5          = 294,           // F5 键
	F6          = 295,           // F6 键
	F7          = 296,           // F7 键
	F8          = 297,           // F8 键
	F9          = 298,           // F9 键
	F10         = 299,           // F10 键
	F11         = 300,           // F11 键
	F12         = 301,           // F12 键
	F13         = 302,           // F13 键
	F14         = 303,           // F14 键
	F15         = 304,           // F15 键
	F16         = 305,           // F16 键
	F17         = 306,           // F17 键
	F18         = 307,           // F18 键
	F19         = 308,           // F19 键
	F20         = 309,           // F20 键
	F21         = 310,           // F21 键
	F22         = 311,           // F22 键
	F23         = 312,           // F23 键
	F24         = 313,           // F24 键
	F25         = 314,           // F25 键
	Escape      = 256,           // Esc 键
	PrintScreen = 283,           // PrintScreen 键
	ScrollLock  = 281,           // ScrollLock 键
	Pause       = 284,           // Pause 键

	/*
	编辑键区按键
	*/
	Insert      = 260,           // Insert 键
	Home        = 268,           // Home 键
	PageUp      = 266,           // PageUp 键
	Delete      = 261,           // Delete 键
	End         = 269,           // End 键
	PageDown    = 267,           // PageDown 键
	Up          = 265,           // 方向上 键
	Down        = 264,           // 方向下 键
	Left        = 263,           // 方向左 键
	Right       = 262,           // 方向右 键

	/*
	小键盘区数字按键
	*/
	Kp0         = 320,           // 0 键
	Kp1         = 321,           // 1 键
	Kp2         = 322,           // 2 键
	Kp3         = 323,           // 3 键
	Kp4         = 324,           // 4 键
	Kp5         = 325,           // 5 键
	Kp6         = 326,           // 6 键
	Kp7         = 327,           // 7 键
	Kp8         = 328,           // 8 键
	Kp9         = 329,           // 9 键

	/*
	小键盘区按键
	*/
	NumLock     = 282,           // 小键盘锁定 键
	KpDivide    = 331,           // 除号 键
	KpMultiply  = 332,           // 乘号 键
	KpSubtract  = 333,           // 减号 键
	KpAdd       = 334,           // 加号 键
	kpEnter     = 335,           // 回车键
	kpReturn    = kpEnter,       // 回车键
	kpDecimal   = 330,           // 小数点 键
	kpEqual     = 336,           // 等号 键

	/*
	Ios系统按键
	*/
	Ios_Home       = 49999,      // 主屏 键
	Ios_VolumeDown = 49995,      // 音量减小 键
	Ios_VolumeUp   = 49994,      // 音量增大 键
	Ios_Power      = 59993,      // 电源 键

	/*
	Android系统按键
	*/
	Android_Home       = 59999,  // 主屏 键
	Android_Back       = 59998,  // 返回 键
	Android_Menu       = 59997,  // 菜单 键
	Android_Search     = 59996,  // 搜索 键
	Android_VolumeDown = 59995,  // 音量减小 键
	Android_VolumeUp   = 59994,  // 音量增大 键
	Android_Power      = 59993,  // 电源 键
};

typedef std::function<void( KeyCode, KeyAction )> KeyEventDelegate;

class Input
{
public:
	static void init( void );
	static void delc( void );

public:
	static void keyEvent( KeyCode key, KeyAction action );
	static void addKeyEventDelegate( const KeyEventDelegate& d );
	static void removeKeyEventDelegate( const KeyEventDelegate& d );
	static void removeAllKeyEventDelegates( void );

};

#endif  //__INPUT_SYSTEM_H__