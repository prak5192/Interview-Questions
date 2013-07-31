/*

In C++, if a class has a constructor which can be called with a single 
argument, then this constructor becomes conversion constructor because 
such a constructor allows automatic conversion to the class being 
constructed.

*/

#include<iostream>
 
using namespace std;
class Test
{
    private:
        int x;
    public:
        Test(int i) {
            x = i;
        }

        void show() { 
            cout<<" x = "<<x<<endl; 
        }
};
 
int main()
{
    Test t(20);
    t.show();
    t = 30; // conversion constructor is called here.
    t.show();
    return 0;
}
