#include "PlayerScript.h"
#include "GameObject.h"
#include "JSHTime.h"
#include "Transform.h"

namespace JSH
{
	PlayerScript::PlayerScript()
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
	{
		GameObject* obj = GetOwner();
		Transform* tr = obj->GetComponent<Transform>();
		//Vector3 pos = tr->GetPosition();
		//tr->SetPosition(pos);
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render()
	{
	}
}