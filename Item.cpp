using namespace std;
#include <string>

class Item
{
private:
    string name;
    int category, id, count;
public:
    Item(string name, int category, int id, int count);
    Item();
    ~Item();
    void setName(string name);
    void setId(int id);
    void setCategory(int category);
    void setCount(int count);
    string getName();
    int getId();
    int getCategory();
    int getCount();
};

Item::Item(string name, int category, int id, int count)
{
    this->name = name;
    this->category = category;
    this->id = id;
    this->count = count;
}

Item::Item() {
    name = "N/A";
    category = 0;
    id = 0;
    count = 0;
}

Item::~Item()
{
}

void Item::setName(string name)
{
    this->name = name;
}

void Item::setId(int id)
{
    this->id = id;
}

void Item::setCategory(int category)
{
    this->category = category;
}

void Item::setCount(int count)
{
    this->count = count;
}

string Item::getName()
{
    return name;
}

int Item::getId()
{
    return id;
}

int Item::getCategory()
{
    return category;
}

int Item::getCount()
{
    return count;
}
