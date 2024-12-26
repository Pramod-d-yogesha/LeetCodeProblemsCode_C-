/**********************************************
  1. What is Abstraction?
Abstraction means hiding unnecessary details and exposing only the essential functionality.

Real-life Example:
When you drive a car:

You use the steering wheel to turn the car.
You use the brake pedal to stop the car.
Do you know or care how the steering or brake works internally? No!
The car hides unnecessary details (e.g., mechanics of the brake system) and provides only the interface you need (steering and pedals).

2. How Does Abstraction Apply to Programming?
In programming, abstraction hides the implementation details and exposes only what is necessary through a clean interface.

For example:

If you want to calculate the area of a shape, you don’t need to know how a circle or rectangle computes its area. You just call a method calculateArea.
3. What is an Abstract Class?
An abstract class is a tool in C++ that helps achieve abstraction.

It defines an interface (pure virtual functions) that derived classes must implement.
It ensures derived classes focus on necessary details (e.g., how to calculate area for their specific shape) without exposing internal logic.
Why Use an Abstract Class?
It acts as a blueprint.
It says, “If you are a shape, you must define how to calculate your area,” but doesn’t dictate how to do it.

4. Connection Between Abstraction and Abstract Classes
An abstract class helps achieve abstraction by:

Providing a general interface (pure virtual functions).
Forcing derived classes to implement only the necessary functionality.
5. Example to Tie It Together
Imagine you have different shapes (Circle, Rectangle, Triangle) and want to calculate their area.

Without Abstraction:
You’d write separate functions for each shape.
You’d have to manually check which shape you’re dealing with and call the correct function.

******************************************************/

#include <iostream>
using namespace std;
class Shape
{
    public:
    virtual void draw()=0;
    virtual ~Shape() {
        cout<<"Destructor called"<<endl;
    }
};
class Circle : public Shape
{
  public:
  void draw()
  {
      cout<<"Circle draw"<<endl;
  }
};
class Rectangle : public Shape
{
    void draw()
    {
        cout<<"Rectangle draw"<<endl;
    }
};
int main()
{
    Shape* shp=nullptr;
    shp=new Circle();
    shp->draw();
    delete shp;
    
    shp=new Rectangle();
    shp->draw();
    delete shp;
}
