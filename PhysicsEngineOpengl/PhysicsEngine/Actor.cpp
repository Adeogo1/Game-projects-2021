#include "Actor.h"
#include "Game.h"

Actor::Actor(Game* _game, Actor* _parent, string _name, bool _static) :m_ActorState(EActive), m_Game(_game)
{
	//m_Transform = new TransformComponent(_parent,1);
	//m_Components.push_back(m_Transform);
	m_Game->AddActor(this);
}

Actor::~Actor()
{
	m_Game->RemoveActor(this);
	// Need to delete components
	// Because ~Component calls RemoveComponent, need a different style loop
	while (!m_Components.empty())
	{
		delete m_Components.back();
	}
}

void Actor::Update(float _deltaTime)
{
	if (m_ActorState != State::EActive)return;
	UpdateComponent(_deltaTime);
	UpdateActor(_deltaTime);
}

void Actor::UpdateComponent(float _deltaTime)
{
	for (Component* c : m_Components)
	{
		c->Update(_deltaTime);
	}
}

void Actor::UpdateActor(float _deltaTime)
{

}

void Actor::ProcessInput(const uint8_t* _keyState)
{
	if (m_ActorState != State::EActive)return;
	for (auto comp : m_Components)
	{
		comp->ProcessInput(_keyState);
	}
	ActorInput(_keyState);
}

void Actor::ActorInput(const uint8_t* _keyState)
{
}

void Actor::Draw()
{
}

void Actor::AddComponent(Component* comp)
{
	//find the insertion point in the sorted vector
	int myOrder = comp->GetUpdateOrder();
	auto iter = m_Components.begin();
	for (;
		iter != m_Components.end();
		++iter)
	{
		if (myOrder < (*iter)->GetUpdateOrder())
		{
			break;
		}
	}

	// Inserts element before position of iterator
	m_Components.insert(iter, comp);

}

void Actor::RemoveComponent(Component* comp)
{
	auto iter = find(m_Components.begin(), m_Components.end(), comp);
	if (iter != m_Components.end())
	{
		m_Components.erase(iter);
	}
}
