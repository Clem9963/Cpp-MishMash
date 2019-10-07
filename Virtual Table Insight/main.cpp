#include <cstdlib>
#include <iostream>
#include <string>

class Entity
{
  public:
	virtual std::string getName() { return "The entity has no name"; }
};

class Person : public Entity
{
  private:
	std::string m_name;

  public:
	Person(std::string name) : m_name(name) {}

	std::string getName() override { return m_name; }
};

void printName(Entity &e) { std::cout << e.getName() << std::endl; }

int main(int, char **)
{
	Entity e;
	printName(e);

	Person p("Billy");
	printName(p);
	Person *ptr = &p;

	return EXIT_SUCCESS;
}
