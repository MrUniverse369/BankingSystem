#include<iostream>
#include "Accounts.h"


Accounts::Accounts()
{
	m_deposit = 0;
	m_withdrawAmont = 0;
	m_accountType = ' ';
	m_accountName = " ";
	m_accountNum = 0;
	m_balance = 0;
	m_isAdmin = false;
	

}

Accounts::Accounts(int accNum,std::string accName,char accountType, int balance, bool isAdmin)
{
	this->m_deposit = 0;
	this->m_withdrawAmont = 0;
	this->m_isAdmin = isAdmin;
	this->m_accountType = accountType;
	this->m_accountName = accName ;
	this->m_accountNum = accNum;
	this->m_balance = balance;
	
}

Accounts::~Accounts()
{
}

void Accounts::deposit(int depositAmount)
{
	this->m_balance = this->m_balance + depositAmount;
}

void Accounts::withdraw(int withDrawAmount)
{
	this->m_balance = this->m_balance - withDrawAmount;
}

int Accounts::getAccountNum()
{
	return m_accountNum;
}

void Accounts::setAccountNum(int accNum)
{
	this->m_accountNum = accNum;
}

int Accounts::getBalance()
{
	return m_balance;
}

void Accounts::setBalance(int balance)
{
	this->m_balance = balance;
}

std::string Accounts::getAccountName()
{
	return m_accountName;
}


void Accounts::setAccountName(std::string accName)
{
	

}
