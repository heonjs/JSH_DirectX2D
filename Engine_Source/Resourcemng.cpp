#include "Resourcemng.h"

namespace JSH
{
	std::map<std::wstring, Resource*> Resourcemng::mResourcemng;

	void Resourcemng::Release()
	{
		std::map<std::wstring, Resource*>::iterator iter = mResourcemng.begin();
		for (; iter != mResourcemng.end(); ++iter)
		{
			delete iter->second;
			iter->second = nullptr;
		}
	}
}
