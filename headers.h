#ifndef _HEADERS_H_
#define _HEADERS_H_

#include "types.h"
#include <stdio.h>


typedef struct ST_cardData_t
{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef struct ST_terminalData_t
{
	float transAmount;
	float maxTransAmount;
	uint8_t transactionDate[11];
}ST_terminalData_t;
/*
typedef struct ST_transaction_t
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t transData;
	EN_transStat_t transStat;
}ST_transaction_t;
*/
typedef enum EN_transStat_t
{
	DECLINED,
	APPROVED
}EN_transStat_t;

EN_transStat_t payment(ST_cardData_t ,ST_terminalData_t );

typedef struct ST_accountBalance_t
{
	float balance;
	uint8_t primaryAccountNumber[20];
}ST_accountBalance_t;

ST_accountBalance_t arr_server[10]={{100.00,"123456789"},{6000.00,"234567891"},
{3250.25,"567891234"},{1500.12,"456789123"}
,{500.00,"258649173"},{2100.00,"654823719"},
{0.00,"971362485"},{1.00,"793148625"},
{10.12,"123123456"},{0.55,"456789321"}};

#endif