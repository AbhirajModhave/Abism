#include <stdio.h>

void withdraw(int,int*);
void deposit(int,int*);
void Show(int*);


int main()
{
    int pin=0;
    int choice=0;
    int balance=25000;
    char ch;



    printf("\n\t\t\t\t***WELCOME TO ATM!***");

    printf("\n\n\tPlease insert your ATM card: "); /*Please enter i ot I to insert your card */
    scanf("%c",&ch);

    if(ch=='i' || ch=='I')
    {
        printf("\n\n\tEnter your pin number: ");
        scanf("%d",&pin);

        do{

                printf("\n\n\n\n\tWhich action you want to take");
                printf("\n\t1.Withdraw cash");
                printf("\n\t2.Deposit cash");
                printf("\n\t3.Show Balance");
                printf("\n\t4.Quit");

                printf("\n\n\tselect your action:  ");
                scanf("\n\t%d",&choice);

                switch(choice)
                {

                    case 1: withdraw(pin,&balance);
                    break;

                    case 2: deposit(pin,&balance);
                    break;

                    case 3: Show(&balance);
                    break;

                    case 4: printf("\n\t\tThank u for using this ATM!!!");
                    break;

                    default: printf("\nINVALID INPUT!");


                }
            }while(choice!=4);

    }


    else
    {

          printf("\n\n\t\t\tINVALID CARD!!!!!!!!!!!");
    }


    return 0;

}

void withdraw(int pin,int* balance)
{

     int ver=0;
     int amt=0;


     printf("\n\n\t\t\t***WELCOME TO WITHDRAW SECTION!***");

     printf("\n\n\tEnter the amount you want to withdraw: ");
     scanf("%d",&amt);



     printf("\n\tYou have entered amount of rs.%d",amt);

     printf("\n\n\tPlease enter your pin to proceed: ");
     scanf("%d",&ver);

     if(ver==pin && amt<=*balance && amt>0)
     {



        *balance=*balance-amt;
         printf("\n\n\tWithdraw succesfull!!!! ");

        Show(balance);



     }
      else if (amt<=0)
	{

		printf("\n\n\t\t\tAmount cannot be negative or zero!!!!");
		printf("\n\n\n\t\t\tPROCESS HAS BEEN TERMINATED!!!");
	}
     else if(ver!=pin)
     {

        printf("\n\n\tWrong pin! please Enter a valid pin: ");
        scanf("%d",&ver);

		if(ver==pin)
		{

			withdraw(pin,balance);

	    }
	    else
	    {

			printf("\n\n\t\tWrong PIN!!!!Process has been terminated");


		}
     }
      else if(amt>*balance)
     {

        printf("\n\n\tTransacton failed!!!Withdraw amount exceeds available balance");
     }


}

void deposit(int pin,int* balance)
{
    int d_amt=0;
    int d_ver=0;

    printf("\n\n\t\t\t***WELCOME TO DEPOSIT SECTION!***");

    printf("\n\n\tEnter the amount you want to deposit: ");
    scanf("%d",&d_amt);

    printf("\n\tTHe amount %d will be deposited to your account: ",d_amt);

    printf("\n\n\tPlease enter your pin to proceed: ");
    scanf("%d",&d_ver);

    if(d_ver==pin && d_amt>0)
    {
        *balance=*balance+d_amt;

        printf("\n\tCash deposited successfully!!");

        Show(balance);
    }
    else if(d_ver!=pin)
    {

        printf("\n\n\tINVALID PIN!Please enter a valid pin: ");
        scanf("%d",&d_ver);

        if(d_ver==pin)
        {
            deposit(pin,balance);
        }
        else{

            printf("\n\n\tInvalid PIN!!!!Process has been terminated");

        }
    }
     else if (d_amt<=0)
	{

		printf("\n\n\t\tAmount cannot be negative or zero!!!!");
		printf("\n\n\n\t\t\tPROCESS HAS BEEN TERMINATED!!!");
	}


}


void Show(int* balance)
{

    printf("\n\n\tYour available balance is: %d",*balance);

}

