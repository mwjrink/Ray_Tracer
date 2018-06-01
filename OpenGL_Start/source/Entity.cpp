#include "Entity.h"


//Constructor
Entity::Entity(int id)
{
	ID = id;
}

//remove this later
Entity::Entity()
{ }

//Getters
float Entity::GetWidth() {
	return Width;
}
float Entity::GetLength() {
	return Length;
}
float Entity::GetHeight() {
	return Height;
}
Point Entity::GetPosition() {
	return Position;
}

//Member Function
int Entity::GetID() {
	return ID;
}

bool Entity::Equals(Entity entity) {
	return ID == entity.GetID();
}

//Destructor
Entity::~Entity()
{
}
