#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "headers.h"
#include "types.h"

void test_approved(void)
{
	ST_cardData_t card_1;
	ST_terminalData_t terminal_1;
	EN_transStat_t state_1;
	EN_transStat_t state;
	strcpy(card_1.cardHolderName,"Mohamed Ehab");
	strcpy(card_1.primaryAccountNumber,"456789123");
	strcpy(card_1.cardExpirationDate,"12/19");
	terminal_1.transAmount=20.50;
	strcpy(terminal_1.transactionDate,"27/11/2019");
	state = payment(card_1 ,terminal_1);
	if(state==APPROVED)
	{
		printf("Test case 1 passed\n");
	}else if(state==DECLINED)
	{
		printf("Test case 1 failed\n");
	}
}

void test_declined_expired(void)
{
	ST_cardData_t card_1;
	ST_terminalData_t terminal_1;
	EN_transStat_t state_1;
	EN_transStat_t state;
	strcpy(card_1.cardHolderName,"Mohamed Ehab");
	strcpy(card_1.primaryAccountNumber,"456789123");
	strcpy(card_1.cardExpirationDate,"10/19");
	terminal_1.transAmount=20.50;
	strcpy(terminal_1.transactionDate,"27/11/2019");
	state = payment(card_1 ,terminal_1);
	if(state==DECLINED)
	{
		printf("Test case 2 passed\n");
	}else if(state==APPROVED)
	{
		printf("Test case 2 failed\n");
	}
}

void test_declined_no_pan(void)
{
	ST_cardData_t card_1;
	ST_terminalData_t terminal_1;
	EN_transStat_t state_1;
	EN_transStat_t state;
	strcpy(card_1.cardHolderName,"Mohamed Ehab");
	strcpy(card_1.primaryAccountNumber,"999999999");
	strcpy(card_1.cardExpirationDate,"12/19");
	terminal_1.transAmount=20.50;
	strcpy(terminal_1.transactionDate,"27/11/2019");
	state = payment(card_1 ,terminal_1);
	if(state==DECLINED)
	{
		printf("Test case 3 passed\n");
	}else if(state==APPROVED)
	{
		printf("Test case 3 failed\n");
	}
}

void test_declined_transaction_more_than_max(void)
{
	ST_cardData_t card_1;
	ST_terminalData_t terminal_1;
	EN_transStat_t state_1;
	EN_transStat_t state;
	strcpy(card_1.cardHolderName,"Mohamed Ehab");
	strcpy(card_1.primaryAccountNumber,"456789123");
	strcpy(card_1.cardExpirationDate,"10/19");
	terminal_1.transAmount=6000.00;
	strcpy(terminal_1.transactionDate,"27/11/2019");
	state = payment(card_1 ,terminal_1);
	if(state==DECLINED)
	{
		printf("Test case 4 passed\n");
	}else if(state==APPROVED)
	{
		printf("Test case 4 failed\n");
	}
}

void test_declined_transaction_more_than_balance(void)
{
	ST_cardData_t card_1;
	ST_terminalData_t terminal_1;
	EN_transStat_t state_1;
	EN_transStat_t state;
	strcpy(card_1.cardHolderName,"Mohamed Ehab");
	strcpy(card_1.primaryAccountNumber,"456789123");
	strcpy(card_1.cardExpirationDate,"10/19");
	terminal_1.transAmount=2000.00;
	strcpy(terminal_1.transactionDate,"27/11/2019");
	state = payment(card_1 ,terminal_1);
	if(state==DECLINED)
	{
		printf("Test case 5 passed\n");
	}else if(state==APPROVED)
	{
		printf("Test case 5 failed\n");
	}
}

int main(void)
{
	test_approved();
	test_declined_expired();
	test_declined_no_pan();
	test_declined_transaction_more_than_max();
	test_declined_transaction_more_than_balance();
	return 0;
}