#include <stdio.h>
#define SIZE 100  //피연산자의 최대 길이

double stack[SIZE];  // 스택을 위한 배열
int top = -1;   // 맨 위의 원소를 나타낼 top변수

int isFull() {    // 스택이 포화 상태인지 검사하는 함수
	if(top >= SIZE - 1) {   // top이 최대 크기와 같거나 클 경우
		printf("Error : Stack is Full. \n");  // 에러메시지 출력
		return 1;  // 1 반환 (true)
	}
	return 0;   // 그렇지 않을 경우 0 반환 (false)
}

int isEmpty() {    // 스택이 공백 상태인지 검사하는 함수
	if(top == -1) {    // top이 -1인 경우
		printf("Error : Stack is empty. \n");  // 에러메시지 출력
		return 1;  // 1 반환 (true)
	}
	return 0;   // 그렇지 않을 경우 0 반환 (false)
}

void push(double data) {      // 스택에 원소를 삽입하는 함수
	if(!isFull()) {    // 스택이 포화 상태가 아닐 경우
		top++;         // top을 1 증가
		stack[top] = data;   // 해당 공간에 data 삽입
	}
}
 
double pop() {  // 스택에 원소를 제거하는 함수
	if(!isEmpty())  {   // 배열이 비어있지 않은 경우
		double temp = stack[top];    // top 원소를 임시 변수 temp에 저장
		top--;                     // top 변수 1 감소
		return temp;               // temp 반환
	}
}

double peek() {    // 스택의 맨 위의 원소를 반환하는 함수
	if(!isEmpty()) {    // 스택이 비어 있지 않은 경우
		return stack[top];   // 스택의 맨 위 값 반환
	}
}

int main()
{
    int n; // 피연산자의 개수를 위한 변수
    double arr[100]; // 피연산자에 해당하는 값을 위한 배열
    scanf("%d\n", &n); // 피연산자 개수 받기
    char s[100]; // 후위 표기식을 위한 배열
    scanf("%s\n", &s); // 후위 표기식 받기
    for(int i = 0; i < n; i++) // n개만큼 피연산자를 받기 위한 반복문
        scanf("%lf", &arr[i]); // 피연산자에 해당하는 값 받기
    for(int k = 0; s[k] != '\0'; k++){ // 공백이 나올 때까지 반복
        char c = s[k]; // 후위 표기식 문자 단위로 자르기
        if(c <= 'Z' && c >= 'A') // 알파벳일 경우 분류
            push(arr[c-'A']); // 알파벳 스택에 삽입 --- c(알파벳)에서 대문자 'A'만큼의 아스키 코드 뺄셈으로 피연산자 값 지정
        else{ // 연산자가 나올 경우 분류
            double y = peek(); // 후위 표기식에서 연산자 바로 앞에 있는 수 호출 == 가장 top에 있는 값 반환
            pop(); // 스택에서 제거
            double x = peek(); // 후위 표기식에서 연산자 두 번째 앞에 있는 수 호출 == 가장 top에 있는 값 반환
            pop(); // 스택에서 제거
            double n1 = x*y; // *의 경우 연산 결과
            double n2 = x+y; // +의 경우 연산 결과
            double n3 = x-y; // -의 경우 연산 결과
            double n4 = x/y; // /의 경우 연산 결과
            if(c == '*') // *의 경우
                push(n1); // 곱한 값 스택에 삽입
            else if(c == '+') // +의 경우
                push(n2); // 더한 값 스택에 삽입
            else if(c == '-') // -의 경우
                push(n3); // 뺀 값 스택에 삽입
            else // /의 경우
                push(n4); // 나눈 값 스택에 삽입
        }
    }
    double z = peek(); // 후위 표기식의 계산 결과 반환
    printf("%.2lf\n", z); // 계산 결과 소숫점 둘째 자리까지 출력
    return 0;
}
