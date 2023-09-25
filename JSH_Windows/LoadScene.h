#pragma once
#include "..\\Engine_Source\\SceneManager.h"
#include "PlayScene.h"

#ifdef  _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\JSH_Windows.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\JSH_Windows.lib")
#endif //  _DEBUG

namespace JSH
{
	void InitializeScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}