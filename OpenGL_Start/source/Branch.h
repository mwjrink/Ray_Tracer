#pragma once
#include "ImportUtility.h"
#include <vector>
#include <iostream>
#include "CollisionOctTree.h"
#include "Entity.h"

class Branch : public CollisionOctTree {
private:
	const int MAXIMUMCOLLISIONELEMENTS = 10;
	bool isSplit = false;
	Branch* Branches;
	std::vector<Entity> Entities;
	int NumElements;
	Point Position;
	float Width;

public:
	//Constructor
	Branch();
	Branch(Point, float);
	void Init(Point, float);

	//Member Functions
	void Add(Entity);
	void Remove(Entity);
	std::vector<Entity> GetCollidableEntities(Entity);
	void EntityMoved(Entity);


	//Destructor
	~Branch();
};

