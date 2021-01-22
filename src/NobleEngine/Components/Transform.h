#pragma once
#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include <iostream>
#include <memory>
#include <vector>

#include "glm/glm.hpp"
#include <Bullet/btBulletDynamicsCommon.h>

#include "../EngineCore/Component.h"

namespace NobleEngine
{
	struct PhysicsBody;

	/**
	*Stores a transform component data.
	*/
	struct Transform : public Component<Transform>
	{
		/**
		*Stores a physics body. If a physics body is attached to the same entity then its transform data is used instead.
		*/
		std::shared_ptr<PhysicsBody> pBody;
		bool checkForPhysicsBody = false;
		btTransform oldBodyPos;
		/**
		*Stores the parent transform of the object.
		*/
		std::shared_ptr<Transform> parent;
		/**
		*Contains the position of the transform. Defaults to the origin.
		*/
		glm::vec3 position;
		/**
		*Contains the rotation of the transform. Defaults with no rotation.
		*/
		glm::vec3 rotation;
		/**
		*Contains the scale of the transform. Defaults to a scale of 1 on each axis.
		*/
		glm::vec3 scale = glm::vec3(1, 1, 1);
		/**
		*Contains the model matrix for use in rendering.
		*/
		glm::mat4 model;

		void OnInitialize()
		{
			position = glm::vec3(0, 0, 0);
			rotation = glm::vec3(0, 0, 0);
			scale = glm::vec3(1, 1, 1);
		}
		/**
		*Initializes the Tranform component with the passed paramaters. Initializes a position, rotation and a scale.
		*/
		void OnInitialize(glm::vec3 pos, glm::vec3 rot, glm::vec3 sca)
		{
			position = pos;
			rotation = rot;
			scale = sca;
		}
		/**
		*Initializes the Tranform component with the passed paramaters. Initializes a position, rotation.
		*/
		void OnInitialize(glm::vec3 pos, glm::vec3 rot)
		{
			position = pos;
			rotation = rot;
		}
		/**
		*Initializes the Tranform component with the passed paramaters. Initializes a position.
		*/
		void OnInitialize(glm::vec3 pos)
		{
			position = pos;
		}
	};
}

#endif