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
#include "Color.h"

NAMESPACE_MAGICAL

const Color4f Color4f::Red = { 1.0f, 0.0f, 0.0f, 1.0f };
const Color4f Color4f::Green = { 0.0f, 1.0f, 0.0f, 1.0f };
const Color4f Color4f::Blue = { 0.0f, 0.0f, 1.0f, 1.0f };
const Color4f Color4f::White = { 1.0f, 1.0f, 1.0f, 1.0f };
const Color4f Color4f::Black = { 0.0f, 0.0f, 0.0f, 1.0f };
const Color4f Color4f::Yello = { 1.0f, 1.0f, 0.0f, 1.0f };
const Color4f Color4f::Magenta = { 1.0f, 0.0f, 1.0f, 1.0f };
const Color4f Color4f::Cyan = { 0.0f, 1.0f, 1.0f, 1.0f };
const Color4f Color4f::DarkGray = { 0.25f, 0.25f, 0.25f, 1.0f };
const Color4f Color4f::LightGray = { 0.75f, 0.75f, 0.75f, 1.0f };
const Color4f Color4f::Brown = { 0.6f, 0.4f, 0.12f, 1.0f };
const Color4f Color4f::Orange = { 0.98f, 0.625f, 0.12f, 1.0f };
const Color4f Color4f::Pink = { 0.98f, 0.04f, 0.7f, 1.0f };
const Color4f Color4f::Purple = { 0.6f, 0.4f, 0.7f, 1.0f };

const Color4b Color4b::Red = { 255, 0, 0, 255 };
const Color4b Color4b::Green = { 0, 255, 0, 255 };
const Color4b Color4b::Blue = { 0, 0, 255, 255 };
const Color4b Color4b::White = { 255, 255, 255, 255 };
const Color4b Color4b::Black = { 0, 0, 0, 255 };
const Color4b Color4b::Yello = { 255, 255, 0, 255 };
const Color4b Color4b::Magenta = { 255, 0, 255, 255 };
const Color4b Color4b::Cyan = { 0, 255, 255, 255 };
const Color4b Color4b::DarkGray = { 64, 64, 64, 255 };
const Color4b Color4b::LightGray = { 191, 191, 191, 255 };
const Color4b Color4b::Brown = { 153, 102, 31, 255 };
const Color4b Color4b::Orange = { 250, 159, 31, 255 };
const Color4b Color4b::Pink = { 250, 10, 179, 255 };
const Color4b Color4b::Purple = { 153, 102, 179, 255 };

NAMESPACE_END