#pragma once
#include "CommonInclude.h"
#include "Engine.h"

namespace JSH
{
	class Resource;
	class Resourcemng
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& key)
		{
			std::map<std::wstring, Resource*>::iterator iter = mResourcemng.find(key);

			// 이미 동일한 키값으로 다른 리소스가 먼저 등록되어 있었다.
			if (iter != mResourcemng.end())
			{
				return dynamic_cast<T*>(iter->second);
			}

			return nullptr;
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			// 키값으로 탐색
			T* resource = Resourcemng::Find<T>(key);
			if (nullptr != resource)
			{
				// 해당키로 이미 로딩된게 있으면 해당 리소스를 반환
				return resource;
			}

			// 해당 키로 로딩된 리소스가 없다.
			resource = new T();
			if (FAILED(resource->Load(path)))
			{
				MessageBox(nullptr, L"Image Load Failed!", L"Error", MB_OK);
				return nullptr;
			}

			resource->SetKey(key);
			resource->SetPath(path);
			mResourcemng.insert(make_pair(key, dynamic_cast<Resource*>(resource)));

			return dynamic_cast<T*>(resource);
		}

		template <typename T>
		static void Insert(const std::wstring& key, T* resource)
		{
			mResourcemng.insert(make_pair(key, dynamic_cast<Resource*>(resource)));
		}

		static void Release();

	private:
		Resourcemng() = delete;
		~Resourcemng() = delete;

	private:
		static std::map<std::wstring, Resource*> mResourcemng;
	};
}
