#ifndef _ACCOUNTS_
#define _ACCOUNTS_


class Accounts
{
public:
	Accounts();
	Accounts(int accNum, std::string accName, char accountType, int balance, bool isAdmin);
	~Accounts();
	int m_deposit;
	int m_withdrawAmont;
	bool m_isAdmin;
	char m_accountType;
	void showAccountDetails();
	void deposit(int depositAmount);
	void  withdraw(int withDrawAmount);
	int getAccountNum();
	void setAccountNum(int accNum);
	int getBalance();
	void setBalance(int balance);
	std::string getAccountName();
	void setAccountName(std::string accName);


private:
	int m_accountNum;
	int m_balance;
	std::string m_accountName;
};


#endif // !_ACCOUNTS_

