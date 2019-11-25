typedef unsigned char SString[256];
int next[256] = {0};

void getNext(SString);
int indexKMP(SString, SString, int);
int getLen(SString);
int slen, tlen;

void getNext(SString T)
{
	int i = 0, j = -1;
	next[0] = -1;
	while (i < tlen)
	{
		if (j == -1 || T[i] == T[j])
		{
			++i, ++j;
			if (T[i] != T[j])
				next[i] = j;
			else
				next[i] = next[j];
		}
		else
			j = next[j];
	}
}

int indexKMP(SString S, SString T, int pos) //从pos处开始匹配 pos:[0, length - 1]
{
	slen= getLen(S);
	tlen = getLen(T);
	int i = pos, j = 0;
	getNext(T);
	while (i < slen)
	{
		while (j != -1 && S[i] != T[j]) j = next[j];
		i++, j++;
	}
	if (j >= tlen)
		return i - tlen + 1;
	else
		return -1;
}

int getLen(SString T)
{
	int len = 0;
	for (int i = 0; T[i] != '\0'; i++)
		len++;
	return len;
}