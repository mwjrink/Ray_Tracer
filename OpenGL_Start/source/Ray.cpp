#include "Ray.h"



Ray::Ray(Vector v) : RayVec(v) {

}

Color Ray::Trace() {
	throw std::exception("Not Implemented");
}

Ray::~Ray() {

}
