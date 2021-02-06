#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

#include "Utilities.h"


//Camera Movement Enumerators
enum Camera_Movement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

//Default Camera Values
constexpr float YAW = 90.0f;
constexpr float PITCH = 0.0f;
constexpr float SPEED = 5.0f;
constexpr float SENSIVITY = 0.1f;
constexpr float ZOOM = 45.0f; //FOV


class Camera
{
public:
	Camera(glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 wUp = glm::vec3(0.0f, 1.0f, 0.0f), float yaw_in = YAW, float pitch_in = PITCH);
	Camera(float posX, float posY, float posZ, float wUpX, float wUpY, float wUpZ, float yaw_in, float pitch_in);
	//Will be used to pass the view matrix to the shaders
	glm::mat4 getViewMatrix() const;
	
	//Setters
	void setSpeed(float speed_in);
	void setSensivity(float sensivity_in);
	void setZoom(float zoom_in);


	void processKeyboard(Camera_Movement direction, double deltaTime);
	void processMouseMovement(double xPos, double yPos, GLboolean constrainPitch = true);


private:
	//Updates the orthonormal base of the camera
	void updateCameraVectors();

private:
	//Camera Attributes
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;
	//Euler Angles
	float yaw;
	float pitch;
	//Camera Options
	float movementSpeed;
	float mouseSensivity;
	float zoom;
	//These are the last positions camera looks at (pixelwise)
	double lastX;
	double lastY;
};



#endif