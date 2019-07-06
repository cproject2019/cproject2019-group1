#pragma once

/*����������,�����������������Ϸ��������*/
typedef struct wordlist
{
	int num;				//���
	char word[17];			//����
	struct wordlist *next;	//ָ����һ�ڵ��ָ��
}WORDLIST, ALL_WORDLIST, RESULT_WORDLIST, PLAY_WORDLIST;

/*���󵥴�����*/
typedef struct wronglist
{
	char word[17];			//������
	int wrongLocation;		//����λ��
	int wrongTime = 0;		//�������
	struct wronglist *next;	//ָ����һ�ڵ��ָ��
}WRONG_WORDLIST;

/*Ŀ���ַ�������*/
typedef struct targetlist
{
	char target[4];			//Ŀ���ַ���
	struct targetlist* next;//ָ����һ�ڵ��ָ��
}TARGET_WORDLIST;