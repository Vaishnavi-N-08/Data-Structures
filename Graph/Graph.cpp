#include <iostream>
#include <vector>
using namespace std;

class Graphs
{

public:
    void Create(int length)
    {
        CreateMatrix(length);
        return;
    }

    void CreateMatrix(int length)
    {
        int arr[length][length];

        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {
                arr[i][j] = 0;
            }
        }

        for (int i = 1; i < length; i++)
        {
            int x, y, z;
            cout << "Enter the adjacent elements : ";
            cin >> x >> y >> z;
            arr[x][y] = z;
            arr[y][x] = z;
        }

        for (int i = 1; i < length; i++)
        {
            for (int j = 1; j < length; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    void CreateList(int length)
    {
        vector<int> arl[length];

        for (int i = 1; i < length; i++)
        {
            int x, y;
            cout << "Enter the adjacent elements(for List) : ";
            cin >> x >> y;
            arl[x].push_back(y);
            arl[y].push_back(x);
        }

        for (int i = 1; i < length; i++)
        {
            cout << "Vertex " << i << ":";
            for (auto j : arl[i])
            {
                cout << "-> " << j;
            }
            cout << endl;
        }

        return;
    }
};

int main()
{

    Graphs g;
    int choice;
    int length;
    cout << "Enter the number of nodes : ";
    cin >> length;
    length++;

    while (choice != 3)
    {
        cout << "--------------------------------------" << endl;
        cout << "Press 1 : Graph representation using adjacent matrix" << endl;
        cout << "Press 2 : Graph representation using adjacent list" << endl;
        cout << "Press 3 : exit" << endl;

        cout << "Enetr your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {

            g.CreateMatrix(length);
            break;
        }

        case 2:
        {
            g.CreateList(length);
            break;
        }

        case 3:
        {

            break;
        }
        }
    }
    return 0;
}