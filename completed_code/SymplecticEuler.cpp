#include "SymplecticEuler.h"
#include <iostream>

using namespace std;
bool SymplecticEuler::stepScene( TwoDScene& scene, scalar dt )
{
  /* Add milestone 2 code here.      */
  VectorXs& x = scene.getX();
  VectorXs& v = scene.getV();
  const VectorXs& m = scene.getM();

//   cout << "mass=" <<m<<endl;
  VectorXs f(x.size());
  f.setZero();
  scene.accumulateGradU(f);
  
  f = -f;
  for (int i = 0 ; i < scene.getNumParticles(); i++)
  {
       if (scene.isFixed(i))
       {
           f[2*i] = 0;
           f[2*i + 1] = 0;
       }
  }
  v = v + dt * (m.array().inverse() * f.array()).matrix();
  x = x + dt * v;
//   cout << "TE="<<scene.computeTotalEnergy() << endl;
  return true;
}






