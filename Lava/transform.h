#pragma once

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

class Transform
{
public:
	Transform(const glm::vec3 inputPosition = glm::vec3(), const glm::vec3 inputRotation = glm::vec3(), const glm::vec3 inputScale = glm::vec3(1.0, 1.0, 1.0)) :
		position(inputPosition), rotation(inputRotation), scale(inputScale) {}

	inline glm::mat4 GetModel() const
	{
		glm::mat4 positionMatrix = glm::translate(position);
		glm::mat4 rotationXMatrix = glm::rotate(rotation.x, glm::vec3(1.0, 0.0, 0.0));
		glm::mat4 rotationYMatrix = glm::rotate(rotation.y, glm::vec3(0.0, 1.0, 0.0));
		glm::mat4 rotationZMatrix = glm::rotate(rotation.z, glm::vec3(0.0, 0.0, 1.0));
		glm::mat4 rotationMatrix = rotationZMatrix * rotationYMatrix * rotationXMatrix;
		glm::mat4 scaleMatrix = glm::scale(scale);

		return positionMatrix * rotationMatrix * scaleMatrix;
	}

	inline glm::vec3 &GetPosition() { return position; }
	inline glm::vec3 &GetRotation() { return rotation; }
	inline glm::vec3 &GetScale() { return scale; }

	inline void SetPosition(const glm::vec3 &inputPosition) { position = inputPosition; }
	inline void SetRotation(const glm::vec3 &inputRotation) { rotation = inputRotation; }
	inline void SetScale(const glm::vec3 &inputScale) { scale = inputScale; }
protected:
private:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

