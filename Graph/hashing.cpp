#include <iostream>
using namespace std;

#define size 7 // size of array should be prime number
// int array[size];

class Hash
{

public:
    int array[size];
    int count;

    Hash()
    {
        for (int i = 0; i < size; i++)
        {
            array[i] = -1;
        }
        count = 0;
    }

    void insert(int value)
    {
        int key = value % size;

        if (count == size)
        {
            cout << "oopsss Sorry hash is full";
            return;
        }

        if (array[key] == -1)
        {
            array[key] = value;
            cout << value << " "
                 << "inserted at"
                 << " " << key << endl;
            return;
        }

        else
        {
            int temp;
            temp = array[key];
            int temphash;
            temphash = temp % size;

            if (temphash == key)
            {
                while (key != size)
                {
                    if (array[key] == -1)
                    {
                        array[key] = value;
                        cout << value << " inserted at " << key << endl;
                        return;
                    }
                    key++;
                    if (key == size)
                    {
                        key = 0;
                    }
                }
            }

            else
            {
                // replacement
                array[key] = value;
                value = temp;
                while (key != size)
                {
                    if (array[key] == -1)
                    {
                        array[key] = value;
                        cout << value << " inserted at " << key << endl;
                        return;
                    }
                    key++;
                    if (key == size)
                    {
                        key = 0;
                    }
                }
            }
        }
    }

    void search(int value)
    {
        int key = value % size;
        if (array[key] == value)
        {
            cout << "search found" << endl;
        }
        else
        {
            cout << "not found" << endl;
        }
    }

    void Display()
    {

        for (int i = 0; i < size; i++)
        {
            cout << i << "=" << array[i] << endl;
        }
    }
};

int main()
{

    Hash hs;
    int choice;

    while (choice != 4)
    {
        cout << "--------------------------------------" << endl;
        cout << "Press 1 : To insert " << endl;
        cout << "Press 2 : To Search" << endl;
        cout << "Press 3 : To Display  " << endl;
        cout << "Press 4 : exit" << endl;

        cout << "Enetr your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int val;
            cout << "Enter an element to be inserted :";
            cin >> val;
            hs.insert(val);
            break;
        }

        case 2:
        {
            int x;
            cout << "Enter an element to search :";
            cin >> x;
            hs.search(x);
            break;
        }

        case 3:
        {
            hs.Display();
            break;
        }

        case 4:
        {
            break;
        }
        }
    }

    return 0;
}
