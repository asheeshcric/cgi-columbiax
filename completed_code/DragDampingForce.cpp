#include "DragDampingForce.h"

void DragDampingForce::addGradEToTotal( const VectorXs& x, const VectorXs& v, const VectorXs& m, VectorXs& gradE )
{
  assert( x.size() == v.size() );
  assert( x.size() == m.size() );
  assert( x.size() == gradE.size() );
  assert( x.size()%2 == 0 );
  
  // Add milestone 2 code here.
  for(int i = 0; i < x.size()/2; i++) {
      gradE.segment<2>(2 * i) += m_b * v.segment<2>(2 * i);
//       gradE[2*i] += m_b * v[2*i];
//       gradE[2*i+1] += m_b * v[2*i+1];
  }
}
