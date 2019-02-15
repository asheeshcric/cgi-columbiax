#include "GravitationalForce.h"

void GravitationalForce::addEnergyToTotal( const VectorXs& x, const VectorXs& v, const VectorXs& m, scalar& E )
{
  assert( x.size() == v.size() );
  assert( x.size() == m.size() );
  assert( x.size()%2 == 0 );
  assert( m_particles.first >= 0 );  assert( m_particles.first < x.size()/2 );
  assert( m_particles.second >= 0 ); assert( m_particles.second < x.size()/2 );

  // Add milestone 2 code here.
  VectorXs xi, xj, n;
  xi = x.segment<2>(2 * m_particles.first);
  xj = x.segment<2>(2 * m_particles.second);
  E -= m_G * m[m_particles.first] * m[m_particles.second] / (xi - xj).norm();
}

void GravitationalForce::addGradEToTotal( const VectorXs& x, const VectorXs& v, const VectorXs& m, VectorXs& gradE )
{
  assert( x.size() == v.size() );
  assert( x.size() == m.size() );
  assert( x.size() == gradE.size() );
  assert( x.size()%2 == 0 );
  assert( m_particles.first >= 0 );  assert( m_particles.first < x.size()/2 );
  assert( m_particles.second >= 0 ); assert( m_particles.second < x.size()/2 );

  // Add milestone 2 code here.
  VectorXs xi, xj, n;
  xi = x.segment<2>(2 * m_particles.first);
  xj = x.segment<2>(2 * m_particles.second);
  n = (xi - xj) / (xi - xj).norm();
  gradE.segment<2>(2 * m_particles.first) += m_G * m[m_particles.first * 2] * m[m_particles.second * 2] * n / (xi - xj).squaredNorm();
  gradE.segment<2>(2 * m_particles.second) -= m_G * m[m_particles.first * 2] * m[m_particles.second * 2] * n / (xi - xj).squaredNorm();
}
