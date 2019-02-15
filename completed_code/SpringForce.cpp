#include "SpringForce.h"
#include <iostream>
#include <cmath>

using namespace std;
void SpringForce::addEnergyToTotal( const VectorXs& x, const VectorXs& v, const VectorXs& m, scalar& E )
{
  assert( x.size() == v.size() );
  assert( x.size()%2 == 0 );
  assert( m_endpoints.first >= 0 );  assert( m_endpoints.first < x.size()/2 );
  assert( m_endpoints.second >= 0 ); assert( m_endpoints.second < x.size()/2 );

  // Add milestone 2 code here.
  VectorXs xi, xj;
  xi = x.segment<2>(2 * m_endpoints.first);
  xj = x.segment<2>(2 * m_endpoints.second);
  E += 0.5 * m_k * pow(((xi - xj).norm() - m_l0), 2);
//       pow(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) - m_l0, 2);
}

void SpringForce::addGradEToTotal( const VectorXs& x, const VectorXs& v, const VectorXs& m, VectorXs& gradE )
{
  assert( x.size() == v.size() );
  assert( x.size() == gradE.size() );
  assert( x.size()%2 == 0 );
  assert( m_endpoints.first >= 0 );  assert( m_endpoints.first < x.size()/2 );
  assert( m_endpoints.second >= 0 ); assert( m_endpoints.second < x.size()/2 );

  // Add milestone 2 code here.
  VectorXs xi, xj, n, vi, vj;
  xi = x.segment<2>(2 * m_endpoints.first);
  xj = x.segment<2>(2 * m_endpoints.second);
  n = (xi - xj) / (xi - xj).norm();
  gradE.segment<2>(2 * m_endpoints.first) += m_k * ((xi - xj).norm() - m_l0) * n;
  gradE.segment<2>(2 * m_endpoints.second) -= m_k * ((xi - xj).norm() - m_l0) * n;
    
  vi = v.segment<2>(2 * m_endpoints.first);
  vj = v.segment<2>(2 * m_endpoints.second);
  gradE.segment<2>(2 * m_endpoints.first) += m_b * n.dot(vi - vj) * n;
  gradE.segment<2>(2 * m_endpoints.second) -= m_b * n.dot(vi - vj) * n;
//   cout<<gradE
}
