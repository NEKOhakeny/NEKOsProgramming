
    Point rotate_1(double rad,Point a,Point b){
  Point trans;
  double x = b.x - a.x;
  double y = b.y - a.y;
  x = x * cos(rad) + y * sin(rad);
  y = x * sin(rad) + y * cos(rad);
  x += a.x;
  y += a.y;
  trans.x = x;
  trans.y = y;
  return trans;
}

trans rotate_2(double,Point *a,Point *b){
  double x = (*b).x - (*a).x;
  double y = (*b).y - (*a).y;
  x = x * cos(rad) + y * sin(rad);
  y = x * sin(rad) + y * cos(rad);
client_loop: send disconnect: Broken pipe

    
}