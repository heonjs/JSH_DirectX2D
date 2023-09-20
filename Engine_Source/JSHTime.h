#pragma once
#include "CommonInclude.h"
#include "Engine.h"

namespace JSH
{
	class JSHTime
	{
	public:
		static __forceinline float DeltaTime() { return mDeltaTime; }

		static void Initialize();
		static void Update();
		static void Render();

	private:
		static LARGE_INTEGER	mCpuFrequency;
		static LARGE_INTEGER   mPrevFrequency;
		static LARGE_INTEGER	mCurFrequency;

		static float			mDeltaTime;
		static float			mOneSecond;
	};
}