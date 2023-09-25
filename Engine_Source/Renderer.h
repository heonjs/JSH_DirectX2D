#pragma once
#include "JSHEnums.h"
#include "CommonInclude.h"
#include "Engine.h"
#include "JSHMath.h"
#include "GraphicsDevice_DX11.h"

#include "Mesh.h"
#include "Shader.h"
#include "ConstantBuffer.h"

using namespace JSH::graphics;
using namespace JSH::enums;
using namespace JSH::math;

namespace JSH::renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	CBUFFER(TransformCB, CBSLOT_TRANSFORM)
	{
		Vector3 pos;
		int padd1;

		Vector3 scale;
		int padd2;
	};

	extern Mesh* mesh;
	extern Shader* shader;
	extern ConstantBuffer* constantBuffers[];

	// Initialize the renderer
	void Initialize();
	void Release();
}
