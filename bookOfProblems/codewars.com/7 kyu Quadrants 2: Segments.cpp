bool quadrant_segment(const coord &A, const coord &B) {
  int qA = 0, qB = 0;
 
  if(A.x > 0 and A.y > 0) qA = 1;
  else if(A.x < 0 and A.y > 0) qA = 2;
  else if(A.x < 0 and A.y < 0) qA = 3;
  else if(A.x > 0 and A.y < 0) qA = 4;
  
  if(B.x > 0 and B.y > 0) qB = 1;
  else if(B.x < 0 and B.y > 0) qB = 2;
  else if(B.x < 0 and B.y < 0) qB = 3;
  else if(B.x > 0 and B.y < 0) qB = 4;
  
  if(qA == qB) return false;
  else return true;
}

////////

