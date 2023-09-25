#include "SceneManager.h"
#include "Resourcemng.h"
#include "GameObject.h"
#include "Transform.h"
#include "MeshRenderer.h"

namespace JSH
{
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
		//mPlayScene = new Scene();

		//{
		//	GameObject* object = new GameObject();
		//	Transform* tr = new Transform();
		//	tr->SetPosition(Vector3(0.5f, 0.2f, 0.0f));
		//	tr->SetScale(Vector3(2.0f, 2.0f,   1.0f));
		//	object->AddComponent(tr);

		//	MeshRenderer* meshRenderer = new MeshRenderer();
		//	meshRenderer->SetMesh(Resourcemng::Find<Mesh>(L"TriangleMesh"));
		//	meshRenderer->SetShader(Resourcemng::Find<Shader>(L"TriangleShader"));
		//	object->AddComponent(meshRenderer);

		//	mPlayScene->AddGameObject(object, LAYER::NONE);
		//}

		//{
		//	GameObject* object = new GameObject();
		//	Transform* tr = new Transform();
		//	tr->SetPosition(Vector3(-0.5f, -0.2f, 0.0f));
		//	object->AddComponent(tr);

		//	MeshRenderer* meshRenderer = new MeshRenderer();
		//	meshRenderer->SetMesh(Resourcemng::Find<Mesh>(L"TriangleMesh"));
		//	meshRenderer->SetShader(Resourcemng::Find<Shader>(L"TriangleShader"));
		//	object->AddComponent(meshRenderer);

		//	mActiveScene->AddGameObject(object, LAYER::NONE);
		//}
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render()
	{
		mActiveScene->Render();
	}
	Scene* SceneManager::LoadScene(const std::wstring name)
	{
		std::map<std::wstring, Scene*>::iterator iter
			= mScenes.find(name);

		if (iter == mScenes.end())
		{
			return nullptr;
		}

		mActiveScene = iter->second;

		return iter->second;
	}
}
