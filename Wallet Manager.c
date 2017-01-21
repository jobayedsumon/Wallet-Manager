#include <stdio.h>


struct AccType        //declaring structure
{
    int AccNum[20];
    int AccPass[10];
    int AccBal;
}DBBL,Payoneer,Rocket,bKash,Neteller,Skrill,PerfectMoney,WebMoney;

int main()
{

    //FILE *fp=fopen("MoneyManagement.dat","rb+");      //file path
    FILE *fp=fopen("WalletManager.txt","rt+");
    if(fp==NULL)
    {
        fp=fopen("WalletManager.txt","wt+");        //if there is no such file then program will create a new
    }

    int ProgramPass,InputPass,Selection1,Selection2,Selection3,Cond,StartingBalance;     //declaring some variable which will used later
    int TmpVar1,TmpVar2,TmpVar3;


    ProgramPass=1234;       //this are some

    printf("Please enter the system password: ");   //asking user the password to enter the system
    scanf("%d",&InputPass);

    system("cls");               //clearing the console screen

    if(ProgramPass==InputPass)
    {
        printf("Which account information you want to see?\n 1.DBBL\n 2.Payoneer\n 3.Rocket\n 4.bKash\n 5.Neteller\n 6.Skrill\n 7.Perfect Money\n 8.Web Money\n 9.Change System Password.\n");
        Selection1=getche();
        system("cls");

        switch(Selection1)
        {
            case '1':            //if user press 1 then this part will work
            printf("Which act you want to play?\n 1.View your account balance.\n 2.Add fund.\n 3.Cut fund.\n");

            Selection2=getche();
            system("cls");

            switch(Selection2)
            {
                case '1':
                rewind(fp);             //cursor will go to the start of the file
                fscanf(fp,"%d",&DBBL.AccBal);              //reading data from document and store it to structure variable
                printf("Your DBBL account balance is: %d",DBBL.AccBal);       //then print it
                fclose(fp);        //closing the file
                break;

                case '2':
                fscanf(fp,"%d",&DBBL.AccBal);             //reading from the file
                printf("%d+",DBBL.AccBal);
                scanf("%d",&TmpVar3);                  //asking user to type how much he/she want to add
                DBBL.AccBal+=TmpVar3;                  //add the user value with the previous data
                fseek(fp,-sizeof(DBBL.AccBal),SEEK_CUR);                //move the cursor where data about DBBL.AccBal is situated
                fprintf(fp,"%d",DBBL.AccBal);                  //and replace previous one and set new value
                printf("Account balance added successfully.Final balance is %d.",DBBL.AccBal);

                fclose(fp);
                break;

                case '3':
                fscanf(fp,"%d",&DBBL.AccBal);                 //reading data form file
                printf("%d-",DBBL.AccBal);                  //asking user to type how much he/she want to cut
                scanf("%d",&TmpVar3);                      //take the value at a temporary variable
                DBBL.AccBal-=TmpVar3;
                fseek(fp,-sizeof(DBBL.AccBal),SEEK_CUR);                //move cursor where DBBL.AccBal structure data is situated
                fprintf(fp,"%d",DBBL.AccBal);                     //and replace with new one
                printf("Account balance cut successfully.Final balance is %d",DBBL.AccBal);

                fclose(fp);
                break;
            }
            break;

            case '2':                   //rest of the code is just like previous one here just used payoneer/rocket/bKash instead of DBBL
            printf("Which act you want to play?\n 1.View your account balance.\n 2.Add fund.\n 3.Cut fund.\n");

            Selection2=getche();
            system("cls");

            switch(Selection2)
            {
                case '1':
                rewind(fp);
                fscanf(fp,"%d",&Payoneer.AccBal);
                printf("Your Payoneer account balance is: %d",Payoneer.AccBal);
                fclose(fp);
                break;

                case '2':
                fscanf(fp,"&d",&Payoneer.AccBal);
                printf("%d+",Payoneer.AccBal);
                scanf("%d",&TmpVar3);
                Payoneer.AccBal+=TmpVar3;
                fseek(fp,-sizeof(Payoneer.AccBal),SEEK_CUR);
                printf("Account balance added successfully.Final balance is %d",Payoneer.AccBal);
                fclose(fp);
                break;

                case '3':
                fscanf(fp,"&d",&Payoneer.AccBal);
                printf("%d-",Payoneer.AccBal);
                scanf("%d",&TmpVar3);
                Payoneer.AccBal-=TmpVar3;
                fseek(fp,-sizeof(Payoneer.AccBal),SEEK_CUR);
                printf("Account balance cut successfully.Final balance is %d",Payoneer.AccBal);
                fclose(fp);
                break;
            }
            break;

            case '3':
            printf("Which act you want to play?\n 1.View your account balance.\n 2.Add fund.\n 3.Cut fund.\n");

            Selection2=getche();
            system("cls");

            switch(Selection2)
            {
                case '1':
                rewind(fp);
                fscanf(fp,"&d",&Rocket.AccBal);
                printf("Your Rocket account balance is: %d",Rocket.AccBal);
                break;

                case '2':
                fscanf(fp,"&d",&Rocket.AccBal);
                printf("%d+",Rocket.AccBal);
                scanf("%d",&TmpVar3);
                Rocket.AccBal+=TmpVar3;
                fseek(fp,-sizeof(Rocket.AccBal),SEEK_CUR);
                fscanf(fp,"%d",Rocket.AccBal);
                printf("Account balance added successfully.Final balance is %d",Rocket.AccBal);
                break;

                case '3':
                fscanf(fp,"&d",&Rocket.AccBal);
                printf("%d-",Rocket.AccBal);
                scanf("%d",&TmpVar3);
                Rocket.AccBal-=TmpVar3;
                fseek(fp,-sizeof(Rocket.AccBal),SEEK_CUR);
                fprintf(fp,"%d",Rocket.AccBal);
                printf("Account balance cut successfully.Final balance is %d",Rocket.AccBal);
                break;
            }
            break;

            case '4':
            printf("Which act you want to play?\n 1.View your account balance.\n 2.Add fund.\n 3.Cut fund.\n");

            Selection2=getche();
            system("cls");

            switch(Selection2)
            {
                case '1':
                rewind(fp);
                fscanf(fp,"&d",&bKash.AccBal);
                printf("Your bKash account balance is: %d",bKash.AccBal);
                break;

                case '2':
                fscanf(fp,"&d",&bKash.AccBal);
                printf("%d+",bKash.AccBal);
                scanf("%d",&TmpVar3);
                bKash.AccBal+=TmpVar3;
                fseek(fp,-sizeof(bKash.AccBal),SEEK_CUR);
                fprintf(fp,"%d",bKash.AccBal);
                printf("Account balance added successfully.Final Balance is %d",bKash.AccBal);
                break;

                case '3':
                fscanf(fp,"&d",&bKash.AccBal);
                printf("%d-",bKash.AccBal);
                scanf("%d",&TmpVar3);
                bKash.AccBal-=TmpVar3;
                fseek(fp,-sizeof(bKash.AccBal),SEEK_CUR);
                fprintf(fp,"%d",bKash.AccBal);
                printf("Account balance cut successfully.Final Balance is %d",bKash.AccBal);
                break;
            }
                case '5':
                printf("This options are developing now.Please check later.Thanks from the author.");       //these option will add soon.I am facing some problem with result execution so focusing to solve the problem.
                break;

                case '6':
                printf("This options are developing now.Please check later.Thanks from the author.");
                break;

                case '7':
                printf("This options are developing now.Please check later.Thanks from the author.");
                break;

                case '8':
                printf("This options are developing now.Please check later.Thanks from the author.");
                break;

                case '9':
                printf("This options are developing now.Please check later.Thanks from the author.");
                break;
        }
    }
    else
    {
        printf("Sorry,system password was incorrect.");
    }

    return 0;
}
