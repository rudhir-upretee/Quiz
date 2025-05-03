#include <iostream>
#include <memory>
using namespace std;

class A {
public:
    A()
    {
        cout << "A::Constructor()" << endl;
    }
    
    ~A()
    {
        cout << "A::Destructor()" << endl;
    }
    void show() { cout << "A::show()" << endl; }
};

int main()
{
    {
        A* aptr = new A();
        aptr->show();
        //delete(aptr); 

        
        A aobj;
        aobj.show(); 

    }
    //aptr is freed but memory allocated by new not freed
    //Memory of aobj is freed
    
    {
        shared_ptr<A> p1 = make_shared<A>();
        p1->show();
        shared_ptr<A> p2(p1);
        p2->show();
        cout << "Ref :" << p2.use_count() << endl;
    }
    
    cout << "Bye" << endl;
}