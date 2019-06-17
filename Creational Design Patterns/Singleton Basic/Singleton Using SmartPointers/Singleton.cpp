#include <iostream> 
#include <tr1/memory>

using namespace std;
using namespace std::tr1;

struct SharedClass
{
    SharedClass();
    ~SharedClass();
};

SharedClass::SharedClass()
{
    cout << "SharedClass ctor: " << this << "\n";
}

SharedClass::~SharedClass()
{
    cout << "SharedClass dtor: " << this << "\n";
}

struct ContainerClass
{
    ContainerClass();
    ~ContainerClass();

    std::shared_ptr<SharedClass> getshared();

    std::shared_ptr<SharedClass> memberptr;

    static std::weak_ptr<SharedClass> masterptr;
};

std::weak_ptr<SharedClass> ContainerClass::masterptr;

std::shared_ptr<SharedClass> ContainerClass::getshared()
{
    std::shared_ptr<SharedClass> temp = masterptr.lock();

    if(!temp){
        temp.reset(new SharedClass());
        masterptr = temp;
    }

    return temp;
}

ContainerClass::ContainerClass()
{
   cout << "ContainerClass ctor:" << this << "\n";
   cout << "\tbefore\tcopy: " << memberptr.use_count() << "\t" << "master: " << masterptr.use_count() << "\n";

   memberptr = getshared();

   cout << "\tafter\tcopy: " << memberptr.use_count() << "\t" << "master: " << masterptr.use_count() << "\n";
   cout << "\n";

}

ContainerClass::~ContainerClass()
{
   cout << "ContainerClass dtor:" << this << "\n";
   cout << "\tbefore\tcopy: " << memberptr.use_count() << "\t" << "master: " << masterptr.use_count() << "\n";

   cout << "\n";
}

int main()
{
    cout << "Entering main\n";

    ContainerClass* pClass1 = new ContainerClass();
    ContainerClass* pClass2 = new ContainerClass();

    delete pClass1;
    delete pClass2;

    ContainerClass* pClass3 = new ContainerClass();
    delete pClass3;

    cout << "Exiting main\n";
}
