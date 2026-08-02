#include<bits/stdc++.h>
using namespace std;

//segregate the interface for each client

class TwoDimensionshape {
   public:
   virtual void area()=0;
   virtual void perimeter() = 0;
};

class ThreeDimensionShape:public TwoDimensionshape{
  public:
    virtual void volume() = 0;
};

class circle:public TwoDimensionshape{
  private:
    double radius;
  
  public:
  circle(double r){
    this->radius = r;
  }

  void area(){
    cout << "area of circle is : " << 3.14*radius * radius << endl;
  }

  void perimeter(){
    cout << "perimeter of circle is: " << 2 * 3.14 * radius << endl;
  }
};

class reactangle:public TwoDimensionshape{
  private:
    double length;
    double breadth;
  
  public:
  reactangle(double l,double b){
    this->length = l;
    this->breadth = b;
  }

  void area(){
    cout << "area of ractangle is :" << length * breadth << endl;
  }

  void perimeter(){
    cout << "perimeter of reactangle is:" << 2 * (length + breadth) << endl;
  }
};

class cube: public ThreeDimensionShape{
  private:
    double side;
  
  public:
   cube(double s){
     this->side = s;
   }

   void area(){
     cout << "area of cube is :" << 6 * side * side << endl;
   }

   void perimeter(){
     cout << "perimeter of cube is :" << 12 * side << endl;
   }

   void volume(){
     cout << "volume of cube is :" << side * side * side << endl;
   }
};

int main(){
  circle ci(5.0);
  reactangle re(5.0, 4.0);
  cube cu(5.0);

  cout << "----------" << "circle" << "-----------" << endl;
  ci.area();
  ci.perimeter();

  cout << "----------" << "reactangle" << "-----------" << endl;
  re.area();
  re.perimeter();

  cout << "----------" << "cube" << "-----------" << endl;
  cu.area();
  cu.perimeter();
  cu.volume();
  return 0;
}