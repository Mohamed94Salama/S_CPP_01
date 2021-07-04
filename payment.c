#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "headers.h"
#include "types.h"

ST_cardData_t card_1;
ST_terminalData_t terminal_1;
EN_transStat_t state_1;

ST_accountBalance_t arr_server[10]={{100.00,"123456789"},{6000.00,"234567891"},
{3250.25,"567891234"},{1500.12,"456789123"}
,{500.00,"258649173"},{2100.00,"654823719"},
{0.00,"971362485"},{1.00,"793148625"},
{10.12,"123123456"},{0.55,"456789321"}};

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
