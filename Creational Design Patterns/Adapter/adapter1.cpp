// Things to keep in mind before the implementation

// Specify the new desired interface
// Design a "wrapper" class that can "impedance match" the old to the new
// The client uses (is coupled to) the new interface
// The adapter/wrapper "maps" to the legacy implementation

#include <iostream>
#include <memory>

using namespace std;

class ExecuteInterface{
public:
    // 1. Specify the new interface
    virtual ~ExecuteInterface() = default;
    virtual void execute() = 0;
};


//2. Adapter class
template<class TYPE>
class ExecuteAdapter: public ExecuteInterface
{
public:
    ExecuteAdapter(TYPE *o, void(TYPE:: *m)()): object{o}, method{m} {} 
    ~ExecuteAdapter(){
        delete object;
    }
  
    // 4. The adapter "maps" the new to the legacy implementation
    void execute(){
        (object->*method)();
    }

private:
    TYPE *object;// ptr-to-object attribute
    void(TYPE:: *method)(); /* the old */ //ptr-to-member-function attribute
    
};


// The old: three totally incompatible classes
// no common base class,
class Fea{
public:
    ~Fea(){
        std::cout << "Fea::dtor" << "\n";
    }

    void doThis(){
        std::cout << "Fea::doThis" << "\n";
    }
};

class Feye{
public:
    ~Feye(){
        std::cout << "Feye::dtor" << "\n";
    }

    void doThat(){
        std::cout << "Feye::doThat" << "\n";
    }
};

class Pheau{
public:
    ~Pheau(){
        std::cout << "Pheau::dtor" << "\n";
    }
    void doTheOther(){
        std::cout << "Pheau::doTheOther" << "\n";
    }
};

//the new is returned
ExecuteInterface **initialize(){
    ExecuteInterface **array = new ExecuteInterface*[3];

    array[0] = new ExecuteAdapter<Fea> (new Fea(), &Fea::doThis);
    array[1] = new ExecuteAdapter<Feye> (new Feye(), &Feye::doThat);
    array[2] = new ExecuteAdapter<Pheau> (new Pheau(), &Pheau::doTheOther);
    return array;
}

int main()
{
  ExecuteInterface **objects = initialize();
  for (int i = 0; i < 3; i++) {
   objects[i]->execute();
  }
 
  // 3. Client uses the new (polymporphism)
  for (int i = 0; i < 3; i++) {
    delete objects[i];
  }
  delete objects;
  return 0;
}
