#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 100
struct node
{
    int data;
    struct node* next;
    struct node* pre;
};

void InsertLast(int x,struct node* L);
void Insert(int x,struct node* P);
struct node* MakeEmpty(struct node* L);
void Delete(int X, struct node* L);
void DeleteList(struct node* L);
void DeleteListForDivision(struct node* L);
int IsLast(struct node* P,struct node* L);
int IsEmpty(struct node* L);
int size( struct node* L);
void PrintList(struct node* L);
struct node* FindPrevious(int X, struct node* L);
int IsGreater(struct node* x1, struct node* x2);
struct node* Adder(struct node* num1, struct node* num2);
struct node* Subtractor(struct node* n1, struct node* n2);
struct node* Multiplication(struct node* num1, struct node* num2);
struct node* Division(struct node* num1, struct node* num2);

int main()
{
    FILE *input , *output;
    output = fopen("outputs.txt","w");
    input = fopen("inputs.txt","r");
    char number[SIZE][100] = {};
    char outputs[SIZE][100] = {};
    int countOfnumbers = 0, diff;
    int R = fscanf(input,"%s",number[0]);
    for(int i = 0 ; R != EOF ; i++)
    {
        countOfnumbers++;
        R = fscanf(input,"%s",number[i+1]);
    }
    struct node *num1, *num2, *results[SIZE], *Add, *Sub, *Mult, *Div, *temp;
    temp = MakeEmpty(NULL);
    num1 = MakeEmpty(NULL);
    num2 = MakeEmpty(NULL);
    Add = MakeEmpty(NULL);
    Sub = MakeEmpty(NULL);
    Mult = MakeEmpty(NULL);
    Div = MakeEmpty(NULL);
    for(int i = 0 ; i < 3 ; i++)
    {
        results[i] = MakeEmpty(NULL);
    }
    int selection1, selection2, selection, count = 0 ;
    printf("Welcome to the scientific calculator:\n**********************************************\n");
    printf("1- Read the input file.\n2- Addition.\n3- Subtraction.\n4- Multiplication.\n5- Division.\n6- Print the results to an output file.\n7- Exit.\n");
    scanf("%d",&selection);
    while(selection != 7)
    {
        switch(selection)
        {
        case 1 :
            for(int i = 0 ; i < countOfnumbers ; i++)
            {
                printf("%d : %s\n",(i+1),number[i]);
            }
            break;
        case 2 :
            printf("Determine two numbers.\n");
            scanf("%d",&selection1);
            scanf("%d",&selection2);
            if(number[selection1-1][0] == '-' && number[selection2-1][0] == '-')
            {
                for(int i = 1 ; i < strlen(number[selection1-1]) ; i++)
                {
                    InsertLast((int)number[selection1-1][i]-'0',num1);
                }
                for(int i = 1 ; i < strlen(number[selection2-1]) ; i++)
                {
                    InsertLast((int)number[selection2-1][i]-'0',num2);
                }
                Add = Adder(num1,num2);
                Add->next->data *= (-1);
            }
            else if(number[selection1-1][0] == '-' && number[selection2-1][0] != '-')
            {
                diff = strlen(number[selection1-1]) - strlen(number[selection2-1]);
                if(diff >= 0)
                {
                    for(int i = 1 ; i < strlen(number[selection1-1]) ; i++)
                    {
                        InsertLast((int)number[selection1-1][i]-'0',num1);
                    }
                    for(int i = 0 ; i < strlen(number[selection2-1]) ; i++)
                    {
                        InsertLast((int)number[selection2-1][i]-'0',num2);
                    }
                    Add = Subtractor(num1,num2);
                    Add->next->data *= (-1);
                }
                else
                {
                    for(int i = 1 ; i < strlen(number[selection1-1]) ; i++)
                    {
                        InsertLast((int)number[selection1-1][i]-'0',num1);
                    }
                    for(int i = 0 ; i < strlen(number[selection2-1]) ; i++)
                    {
                        InsertLast((int)number[selection2-1][i]-'0',num2);
                    }
                    Add = Subtractor(num1,num2);
                }
            }
            else if(number[selection1-1][0] != '-' && number[selection2-1][0] == '-')
            {
                diff = strlen(number[selection1-1]) - strlen(number[selection2-1]);
                if(diff > 0)
                {
                    for(int i = 0 ; i < strlen(number[selection1-1]) ; i++)
                    {
                        InsertLast((int)number[selection1-1][i]-'0',num1);
                    }
                    for(int i = 1 ; i < strlen(number[selection2-1]) ; i++)
                    {
                        InsertLast((int)number[selection2-1][i]-'0',num2);
                    }
                    Add = Subtractor(num1,num2);
                }
                else
                {
                    for(int i = 0 ; i < strlen(number[selection1-1]) ; i++)
                    {
                        InsertLast((int)number[selection1-1][i]-'0',num1);
                    }
                    for(int i = 1 ; i < strlen(number[selection2-1]) ; i++)
                    {
                        InsertLast((int)number[selection2-1][i]-'0',num2);
                    }
                    Add = Subtractor(num1,num2);
                    Add->next->data *= (-1);
                }
            }
            else
            {
                for(int i = 0 ; i < strlen(number[selection1-1]) ; i++)
                {
                    InsertLast((int)number[selection1-1][i]-'0',num1);
                }
                for(int i = 0 ; i < strlen(number[selection2-1]) ; i++)
                {
                    InsertLast((int)number[selection2-1][i]-'0',num2);
                }
                Add = Adder(num1,num2);
            }
            results[count] = Add;
            break;
        case 3 :
            printf("Determine two numbers.\n");
            scanf("%d",&selection1);
            scanf("%d",&selection2);
            if(number[selection1-1][0] == '-' && number[selection2-1][0] != '-')
            {
                for(int i = 1 ; i < strlen(number[selection1-1]) ; i++)
                {
                    InsertLast((int)number[selection1-1][i]-'0',num1);
                }
                for(int i = 0 ; i < strlen(number[selection2-1]) ; i++)
                {
                    InsertLast((int)number[selection2-1][i]-'0',num2);
                }
                Sub = Adder(num1,num2);
                Sub->next->data *= (-1);
            }
            else if(number[selection1-1][0] != '-' && number[selection2-1][0] == '-')
            {
                for(int i = 0 ; i < strlen(number[selection1-1]) ; i++)
                {
                    InsertLast((int)number[selection1-1][i]-'0',num1);
                }
                for(int i = 1 ; i < strlen(number[selection2-1]) ; i++)
                {
                    InsertLast((int)number[selection2-1][i]-'0',num2);
                }
                Sub = Adder(num1,num2);
            }
            else if(number[selection1-1][0] == '-' && number[selection2-1][0] == '-')
            {
                for(int i = 1 ; i < strlen(number[selection1-1]) ; i++)
                {
                    InsertLast((int)number[selection1-1][i]-'0',num1);
                }
                for(int i = 1 ; i < strlen(number[selection2-1]) ; i++)
                {
                    InsertLast((int)number[selection2-1][i]-'0',num2);
                }
                Sub = Subtractor(num1,num2);
                Sub->next->data *= (-1);
            }
            else
            {
                for(int i = 0 ; i < strlen(number[selection1-1]) ; i++)
                {
                    InsertLast((int)number[selection1-1][i]-'0',num1);
                }
                for(int i = 0 ; i < strlen(number[selection2-1]) ; i++)
                {
                    InsertLast((int)number[selection2-1][i]-'0',num2);
                }
                Sub = Subtractor(num1,num2);
            }
            results[count] = Sub;
            break;
        case 4 :
            printf("Determine two numbers.\n");
            scanf("%d",&selection1);
            scanf("%d",&selection2);
            if(number[selection1-1][0] == '-' && number[selection2-1][0] == '-')
            {
                for(int i = 1 ; i < strlen(number[selection1-1]) ; i++)
                {
                    InsertLast((int)number[selection1-1][i]-'0',num1);
                }
                for(int i = 1 ; i < strlen(number[selection2-1]) ; i++)
                {
                    InsertLast((int)number[selection2-1][i]-'0',num2);
                }
                Mult = Multiplication(num1,num2);
            }
            else if(number[selection1-1][0] == '-' && number[selection2-1][0] != '-')
            {
                for(int i = 1 ; i < strlen(number[selection1-1]) ; i++)
                {
                    InsertLast((int)number[selection1-1][i]-'0',num1);
                }
                for(int i = 0 ; i < strlen(number[selection2-1]) ; i++)
                {
                    InsertLast((int)number[selection2-1][i]-'0',num2);
                }
                Mult = Multiplication(num1,num2);
                Mult->next->data *= (-1);
            }
            else if(number[selection1-1][0] != '-' && number[selection2-1][0] == '-')
            {
                for(int i = 0 ; i < strlen(number[selection1-1]) ; i++)
                {
                    InsertLast((int)number[selection1-1][i]-'0',num1);
                }
                for(int i = 1 ; i < strlen(number[selection2-1]) ; i++)
                {
                    InsertLast((int)number[selection2-1][i]-'0',num2);
                }
                Mult = Multiplication(num1,num2);
                Mult->next->data *= (-1);
            }
            else
            {
                for(int i = 0 ; i < strlen(number[selection1-1]) ; i++)
                {
                    InsertLast((int)number[selection1-1][i]-'0',num1);
                }
                for(int i = 0 ; i < strlen(number[selection2-1]) ; i++)
                {
                    InsertLast((int)number[selection2-1][i]-'0',num2);
                }
                Mult = Multiplication(num1,num2);
            }
            results[count] = Mult;
            break;
        case 5 :
            printf("Determine two numbers.\n");
            scanf("%d",&selection1);
            scanf("%d",&selection2);
            if(number[selection1-1][0] == '-' && number[selection2-1][0] == '-')
            {
                for(int i = 1 ; i < strlen(number[selection1-1]) ; i++)
                {
                    InsertLast((int)number[selection1-1][i]-'0',num1);
                }
                for(int i = 1 ; i < strlen(number[selection2-1]) ; i++)
                {
                    InsertLast((int)number[selection2-1][i]-'0',num2);
                }
                Div = Division(num1,num2);
            }
            else if(number[selection1-1][0] == '-' && number[selection2-1][0] != '-')
            {
                for(int i = 1 ; i < strlen(number[selection1-1]) ; i++)
                {
                    InsertLast((int)number[selection1-1][i]-'0',num1);
                }
                for(int i = 0 ; i < strlen(number[selection2-1]) ; i++)
                {
                    InsertLast((int)number[selection2-1][i]-'0',num2);
                }
                Div = Division(num1,num2);
                Div->next->data *= (-1);
            }
            else if(number[selection1-1][0] != '-' && number[selection2-1][0] == '-')
            {
                for(int i = 0 ; i < strlen(number[selection1-1]) ; i++)
                {
                    InsertLast((int)number[selection1-1][i]-'0',num1);
                }
                for(int i = 1 ; i < strlen(number[selection2-1]) ; i++)
                {
                    InsertLast((int)number[selection2-1][i]-'0',num2);
                }
                Div = Division(num1,num2);
                Div->next->data *= (-1);
            }
            else
            {
                for(int i = 0 ; i < strlen(number[selection1-1]) ; i++)
                {
                    InsertLast((int)number[selection1-1][i]-'0',num1);
                }
                for(int i = 0 ; i < strlen(number[selection2-1]) ; i++)
                {
                    InsertLast((int)number[selection2-1][i]-'0',num2);
                }
                Div = Division(num1,num2);
            }
            results[count] = Div;
            break;
        case 6 :
            for(int i = 0 ; i < count ; i++)
            {
                temp = MakeEmpty(NULL);
                temp = results[i];
                if(results[i]->next->data < 0)
                {
                    outputs[i][0] = '-';
                    for(int j = 1 ; temp->next != NULL ; j++)
                    {

                        outputs[i][j] = ((char)(temp->next->data))+'0';
                        temp = temp->next;
                    }
                    temp = results[i];
                }
                else
                {
                    for(int j = 0 ; temp->next != NULL ; j++)
                    {

                        outputs[i][j] = ((char)(temp->next->data))+'0';
                        temp = temp->next;
                    }
                    temp = results[i];
                }
            }
            for(int i = 0 ; i < count ; i++)
            {
                fprintf(output,"%d : %s\n",(i+1),outputs[i]);
            }
            break;
        default :
            printf("Invalid choice:\n");
            break;
        }
        if(selection != 1)
        {
            PrintList(results[count]);
            count++;
        }
        DeleteList(Add);
        DeleteList(Sub);
        DeleteList(Mult);
        DeleteList(Div);
        DeleteList(num1);
        DeleteList(num2);
        printf("\n1- Read the input file.\n2- Addition.\n3- Subtraction.\n4- Multiplication.\n5- Division.\n6- Print the results to an output file.\n7- Exit.\n");
        scanf("%d",&selection);
    }
    printf("Exiting...\n");
    return 0;
}

void InsertLast(int x,struct node* L)
{
    struct node* P;
    P = (struct node*)malloc(sizeof(struct node));
    P->data = x;
    P->next = NULL;
    if(L == NULL)
    {
        L = P;
        P->pre = NULL;
    }
    struct node* temp = L;

    while(temp->next != NULL)
        temp=temp->next;
    temp->next = P;
    P->pre = temp;
}

void Insert(int x,struct node* P)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = P->next;
    P->next = temp;
    temp->pre = P;
}

void Delete(int X, struct node* L)
{
    struct node* P, *temp;
    P = FindPrevious(X, L);
    if( !IsLast(P, L) )
    {
        temp = P->next;
        P->next = temp->next;
        free(temp);
    }
}

void DeleteList(struct node* L)
{
    struct node* p,*temp;
    p = L->next;
    L->next = NULL;
    L->pre = NULL;

    while(p != NULL)
    {
        temp = p->next;
        free(p);
        p=temp;
    }
}

void DeleteListForDivision(struct node* L)
{
    struct node* p,*temp;
    p = L->next;
    L->next = NULL;

    while(p != NULL)
    {
        temp = p->next;
        free(p);
        p=temp;
    }
}

struct node* MakeEmpty(struct node* L)
{
    if(L != NULL)
        DeleteList( L );
    L = (struct node*)malloc(sizeof(struct node));
    if(L == NULL)
        printf("Out of memory!\n");
    L->next = NULL;
    L->pre = NULL;
    return L;
}

int IsLast(struct node* P,struct node* L)
{
    return P->next == NULL;
}

int IsEmpty(struct node* L)
{
    return L->next == NULL;
}

void PrintList(struct node* L)
{
    struct node* P = L;
    if( IsEmpty(L))
        printf("Empty list\n");
    else
        do
        {
            P=P->next;
            printf("%d", P->data);
        }
        while( !IsLast(P, L) );
    printf("\n");
}
int size( struct node* L)
{
    struct node* p = L->next;
    int count = 0;
    while(p != NULL )
    {
        count += 1;
        p = p->next;
    }
    return count;
}

struct node* FindPrevious(int X, struct node* L)
{
    struct node* P;
    P = L;
    while(P->next != NULL && P->next->data != X)
        P = P->next;
    return P;
}
int IsGreater(struct node* x1, struct node* x2)
{
    struct node *L1, *L2;
    L1 = x1, L2 = x2;
    int diff = size(x1) - size(x2);
    if(diff > 0 )
        return 1;
    else if(diff < 0)
        return -1;
    else
    {
        while(L1->next != NULL)
        {
            if(L1->next->data > L2->next->data)
                return 1;
            else if(L1->next->data < L2->next->data)
                return -1;
            else
            {
                if(L1->next->next == NULL)
                    return 0;
                else
                {
                    L1 = L1->next;
                    L2 = L2->next;
                }
            }
        }
    }
    return 0;
}

struct node* Adder(struct node* s1, struct node* s2)
{
    struct node* sum, *copy1, *copy2, *carry;
    sum = MakeEmpty(NULL);
    copy1 = MakeEmpty(NULL);
    copy2 = MakeEmpty(NULL);
    carry = MakeEmpty(NULL);
    copy1 = s1,copy2 = s2;
    InsertLast(0,carry);

    int diff = size(s1)-size(s2);
    if(diff >= 0)
        copy1 = s1, copy2 = s2;
    else
        copy1 = s2, copy2 = s1;
    while(copy1->next != NULL)
        copy1 = copy1->next;
    while(copy2->next != NULL)
        copy2 = copy2->next;
    while(copy2->pre != NULL)
    {
        InsertLast(((copy1->data) + (copy2->data) + (carry->next->data))/10,carry);
        InsertLast(((copy1->data) + (copy2->data) + (carry->next->data))%10,sum);

        carry = carry->next;
        copy1 = copy1->pre;
        copy2 = copy2->pre;
    }
    for(int i = abs(diff) ; i > 0 ; i--)
    {
        InsertLast(((copy1->data) + (carry->next->data))/10,carry);
        InsertLast(((copy1->data) + (carry->next->data))%10,sum);

        copy1 = copy1->pre;
        carry = carry->next;
    }
    if((carry->next->data) != 0)
        InsertLast((carry->next->data),sum);

    struct node* result = MakeEmpty(NULL);
    while(sum->next != NULL)
        sum = sum->next;
    while(sum->pre != NULL)
    {
        InsertLast(sum->data,result);
        sum = sum->pre;
    }
    return result;
}
struct node* Subtractor(struct node* num1, struct node* num2)
{
    struct node* sub, *temp1, *temp2, *result, *borrow;
    sub = MakeEmpty(NULL);
    temp1 = MakeEmpty(NULL);
    temp2 = MakeEmpty(NULL);
    result = MakeEmpty(NULL);
    borrow = MakeEmpty(NULL);
    int x = IsGreater(num1,num2);
    if(x > 0)
        temp1 = num1, temp2 = num2;
    else if(x < 0)
        temp1 = num2, temp2 = num1;
    else
    {
        struct node* zero = MakeEmpty(NULL);
        InsertLast(0,zero);
        return zero;
    }
    InsertLast(0,borrow);
    while(temp1->next != NULL)
        temp1 = temp1->next;
    while(temp2->next != NULL)
        temp2 = temp2->next;
    while(temp2->pre != NULL)
    {
        if(((temp1->data) - (temp2->data) + (borrow->next->data)) >= 0)
        {
            InsertLast(((temp1->data) - (temp2->data) + borrow->next->data),sub);
            InsertLast(0,borrow);
        }
        else
        {
            InsertLast((((temp1->data) - (temp2->data) + (borrow->next->data)) + 10),sub);
            InsertLast((-1),borrow);
        }
        temp2 = temp2->pre;
        temp1 = temp1->pre;
        borrow = borrow->next;
    }
    for(int i = 0 ; i < abs(size(num1)-size(num2)) ; i++)
    {
        if((temp1->data) + (borrow->next->data) >= 0)
        {
            InsertLast((temp1->data) + (borrow->next->data),sub);
            InsertLast(0,borrow);
        }
        else
        {
            InsertLast((temp1->data) + (borrow->next->data) + 10,sub);
            InsertLast(-1,borrow);
        }
        temp1 = temp1->pre;
        borrow = borrow->next;
    }
    while(sub->next != NULL)
        sub = sub->next;
    while(sub->pre != NULL)
    {
        InsertLast(sub->data,result);
        sub = sub->pre;
    }
    for(int i = 0 ; result->next->data == 0 && result->next->next != NULL ; i++)
    {
        Delete(0,result);
    }
    x = IsGreater(num1,num2);
    if(x < 0)
        result->next->data *= (-1);
    return result;
}
struct node* Multiplication(struct node* num1, struct node* num2)
{
    if(num1->next == NULL)
        return num2;
    else if (num2->next == NULL)
        return num1;
    struct node *multi[size(num2)], *carry, *multiplication[size(num2)], *temp1, *temp2, *result ;
    for(int i = 0 ; i < size(num2) ; i++)
    {
        multi[i] = MakeEmpty(NULL);
        multiplication[i] = MakeEmpty(NULL);
    }
    carry = MakeEmpty(NULL);
    temp1 = MakeEmpty(NULL);
    temp2 = MakeEmpty(NULL);
    result = MakeEmpty(NULL);
    temp1 = num1,temp2 = num2;
    while(temp1->next != NULL)
        temp1 = temp1->next;
    while(temp2->next != NULL)
        temp2 = temp2->next;
    int count = 0;
    for(int i = 0 ; temp2->pre != NULL  ; i++)
    {
        for(int k = 0 ; k < count ; k++)
        {
            InsertLast(0,multi[i]);
        }
        InsertLast(0,carry);
        while(temp1->pre != NULL)
        {
            InsertLast(((temp1->data) * (temp2->data) + (carry->next->data))/10,carry);
            InsertLast(((temp1->data) * (temp2->data) + (carry->next->data))%10,multi[i]);

            carry = carry->next;
            temp1 = temp1->pre;
        }
        if((carry->next->data) != 0)
            InsertLast((carry->next->data),multi[i]);
        temp2 = temp2->pre;
        temp1 = num1;
        while(temp1->next != NULL)
            temp1 = temp1->next;
        DeleteList(carry);
        count++;
    }
    for(int i = 0 ; i < size(num2) ; i++)
    {
        while(multi[i]->next != NULL)
            multi[i] = multi[i]->next;
        while(multi[i]->pre != NULL)
        {
            InsertLast(multi[i]->data,multiplication[i]);
            multi[i] = multi[i]->pre;
        }
    }
    for(int i = 0 ; i < size(num2) ; i++)
    {
        result = Adder(multiplication[i],result);
    }
    for(int i = 0 ; result->next->data == 0 && result->next->next != NULL ; i++)
    {
        Delete(0,result);
    }
    return result;
}


struct node* Division(struct node* num1, struct node* num2)
{
    struct node* result, *temp1,*temp2,*remainder, *result1, *result2, *count, *temp3;
    result = MakeEmpty(NULL);
    temp1 = MakeEmpty(NULL);
    temp2 = MakeEmpty(NULL);
    remainder = MakeEmpty(NULL);
    result1 = MakeEmpty(NULL);
    result2 = MakeEmpty(NULL);
    count = MakeEmpty(NULL);
    temp1 = num1, temp2 = num2;
    int x = IsGreater(temp1,temp2), y[size(num1)], counter = 0, k = 0 ;
    if(x < 0)
    {
        InsertLast(0,result);
        remainder = temp1;
        return result;
    }
    else
    {
        temp3 = temp1;
        x = IsGreater(temp3,temp2);
        for(k = 0 ; x >= 0 ; k++)
        {
            while(temp3->next != NULL)
                temp3 = temp3->next;
            y[k] = temp3->data;
            temp3 = temp3->pre;
            Delete(temp3->next->data,temp3);
            while(temp3->pre != NULL)
                temp3 = temp3->pre;
            x = IsGreater(temp3,temp2);
        }
        if( IsGreater(temp3,temp2) )
        {
            InsertLast(y[k-1],temp3);
            k--;
        }
        for(int i = k ; i >= 0 ; i--)
        {
            result1 = temp3;
            result1 = Subtractor(result1,temp2);
            while( !IsGreater(result1,temp2))
            {
                counter++;
                result1 = Subtractor(result1,temp2);
            }
            InsertLast(counter,count);
            result2 = Multiplication(count,temp2);
            temp3 = Subtractor(temp3,result2);
            if(i > 0)
                InsertLast(y[i-1],temp3);
            DeleteList(result1);
            DeleteList(result2);
            InsertLast(count->next->data,result);
            DeleteList(count);
            counter=0;
        }
        remainder = temp3;
    }
    return result;
}
