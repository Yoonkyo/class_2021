//Q1   ykjung@mnd.go.kr

//stack
#include <stdio.h>
#define SIZE 100 

double stack[SIZE];  
int top = -1;  

int isFull() {   
	if(top >= SIZE - 1) {   
		printf("Error : Stack is Full. \n");  
		return 1;  
	}
	return 0;   
}

int isEmpty() {   
	if(top == -1) {    
		printf("Error : Stack is empty. \n"); 
		return 1; 
	}
	return 0;   
}

void push(double data) {     
	if(!isFull()) {   
		top++;        
		stack[top] = data;  
	}
}
 
double pop() { 
	if(!isEmpty())  {   
		double temp = stack[top];    
		top--;                     
		return temp;              
	}
}

double peek() {    
	if(!isEmpty()) {    
		return stack[top];   
	}
}

int main()
{
    int n;
    double arr[100]; 
    scanf("%d\n", &n); 
    char s[100]; 
    scanf("%s\n", &s); 
    for(int i = 0; i < n; i++)
        scanf("%lf", &arr[i]); 
    for(int k = 0; s[k] != '\0'; k++){ 
        char c = s[k]; 
        if(c <= 'Z' && c >= 'A') 
            push(arr[c-'A']);
        else{ 
            double y = peek(); 
            pop(); 
            double x = peek(); 
            pop();
            double n1 = x*y; 
            double n2 = x+y; 
            double n3 = x-y; 
            double n4 = x/y; 
            if(c == '*')
                push(n1); 
            else if(c == '+')
                push(n2); 
            else if(c == '-') 
                push(n3); 
            else 
                push(n4); 
        }
    }
    double z = peek(); 
    printf("%.2lf\n", z);
    return 0;
}
