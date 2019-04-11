//Open for Extension and closed for Modification
#include <string>
#include <vector>
#include <iostream>
using namespace std;

enum class Color {red, green, blue};
enum class Size  {small, medium, large};

struct Product
{
  string name;
  Color  color;
  Size   size;
};

template <typename T> struct AndSpecification;

// template -> item satisfy particular specification
template <typename T> 
struct Specification
{
  virtual ~Specification() = default;
  virtual bool is_satisfied(T* item) const = 0;
};

template <typename T> AndSpecification<T> operator&&
          (const Specification<T>& first, const Specification<T>& second)
{

  return { first, second };
}

template <typename T> 
struct AndSpecification : Specification<T>
{
  const Specification<T>& first;
  const Specification<T>& second;

    AndSpecification(const Specification<T>& first, const Specification<T>& second) 
                     : first(first), second(second) {}

    bool is_satisfied(T* item) const override {
      return first.is_satisfied(item) && second.is_satisfied(item);
    }
};


struct ColorSpecification : Specification<Product>
{
  Color color;
  ColorSpecification(Color color) : color(color) {}

  bool is_satisfied(Product *item) const override
  {
    return item->color == color;
  }
  
};

struct SizeSpecification : Specification<Product>
{
  Size size;
  explicit SizeSpecification(Size size) : size(size) {}

  bool is_satisfied(Product *item) const override
  {
    return item->size == size;
  }
};


//template ->  filter on items on the basis of specification
template <typename T> 
struct Filter
{
  virtual vector<T*> filter(vector<T*> items, 
                          Specification<T>& spec) = 0;
};

struct BetterFilter : Filter<Product>
{
  vector<Product*> filter(vector<Product*> items,
                        Specification<Product>& spec) override 
  {
    vector<Product*> result;
    for(auto& item : items){
      if(spec.is_satisfied(item))
        result.push_back(item);
    }

    return result;
  }
};

int main(){

  Product apple{"apple", Color::green, Size::small};
  Product tree{"Tree", Color::green, Size::large};
  Product house{"House", Color::blue, Size::large};

  vector<Product*> items{&apple, &tree, &house};

  BetterFilter bf;

  ColorSpecification green(Color::green);
  for(auto& x : bf.filter(items, green)){
    cout << x->name << " is green.\n";
  }

  SizeSpecification large(Size::large);
  for(auto& x : bf.filter(items, large)){
    cout << x->name << " is large.\n";
  }
  //AndSpecification<Product> green_and_large(green, large);

  auto spec = green && large;
  for(auto& x : bf.filter(items, spec)){
    cout << x->name << " is green and large\n";
  }
  return 0;
}
