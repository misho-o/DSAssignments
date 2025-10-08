
#include <iostream>
using namespace std;
class Box {
    public:
        int* size;
        
        Box(int s) {
            
            size = new int(s); 
            cout<<"BOX OBJECT CREATED WITH SIZE:"<<s<<endl;
        }
        
        Box(const Box &other) {
            size = new int(*other.size);
            cout<<"BOX OBJECT DEEP COPY CREATED "<<endl;
            
        }
        
        //copy assignment when we want object to hold same properties as the other one so we delete its old heap and assign new heap
        
        Box& operator=(const Box& other){
            if(this == &other){
                return *this;
            }
            
            delete size;
            
            size = new int(*other.size);
            return *this;
        }
        void display(){
            cout<<"SIZE OF BOX: "<<*size<<endl;
        }
        ~Box() {
            delete size; 
    }
};
 // Deep copy: box2.size
int main()
{
    
    Box box1(55);
    Box box2 = box1;
    box1.display();
    
    
    Box box3(20);
    box3.display();
    box3 =box2;
    
    box3.display();
    return 0;
}
