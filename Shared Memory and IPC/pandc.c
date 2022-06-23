#include <stdio.h>

int mutex=1;
int full=0;
int empty=10,x=0;

void producer(){
    mutex--;
    full++;
    empty--;
    x++;
    printf("Producer produces items %d",x);
    mutex++;
}
void consumer(){
    mutex--;
    full--;
    empty++;
    printf("Consumers consumes item %d",x);
    x--;
    mutex++;
}

int main(){
    int i,n;
    int ch,choice;
    do{
        printf("\t\t\tMain Menu");
        printf("\n1.Producer \n2.Consumers \n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(mutex==1 && empty!=0)
                    producer();
                else
                    printf("Buffer is full");
                break;
            case 2:
                if(mutex==1 && full!=0)
                    consumer();
                else
                    printf("Buffer is empty");
                break;
            default:
                printf("Wrong choice");
        }
        printf("\nDo you want to continue?<0/1>: ");
        scanf("%d",&ch);
    }while(ch==1);
    return 0;
}
