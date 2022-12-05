#include<iostream> 
#include<string.h>         
using namespace std;
typedef struct student{
    int roll_no;
    char name[20];
    float marks;
}stud;

void create(stud s[20],int n);
void display(stud s[20],int n);
void bubblesort(stud s[20],int n);
void quicksort(stud s[20],int l, int u);
int partition(stud s[20],int l, int u);
void insertionsort(stud s[20], int n);
void search(stud s[20],int n, int key);
int bsearch(stud s[20], char x[20], int low, int high);

int main(){
    stud s[20];
    int ch,n,key,result;
    char x[20];
    do{
        cout<<"\n 1. Create Student Database ";
        cout<<"\n 2. Display Student Database ";
        cout<<"\n 3. Bubble Sort ";
        cout<<"\n 4. Quick Sort";
        cout<<"\n 5. Insertion Sort";
        cout<<"\n 6. Linear Searching";
        cout<<"\n 7. Binary Searching";
        cout<<"\n 0. Exit ";
        cout<<"\n Enter choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"\n Enter the number of Records: ";
                cin>>n;
                create(s,n);
                break;
            case 2:
                display(s,n);
                break;
            case 3:
                bubblesort(s,n);
                cout<<"Bubble Sort completed!\n";
                break;
            case 4:
                quicksort(s,0,n-1);
                cout<<"Quick Sort completed!\n";
                break;
            case 5:
                insertionsort(s,n);
                cout<<"Insertion Sort completed!\n";
                break;
            case 6:
                cout<<"\nEnter the marks which you want to search: \n";
                cin>>key;
                search(s,n,key);
                break;
            case 7:
                cout<<"Enter the name of student which you want to search: ";
                cin>>x;
                insertionsort(s,n);
                result=bsearch(s,x,0,n-1);
                if(result==-1){
                    cout<<"\n Student name you want to search for is not present!\n";
                }
                else{
                    cout<<"\n The Student is present : "<<s[result].name;
                }
                break;
            case 0:
                return 0;
            default:
                cout<<"\n INVALID CHOICE!!  Please Enter valid choice: \n";
        }
    }while(ch!=0);
}

void create(stud s[20],int n){
    for(int i=0;i<n;i++){
        cout<<"\n Enter the roll number: ";
        cin>>s[i].roll_no;
        for(int j=0;j<i;j++){
            if(s[j].roll_no==s[i].roll_no){
                cout<<"\n Enter Unique roll number: ";
                cin>>s[i].roll_no;
                break;
                i--;
            }
        }
        cout<<"\n Enter the name: ";
        cin>>s[i].name;
        cout<<"\n Enter marks: ";
        cin>>s[i].marks;
    }
}
void display(stud s[20], int n){
    cout<<"\n\tRoll no.\tName\tMarks\n";
    for(int i=0;i<n;i++){
        cout<<"\t"<<s[i].roll_no<<"\t\t"<<s[i].name<<"\t"<<s[i].marks<<"\n";
    } 
}
void bubblesort(stud s[20], int n){
    stud temp;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(s[j].roll_no>s[j+1].roll_no){
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}
void quicksort(stud s[20], int l, int u){
    int j;
    if(l<u){
        j=partition(s,l,u);
        quicksort(s,l,j-1);
        quicksort(s,j+1,u);
    }
}
int partition(stud s[20],int l, int u){
    int i,j;
    stud temp,v;
    v=s[l];
    i=l;
    j=u+1;
    do{
        do{
            i++;
        }while(s[i].marks<v.marks&&i<=u);
        do{
            j--;
        }while(v.marks<s[j].marks);
            if(i<j){
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }while(i<j);
    s[l]=s[j];
    
    s[j]=v;
    return (j);
}
void insertionsort(stud s[20],int n){
    int i,j;
    stud key;
    for(int i=1;i<n;i++){    
        key=s[i];
        j=i-1;
    while(j>=0 && strcmp(s[j].name,key.name)>0){       //strcmp gives positive value if string 1>string 2
        s[j+1]=s[j];                                   //strcmp gives negative value if string 1<string 2
        j=j-1;                                         //strcmp gives 0 value if string 1=string 2
    }    
    s[j+1]=key; 
    }                                             
}
void search(stud s[20],int n, int key){
    int i;
    cout<<"\n"<<"\t"<<"Roll no"<<"\t"<<"Name"<<"\t"<<"Marks";
    for(i=0;i<n;i++){
        if(key==s[i].marks){
            cout<<"\n\t "<<s[i].roll_no<<"\t"<<s[i].name<<"\t"<<s[i].marks;
        }
    }
}
int bsearch(stud s[20], char x[20], int low, int high){
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(strcmp(x,s[mid].name)==0){
            return mid;
        }
        else if(strcmp(x,s[mid].name)<0){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
