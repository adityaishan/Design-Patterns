// Builder : When piecewise object construction is complicated,
//           provide an API for doing it succinctly.

//Fluent Builder too

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;

struct HtmlBuilder;

struct HtmlElement
{
  string name, text;
  vector<HtmlElement> elements;

  const size_t indent_size = 2;

  HtmlElement() {}
  HtmlElement(const string& name, const string& text) : name(name), text(text) {}

  string str(int indent = 0) const {

    ostringstream oss;
    string i(indent_size * indent, ' ');
    oss << i << "<" << name << ">" << endl;
    if(text.size() > 0)
      oss << string(indent_size * (indent + 1), ' ') << text << endl;

    for(const auto& e : elements)
      oss << e.str(indent + 1);

    oss << i <<"</" << name << ">" << endl;
    return oss.str();
  }

  static unique_ptr<HtmlBuilder> build(string root_name)
  {
    return make_unique<HtmlBuilder>(root_name);
  }
};

struct HtmlBuilder
{
  HtmlBuilder(string root_name){

    root.name = root_name;
  }

  HtmlBuilder& add_child(string child_name, string child_text){

    HtmlElement e(child_name, child_text);
    root.elements.emplace_back(e);
    return *this;
  }

  HtmlBuilder* add_child_2(string child_name, string child_text){

    HtmlElement e(child_name, child_text);
    root.elements.emplace_back(e);
    return this;
    }

  string str() const { return root.str(); }

  operator HtmlElement() const { return  root; }
  HtmlElement root; 
};

int main()
{
  //<p>hello</p>
  auto text = "hello";
  string output;
  output += "<p>";
  output += text;
  output += "</p>";
  cout << output << "\n";

    //<ul><li>hello</li><li>world</li></ul>
  string words[] = {"hello", "world"};
  ostringstream oss;
  oss << "<ul>";
  for(auto w : words)
    oss << " <li>" << w <<"</li>";
  oss<<"</ul>";
  cout << oss.str() << "\n";

  HtmlBuilder builder("ul");
  builder.add_child("li", "hello").add_child("li", "world");
  cout << builder.str() << endl;

    auto builder2 = HtmlElement::build("ul")
  ->add_child_2("li", "hello")->add_child_2("li", "world");
  cout << builder2 << "\n";

  return 0;
}
