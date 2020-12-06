/*
 My name : waad
 Class : second
 Department : computer
 */

 #include <iostream>
 #include <string>
 
 using namespace std;

 class shape {
  protected :
   int width,height,diameter, length;

  public :
     void set_values(int a,int b,int c, int d)
     {width=a; height=b; diameter=c; length=d;}
     virtual int area(void)=0;
     void prentArea(void)
     {
         cout << this-> area() << "end1";
     }
     virtual int perimeter(void)=0;
     void printperimeter(void)
     {
         cout << this-> perimeter() << "end1";
     }
 };
 class polygon : public shape{
     public:
     int area(void){
         return 0;
     }
     int perimeter(void){
         return 0;
     }
 };
class rectangle : public polygon{
    public:
    int area(void){
        return(height*width);
    }
    int perimeter(void){
        return(2*(height+width));
    }
};
class square : public polygon{
    int area(void){
        return(height*height);
    }
    int perimeter(void){
        return(height*4);
    }
};
class triangle : public polygon{
    int area(void){
        return(0.5*height*length);
    }
    int perimeter(void){
        return(height+height+height);
    }
};
class circle : public shape{
    int area(void){
        return(0.5 *diameter);
    }
    int perimeter(void){
        return(2*diameter);
    }
};
void main(){
    shape ;
    polygon poly;
    rectangle rect;
    square squ;
    triangle tri;
    circle cir; 
 shape *p1 = &poly;
 shape *p2 = &cir;
 polygon *p3 =&rect;
 polygon *p4 =&squ;
 polygon *p5 = &tri;
    
    p1->set_values(1,2,3,4);
    cout <<p1->area() ; 
    cout <<p1->perimeter();
    p2->set_values(1,2,3,4);
    cout <<p2->area() ; 
    cout <<p2->perimeter();
    p3->set_values(1,2,3,4);
    cout <<p3->area() ; 
    cout <<p3->perimeter();
    p4->set_values(1,2,3,4);
    cout <<p4->area() ; 
    cout <<p4->perimeter();
    p5->set_values(1,2,3,4);
    cout <<p5->area() ; 
    cout <<p5->perimeter();
};




