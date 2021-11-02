#include <stdio.h>
#include <math.h> //pow 사용 위해 헤더 삽입


// 문제의 기본적인 풀이방법은 n-1번째의 옮기는 횟수와 방법을 이용해서
//n번째의 옮기는 횟수와 방법을 구하는 것이다.
// 예를 들어 3개의 원판을 옮기기 위해서 1번째 장대에서 3번째 장대로 7번의 횟수를 이용하는데
//4개의 원판을 옮기기 위해서는 위의 3개의 원판을 1번째 장대에서 2번째 장대로 옮긴 후 마지막 원판을
//3번째 장대로 옮긴 뒤 3개의 원판을 옮기기 위해서 사용한 7번의 횟수를 이용하게 된다는 점이다.
void hanoi(int n, int start, int extra, int end) //n은 원판 갯수, start는 시작장대, end는 도착장대, extra는 나머지 장대이다.
{
    if (n == 1)
    {
        printf("%d %d\n", start, end);
        return;
    }
    hanoi(n - 1, start, end, extra); //n-1개의 원판을 2번째 기둥으로 모두 옮기는 방법의 수를 모두 나타낸 것이다. (n-1번째 hanoi에서는 3번째 기둥으로 모두 옮기는 것이므로 end와 extra의 위치가 바뀐 것)
    hanoi(1, start, extra, end); //n번째의 원판을 3번째 기둥으로 옮기는 것이다.
    hanoi(n - 1, extra, start, end); //다시 n-1개의 원판을 3번째 기둥으로 모두 옮기는 방법을 나타낸 것이다.(N번째 원판이 없다고 생각하고 기둥 자체를 뽑아서 위치를 바꾼다고 생각)
}


int main()
{
    int N;
    scanf("%d", &N);

    int cnt = pow(2, N) - 1; //N-1번째 hanoi 이동 횟수 + N번째 크기의 원판을 옮기는 횟수 1 + N-1번째 hanoi 이동 횟수 = 2*(N-1)번째 hanoi 이동 횟수 - 1= 2^N -1 
    printf("%d\n", cnt);
    hanoi(N, 1, 2, 3);

    return 0;
 }