// Tema_2_Cloud_Computing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<thread>
#include<vector>
#include "Wallet.cpp"

int testMultithreadedWallet()
{
	Wallet walletObject;
	std::vector<std::thread> threads;
	for (int i = 0; i < 5; ++i) {
		threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
	}
	for (int i = 0; i < threads.size(); i++)
	{
		threads.at(i).join();
	}
	return walletObject.getMoney();
}
int main()
{
	int val = 0;
	for (int k = 0; k < 100; k++)
	{
		if ((val = testMultithreadedWallet()) != 5000)
		{
			std::cout << "Error at count = " << k + 1 << "  Money in Wallet = " << val << std::endl;
			//break;
		}
		else {
			std::cout << "All good for count = " << k + 1 << std::endl;
		}
	}
	return 0;
}
