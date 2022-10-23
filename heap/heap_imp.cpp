#include<bits/stdc++.h>
using namespace std;

class heap//max
{
        int arr[100];
        int size;

        void h_heapify( int i)
        {
            int largest=i;
            int left=2*i;
            int right=2*i+1;
            if(left<=size && arr[largest]<arr[left])
            {
                largest=left;
            }
            if(right<=size && arr[largest]<arr[right])
            {
                largest=right;
            }
            if(largest!=i)
            {
                swap(arr[largest],arr[i]);
                h_heapify(largest);
            }
        }
       
    public:
        heap()
        {
            arr[0]=-1;
            size=0;
        }
        void insert(int val)
        {
            size+=1;
            int index=size;
            arr[index]=val;
            while(index>1)
            {
                int parent =index/2;
                if(arr[parent]<arr[index])
                {
                    swap(arr[parent],arr[index]);
                    index=parent;
                }
                else
                {
                    return;
                }
            }
        }
        void del()
        {
            if(size==0)
            {
                return;
            }
            arr[1]=arr[size];
            size--;
            h_heapify(1);    
        }

        void del_arbitrary(int i)
        {
            if(size==0)
            {
                return;
            }
            arr[i]=arr[1]+1;
            while(i>1)
            {
                int parent =i/2;
                if(arr[parent]<arr[i])
                {
                    swap(arr[parent],arr[i]);
                    i=parent;
                }
                else
                {
                    return;
                }
            }
            del();
        }

        void print()
        {
            for(int i=1;i<=size;i++)
            {
                cout<<arr[i]<<' ';
            }
            cout<<'\n';
        }
};
void heapify(int arr[], int n, int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[largest]<arr[left])
    {
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

int main()
{
    heap h;
    h.insert(56);
    h.insert(50);
    h.insert(52);
    h.insert(46);
    h.insert(42);
    h.insert(44);
    h.insert(59);
    h.print();
    h.del();
    h.print();
    h.del_arbitrary(3);
    h.print();


    int arr[10]={-1,9, 36 ,65 ,5, 212 ,33, 13 ,95, 1};
    int n=9;
    for(int i=n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<' ';
    }cout<<'\n';
}