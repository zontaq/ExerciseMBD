#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct car{
	string reg_number;
	string colour;
}car;

class parking{
	car* arr[1000];
 	int ind[1000];
 	int n;
 
	public:
	parking(int n){
        for(int i=0;i<n;i++){
        	ind[i]=0;
            arr[i]=NULL; 
		}
        this->n = n;
    }     

     int placing(string res,string col);
     int freeslot(int slot);
     void status();
     void reg_nums_col(string colour); 
     void slot_nums_col(string);
     void slot_nums_reg(string);
};

int parking::placing(string res, string col){  
	int flag =-1; 
	for(int i=0;i<n;i++){
		if(ind[i] == 0){
        	ind[i]=1;
        	arr[i] =(car *)new car;
        	(arr[i])->reg_number = res;
        	(arr[i])->colour = col;
        	flag = i;
        	break;
      	}
   	}
    return flag;
}

int parking::freeslot(int slot){
	if(slot <= n){
		ind[slot-1]=0;
    	arr[slot-1]=NULL;
    	return slot;
  	}
}

void parking::status(){ 
	cout<<"Slot No.\tRegistration No\tColour\n";
	for(int i=0;i<n;i++){   
    	if(ind[i] != 0){
     		cout<<(i+1)<<"\t"; 
     		cout<<((arr[i])->reg_number)<<"\t"<<((arr[i])->colour)<<endl;
     	}
  	}
}

void parking::reg_nums_col(string colour)
{
	for(int i=0;i<n;i++){
    	if(ind[i] != 0){
       		if(((arr[i])->colour) == colour)
        	cout<<((arr[i])->reg_number)<<", ";
    	}
  	}
  	cout<<endl;
}

void parking::slot_nums_reg(string reg){
	for(int i=0;i<n;i++){
		if(ind[i] != 0){
    		if(((arr[i])->reg_number) == reg){ 
				cout<<(i+1)<<endl;
        		break;
       		}
    	}
	} 
}

void parking::slot_nums_col(string colour){
	for(int i=0;i<n;i++){
    	if(ind[i] != 0){
       		if(((arr[i])->colour) == colour)
        	cout<<(i+1)<<", ";
    	}
  	}
  	cout<<endl;
}

int main(){  
	int n;
	string init;
	cin>>init;
    cin>>n;
  	parking p1(n);
  	cout<<"Created a parking lot with "<<n<<" slots"<<endl;
   	string status;
   	string regis;
   	string warna;
   	while(true){
		cin>>status;

		if(status == "park"){
			cin>>regis>>warna;  
	        int flag = p1.placing(regis,warna); 
	        if(flag == -1)
	        	cout<<"Sorry, parking lot is full\n";
	        else
	            cout<<"Allocated slot number: "<<(flag+1)<<endl;
		}
		
		if(status == "leave"){
			int slot;
	     	cin>>slot;
	     	int flag = p1.freeslot(slot);
	     	cout<<"Slot number "<<flag<<" is free\n";
		}
		
	 	if(status == "status"){
	   		p1.status();
		}
		
		if(status == "registration_numbers_for_cars_with_colour"){  
			cin>>warna;
	    	p1.reg_nums_col(warna);
	 	}  
	 
		if(status =="slot_numbers_for_cars_with_colour"){
	   		cin>>warna;
	   		p1.slot_nums_col(warna);
	  	}
	  
		if(status == "slot_number_for_registration_number"){
	    	cin>>regis;
	   		p1.slot_nums_reg(regis);
	  	}
	}
}
