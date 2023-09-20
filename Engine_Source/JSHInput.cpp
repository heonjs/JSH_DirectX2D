#include "JSHInput.h"
#include "Application.h"

extern JSH::Application application;

namespace JSH
{
	std::vector<JSHInput::Key> JSHInput::mKeys = {};
	Vector2 JSHInput::mMousePos = {};
	int ASCII[(UINT)eKeyCode::END] =
	{
		//Alphabet
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',

		//Special Key
		VK_RETURN, VK_ESCAPE, VK_LSHIFT, VK_LMENU, VK_LCONTROL,
		VK_SPACE, VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
		VK_LBUTTON, VK_RBUTTON,

		//Num Pad
		VK_NUMPAD0, VK_NUMPAD1, VK_NUMPAD2,
		VK_NUMPAD3, VK_NUMPAD4, VK_NUMPAD5,
		VK_NUMPAD6, VK_NUMPAD7, VK_NUMPAD8,
		VK_NUMPAD9,

		//Num Line
		'0', '1', '2', '3', '4', '5',
		'6', '7', '8', '9',
	};


	void JSHInput::Initialize()
	{
		for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
		{
			Key key;
			key.Code = (eKeyCode)i;
			key.State = eKeyState::None;
			key.bPressed = false;

			mKeys.push_back(key);
		}
	}

	void JSHInput::Update()
	{
		HWND hwnd = application.GetHwnd();
		HWND Nowhwnd = GetFocus();

        if (hwnd == Nowhwnd)
        {
            for (int i = 0; i < (int)eKeyCode::END; i++)
            {
                POINT MousePos = {};

                // ���� ���콺 Pos �� �޾ƿ´�
                GetCursorPos(&MousePos);

                // ���콺 Pos �� ��ũ�� ��ǥ���� Ư�� Ŭ���̾�Ʈ ��ǥ�� �ٲ��ش�
                ScreenToClient(hwnd, &MousePos);
                mMousePos.x = (float)MousePos.x;
                mMousePos.y = (float)MousePos.y;

                //������ ���� ���� ���� ȣ�� �������� ���� ���� (0x8000)
                if (GetAsyncKeyState(ASCII[i]) & 0x8000)
                {
                    //���� ������ �ִ� ���� (pressed)
                    if (mKeys[i].bPressed == true) //true
                    {
                        mKeys[i].State = eKeyState::Pressed;
                    }
                    else
                    {
                        mKeys[i].State = eKeyState::Down;
                    }

                    mKeys[i].bPressed = true;
                }
                //else if (GetAsyncKeyState(ASCII[i]) & 0)
                else //������ ���� ���� ���� ȣ�� �������� �Է��� �ȵ� ���� (0x0000)
                {
                    //������ ������ �ִ� ����
                    if (mKeys[i].bPressed == true)
                    {
                        mKeys[i].State = eKeyState::Up;
                    }
                    else
                    {
                        mKeys[i].State = eKeyState::None;
                    }

                    mKeys[i].bPressed = false;
                }
            }

        }
        else // ���� ��Ŀ������ �ƴϴ�
        {
            for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
            {
                mKeys[i].bPressed = false;

                if (mKeys[i].State == eKeyState::Down or mKeys[i].State == eKeyState::Pressed)
                {
                    mKeys[i].State = eKeyState::Up;
                }
                else if (mKeys[i].State == eKeyState::Up)
                {
                    mKeys[i].State = eKeyState::None;
                }
            }
        }

	}
}