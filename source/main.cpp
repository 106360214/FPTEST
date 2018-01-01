#include <iostream>//input output
#include <ctime> //�ɶ��禡�w

using namespace std;//�Ŷ��R�W�A�᭱�i�H���Υ�std::

class slotMachine {//����struct
private://�u��ۤvclass����ק鷺�e
	int wheelA;
	int wheelB;
	int wheelC;
	double pullTimes;
	double payOut;
	double moneyInMachine;
	double moneyInPeople;
	double gameCost;
	double moneyPaid;
public://�j�a���i�H��
	slotMachine();
	bool displayMenu(void);
	bool pullHandle(void);
	void spinWheel(int &);
	double calculatePayout();
	void insertCoin(double);
	void displaySpinResults();
	int Random(int, int);
	void displayStatus();
};

int main(void) {
	slotMachine mySlot;//�w�qmySlot�����A�OslotMachine
	cout << "Hellow!" << endl;
	cout << "Welcome to our Slot Machine Game." << endl;
	cout << "Now your status:" << endl;
	cout << endl << "Money in Peoele $" << 150 << endl;
	cout << "Money in Machine $" << 100 << endl;
	cout << "Pulls Left: " << 0 << endl << endl;
	//�W���Ϊk��printf�O�@�˪��Aendl����\n���Ϊk
	bool ok = true;
	while (ok)
	{
		ok = mySlot.displayMenu();
	}
	system("pause");
	return 0;
}

slotMachine::slotMachine()//����W���w�q��private���ȳ]�w�n
{
	srand((int)time(0));//��ɶ����ü�
	moneyInMachine = 100;
	moneyInPeople = 150;
	moneyPaid = 0;
	pullTimes = 0;
	payOut = 0;
	wheelA = 0;
	wheelB = 0;
	wheelC = 0;
	gameCost = 2;
}
bool slotMachine::pullHandle(void)//�ϥΩ��Q
{
	if (pullTimes > 0)//���Ѿl���ơA�~�i�H�ϥ�
	{
		spinWheel(wheelA);
		spinWheel(wheelB);
		spinWheel(wheelC);

		moneyPaid -= gameCost;
		return true;
	}
	else
	{
		return false;
	}
}

void slotMachine::spinWheel(int &theWheel)//�ϥ�Random�H����1~7
{
	theWheel = Random(1, 7);
}

int slotMachine::Random(int lowerLimit, int upperLimit)//���ü�
{
	return 1 + rand() % (upperLimit - lowerLimit + 1);
}

void slotMachine::insertCoin(double amount)//�p���i���B�Ϊ�
{
	moneyPaid += amount;
	moneyInMachine += amount;
	moneyInPeople -= amount;
}

void slotMachine::displaySpinResults()//��ܩ��Q�Ʀr
{
	cout << "[" << wheelA << "] "
		<< "[" << wheelB << "] "
		<< "[" << wheelC << "] \n\n";
}

void slotMachine::displayStatus()//�˵����A
{
	cout << "\nMoney in Peoele $" << moneyInPeople << endl;
	cout << "Money in Machine $" << moneyInMachine << endl;
	cout << "Pulls Left: " << pullTimes << endl << endl;
}
