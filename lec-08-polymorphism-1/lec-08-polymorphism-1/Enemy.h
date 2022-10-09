#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>

using namespace std;

class Enemy
{
public:
    Enemy(int damage = 10);
    virtual ~Enemy();
    void virtual Attack() const;

protected:
    int* m_pDamage;
};

#endif