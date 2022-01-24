#include <iostream>
#include"C:\ADS\queueApp.cpp"

void rev_stack(Stack_Int &st1)
{
    queue q;

    int m = 0;

    while(!st1.empty())
    {
        int val = st1.pop();
        q.enqueue(val);
        m++;
    }

    for(int i=0;i<n;i++)
    {
        int val = q.dequeue();
        st1.push(val);
    }
    return;

}
int main()
{
    Stack_Int st1;
    int choice;

    while (choice != 4)
    {
        cout << "****************************************" << endl;
        cout << "Press 1 : To push the element" << endl;
        cout << "Press 2 : To pop the element" << endl;
        cout << "Press 3 : To Display the reverse stack the element" << endl;
        cout << "Press 4 : Exit" << endl;
        cout << "****************************************" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "Enter the value you want to push : ";
            cin >> value;
            st1.push(value);
            cout << endl;
            break;
        }
        case 2:
        {
            st1.pop();
            cout << endl;
            break;
        }
        case 3:
        {
            st1.Display();
            cout << endl;
            break;
        }
        case 4:
        {
          break;
        }
        default:
        {
            cout << "Enter a valid choice" << endl;
        }
    };
}

}


