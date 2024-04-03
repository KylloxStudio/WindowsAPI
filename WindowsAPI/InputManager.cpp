#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_CODE_COUNT, KeyState::None);
}

void InputManager::Update()
{
	::GetCursorPos(&_mousePos);
	::ScreenToClient(_hWnd, &_mousePos);

	BYTE asciiKeys[KEY_CODE_COUNT] = {};
	if (::GetKeyboardState(asciiKeys) == false)
	{
		return;
	}

	for (uint32 key = 0; key < KEY_CODE_COUNT; key++)
	{
		if (0 < (asciiKeys[key] & 0x80)) // key가 눌려져있다.
		{
			KeyState& state = _states[key];
			if (state == KeyState::Press || state == KeyState::Down) // 누르고있었다.
			{
				state = KeyState::Press;
			}
			else // 이제막 눌렀다.
			{
				state = KeyState::Down;
			}
		}
		else //key가 안눌려져있다.
		{
			KeyState& state = _states[key];
			if (state == KeyState::Press || state == KeyState::Down) // 누르고있었던 상태면
			{
				state = KeyState::Up;
			}
			else
			{
				state = KeyState::None;
			}
		}
	}
}

bool InputManager::GetKey(KeyCode key)
{
	return GetState(key) == KeyState::Press;
}

bool InputManager::GetKeyDown(KeyCode key)
{
	return GetState(key) == KeyState::Down;
}

bool InputManager::GetKeyUp(KeyCode key)
{
	return GetState(key) == KeyState::Up;
}

POINT InputManager::GetMousePos()
{
	return _mousePos;
}