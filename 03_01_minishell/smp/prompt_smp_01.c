#include <readline/readline.h> // readline
#include <readline/history.h>  // add_history

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* readline함수의 리턴값을 저장하기위해 임의로 포인터를 하나 선언한다 */
    char *str;

    while(1)
    {
        /* readline함수가 호출되면 인자(prompt : )를 터미널에 출력하고 저장할 라인을 입력받는다 */
        str = readline("> ");/* read함수는 저장한 문자열의 메모리주소를 반환한다 */
        if (str)
            printf("%s\n", str);
        else/* str = NULL 이라면 (EOF, cntl + D)*/
            break ;
        /* add_history에 저장된 문자열은 up & down 방향키를 이용해 확인할수있다 */
        add_history(str);
        /* 라인은 힙메모리에 저장되기때문에 다 사용한 메모리는 할당을 해제해줘야한다 */
        free(str);
    }
    return(0);
}