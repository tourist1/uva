#include <bits/stdc++.h>
using namespace std;
  

void swap(char &a, char &b) {
  char tmp = a;
  a = b;
  b = tmp;
}

int main(void) {  
    for(char str[51]; scanf("%s", str) && strcmp(str, "#"); ) {  
        int len = strlen(str)-1, break_point = 0;

        // find the latest one that is greater that predeccesor
        // badaabcaaa
        //       ^
        //      (b < c)
        //        <->
        //         ^
        //       this part is in descending order for (str[i] <= str[i-1])
        for(int i = len; i > 0; --i) {  
            if(str[i] > str[i-1]) {  
                break_point = i;  
                break;  
            }  
        }
        if(break_point == 0) {  
            printf("No Successor\n");
            continue;
        }

        // find the smallest one after str[break_point]
        // since char after str[break_point] is in descending order, 
        // so find the first one after str[break_point] that is smaller than
        // str[break_point "-1" ] -> the one before str[break_point]
        for(int i = len; i >= break_point; --i) {  
            if(str[i] > str[break_point-1]) {  
                // str[i] ^= str[break_point-1] ^= str[i];
                swap(str[i], str[break_point-1]);
                break;  
            }  
        }  
        sort(str + break_point, str + len+1);
          
        printf("%s\n", str);
    }  
    return 0;  
}  