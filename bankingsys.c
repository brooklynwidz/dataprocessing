#include <stdio.h>
#include <string.h>

/*

1. Create Account
2. Deposit Money
3. Withdraw Money
4. Check Balance
5. Exit


*/

// printf("choice is %d", choice);
struct Account
{
    int accNo;
    char holderName[10];
    int balance;
};

void menu(int *choice);
void CreateAccount(struct Account *p);
void DepositMoney(struct Account *p);
void WithdrawMoney(struct Account *p);
void CheckBalance(struct Account *p);

int main()
{

    struct Account acc;
    struct Account *p;
    p = &acc;
    acc.balance = 0;
    int choice = 0;
    while (choice != 5)
    {
        menu(&choice);

        switch (choice)
        {
        case 1:
            CreateAccount(p);
            break;
        case 2:
            DepositMoney(p);
            break;
        case 3:
            WithdrawMoney(p);
            break;
        case 4:
            CheckBalance(p);
            break;
        case 5:
            printf("Thankyou for visiting us...");
            break;
        default:
            printf("Enter a Valid choice");
        }
    }
}

void menu(int *choice)
{

    printf("Menu:\n 1.Create Account\n 2. Deposit Money\n 3. Withdraw Money\n 4. Check Balance \n 5. Exit \n ");

    printf("Enter your choice: ");
    scanf("%d", choice);
}

void CreateAccount(struct Account *p)
{

    static int nextaccNO = 1001;
    p->accNo = nextaccNO;
    nextaccNO++;

    printf("enter your name for account: ");
    scanf("%s", p->holderName);

    printf("Your account details: \n Account Number: %d\n Holder Name: %s", p->accNo, p->holderName);
}

void DepositMoney(struct Account *p)
{
    // printf("dash");
    int add;
    printf("Enter amount you want to add to you account: ");
    scanf("%d", &add);
    p->balance += add;
    printf("your current balance is : %d\n", p->balance);
}
void WithdrawMoney(struct Account *p)
{
    int withdrawAmount;
    printf("enter how much money to withdraw: ");
    scanf("%d", &withdrawAmount);
    if (withdrawAmount <= p->balance)
    {
        printf("withdraw completed.. Thankyou for waiting\n");
        p->balance -= withdrawAmount;
    }
    else
    {
        printf("insuffient ammount.\n");
    }
}
void CheckBalance(struct Account *p)
{
    printf("Your Current Balance is : %d\n", p->balance);
}
