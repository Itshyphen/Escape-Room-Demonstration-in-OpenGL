#include <fstream>
#include <iterator>
#include "object.hpp"
#include <iostream>
#include <string>

using namespace std;

Object::Object()
{

}

Object::Object(std::string name)
{
	Name = name;
	setPosition(0, 0, 0);
	setAngle(0);
	setScale(1, 1, 1);
	setModelName("");
	setTexture("");
	setRotationVector(0,1,0);
}

//get set functions for center coordinates
void Object::setPosition(double x, double y, double z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

VecMat::vec3 Object::getPosition()
{
	return position;
}

//get set functions for scale
void Object::setScale(double x, double y, double z)
{
	scale.x = x;
	scale.y = y;
	scale.z = z;
}

VecMat::vec3 Object::getScale()
{
	return scale;
}

//get set functon for rotation vector
void Object::setRotationVector(double x, double y, double z)
{
	rotationangle.x = x;
	rotationangle.y = y;
	rotationangle.z = z;
}
VecMat::vec3 Object::getRotationVector()
{
	return rotationangle;
}


//getset function for angle
void Object::setAngle(double a)
{
	 angle=a;
}

double Object::getAngle()
{
	return angle;
}

//get set functions for name 
void Object::setName(std::string name)
{
	this->Name = name;
}

std::string Object::getName()
{
	return Name;
}

//get set function for texture
void Object::setTexture(const char* t)
{
	Texture = t;
}

const char* Object::getTexture()
{
	return Texture;
}

//get set function for obj filename
void Object::setModelName(std::string s)
{
	if (s.find(".obj") !=-1)
	{
		ModelName = s;
	}
	else
	{
		std:cout<<"Given file is not the obj file.";
	}
}

std::string Object::getModelName()
{
	return ModelName;
}

void Object::addObject(Object* a)
{
	children.push_back(a);
}
std::vector<Object*> Object::getChildren()
{
	return children;
}
Object::~Object()
{

}



