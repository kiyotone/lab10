#include <iostream>

void addElement(int *array, int &array_size, int &eleelement_sizeme);
void print_element(int *array,int &array_size,int &element_size);
void delete_element(int *array,int &array_size,int &element_size);

using namespace std;

int main(){

    bool running = true;
    char selection;
    int array_size = 2;
    int element_size = 0;


    
    int *array = new int[2];

    while (running)
    {
        
        cout<<endl<<endl<<"(p) Print Elements"<<endl<<"(a) Add Elements"<<endl<<"(d) Delete Element"<<endl<<"(r) Return Size"<<endl<<"(e) Exit"<<endl;
        cout<<"Enter Option : ";
        cin>>selection;
        selection = toupper(selection);
        if(selection=='E'){
            running=false;
            delete [] array;
        }
        else if (selection=='A')
        {
            addElement(array,array_size,element_size);
        }
        else if(selection == 'P'){
            print_element(array,array_size,element_size);
        }
        else if(selection == 'D'){
            delete_element(array,array_size,element_size);
        }
        else if(selection == 'R'){
            cout<<endl<<"S: "<<array_size<<", E: "<<element_size<<endl;
        }
    }
    



}


void addElement(int *array,int &array_size,int &element_size){

    

    if(array_size==element_size){
        int temp[array_size];

        for (int x=0;x<array_size;x++){
            temp[x] = array[x];
        }
        
        
        
        
        delete [] array;
        array = new int[array_size*2];
        
        for (int x=0;x<array_size;x++){
            array[x] = temp[x];
        }
        
        array_size = array_size*2;
        cout<<"Array expanded"<<endl;
        cout<<array_size<<endl;

    }

    cout<<"Enter Element ";
    cin>>array[element_size];
    element_size++;
 

}

void print_element(int *array,int &array_size,int &element_size){
    cout<<endl;
    if (element_size==0){
        cout<<"No Elements";
        return;
    }
    for(int i=0;i<element_size;i++){
        cout<<array[i]<<", ";
    }


}

void delete_element(int *array,int &array_size,int &element_size){
    int del;

    cout<<"Enter Element"<<endl;
    cin>>del;

    for(int x=0 ;x<element_size;x++){

        if (array[x]==del){

                for(int y = x; y < element_size-1;y++){

                    array[y]=array[y+1];

                }
                element_size--;

        }


    }
    if(element_size==array_size/2){
        int temp[array_size];

        for (int x=0;x<array_size;x++){
            temp[x] = array[x];
        }
            
        delete [] array;
        array = new int[array_size/2];
        
        for (int x=0;x<array_size;x++){
            array[x] = temp[x];
        }
        
        array_size = array_size/2;
        cout<<"Array shrinked"<<endl;
        cout<<array_size<<endl;

    }
}