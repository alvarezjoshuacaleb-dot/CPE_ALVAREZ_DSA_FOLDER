#include <iostream>
#include <string>
using namespace std;


class Fruit {
private:
    string name;
    double price;
    int quantity;

public:
    // Constructor
    Fruit(string n = "", double p = 0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    // Copy Constructor
    Fruit(const Fruit& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    // Copy Assignment Operator
    Fruit& operator=(const Fruit& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    // Destructor
    ~Fruit() {
        cout << "Fruit Deleted: " << name << endl;
    }

    // Calculate total price
    double calculateSum() const {
        return price * quantity;
    }

    // Display information
    void display() const {
        cout << "Fruit: " << name
             << " | Price: PHP " << price
             << " | Quantity: " << quantity
             << " | Total: PHP " << calculateSum()
             << endl;
    }
};


class Vegetable {
private:
    string name;
    double price;
    int quantity;

public:
    // Constructor
    Vegetable(string n = "", double p = 0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    // Copy Constructor
    Vegetable(const Vegetable& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    // Copy Assignment Operator
    Vegetable& operator=(const Vegetable& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    // Destructor
    ~Vegetable() {
        cout << "Vegetable Deleted: " << name << endl;
    }

    // Calculate total
    double calculateSum() const {
        return price * quantity;
    }

    // Display information
    void display() const {
        cout << "Vegetable: " << name
             << " | Price: PHP " << price
             << " | Quantity: " << quantity
             << " | Total: PHP " << calculateSum()
             << endl;
    }
};


double TotalSum(Fruit* fruits[], int fruitCount,
                Vegetable* vegetables[], int vegetableCount)
{
    double total = 0;

    for (int i = 0; i < fruitCount; i++)
        total += fruits[i]->calculateSum();

    for (int i = 0; i < vegetableCount; i++)
        total += vegetables[i]->calculateSum();

    return total;
}

//==========================
// Main Function
//==========================
int main() {

    // Dynamic Memory Allocation
    Fruit* fruits[2];
    Vegetable* vegetables[2];

    fruits[0] = new Fruit("Apple", 10, 7);
    fruits[1] = new Fruit("Banana", 10, 8);

    vegetables[0] = new Vegetable("Broccoli", 60, 12);
    vegetables[1] = new Vegetable("Lettuce", 50, 10);

    cout << "===== Jenna's Grocery List =====" << endl;

    // Display fruits
    for (int i = 0; i < 2; i++)
        fruits[i]->display();

    // Display vegetables
    for (int i = 0; i < 2; i++)
        vegetables[i]->display();

    cout << endl;

    // Display total amount
    cout << "Total Amount: PHP "
         << TotalSum(fruits, 2, vegetables, 2)
         << endl;

    cout << endl;

    // Delete Lettuce
    cout << "Deleting Lettuce..." << endl;
    delete vegetables[1];
    vegetables[1] = nullptr;

    // Free remaining memory
    delete fruits[0];
    delete fruits[1];
    delete vegetables[0];

    return 0;
}