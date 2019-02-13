#include "ExplicitEuler.h"
#include <iostream>
using namespace std;

bool ExplicitEuler::stepScene( TwoDScene& scene, scalar dt )
{
    // Your code goes here!
    
    // Some tips on getting data from TwoDScene:
    // A vector containing all of the system's position DoFs. x0, y0, x1, y1, ...
    //VectorXs& x = scene.getX();
    // A vector containing all of the system's velocity DoFs. v0, v0, v1, v1, ...
    //VectorXs& v = scene.getV();
    // A vector containing the masses associated to each DoF. m0, m0, m1, m1, ...
    //const VectorXs& m = scene.getM();
    // Determine if the ith particle is fixed
    // if( scene.isFixed(i) )
    
    VectorXs& x = scene.getX();
    VectorXs& v = scene.getV();
    const VectorXs& m = scene.getM();

    // Create a new Force vector of the same size as x and v
    VectorXs F(x.size());
    // Set the initial value of the Force vector to be zero
    F.setZero();

    // Pass the Force vector by reference to accumulateGradU method to change its value
    scene.accumulateGradU(F);
    // Force is negative the energy gradient
    F *= -1.0;

    // Zero the force for fixed DoFs
    for( int i = 0; i < scene.getNumParticles(); ++i ) if( scene.isFixed(i) ) F.segment<2>(2*i).setZero();

    // New position for the next time-step based on the current velocity
    x += dt*v;

    // Normalize the Force vector by dividing with the mass array (done to extract the acceleration part from the Force)
    F.array() /= m.array();
    
    // New velocity for the next time-step based on the acceleration
    v += dt*F;

    cout << "x = " << x << endl << ", v = " << v << endl << ", m = " << m << endl;

    return true;
}