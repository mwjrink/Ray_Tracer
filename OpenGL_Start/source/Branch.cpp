#include "Branch.h"

//TODO (this is random file) USE RESERVE FOR VECTORS C++
Branch::Branch() : Position(0, 0, 0) {
	Position = Point(0, 0, 0);
	NumElements = 0;
}

Branch::Branch(Point position, float width) : Position(position) {
	NumElements = 0;
	Width = width;

}

void Branch::Init(Point position, float width) {
	Position = position;
	Width = width;
}

//TODO make into kd tree (split at median not at half) (currently a cube->no height)
void Branch::Add(Entity entity) {
	if (NumElements < MAXIMUMCOLLISIONELEMENTS) {
		Entities.push_back(entity);
		NumElements++;
		return;
	} else {
		NumElements = 0;
		isSplit = true;
		Branches = new Branch[8];
		//height split width split
		/* Layer

		P________
		|_A_|_B_|
		|_C_|_D_|

		*/

		//Layer 1
		//A
		Branches[0].Init(Position, Width / 2);
		//B
		Branches[1].Init(Point(Position.X + Width / 2, Position.Y, Position.Z), Width / 2);
		//C
		Branches[2].Init(Point(Position.X, Position.Y + Width / 2, Position.Z), Width / 2);
		//D
		Branches[3].Init(Point(Position.X + Width / 2, Position.Y + Width / 2, Position.Z), Width / 2);

		//Layer 2
		//A
		Branches[4].Init(Point(Position.X, Position.Y, Position.Z + Width / 2), Width / 2);
		//B
		Branches[5].Init(Point(Position.X + Width / 2, Position.Y, Position.Z + Width / 2), Width / 2);
		//C
		Branches[6].Init(Point(Position.X, Position.Y + Width / 2, Position.Z + Width / 2), Width / 2);
		//D
		Branches[7].Init(Point(Position.X + Width / 2, Position.Y + Width / 2, Position.Z + Width / 2), Width / 2);

		for (std::vector<Entity>::iterator it = Entities.begin(); it != Entities.end(); it++) {
			if ((*it).GetWidth() > Width / 2 || (*it).GetLength() > Width / 2 || (*it).GetHeight() > Width / 2)
				continue;

			//this assumes 0, 0, 0 is the bottom left of the world space (NO NEGATIVE VALUES)
			//TODO modify for a 0, 0, 0 center with changing cells
			//TODO check if the height width or length exceeds the bounds of the branch
			if ((*it).GetPosition().X > Position.X + Width / 2) {
				if ((*it).GetPosition().Z > Position.Z + Width / 2) {
					if ((*it).GetPosition().Y > Position.Y + Width / 2) {
						//if((*it).GetPosition().X + (*it).GetWidth || )
						Branches[7].Add((*it));
						Entities.erase(it);
						continue;
					} else {
						Branches[5].Add((*it));
						Entities.erase(it);
						continue;
					}

				} else {
					if ((*it).GetPosition().Y > Position.Y + Width / 2) {
						Branches[3].Add((*it));
						Entities.erase(it);
						continue;
					} else {
						Branches[1].Add((*it));
						Entities.erase(it);
						continue;
					}

				}
			} else {
				if ((*it).GetPosition().Z > Position.Z + Width / 2) {
					if ((*it).GetPosition().Y > Position.Y + Width / 2) {
						Branches[6].Add((*it));
						Entities.erase(it);
						continue;
					} else {
						Branches[4].Add((*it));
						Entities.erase(it);
						continue;
					}
				} else {
					if ((*it).GetPosition().Y > Position.Y + Width / 2) {
						Branches[2].Add((*it));
						Entities.erase(it);
						continue;
					} else {
						Branches[0].Add((*it));
						Entities.erase(it);
						continue;
					}
				}
			}
		}
	}
}

//void Branch::Remove(Entity en) {
//	if (
//		(en.GetPosition().X > Position.X && en.GetPosition().X < Position.X) &&
//		(en.GetPosition().Y > Position.Y && en.GetPosition().Y < Position.Y) &&
//		(en.GetPosition().Z > Position.Z && en.GetPosition().Z < Position.Z)) {
//		//check if in bounds with height and width
//		for (Entity entity : Entities) {
//			if (entity.Equals(en)) {
//				Entities.erase(remove(Entities.begin(), Entities.end(), en), Entities.end());
//				return;
//			}
//		}
//		if (isSplit) {
//
//			if (en.GetPosition().X > Position.X + Width / 2) {
//				if (en.GetPosition().Z > Position.Z + Width / 2) {
//					if (en.GetPosition().Y > Position.Y + Width / 2) {
//						//if(en.GetPosition().X + en.GetWidth || )
//						Branches[7].Remove(en);
//						return;
//					} else {
//						Branches[5].Remove(en);
//						return;
//					}
//
//				} else {
//					if (en.GetPosition().Y > Position.Y + Width / 2) {
//						Branches[3].Remove(en);
//						return;
//					} else {
//						Branches[1].Remove(en);
//						return;
//					}
//				}
//			} else {
//				if (en.GetPosition().Z > Position.Z + Width / 2) {
//					if (en.GetPosition().Y > Position.Y + Width / 2) {
//						Branches[6].Remove(en);
//						return;
//					} else {
//						Branches[4].Remove(en);
//						return;
//					}
//				} else {
//					if (en.GetPosition().Y > Position.Y + Width / 2) {
//						Branches[2].Remove(en);
//						return;
//					} else {
//						Branches[0].Remove(en);
//						return;
//					}
//				}
//			}
//		}
//	}
//	std::cout << "Exception handling entity(" << en.GetID() << "): \n";
//	throw std::exception("Tried to remove entity from Branch, but it is not in this branch or its child branches");
//}

std::vector<Entity> Branch::GetCollidableEntities(Entity en) {
	throw std::exception("The GetCollidableEntities Function does not exist yet rn, GET ON IT MR. DEV MAN");
	return Entities;
	//if (
	//	(en.GetPosition().X > Position.X && en.GetPosition().X < Position.X) &&
	//	(en.GetPosition().Y > Position.Y && en.GetPosition().Y < Position.Y) &&
	//	(en.GetPosition().Z > Position.Z && en.GetPosition().Z < Position.Z)) {
	//	//check if in bounds with height and width
	//	for (Entity entity : Entities) {
	//		if (entity.Equals(en)) {
	//			Entities.erase(remove(Entities.begin(), Entities.end(), en), Entities.end());
	//			return Entities;
	//		}
	//	}
	//	if (isSplit) {
	//		//TODO
	//		//not return all of entities, sort through them by the ones in the branch and the ones with the right ids
	//		if (en.GetPosition().X > Position.X + Width / 2) {
	//			if (en.GetPosition().Z > Position.Z + Width / 2) {
	//				if (en.GetPosition().Y > Position.Y + Width / 2) {
	//					//if(en.GetPosition().X + en.GetWidth || )
	//					Branches[7].Remove(en);
	//					return Entities;
	//				} else {
	//					Branches[5].Remove(en);
	//					return Entities;
	//				}

	//			} else {
	//				if (en.GetPosition().Y > Position.Y + Width / 2) {
	//					Branches[3].Remove(en);
	//					return Entities;
	//				} else {
	//					Branches[1].Remove(en);
	//					return Entities;
	//				}
	//			}
	//		} else {
	//			if (en.GetPosition().Z > Position.Z + Width / 2) {
	//				if (en.GetPosition().Y > Position.Y + Width / 2) {
	//					Branches[6].Remove(en);
	//					return Entities;
	//				} else {
	//					Branches[4].Remove(en);
	//					return Entities;
	//				}
	//			} else {
	//				if (en.GetPosition().Y > Position.Y + Width / 2) {
	//					Branches[2].Remove(en);
	//					return Entities;
	//				} else {
	//					Branches[0].Remove(en);
	//					return Entities;
	//				}
	//			}
	//		}
	//	}
	//}
	//return Entities;
	//TODO
	//check against entities in this Branch
	//if (isSplit) {
		//send off to a sub Branch
	//}
}

void Branch::EntityMoved(Entity entity) {
	//TODO: this Function

	//check for leaving current branch, pass up a branch
	//possibly call function recalculate
}


Branch::~Branch() {

}
