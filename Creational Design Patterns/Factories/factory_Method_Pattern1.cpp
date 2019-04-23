#include <iostream>

//Abstract base class declared by framework
class Document
{
    public:
        Document(std::string name) : _name(name) {}

        virtual void open() const = 0;

        virtual void close() const = 0;

        virtual void printName(std::string) const = 0;

        std::string getName() const {
            return _name;
        }

    private:
        std::string _name;
};

// Derived class defined by client
class MyDocument : public Document
{
    public:
        MyDocument(std::string name) : Document(name) {}

        void open() const {
            std::cout << "  MyDocument: Open()\n";
        }

        void close()const {
            std::cout << "  MyDocument: Close()\n";
        }

        void printName(std::string id) const {
            std::cout << "Name: " << id << "\n";
        }
};

//Framework Declaration act as a Factory Pattern
class Application
{
    public:
        Application() : _index(0) {

            std::cout << "Application: ctor\n";
        }

        //entry point for client inside the framework
        void NewDocumnet(std::string name){
            
            std::cout << "Application: NewDocumnet()\n";

            //Framework calls the CreateDocument reserved for client customization
            _docs[_index] = CreateDocument(name);
            _docs[_index]->open();
            _docs[_index]->printName(_docs[_index]->getName());
            _docs[_index]->close();
            ++_index;
        }

        virtual Document* CreateDocument(std::string) = 0;

    private:
        int _index;
        Document* _docs[10];
};

class MyApplication : public Application
{
    public:
        MyApplication(){
            std::cout << "MyApplication: ctor\n";
        }
        
        //client defines the entry point of Document Customization
        Document* CreateDocument(std::string name){

            std::cout << "  MyApplication: CreateDocument()\n";

            return new MyDocument(name);
        }
};

int main()
{
    MyApplication app;

    app.NewDocumnet("foo");
    app.NewDocumnet("bar");

    return 0;
}
