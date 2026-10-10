#include <stdio.h>

/* Function declarations */
void menu(void);
void checkbalance(float balance);
float deposit(float balance);
float withdraw(float balance);
int changepin(int pin);

int main()
{
    int pin = 1234;
    int enteredpin;
    int newpin;
    int attempts = 0;
    int choice;
    float balance = 10000.0;

    printf("===== ATM MACHINE =====\n");

    /* PIN login */
    while (attempts < 3)
    {
        printf("ENTER YOUR PIN: ");
        scanf("%d", &enteredpin);

        if (enteredpin == pin)
        {
            printf("LOGIN SUCCESSFUL\n");
            break;
        }

        attempts++;

        printf("INCORRECT PIN\n");
        printf("ATTEMPTS REMAINING: %d\n", 3 - attempts);

        if (attempts == 3)
        {
            printf("TOO MANY INCORRECT ATTEMPTS.\n");
            printf("ACCOUNT TEMPORARILY BLOCKED.\n");
            return 0;
        }
    }

    /* ATM menu */
    do
    {
        menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                checkbalance(balance);
                break;

            case 2:
                balance = deposit(balance);
                break;

            case 3:
                balance = withdraw(balance);
                break;

            case 4:
                newpin = changepin(pin);

                if (newpin != pin)
                {
                    pin = newpin;
                }
                break;

            case 5:
                printf("Thank you for using the ATM.\n");
                printf("Have a nice day!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}

/* Display ATM menu */
void menu(void)
{
    printf("\n----- MENU -----\n");
    printf("1. CHECK BALANCE\n");
    printf("2. DEPOSIT MONEY\n");
    printf("3. WITHDRAW MONEY\n");
    printf("4. CHANGE PIN\n");
    printf("5. EXIT\n");
}

/* Check balance */
void checkbalance(float balance)
{
    printf("CURRENT BALANCE: %.2f\n", balance);
}

/* Deposit money */
float deposit(float balance)
{
    float amount;

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("INVALID AMOUNT\n");
    }
    else
    {
        balance += amount;

        printf("%.2f deposited successfully.\n", amount);
        printf("NEW BALANCE: %.2f\n", balance);
    }

    return balance;
}

/* Withdraw money */
float withdraw(float balance)
{
    float amount;

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("INVALID AMOUNT\n");
    }
    else if (amount > balance)
    {
        printf("INSUFFICIENT BALANCE\n");
    }
    else
    {
        balance -= amount;

        printf("Please collect your cash.\n");
        printf("%.2f withdrawn successfully.\n", amount);
        printf("Remaining balance: %.2f\n", balance);
    }

    return balance;
}

/* Change PIN */
int changepin(int pin)
{
    int currentpin;
    int newpin;

    printf("Enter your current PIN: ");
    scanf("%d", &currentpin);

    if (currentpin != pin)
    {
        printf("Incorrect PIN\n");
        return pin;
    }

    printf("Enter your new 4-digit PIN: ");
    scanf("%d", &newpin);

    if (newpin >= 1000 && newpin <= 9999)
    {
        printf("PIN changed successfully.\n");
        return newpin;
    }
    else
    {
        printf("PIN must contain exactly 4 digits.\n");
        return pin;
    }
}