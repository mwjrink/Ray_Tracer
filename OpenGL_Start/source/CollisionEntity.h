#pragma once
#include "ImportUtility.h"
#include <vector>
#include <algorithm>
#include "Entity.h"

class CollisionEntity : public Entity {
private:
	std::vector<int> CollisionIDs;

public:
	//Constructor
	CollisionEntity();

	//vector<int> GetCollisionIDs();
	bool CollidesWith(int);
	void AddCollisionIDs(int);

	//Destructor
	~CollisionEntity();
};

