#include<stdio.h>
void main()
{
	int K,Q,k,q; int i,r,l;
	int a[8][4]={0},m[8][8]={0},n[8][8]={0};                //a�����뼶������˶˿ڣ�m���м伶������˶˿ڣ�n���м伶������˶˿�
	int A[8][4][8]={0},B[8][8][8]={0},C[8][8][4]={0};       //A�����뼶���ؾ���B���м伶���ؾ���C����������ؾ���

	while(1)
	{
		printf("����������ں������ֵ���ÿո�ֿ�����");
		scanf_s("%d%d",&K,&Q);
		if(K==0&&Q==0) break;                                       //����0 0������ѭ��
		k=int((K-1)/4); q=int((Q-1)/4);

	    if(a[k][K-4*k-1]==0)                    //����
		{
			for(i=0;i<=7;i++)
			{
				if(m[i][k]==0&&n[i][q]==0)
				{
					a[k][K-4*k-1]=1;m[i][k]=1;n[i][q]=1;                     //�˿���1
					A[k][K-4*k-1][i]=1;B[i][k][q]=1;C[q][i][Q-4*q-1]=1;      //������1
					break;
				}
				else 
					continue;
			}
			if(i==8) printf("Error!\n");
		}

		if(a[k][K-4*k-1]==1)                   //�鲥
		{
			for(i=0;i<=7;i++)
			{
				if(A[k][K-4*k-1][i]==1&&B[i][k][q]==1)   //�ж��Ƿ�ȥ��ͬһ�������ģ��
				{
					C[q][i][Q-4*q-1]=1;           
					break;
				}
				else
				{
					if(m[i][k]==0&&n[i][q]==0)
					{
						/*a[k][K-4*k-1]=1;*/m[i][k]=1;n[i][q]=1;           
						A[k][K-4*k-1][i]=1;B[i][k][q]=1;C[q][i][Q-4*q-1]=1;      
						break;
					}
					else 
						continue;
				}
			}
			if(i==8) printf("Error!\n");
		}
	}

	//���A����
	printf("���뼶���ؾ���:\n");
    for(i=0;i<=7;i++){
		for(r=0;r<=3;r++){
			for(l=0;l<=7;l++){
				printf("%d",A[i][r][l]);
			}
			printf("\n");
		}
		printf("\n");
	}
	//���B����
	printf("�м伶���ؾ���:\n");
    for(i=0;i<=7;i++){
		for(r=0;r<=7;r++){
			for(l=0;l<=7;l++){
				printf("%d",B[i][r][l]);
			}
			printf("\n");
		}
		printf("\n");
	}
	//���C����
	printf("��������ؾ���:\n");
    for(i=0;i<=7;i++){
		for(r=0;r<=7;r++){
			for(l=0;l<=3;l++){
				printf("%d",C[i][r][l]);
			}
			printf("\n");
		}
		printf("\n");
	}
}