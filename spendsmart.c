
#include <stdio.h>

// FUNCTION 1: Add a new expense
int addExpense(float expenses[], int count)
{
    float amount;

    if (count == 100)
    {
        printf("\nExpense limit reached!\n");
        return count;
    }

    printf("\nEnter expense amount: Rs. ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("\nInvalid amount! Enter a positive value.\n");
        return count;
    }

    expenses[count] = amount;
    count++;

    printf("\nExpense added successfully!\n");

    return count;
}


// FUNCTION 2: Display all expenses
void displayExpenses(float expenses[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo expenses recorded yet!\n");
        return;
    }

    printf("\n------ YOUR EXPENSES ------\n");

    for (i = 0; i < count; i++)
    {
        printf("Expense %d: Rs. %.2f\n", i + 1, expenses[i]);
    }
}


// FUNCTION 3: Calculate total spending
float calculateTotal(float expenses[], int count)
{
    int i;
    float total = 0;

    for (i = 0; i < count; i++)
    {
        total = total + expenses[i];
    }

    return total;
}


// FUNCTION 4: Find highest expense
float findHighest(float expenses[], int count)
{
    int i;
    float highest = expenses[0];

    for (i = 1; i < count; i++)
    {
        if (expenses[i] > highest)
        {
            highest = expenses[i];
        }
    }

    return highest;
}


// FUNCTION 5: Display expense summary
void showSummary(float expenses[], int count)
{
    float total, average, highest;

    if (count == 0)
    {
        printf("\nNo expenses available for summary!\n");
        return;
    }

    total = calculateTotal(expenses, count);
    average = total / count;
    highest = findHighest(expenses, count);

    printf("\n------ EXPENSE SUMMARY ------\n");
    printf("Total Expenses   : Rs. %.2f\n", total);
    printf("Average Expense  : Rs. %.2f\n", average);
    printf("Highest Expense  : Rs. %.2f\n", highest);
    printf("Number of Entries: %d\n", count);
}


// MAIN FUNCTION
int main()
{
    float expenses[100];
    int count = 0;
    int choice;

    while (1)
    {
        printf("\n================================\n");
        printf("       SPENDSMART TRACKER\n");
        printf("================================\n");

        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. View Expense Summary\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                count = addExpense(expenses, count);
                break;

            case 2:
                displayExpenses(expenses, count);
                break;

            case 3:
                showSummary(expenses, count);
                break;

            case 4:
                printf("\nThank you for using SpendSmart!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
