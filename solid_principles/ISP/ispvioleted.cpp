#include<bits/stdc++.h>
using namespace std;

//many client specific interface are better than  one single general purpose interface
// client should not be forced to implement methods they don't need to

class Shape{
  public:
    virtual void area() = 0;
    virtual void perimeter() = 0;
    virtual void volume() = 0;
};

class circle:public Shape{
  private:
    double radius;
  public:

  circle(double radius){
    this->radius = radius;
  }

  void area(){
    cout << "area of circle is:" << 3.14 * radius * radius << endl;
  }

  void perimeter(){
    cout << "perimeter of circle is:" << 2 * 3.44 * radius << endl;
  }

  void volume(){
    throw logic_error("volume is not applicable for circle");
  }
};

class reactangle:public Shape{
 private:
   double length;
   double breadth;
 
 public:

 reactangle(double l,double b){
   this->length = l;
   this->breadth = b;
 }

 void area(){
   cout << "area of reactangle is: " << length * breadth << endl;
 }

 void perimeter(){
   cout << "perimeter of reactangle is:" << 2 * (length + breadth) << endl;
 }
 
 void volume(){
   throw logic_error("volume is not applicable for reactangle");
 }
};

class cube:public Shape{
  private:
    double side;

 public:
 cube(double side){
   this->side = side;
 }

 void area(){
   cout << "area of cube is: " << 6 * side * side << endl;
 }

 void perimeter(){
   cout << "perimeter of cube is : " << 12 * side << endl;
 }

 void volume(){
   cout << "volume of cube is: " << side * side * side << endl;
 }
};

int main(){
  circle *ci=new circle(5.0);
  reactangle *re = new reactangle(5.0, 2.0);
  cube *cu = new cube(5.0);

  cout << "----------------" << "circle" << "-----------------------" << endl;
  try{
    ci->area();
    ci->perimeter();
    ci->volume();
  }
  catch(const logic_error &e){
    cout << "error :" << e.what() << endl;
  }


  cout <<"----------------"<< "reactangle" << "-----------------------" << endl;
  try{
    re->area();
    re->perimeter();
    re->volume();
  }
  catch(const logic_error &e){
    cout << "error:" << e.what() << endl;
  }

  cout << "----------------" << "cube" << "-----------------------" << endl;
  cu->area();
  cu->perimeter();
  cu->volume();

  return 0;
}