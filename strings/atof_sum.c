#include <stdio.h>

float myatof(char*v);
int isvalid(char*);

int main() {
    char str[20];
    float n1, n2;

LABEL1:
    puts("Enter first real number:");
    scanf("%s", str);

    if (!(isvalid(str))) {
        printf("Invalid input \n");
        goto LABEL1;
    }
    //converting string to float

    n1 = myatof(str);

LABEL2:
    puts("Enter second real number:");
    scanf("%s", str);

    if (!(isvalid(str))) {
        printf("Invalid input \n");
        goto LABEL2;
    }

    // Now converting string to float.
    n2 = myatof(str);

    printf("%.2f", n1 + n2);

    return 0;
}

int isvalid(char *v) {
  int i = 0, j = 0, flag = 0;
    for (i = 0; v[i]; i++) {
        if (v[0] == '-') {
            continue;
        }
        if (v[i] == '.') {
            flag++;
            continue;
        }
        if (v[i] < 48 || v[i] > 57) {
            return 0;
        }
    }
    if (flag == 1)
        return 1;
    else
        return 0;
}

float myatof(char *v)
{
     int i=0,flag=0,count=1;
     int n1=0,n2=0;
     float sum;

    for(i=0;v[i];i++)
    {
         if(v[i]==46)
         {
              flag=1;
              continue;
         }

         if (flag)
         {
            n2=n2*10+v[i]-48;
            count=count*10;

         }
         else
         {
                 n1=n1*10+v[i]-48;

         }

    }

     sum=n1+((float) n2/(float)count);
     return sum;


}
