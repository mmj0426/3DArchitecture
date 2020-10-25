#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "ICleanUp.h"

#include <vector>
#include<string>

#include "include/GL/glew.h"		
#include "glm/gtc/matrix_transform.hpp"

class Object : public ICleanUp
{
public : 
	Object();
	virtual ~Object() {}

	virtual void ShutDown() override;

	glm::mat4 GetTranslate() const { return translate; }
	glm::mat4 GetRotate() const { return rotate; }
	glm::mat4 GetScale() const { return scale; }

	void SetPosition(glm::vec3 src_position);
	void SetRotation(float rot_angle, glm::vec3 axis);
	void SetScale(glm::vec3 scale_range);
	
	glm::vec3  currentTranslate;
	

private:
	glm::mat4 translate;
	glm::mat4 rotate;
	glm::mat4 scale;
	
};


#endif // !__OBJECT_H__