#include "CollisionEntity.h"



CollisionEntity::CollisionEntity() {

}


bool CollisionEntity::CollidesWith(int id) {
	if (find(CollisionIDs.begin(), CollisionIDs.end(), id) != CollisionIDs.end())
		return true;
	return false;

	/*for (int ID : CollisionIDs)
		if (ID == id) return true;
	return false;*/
}

void CollisionEntity::AddCollisionIDs(int id) {
	if (find(CollisionIDs.begin(), CollisionIDs.end(), id) != CollisionIDs.end())
		CollisionIDs.push_back(id);

	/*for (int ID : CollisionIDs)
	if (ID == id) CollisionIDs.push_back(id);*/
}

CollisionEntity::~CollisionEntity() {
}
