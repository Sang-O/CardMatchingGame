#include "CardGameHeader.h"


int main()
{	
	GameManager manager;
	GAMESTATE status = INIT;
	manager.InitGame();
	
	while (true)
	{
		manager.MovePosition(manager.GetXPos(), manager.GetYPos());
	}


	return 0;
	while (true)
	{
		switch (status)
		{
		case INIT:

			status = READY;
			break;
		case READY:
			//����ȭ�� ���� ���� UI���� Ư�� ��ư�� ������ status�� OPENCARD�� �������ָ��.
			break;
		case OPENCARD:
			//���۹�ư�� �������� ī�尡 ��� ���µǾ��ִ°�.(�ܿ�½ð��̶�� �����)
			//ī�带 �����ϴ� �Լ� ȣ���� ���� �ð����� RUNNING���� �Ѿ���
			status = RUNNING;
			break;
		case RUNNING:
			//ī����� ���������� ������ �ϸ� UI�� ������Ʈ �Ǵ°�
			//if 2���� ī�尡 ���õǾ��ٸ� STOP���� ���� üũ 2�� ���ϸ� RUNNING status����
			break;
		case STOP:
			//2���� �´��� Ȯ���ϴ� ��. >> �´ٰ� �ǴܵǸ� CARDSTATE�� OPEN_CARD�� ����
			//�ƴϸ� CLOSE_CARD�� �ٽ� ��������ߵ�. ������ ������ �ٽ� RUNNING����
			break;
		case SUCCES:
			//���� Ŭ��� �Ǿ�����?
			//������ Ŭ����Ǹ� RESULTâ���� �̵��ؼ� ���� ������ ǥ�����ָ��.
			status = RESULT;
			break;
		case FAIL:
			//���� Ŭ��� ���� �ʴ´ٸ� FAIL�ο� �� ������ ǥ��.
			status = RESULT;
			break;
		case RESULT:
			//������ �Բ� �ٽý����ϰڳĴ� ���� ���.
			//if �ٽ��Ѵٰ� �ϸ� status = READY;
			break;
		default:
			cout << "�߸��� ����" << endl;
			cout << "�ƹ� ��ư�̳� ������ ������ �ٽ� ���۵˴ϴ�." << endl;
			system("pause");
			status = INIT;
			break;
		}
	}

	system("pause");
	return 0;
}