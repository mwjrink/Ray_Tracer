#pragma once
#include "ImportUtility.h"
#include "Point.h"
#include "Mesh.h"

class Entity {
private:
	int ID;
	Point Position;
	float Width, Length, Height;
	Mesh mesh;

public:
	//Constructor
	Entity(int);
	//remove this later
	Entity();

	//Getters
	float GetWidth();
	float GetLength();
	float GetHeight();
	Point GetPosition();

	//Member Function
	int GetID();
	bool Equals(Entity entity);


	//Destructor
	~Entity();
};

