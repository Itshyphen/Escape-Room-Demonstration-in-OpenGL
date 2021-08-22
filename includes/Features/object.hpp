#include <vector>
#include <utility>
#include<glm/glm.hpp>
#include<string>
#include <matrix.hpp>

#pragma once

class Object {
private:
	VecMat::vec3 position;
	VecMat::vec3 scale;
	VecMat::vec3 rotationangle;
	double angle;
	std::string ModelName;
	std::string text;
	const char* Texture;
	std::string Name;


public:
	std::vector<Object*>children;
	//Constructor
	Object();
	Object(std::string name);
	~Object();

	//get set functions for center coordinates
	void setPosition(double x, double y, double z);
    VecMat::vec3 getPosition();

	//get set functions for scale
	void setScale(double x, double y, double z);
	VecMat::vec3 getScale();

	void setRotationVector(double x, double y, double z);
	VecMat::vec3 getRotationVector();
    
	void setAngle(double a);
	double getAngle();

	//get set functions for name 
	void setName(std::string name);
	std::string getName();

	//get set function for mtl filename
	void setTexture(const char*);
	const char* getTexture();

	//get set function for obj filename
	void setModelName(std::string);
	std::string getModelName();

	void addObject(Object* a);
	std::vector<Object*> getChildren();

};

