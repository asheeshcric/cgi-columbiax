#include "SimpleGravityForce.h"

#define IGNORE_ORIGIN true

void SimpleGravityForce::addEnergyToTotal( const VectorXs& x, const VectorXs& v, const VectorXs& m, scalar& E )
{
    assert( x.size() == v.size() );
    assert( x.size() == m.size() );
    assert( x.size()%2 == 0 );
    
    // Your code goes here!
    int size = x.size();
    for (int x = 0, y = 1; x < size; x += 2, y += 2) {
        E += -(m[x] * ((v[x] * m_gravity[0]) + (v[y] * m_gravity[1]))); // U(x) = -m(g . x)
    }
}

void SimpleGravityForce::addGradEToTotal( const VectorXs& x, const VectorXs& v, const VectorXs& m, VectorXs& gradE )
{
    assert( x.size() == v.size() );
    assert( x.size() == m.size() );
    assert( x.size() == gradE.size() );
    assert( x.size()%2 == 0 );
    
    // Your code goes here!
    int size = x.size();
    for (int x0 = 0, x1 = 1; x0 < size; x0 += 2, x1 += 2) {
        if (IGNORE_ORIGIN || x[x1] > 0) {
            gradE[x0] += m[x0] * m_gravity[0];
            gradE[x1] += m[x1] * m_gravity[1];
        }
    }
}
