#include "stdafx.h"
#include "Object.h"


Object::Object()
{
	lpobj[obj_c] = this;
	obj_c++;
}


Object::~Object()
{
}
void Object::die()
{
	
}
BOOL Object::FindMap(Map* map)
{
	return TRUE;
}
void Object::objectshow()
{
}
