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
#ifndef __MAIN_H__
#define __MAIN_H__

#include "magical-engine.h"

USING_NS_MAGICAL;

class MainCameraScript : public Behaviour<Camera>
{
public:
	virtual void onCreate( void );
	virtual void onStart( void );
	virtual void onUpdate( void );
	virtual void onStop( void );
	virtual void onDestroy( void );

	void onKeyEvent( KeyEvent* keyevent );
	void onMouseButtonEvent( MouseButtonEvent* mousebtnevnet );
	void onMouseMoveEvent( MouseMoveEvent* mousemoveevent );

private:
	bool m_w_pressed = false;
	bool m_d_pressed = false;
	bool m_a_pressed = false;
	bool m_s_pressed = false;
	bool m_right_button_down = false;
	double m_last_x = 0.0f;
	double m_last_y = 0.0f;

	Entity* entity1;
};

extern void mainDelegate( void );

#endif //__MAIN_H__