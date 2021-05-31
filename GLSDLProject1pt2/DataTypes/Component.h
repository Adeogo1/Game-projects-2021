//
// Created by a016817k on 31/05/2021.
//

#ifndef GLSDLPROJECT1PT2_COMPONENT_H
#define GLSDLPROJECT1PT2_COMPONENT_H


class Component {
public:
    Component(class Actor* owner, int updateOrder = 100);
    virtual ~Component();
    virtual void Update(float deltaTime);
    int GetUpdateOrder()const{return m_UpdateOrder;}

protected:
    class Actor* m_Owner;
    int m_UpdateOrder;
    
};


#endif //GLSDLPROJECT1PT2_COMPONENT_H
