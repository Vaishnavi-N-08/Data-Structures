
#include<stdio.h>
#include <string.h>
#include<stdlib.h>

struct book {
  
    char name[20];
    int number;
    int price;
};
void Display(struct book v[],int n);

//Fuction for bubble sort(name of book)
void BubbleSort(struct book v[],int n)
{
    struct book temp;
    int i,j;
      for (i=0;i<n-1;i++)
   {
       for (j=i;j<n-1;j++)
       {
           if (strcmp(v[j].name,v[j+1].name)>0)
           {
              temp = v[j];
              v[j] = v[j + 1];
              v[j+1] = temp;
           }
       }
    }
   
}

//Function for insertion sort (number of book)

void InsertionSort(struct book v[],int n){
    for (int i=1;i<n;i++)
    {
        struct book current;
        current = v[i];
        int j = i-1;
        while(v[j].number>current.number && j>=0)
        {
           v[j+1] = v[j];
           j--;
        }
        

        v[j+1] = current;
    }
  
}


void selectionsort(struct book v[],int n)
{   
    struct book temp;
    for (int i=0;i<n-1;i++)
    {
        int min_id = i;
        for(int j=i+1;j<n;j++)
        {
            if (v[j].price< v[min_id].price)
            {
                min_id = j;
            }
            
            temp = v[min_id];
            v[min_id] = v[i];
            v[i] = temp;
            
        }
    }
}

//Function For merging two subarrays which are formed during merge sort
void Merge(struct book v[],int l,int m,int r)
{    
    // Create a ← A[l..m] and b ← A[m+1..r]
    int n1 = m - l+ 1;
    int n2 = r - m;
    struct book a[n1], b[n2];
     for (int i = 0; i < n1; i++)
         a[i] = v[l + i];
    for (int j = 0; j < n2; j++)
        b[j] = v[m + 1 + j];
    
    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2) {
    if (a[i].number <= b[j].number) {
      v[k] = a[i];
      i++;
    } else {
      v[k] = b[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    v[k] = a[i];
    i++;
    k++;
  }

  while (j < n2) {
    v[k] = b[j];
    j++;
    k++;
  }
}

//Function For Merge Sort (Number of Book)
void  MergeSort(struct book v[],int l,int r)
{
  if(l<r)
  {   
      // m is the point where the array is divided into two subarrays
      int m = l + (r - l) / 2;
      MergeSort(v, l, m);
      MergeSort(v, m+1, r);
      // Merge the sorted subarrays
      Merge(v, l, m, r);
     
  }
  
}

void swap(struct book v[],int i,int j)
{
    struct book temp = v[i];
    v[i] = v[j];
    v[j]=temp;
}

int Partition(struct book v[],int l,int r)
{
    struct book pivot = v[r];
    int i = l-1;
    for (int j=l;j<r;j++)
    {
        if(v[j].price<pivot.price)
        {
            i++;
            swap(v,i,j);
        }
    }
    
     swap(v,i+1,r);
     return i+1;
}

//Function For Quick Sort (price of book)
void  QuickSort(struct book v[],int l ,int r)
{
     if(l < r)
    {
        int pi = Partition(v,l,r);
        
         QuickSort(v,l,pi-1);
         QuickSort(v,pi+1,r);
    }
}
//Function For linear search.

int LinearSearch(struct book v[], int n, int key1)
{
    int i;
    int current;
    for (i = 0; i < n; i++)
    // current = v[i].number;
        if (v[i].number == key1 )
            return i;
    return -1;
}

//Function for binary search.
int binarySearch(struct book v[],int l, int r, char key2[])
{   int i;
    
    if(r >= l)
    {
      int mid = l + (r - l) / 2;
    if (strcmp(v[mid].name,key2) == 0)
            return mid;
    if (strcmp(v[mid].name,key2) > 0)
            return binarySearch(v, l, mid - 1, key2);
    return binarySearch(v, mid + 1, r, key2);
    }
    return -1;
}

//Function to display menu
void menu(struct book v[],int n)
{   
    int ch1,ch2,key1;
    char key2[20];
    printf("\nWhat Would You Like To Do");
    printf("\n");
    printf("\n****************************SORT**************************");
    printf("\n");
    printf("\n Press 1 = Bubble sort according to name");
    printf("\n Press 2 = Insertion sort according to book number");
    printf("\n Press 3 = Selection sort according to book price");
    printf("\n Press 4 = Merge sort according to book number");
    printf("\n Press 5 = Quick sort according to book price");
    printf("\n");
    
    printf("\n****************************SEARCH**************************");
    printf("\n");
    printf("\n Press 6 = Linear search using book number");
    printf("\n Press 7 = Binary search using book name ");
    printf("\n Press 8 =  To Exit ");
    printf("\n");
    printf("\n Enter Your Choice : ");
    scanf("%d",&ch1);
    
   
     if (ch1 == 1)
    {
        BubbleSort(v,n);
        Display(v,n);
        menu(v,n);
    }
    else if(ch1 == 2)
    {
        InsertionSort(v,n);
        Display(v,n);
        menu(v,n);
       
    }
    else if(ch1 == 3)
    {
        // SelectionSort(v,n);
         selectionsort(v,n);
         Display(v,n);
         menu(v,n);
    }
    else if (ch1 == 4)
    {
        MergeSort(v,0,n-1);
        Display(v,n);
        menu(v,n);
    }
    else if (ch1 == 5)
    {
        QuickSort(v,0,n);
        Display(v,n);
        menu(v,n);
    }
    else if (ch1 == 6)
    {
        printf("\nEnter the book number you want search :");
        
        scanf("%d", &key1);
        int resultlinear = LinearSearch(v, n, key1); 
        (resultlinear == -1) ? printf("\nBook is not present in Library")
                   : printf("\nBook is present at index %d",
                            resultlinear);
        printf("\n");
        menu(v,n);
    }
    else if(ch1 == 7)
    {
        printf("\nEnter the book name you want search :");
        fflush(stdin);
        scanf("%[^\n]%*c", key2);
       int resultbinary = binarySearch(v, 0, n ,key2);
       (resultbinary == -1) ? printf("\nBook is not present in Library")
                   : printf("\nBook is present at index %d",
                            resultbinary);
        printf("\n");
         menu(v,n);
    }
    else if(ch1 == 8){
       return;
    }

}


//function for displaying the output.
void Display(struct book v[],int n){
    
    printf("\n****************************BOOK DETAILS**************************");
        
    for (int i=0;i<n;i++)
    {      
        
       
        printf("\nnumber = %d ",v[i].number);
        printf("\nName = %s ",v[i].name);
        printf("\nPrice = %d ",v[i].price);
        printf("\n===============================");
        
    }
    menu(v,n);
}


//Main function
void main (){
    int n,i,ch1,ch2,key1;
    char key2[20];
     
    printf("\nEnter the no of books : ");
    scanf("%d",&n);
    struct book v[n];
    printf("\n");
    for (i=0;i<n;i++)
    {
        printf("\nEnter the number of the book :");
        scanf("%d",&v[i].number);
        fflush(stdin);
        printf("\nEnter the name of the book :");
        gets(v[i].name);
        printf("\nEnter the price of the book :");
        scanf("%d",&v[i].price);

    }
    
    menu(v,n);
    
    
}



// Enter the no of books : 5


// Enter the number of the book :45

// Enter the name of the book :CN

// Enter the price of the book :3500

// Enter the number of the book :340

// Enter the name of the book :DMADM

// Enter the price of the book :500

// Enter the number of the book :1

// Enter the name of the book :Math

// Enter the price of the book :4000

// Enter the number of the book :3

// Enter the name of the book :Science

// Enter the price of the book :6700

// Enter the number of the book :74

// Enter the name of the book :OM

// Enter the price of the book :32000

// What Would You Like To Do

// ****************************SORT**************************

//  Press 1 = Bubble sort according to name
//  Press 2 = Insertion sort according to book number
//  Press 3 = Selection sort according to book price
//  Press 4 = Merge sort according to book number
//  Press 5 = Quick sort according to book price

// ****************************SEARCH**************************

//  Press 6 = Linear search using book number
//  Press 7 = Binary search using book name
//  Press 8 =  To Exit

//  Enter Your Choice : 1

// ****************************BOOK DETAILS**************************
// number = 45
// Name = CN
// Price = 3500
// ===============================
// number = 340
// Name = DMADM
// Price = 500
// ===============================
// number = 1
// Name = Math
// Price = 4000
// ===============================
// number = 74
// Name = OM
// Price = 32000
// ===============================
// number = 3
// Name = Science
// Price = 6700
// ===============================
// What Would You Like To Do

// ****************************SORT**************************

//  Press 1 = Bubble sort according to name
//  Press 2 = Insertion sort according to book number
//  Press 3 = Selection sort according to book price
//  Press 4 = Merge sort according to book number
//  Press 5 = Quick sort according to book price

// ****************************SEARCH**************************

//  Press 6 = Linear search using book number
//  Press 7 = Binary search using book name
//  Press 8 =  To Exit

//  Enter Your Choice : 2

// ****************************BOOK DETAILS**************************
// number = 1
// Name = Math
// Price = 4000
// ===============================
// number = 3
// Name = Science
// Price = 6700
// ===============================
// number = 45
// Name = CN
// Price = 3500
// ===============================
// number = 74
// Name = OM
// Price = 32000
// ===============================
// number = 340
// Name = DMADM
// Price = 500
// ===============================
// What Would You Like To Do

// ****************************SORT**************************

//  Press 1 = Bubble sort according to name
//  Press 2 = Insertion sort according to book number
//  Press 3 = Selection sort according to book price
//  Press 4 = Merge sort according to book number
//  Press 5 = Quick sort according to book price

// ****************************SEARCH**************************

//  Press 6 = Linear search using book number
//  Press 7 = Binary search using book name
//  Press 8 =  To Exit

//  Enter Your Choice : 3

// ****************************BOOK DETAILS**************************
// number = 340
// Name = DMADM
// Price = 500
// ===============================
// number = 45
// Name = CN
// Price = 3500
// ===============================
// number = 1
// Name = Math
// Price = 4000
// ===============================
// number = 3
// Name = Science
// Price = 6700
// ===============================
// number = 74
// Name = OM
// Price = 32000
// ===============================
// What Would You Like To Do

// ****************************SORT**************************

//  Press 1 = Bubble sort according to name
//  Press 2 = Insertion sort according to book number
//  Press 3 = Selection sort according to book price
//  Press 4 = Merge sort according to book number
//  Press 5 = Quick sort according to book price

// ****************************SEARCH**************************

//  Press 6 = Linear search using book number
//  Press 7 = Binary search using book name
//  Press 8 =  To Exit

//  Enter Your Choice : 4

// ****************************BOOK DETAILS**************************
// number = 1
// Name = Math
// Price = 4000
// ===============================
// number = 3
// Name = Science
// Price = 6700
// ===============================
// number = 45
// Name = CN
// Price = 3500
// ===============================
// number = 74
// Name = OM
// Price = 32000
// ===============================
// number = 340
// Name = DMADM
// Price = 500
// ===============================
// What Would You Like To Do

// ****************************SORT**************************

//  Press 1 = Bubble sort according to name
//  Press 2 = Insertion sort according to book number
//  Press 3 = Selection sort according to book price
//  Press 4 = Merge sort according to book number
//  Press 5 = Quick sort according to book price

// ****************************SEARCH**************************

//  Press 6 = Linear search using book number
//  Press 7 = Binary search using book name
//  Press 8 =  To Exit

//  Enter Your Choice : 5

// ****************************BOOK DETAILS**************************
// number = 4199136
// Name = ≡■a
// Price = 0
// ===============================
// number = 340
// Name = DMADM
// Price = 500
// ===============================
// number = 45
// Name = CN
// Price = 3500
// ===============================
// number = 1
// Name = Math
// Price = 4000
// ===============================
// number = 3
// Name = Science
// Price = 6700
// ===============================
// What Would You Like To Do

// ****************************SORT**************************

//  Press 1 = Bubble sort according to name
//  Press 2 = Insertion sort according to book number
//  Press 3 = Selection sort according to book price
//  Press 4 = Merge sort according to book number
//  Press 5 = Quick sort according to book price

// ****************************SEARCH**************************

//  Press 6 = Linear search using book number
//  Press 7 = Binary search using book name
//  Press 8 =  To Exit

//  Enter Your Choice : 6

// Enter the book number you want search :3

// Book is present at index 4

// What Would You Like To Do

// ****************************SORT**************************

//  Press 1 = Bubble sort according to name
//  Press 2 = Insertion sort according to book number
//  Press 3 = Selection sort according to book price
//  Press 4 = Merge sort according to book number
//  Press 5 = Quick sort according to book price

// ****************************SEARCH**************************

//  Press 6 = Linear search using book number
//  Press 7 = Binary search using book name
//  Press 8 =  To Exit

//  Enter Your Choice : 7

// Enter the book name you want search :CN

// Book is present at index 2




