#include <iostream>

using namespace std;

class show
{
    private:
    int x;
    int y;
    
    public:
    show();
    
    void fnc(int,int);
    void print(void);
};

show:: show()
{
    cout<<"we are in default constructer"<<endl;
    cin>>x;
    cin>>y;
}
void show:: fnc(int a,int b)
{
    x=a;
    y=b;
    cout<<x<<" "<<y<<endl;
}

void show:: print(void)
{
    cout<<x<<" "<<y;
}

int main()
{
   show obj;
   //obj.fnc(3,4);
   obj.print();
   
   

    return 0;
}
