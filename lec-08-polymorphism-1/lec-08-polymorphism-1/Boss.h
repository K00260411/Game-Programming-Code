#pragma once
#ifndef BOSS_H
#define BOSS_H
#include "Enemy.h"
class Boss : public Enemy
{
public:
    Boss(int multiplier = 3);
    virtual ~Boss();
    void virtual Attack() const;

protected:
    int* m_pMultiplier;
};


#endif