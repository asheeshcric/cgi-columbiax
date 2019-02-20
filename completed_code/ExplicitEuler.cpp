#include "ExplicitEuler.h"
#include<iostream>
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
    
    VectorXs f(x.size());
    f.setZero();
    scene.accumulateGradU(f);
    
    f = -f;
//     cout << "force="<<f<<endl;
//     cout << "mass="<<m<<endl;
//     cout << "velocity="<<v<<endl;
//     cout << "x="<<x<<endl;
    x = x + dt * v;
    for (int i = 0 ; i < scene.getNumParticles(); i++)
    {
        if (scene.isFixed(i))
        {   
            f[2*i] = 0;
            f[2*i + 1] = 0;
        }
    }
    v = v + dt * (m.array().inverse() * f.array()).matrix();
    cout << "KE="<<scene.computeKineticEnergy() << endl;
    return true;
}
