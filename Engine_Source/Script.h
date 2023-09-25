#pragma once
#include "Component.h"
#include "JSHEnums.h"
#include "Entity.h"
#include "JSHMath.h"

namespace JSH
{
	class GameObject;
	class Script : public Entity
	{
	public :
		friend GameObject;

		Script();
		virtual ~Script();

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void LateUpdate() = 0;
		virtual void Render() = 0;

		GameObject* GetOwner()
		{
			return mOwner;
		}
		void SetOwner(GameObject* obj)
		{
			mOwner = obj;
		}

	private :
		GameObject* mOwner;
	};
}
