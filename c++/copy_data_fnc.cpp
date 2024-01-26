#include<iostream>
using namespace std;

class check
{
       int x;
       int y;

        public:

       void print(void)
       {
           cout<<x<<" "<<y;
           cout<<endl;
       }
       void input(int a,int b)
       {
           x=a;
           y=b;
       }
       void copy(check &obj)
       {
          x=obj.x;
          y=obj.y;

       }
};

int main()
{

        check obj1,obj2;
        obj1.input(4,5);
        cout<<"obj1"<<endl;
        obj1.print();
        cout<<"obj2"<<endl;
        obj2.copy(obj1);
        obj2.print();

}
