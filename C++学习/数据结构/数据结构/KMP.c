/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//暴力匹配
int ViolentMatch(char* s, char* p)
{
	int sLen = strlen(s);
	int pLen = strlen(p);

	int i = 0;
	int j = 0;
	while (i < sLen && j < pLen)
	{
		if (s[i] == p[j])
		{
			//①如果当前字符匹配成功（即S[i] == P[j]），则i++，j++      
			i++;
			j++;
		}
		else
		{
			//②如果失配（即S[i]! = P[j]），令i = i - (j - 1)，j = 0      
			i = i - j + 1;
			j = 0;
		}
	}
	//匹配成功，返回模式串p在文本串s中的位置，否则返回-1  
	if (j == pLen)
		return i - j;
	else
		return -1;
}

// KMP算法
int KmpSearch(char* s, char* p)
{
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	while (i < sLen && j < pLen)
	{
		//①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++      
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]      
			//next[j]即为j所对应的next值        
			j = next[j];
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}

//next求法
void GetNext(char* p, int next[])
{
	int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]表示前缀，p[j]表示后缀  
		if (k == -1 || p[j] == p[k])
		{
			++k;
			++j;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

//优化过后的next 数组求法  
void GetNextval(char* p, int next[])
{
	int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]表示前缀，p[j]表示后缀    
		if (k == -1 || p[j] == p[k])
		{
			++j;
			++k;
			//较之前next数组求法，改动在下面4行  
			if (p[j] != p[k])
				next[j] = k;   //之前只有这一行  
			else
				//因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]  
				next[j] = next[k];
		}
		else
		{
			k = next[k];
		}
	}
}

int KmpSearch(char* s, char* p)
{
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	while (i < sLen && j < pLen)
	{
		//①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++      
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]      
			//next[j]即为j所对应的next值        
			j = next[j];
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}*/
void get_next(String T, int *next)
{
	int j = 0;
	int i = 1;
	next[i] = 0;
	while (i < T[0])
	{
		if (0 == j || T[i] == T[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

