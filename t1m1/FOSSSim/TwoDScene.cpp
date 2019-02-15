#include "TwoDScene.h"

#include <iostream>
using namespace std;

scalar TwoDScene::computeKineticEnergy() const
{
    // This class is used to compute the Kinetic Energy of the system T=1/2 mv.v
    // In absence of external forces, the kinetic energy remains constant -- Newton's 1st law
    // For sanity check, execute the scene InertiaTests/test01explicit.xml and print the kinetic energy at each timestep (to verify that it is constant)
    return 0.5 * m_v.dot(VectorXs(m_m.array() * m_v.array()));
}