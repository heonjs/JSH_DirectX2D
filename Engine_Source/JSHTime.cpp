#include "JSHTime.h"
#include "Application.h"

extern JSH::Application application;

namespace JSH
{
    LARGE_INTEGER	JSHTime::mCpuFrequency = {};
    LARGE_INTEGER   JSHTime::mPrevFrequency = {};
    LARGE_INTEGER	JSHTime::mCurFrequency = {};
    float			JSHTime::mDeltaTime = 0.0f;
    float			JSHTime::mOneSecond = 0.0f;

    void JSHTime::Initialize()
    {
        //CPU �� �ʴ� �ݺ��Ǵ� ���ļ��� ���´�.
        QueryPerformanceFrequency(&mCpuFrequency);

        //���α׷��� ������������ CPU Ŭ�� ��
        QueryPerformanceCounter(&mPrevFrequency);
    }

    void JSHTime::Update()
    {
        QueryPerformanceCounter(&mCurFrequency);

        float differenceInFrequancy
            = static_cast<float>((mCurFrequency.QuadPart - mPrevFrequency.QuadPart));

        mDeltaTime = differenceInFrequancy / static_cast<float>(mCpuFrequency.QuadPart);
        mPrevFrequency.QuadPart = mCurFrequency.QuadPart;
    }

    void JSHTime::Render()
    {
        static int iCount = 0;
        ++iCount;


        // 1 �ʿ� �ѹ�
        mOneSecond += mDeltaTime;
        if (1.0f < mOneSecond)
        {
            HWND hWnd = application.GetHwnd();

            wchar_t szFloat[50] = {};
            float FPS = 1.f / mDeltaTime;
            swprintf_s(szFloat, 50, L"DeltaTime : %d", iCount);
            int iLen = wcsnlen_s(szFloat, 50);
            //TextOut(_dc, 10, 10, szFloat, iLen);

            SetWindowText(hWnd, szFloat);

            // �����ð�, ī��Ʈ �ʱ�ȭ
            mOneSecond = 0.f;
            iCount = 0;
        }
    }
}