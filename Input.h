#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include "Vector2.h"
#include <vector>

class Input {
public:
	//Input();
	//~Input();

	//An enum of every keycode (still not complete but more than enough for this game)
	enum KeyCode{A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
					LeftArrow, RightArrow, UpArrow, DownArrow,
					Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
					UNKNOWN};

	void GetInput(const Uint8* keyboard);		//Store the keys pressed this frame

	static bool GetKey(KeyCode key);			//A key is held down
	static bool GetKeyDown(KeyCode key);		//A key was pressed this frame
	static bool GetKeyUp(KeyCode key);			//A key was released this frame
	static bool AnyKey();						//Any key is currently held down

	static bool GetMouseButton(int button);		//A mouse button is held down
	static bool GetMouseButtonDown(int button);	//A mouse button was pressed this frame
	static bool GetMouseButtonUp(int button);	//A mouse button was released this frame

	static Vector2 GetMousePosition();			//Get the position of the mouse on the screen

private:
	static Uint8* m_InputThisFrame;
	static Uint8* m_InputLastFrame;
	static SDL_Scancode KeyCodeToScanCode(KeyCode key);				//Convert a provided scancode to keycode
};
#endif // !INPUT_H
