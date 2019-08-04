#include<stdio.h>
void main()
{
	int K,Q,k,q; int i,r,l;
	int a[8][4]={0},m[8][8]={0},n[8][8]={0};                //a是输入级的输入端端口，m是中间级的输入端端口，n是中间级的输出端端口
	int A[8][4][8]={0},B[8][8][8]={0},C[8][8][4]={0};       //A是输入级开关矩阵，B是中间级开关矩阵，C是输出级开关矩阵

	while(1)
	{
		printf("请输入输入口和输出口值（用空格分开）：");
		scanf_s("%d%d",&K,&Q);
		if(K==0&&Q==0) break;                                       //输入0 0，跳出循环
		k=int((K-1)/4); q=int((Q-1)/4);

	    if(a[k][K-4*k-1]==0)                    //单播
		{
			for(i=0;i<=7;i++)
			{
				if(m[i][k]==0&&n[i][q]==0)
				{
					a[k][K-4*k-1]=1;m[i][k]=1;n[i][q]=1;                     //端口置1
					A[k][K-4*k-1][i]=1;B[i][k][q]=1;C[q][i][Q-4*q-1]=1;      //开关置1
					break;
				}
				else 
					continue;
			}
			if(i==8) printf("Error!\n");
		}

		if(a[k][K-4*k-1]==1)                   //组播
		{
			for(i=0;i<=7;i++)
			{
				if(A[k][K-4*k-1][i]==1&&B[i][k][q]==1)   //判断是否去往同一个输出级模块
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

	//输出A矩阵
	printf("输入级开关矩阵:\n");
    for(i=0;i<=7;i++){
		for(r=0;r<=3;r++){
			for(l=0;l<=7;l++){
				printf("%d",A[i][r][l]);
			}
			printf("\n");
		}
		printf("\n");
	}
	//输出B矩阵
	printf("中间级开关矩阵:\n");
    for(i=0;i<=7;i++){
		for(r=0;r<=7;r++){
			for(l=0;l<=7;l++){
				printf("%d",B[i][r][l]);
			}
			printf("\n");
		}
		printf("\n");
	}
	//输出C矩阵
	printf("输出级开关矩阵:\n");
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