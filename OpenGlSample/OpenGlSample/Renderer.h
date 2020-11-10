#ifndef __RENDERER_H__
#define __RENDERER_H__


#include <vector>


#include "RenderableObject.h"
#include "Singleton.h"

#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 

class RenderableObject;
class NonRenderableObject;
class IRenderer;
class IUpdater;

class Renderer : public ICleanUp, public Singleton<Renderer>
{
public:
	void Initialize();
	void Draw();
	void AddObject(IRenderer* render_obj);
	void Update(IUpdater* src_obj);

	void SetViewMatrix(glm::mat4 src_ViewMatrix) {ViewMatrix = src_ViewMatrix; }
	GLFWwindow* GetWindow() const { return window; }

	virtual void ShutDown() override;

	bool isRenderTiming();

	glm::mat4 ModelMatrix;

private :

	glm::mat4 ViewMatrix;
	glm::mat4 ProjectionMatrix;

	GLuint VertexArrayID;

	GLFWwindow* window;

	std::vector<IRenderer*> objectArray;
	

};
#endif // !__RENDERER_H__