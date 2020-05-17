#include "Input.h"
#include <iostream>

Uint8* Input::m_InputThisFrame = 0;
Uint8* Input::m_InputLastFrame = 0;

SDL_Scancode Input::KeyCodeToScanCode(Input::KeyCode key) {
	switch (key) {
		case Num0: return SDL_SCANCODE_0;
		case Num1: return SDL_SCANCODE_1;
		case Num2: return SDL_SCANCODE_2;
		case Num3: return SDL_SCANCODE_3;
		case Num4: return SDL_SCANCODE_4;
		case Num5: return SDL_SCANCODE_5;
		case Num6: return SDL_SCANCODE_6;
		case Num7: return SDL_SCANCODE_7;
		case Num8: return SDL_SCANCODE_8;
		case Num9: return SDL_SCANCODE_9;
		case A: return SDL_SCANCODE_A;
		case B: return SDL_SCANCODE_B;
		case C: return SDL_SCANCODE_C;
		case D: return SDL_SCANCODE_D;
		case E: return SDL_SCANCODE_E;
		case F: return SDL_SCANCODE_F;
		case G: return SDL_SCANCODE_G;
		case H: return SDL_SCANCODE_H;
		case I: return SDL_SCANCODE_I;
		case J: return SDL_SCANCODE_J;
		case K: return SDL_SCANCODE_K;
		case L: return SDL_SCANCODE_L;
		case M: return SDL_SCANCODE_M;
		case N: return SDL_SCANCODE_N;
		case O: return SDL_SCANCODE_O;
		case P: return SDL_SCANCODE_P;
		case Q: return SDL_SCANCODE_Q;
		case R: return SDL_SCANCODE_R;
		case S: return SDL_SCANCODE_S;
		case T: return SDL_SCANCODE_T;
		case U: return SDL_SCANCODE_U;
		case V: return SDL_SCANCODE_V;
		case W: return SDL_SCANCODE_W;
		case X: return SDL_SCANCODE_X;
		case Y: return SDL_SCANCODE_Y;
		case Z: return SDL_SCANCODE_Z;
		case UpArrow: return SDL_SCANCODE_UP;
		case DownArrow: return SDL_SCANCODE_DOWN;
		case LeftArrow: return SDL_SCANCODE_LEFT;
		case RightArrow: return SDL_SCANCODE_RIGHT;
	}
	return SDL_SCANCODE_0;	//No key found (probably should change this later)
}

void Input::GetInput(const Uint8* keyboard) {
	if (m_InputThisFrame != 0) m_InputLastFrame = m_InputThisFrame;
	else m_InputLastFrame = const_cast<Uint8*>(keyboard);
	m_InputThisFrame = const_cast<Uint8*>(keyboard);
}

bool Input::GetKey(KeyCode key)
{
	if (m_InputLastFrame[KeyCodeToScanCode(key)]) return true;
	return false;
}

bool Input::GetKeyDown(KeyCode key)
{
	if (m_InputThisFrame[KeyCodeToScanCode(key)] && !m_InputLastFrame[KeyCodeToScanCode(key)]) return true;
	return false;
}

bool Input::GetKeyUp(KeyCode key)
{
	if (m_InputThisFrame[KeyCodeToScanCode(key)] && !m_InputLastFrame[KeyCodeToScanCode(key)]) return true;
	return false;
}

bool Input::AnyKey()
{
	return false;
}

bool Input::GetMouseButton(int button)
{
	return false;
}

bool Input::GetMouseButtonDown(int button)
{
	return false;
}

bool Input::GetMouseButtonUp(int button)
{
	return false;
}

Vector2 Input::GetMousePosition()
{
	return Vector2();
}
