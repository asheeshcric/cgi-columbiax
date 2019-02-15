#include "TwoDScene.h"
// #include<iostream>
// using namespace std;
scalar TwoDScene::computeKineticEnergy() const
{
//     cout << "m_v="<<m_v<<endl;
    return (1.0 / 2) * m_v.dot(VectorXs(m_m.array() * m_v.array()));
}
