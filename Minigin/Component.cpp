#include "Component.h"
#include "GameObject.h"

Component::Component(GameObject& gameObect)
	: m_gameObject(gameObect)
{
}
