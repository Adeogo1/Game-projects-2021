#pragma once
#include "TransformComponent.h"
#include "RepeatedIncludes.h"


class Actor
{
public:
	enum State {
		EActive,
		EInactive,
		EPaused,
		EDead
	};
	//move the parent parameter to transform
	Actor(class Game* _game, Actor* _parent,string _name, bool _static = false);
	virtual ~Actor();
	void Update(float _deltaTime);
	void UpdateComponent(float _deltaTime);
	virtual void UpdateActor(float _deltaTime);

	virtual void Draw();

	void AddComponent(Component* comp);
	void RemoveComponent(Component* comp);

	template <typename T>
	T* GetComponent() {
		for (Component* c: m_Components)
		{
			if (dynamic_cast<T*>(c))
			{
				return (T*)c;
			}
		}
		return nullptr;
	}

	template <typename T>
	vector<T*> GetComponents() {
		vector<Component*> components;
		for (Component* c: m_Components)
		{
			if (dynamic_cast<T*>(c))
			{
				components.push_back( (T*)c);
			}
		}
		return components;
	}

	State GetState() {
		return m_ActorState;
	}

	TransformComponent* m_Transform;

protected:
	State m_ActorState;
	string m_Name;
	
private:

	bool m_Static;
	vector<Component*> m_Components;
	class Game* m_Game;
	Actor* m_Parent;

};



