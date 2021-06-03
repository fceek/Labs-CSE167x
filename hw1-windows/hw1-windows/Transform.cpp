// Transform.cpp: implementation of the Transform class.

#include "Transform.h"

//Please implement the following functions:


// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
  // YOUR CODE FOR HW1 HERE

    float rad = glm::radians(degrees);
    mat3 x = glm::outerProduct(axis, axis);
    mat3 dual = mat3(0, axis[2], -axis[1], -axis[2], 0, axis[0], axis[1], -axis[0], 0);
    mat3 rot = cos(rad) * mat3(1.0f) + (1 - cos(rad)) * x + sin(rad) * dual;

  // You will change this return call
  return rot;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
    mat3 rot = rotate(degrees, up);
    eye = rot * eye;
    up = rot * up;
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE 
    vec3 axis = glm::normalize(glm::cross(up, eye));
    mat3 rot = rotate(-degrees, axis);
    eye = rot * eye;
    up = rot * up;
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE

    // constructing the coordinate system
    vec3 w = glm::normalize(eye);
    vec3 u = glm::normalize(glm::cross(up, w));
    vec3 v = glm::cross(w, u);
    mat3 r = mat3(u, v, w);
    r = glm::transpose(r);

    // rotation and translation
    mat4 rot = mat4(r);
    mat4 trans = mat4(1.0f);
    trans[3] = vec4(-eye, 1);

    // apply
    mat4 lookat = rot * trans;

  // You will change this return call
  return lookat;
}

Transform::Transform()
{

}

Transform::~Transform()
{

}