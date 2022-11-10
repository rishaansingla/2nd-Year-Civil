#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

//TIME COMPLEXITY - O(n^2).
pair<int,int> SelectionSort(int *input,int size)
{
    int min_idx;
    int count_swaps = 0;
    int count_comparisons = 0;
    for(int i=0;i<size;i++)
    {
        min_idx = i;
        for(int j=i+1;j<size;j++)
        {
            if(input[j]<input[min_idx])
            {
                min_idx = j;
                count_swaps++;
            }
            count_comparisons++;
        }
        int temp = input[i];
        input[i] = input[min_idx];
        input[min_idx] = temp;
    }
    return {count_swaps, count_comparisons};
}


//TIME COMPLEXITY - O(n^2).
pair<int,int> bubbleSort(int *input, int size)
{
    int count_swaps = 0;
    int count_comparisons = 0;
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - 1 - j; i++)
        {
            if (input[i] > input[i + 1])
            {
                int temp = input[i];
                input[i] = input[i + 1];
                input[i + 1] = temp;
                count_swaps++;
            }
            count_comparisons++;
        }
    }
    return {count_swaps, count_comparisons}; 
}


// Time-run calculator
long getTimeinMicroseconds(){
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}


int main()
{
    int n;
    cout << "Enter array_size : ";
    cin >> n;

    cout<< "Enter array elements : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
   
    pair <int,int> bubble = bubbleSort(arr,n);
    pair <int,int> selection = SelectionSort(arr,n);

    cout << "COMPARING BUBBLE AND SELECTION SORT.  " << endl;
    cout << endl;

    cout << "1. ON THE BASIS OF NUMBER OF COMPARISONS : " << " ";
    if(bubble.second > selection.second)
    {
        cout << "BUBBLE SORT REQUIRES MORE COMPARISONS." << endl;
    }
    else if(bubble.second < selection.second)
    {
        cout << "SELECTION SORT REQUIRES MORE COMPARISONS." << endl;
    }
    else
    {
        cout << "BOTH REQUIRE EQUAL NUMBER OF COMPARISONS." << endl;
    }
    cout << endl;

    cout << "2. ON THE BASIS OF NUMBE ROF SWAPS : " << " ";
    if(bubble.first > selection.first)
    {
        cout << "BUBBLE SORT REQUIRES MORE SWAPS." << endl;
    }
    else if(bubble.first < selection.first)
    {
        cout << "SELECTION SORT REQUIRES MORE SWAPS." << endl;
    }
    else
    {
        cout << "BOTH REQUIRE EQUAL NUMBER OF SWAPS." << endl;
    }

    cout<<endl;
    cout<< "3. ON THE BASIS OF RUN-TIME OF CODE. "<<endl;
    for (int n=10; n<=10000; n*=10){
        int *arr = new int[n];
        long start_time, end_time;
        for(int i=0; i<n; i++) {
            arr[i] = n-i;
        }
        //Bubble sort complexity
        start_time = getTimeinMicroseconds();
        bubble = bubbleSort(arr,n);
        end_time = getTimeinMicroseconds();
        cout<<"BubbleSort for n= "<<n<<" time = "<<end_time-start_time<<" nanoseconds."<<endl;

        //Selection sort complexity
        start_time = getTimeinMicroseconds();
        selection = SelectionSort(arr,n);
        end_time = getTimeinMicroseconds();
        cout<<"SelectionSort for n= "<<n<<" time = "<<end_time-start_time <<" nanoseconds." <<endl;
        cout<<endl;
        
    }   
    cout<<"CLEARLY SELECTION SORT IS FASTER THAN BUBBLE SORT FOR LARGE SIZE ARRAY."<<endl;

}
