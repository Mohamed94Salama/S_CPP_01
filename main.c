#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "headers.h"
#include "types.h"

extern ST_cardData_t card_1;
extern ST_terminalData_t terminal_1;
extern EN_transStat_t state_1;
extern ST_accountBalance_t arr_server[10];

int main(void)
{
	uint8_t name[25];
	uint8_t PAN[20];
	uint8_t date_1[6];
	uint8_t date_2[11];
	float amount;
	EN_transStat_t state;
	uint8_t con;
	do{
	printf("Please Enter Card Data:\n");
	printf("Please Enter the Card Holder Name:\n");
	getchar();
	fgets(name,25,stdin);
	strcpy(card_1.cardHolderName,name);
	printf("Please Enter the Primary Account Number:\n");
	scanf("%s",PAN);
	strcpy(card_1.primaryAccountNumber,PAN);
	printf("Please card Expiry Date:\n");
	scanf("%s",date_1);
	strcpy(card_1.cardExpirationDate,date_1);
	printf("Please Enter Terminal Data:\n");
	printf("Please Enter the transaction Amount:\n");
	scanf("%f",&amount);
	terminal_1.transAmount=amount;
	printf("Please card transaction Date:\n");
	scanf("%s",date_2);
	strcpy(terminal_1.transactionDate,date_2);
	printf("Verifying Data from the server...\n");
	
	state = payment(card_1 ,terminal_1);
	if(state==APPROVED)
	{
		printf("The Transaction is APPROVED\n");
	}else if(state==DECLINED)
	{
		printf("The Transaction is DECLINED\n");
	}
	printf("Do you want to continue(y/n)?:\n");
	getchar();
	scanf(" %c",&con);
	}while(con=='y');
	return 0;
}
/*
EN_transStat_t payment(ST_cardData_t card_1,ST_terminalData_t terminal_1)
{
	uint8_t y_e_1=card_1.cardExpirationDate[3];
	uint8_t y_e_2=card_1.cardExpirationDate[4];
	uint8_t y_t_1=terminal_1.transactionDate[8];
	uint8_t y_t_2=terminal_1.transactionDate[9];
	uint8_t m_e_1=card_1.cardExpirationDate[0];
	uint8_t m_e_2=card_1.cardExpirationDate[1];
	uint8_t m_t_1=terminal_1.transactionDate[3];
	uint8_t m_t_2=terminal_1.transactionDate[4];
	float amount_1=terminal_1.transAmount;
	uint8_t PAN_1[20];
	strcpy(PAN_1,card_1.primaryAccountNumber);
	uint8_t counter=0;
	uint8_t var;
	terminal_1.maxTransAmount=5000;

	if(y_t_1>y_e_1)
	{
		return DECLINED;
	}else if(y_t_1==y_e_1)
	{
		
		if(y_t_2>y_e_2)
		{
			return DECLINED;
		}else if(y_t_2==y_e_2)
		{
			
			if(m_t_1>m_e_1)
			{
				return DECLINED;
			}else if(m_t_1==m_e_1)
			{
				
				if(m_t_2>m_e_2)
				{
					return DECLINED;
				}else
				{
					
		if(amount_1>terminal_1.maxTransAmount)
		{
			return DECLINED;
		}else
		{
			
			for(uint8_t i=0;i<10;i++)
			{
				if((strcmp(arr_server[i].primaryAccountNumber,PAN_1))==0)
				{
					counter++;
					var=i;
				}
			}
			if(counter==0)
			{
				return DECLINED;
			}else
			{
				counter=0;
				if(amount_1>arr_server[var].balance)
				{
					return DECLINED;
				}else
				{
					return APPROVED;
				}
			}
		}
				}
			}else
			{
		if(amount_1>terminal_1.maxTransAmount)
		{
			return DECLINED;
		}else
		{
			for(uint8_t i=0;i<10;i++)
			{
				if((strcmp(arr_server[i].primaryAccountNumber,PAN_1))==0)
				{
					counter++;
					var=i;
				}
			}
			if(counter==0)
			{
				return DECLINED;
			}else
			{
				counter=0;
				if(amount_1>arr_server[var].balance)
				{
					return DECLINED;
				}else
				{
					return APPROVED;
				}
			}
		}
			}
		}else
		{
		if(amount_1>terminal_1.maxTransAmount)
		{
			return DECLINED;
		}else
		{
			for(uint8_t i=0;i<10;i++)
			{
				if((strcmp(arr_server[i].primaryAccountNumber,PAN_1))==0)
				{
					counter++;
					var=i;
				}
			}
			if(counter==0)
			{
				return DECLINED;
			}else
			{
				counter=0;
				if(amount_1>arr_server[var].balance)
				{
					return DECLINED;
				}else
				{
					return APPROVED;
				}
			}
		}
		}
	}else
	{
		if(amount_1>terminal_1.maxTransAmount)
		{
			return DECLINED;
		}else
		{
			for(uint8_t i=0;i<10;i++)
			{
				if((strcmp(arr_server[i].primaryAccountNumber,PAN_1))==0)
				{
					counter++;
					var=i;
				}
			}
			if(counter==0)
			{
				return DECLINED;
			}else
			{
				counter=0;
				if(amount_1>arr_server[var].balance)
				{
					return DECLINED;
				}else
				{
					return APPROVED;
				}
			}
		}
	}
}
*/